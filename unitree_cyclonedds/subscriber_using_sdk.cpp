#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>

#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/idl/hg/LowCmd_.hpp>
#include <unitree/idl/hg/LowState_.hpp>

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
  const unitree_hg::msg::dds_::LowCmd_ *cmd = (const unitree_hg::msg::dds_::LowCmd_ *)msg;

  std::cout << "mode_machine:" << cmd->mode_machine() << ", crc:" << cmd->crc() << std::endl;
}

int main(int argc, char **argv)
{
  ChannelFactory::Instance()->Init(1, "lo");

  ChannelPublisherPtr<unitree_hg::msg::dds_::LowState_> publisher = ChannelPublisherPtr<unitree_hg::msg::dds_::LowState_>(new ChannelPublisher<unitree_hg::msg::dds_::LowState_>("rt/lowstate"));
  publisher->InitChannel();

  ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_> subscriber = ChannelSubscriberPtr<unitree_hg::msg::dds_::LowCmd_>(new ChannelSubscriber<unitree_hg::msg::dds_::LowCmd_>("rt/lowcmd"));
  subscriber->InitChannel(
      std::bind(CmdHandler, std::placeholders::_1), 1);

  while (true)
  {
    unitree_hg::msg::dds_::LowState_ lowstate{};
    publisher->Write(lowstate);
    usleep(2000);
  }

  return EXIT_SUCCESS;
}
