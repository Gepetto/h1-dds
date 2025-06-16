#include "messages/LowCmd.h"
#include "messages/LowState.h"
#include "dds/dds.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// DDS
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>

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

void cmd_handler(const void *message)
{
  std::cout << "Received command message" << std::endl;
}

int main(int argc, char **argv)
{
  unitree::robot::ChannelFactory::Instance()->Init(1, "lo");

  unitree::robot::ChannelPublisherPtr<lowlevel_state> publisher;
  publisher.reset(new unitree::robot::ChannelPublisher<lowlevel_state>("rt/lowstate"));
  publisher->InitChannel();

  unitree::robot::ChannelSubscriberPtr<lowlevel_Cmd> subscriber;
  subscriber.reset(new unitree::robot::ChannelSubscriber<lowlevel_Cmd>("rt/lowcmd"));
  subscriber->InitChannel(
      &cmd_handler, 1);

  return EXIT_SUCCESS;
}
