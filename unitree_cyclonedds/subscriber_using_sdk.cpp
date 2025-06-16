#include "LowCmd.hpp"
#include "LowState.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// DDS
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

using namespace unitree::common;
using namespace unitree::robot;

uint32_t crc32_core(uint32_t *ptr, uint32_t len)
{
  unsigned int xbit = 0;
  unsigned int data = 0;
  unsigned int CRC32 = 0xFFFFFFFF;
  const unsigned int dwPolynomial = 0x04c11db7;

  for (unsigned int i = 0; i < len; i++)
  {
    xbit = 1 << 31;
    data = ptr[i];
    for (unsigned int bits = 0; bits < 32; bits++)
    {
      if (CRC32 & 0x80000000)
      {
        CRC32 <<= 1;
        CRC32 ^= dwPolynomial;
      }
      else
      {
        CRC32 <<= 1;
      }

      if (data & xbit)
        CRC32 ^= dwPolynomial;
      xbit >>= 1;
    }
  }

  return CRC32;
}

void CmdHandler(const void *msg)
{
  const lowlevel::Cmd *cmd = (const lowlevel::Cmd *)msg;

  std::cout << "mode_machine:" << cmd->mode_machine() << ", crc:" << cmd->crc() << std::endl;
}

int main(int argc, char **argv)
{
  ChannelFactory::Instance()->Init(1, "lo");

  ChannelPublisherPtr<lowlevel::state> publisher = ChannelPublisherPtr<lowlevel::state>(new ChannelPublisher<lowlevel::state>("rt/lowstate"));
  publisher->InitChannel();

  ChannelSubscriberPtr<lowlevel::Cmd> subscriber = ChannelSubscriberPtr<lowlevel::Cmd>(new ChannelSubscriber<lowlevel::Cmd>("rt/lowcmd"));
  subscriber->InitChannel(
      std::bind(CmdHandler, std::placeholders::_1), 1);

  return EXIT_SUCCESS;
}
