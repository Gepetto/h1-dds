#include "messages/LowCmd.h"
#include "messages/LowState.h"
#include "dds/dds.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

// int init_state_mocker()
// {

//   lowstate_rc = dds_set_status_mask(lowstate_writer, DDS_PUBLICATION_MATCHED_STATUS);
//   if (lowstate_rc != DDS_RETCODE_OK)
//     DDS_FATAL("dds_set_status_mask: %s\n", dds_strretcode(-lowstate_rc));

//   while (!(lowstate_status & DDS_PUBLICATION_MATCHED_STATUS))
//   {
//     lowstate_rc = dds_get_status_changes(lowstate_writer, &lowstate_status);
//     if (lowstate_rc != DDS_RETCODE_OK)
//       DDS_FATAL("dds_get_status_changes: %s\n", dds_strretcode(-lowstate_rc));

//     /* Polling sleep. */
//     dds_sleepfor(DDS_MSECS(20));
//   }

//   return EXIT_SUCCESS;
//   dds_entity_t lowstate_participant;
//   dds_entity_t lowstate_topic;
//   dds_entity_t lowstate_writer;
//   dds_return_t lowstate_rc;
//   lowlevel_state lowstate_msg;
//   uint32_t lowstate_status = 0;
// }

/* An array of one message (aka sample in dds terms) will be used. */
#define MAX_SAMPLES 40

int main(int argc, char **argv)
{
  dds_entity_t lowcmd_participant;
  dds_entity_t lowcmd_topic;
  dds_entity_t lowcmd_reader;
  lowlevel_Cmd *lowcmd_msg;
  void *lowcmd_samples[MAX_SAMPLES];
  dds_sample_info_t lowcmd_infos[MAX_SAMPLES];
  dds_return_t lowcmd_rc;
  dds_qos_t *lowcmd_qos;
  dds_entity_t lowstate_participant;
  dds_entity_t lowstate_topic;
  dds_entity_t lowstate_writer;
  dds_return_t lowstate_rc;
  lowlevel_state lowstate_msg;
  uint32_t lowstate_status = 0;
  (void)argc;
  (void)argv;

  /* Create a Participant. */
  lowcmd_participant = dds_create_participant(1, NULL, NULL);
  if (lowcmd_participant < 0)
    DDS_FATAL("dds_create_participant: %s\n", dds_strretcode(-lowcmd_participant));

  /* Create a Topic. */
  lowcmd_topic = dds_create_topic(
      lowcmd_participant, &lowlevel_Cmd_desc, "rt/lowcmd", NULL, NULL);
  if (lowcmd_topic < 0)
    DDS_FATAL("dds_create_topic: %s\n", dds_strretcode(-lowcmd_topic));

  /* Create a reliable Reader. */
  lowcmd_qos = dds_create_qos();
  dds_qset_reliability(lowcmd_qos, DDS_RELIABILITY_RELIABLE, DDS_SECS(10));
  lowcmd_reader = dds_create_reader(lowcmd_participant, lowcmd_topic, lowcmd_qos, NULL);
  if (lowcmd_reader < 0)
    DDS_FATAL("dds_create_reader: %s\n", dds_strretcode(-lowcmd_reader));
  dds_delete_qos(lowcmd_qos);

  /* Create a Participant. */
  lowstate_participant = dds_create_participant(1, NULL, NULL);
  if (lowstate_participant < 0)
    DDS_FATAL("dds_create_participant: %s\n", dds_strretcode(-lowstate_participant));

  /* Create a Topic. */
  lowstate_topic = dds_create_topic(
      lowstate_participant, &lowlevel_state_desc, "rt/lowstate", NULL, NULL);
  if (lowstate_topic < 0)
    DDS_FATAL("dds_create_topic: %s\n", dds_strretcode(-lowstate_topic));

  /* Create a Writer. */
  lowstate_writer = dds_create_writer(lowstate_participant, lowstate_topic, NULL, NULL);
  if (lowstate_writer < 0)
    DDS_FATAL("dds_create_writer: %s\n", dds_strretcode(-lowstate_writer));

  printf("=== [Publisher]  Waiting for a reader to be discovered ...\n");
  fflush(stdout);

  printf("\n=== [Subscriber] Waiting for a sample ...\n");
  fflush(stdout);

  /* Initialize sample buffer, by pointing the void pointer within
   * the buffer array to a valid sample memory location. */
  lowcmd_samples[0] = lowlevel_Cmd__alloc();

  /* Poll until data has been read. */
  while (true)
  {
    /* Do the actual read.
     * The return value contains the number of read samples. */
    lowcmd_rc = dds_read(lowcmd_reader, lowcmd_samples, lowcmd_infos, MAX_SAMPLES, MAX_SAMPLES);
    if (lowcmd_rc < 0)
      DDS_FATAL("dds_read: %s\n", dds_strretcode(-lowcmd_rc));

    /* Check if we read some data and it is valid. */
    if ((lowcmd_rc > 0) && (lowcmd_infos[0].valid_data))
    {
      /* Print Message. */
      lowcmd_msg = (lowlevel_Cmd *)lowcmd_samples[0];
      printf("=== [Subscriber] Received : ");
      printf("Message (crc %d, tau %f)\n", lowcmd_msg->crc, lowcmd_msg->motor_cmd->tau);
      fflush(stdout);
    }
    else
    {
      /* Polling sleep. */
      dds_sleepfor(DDS_MSECS(20));
    }

    /* Create a message to write. */
    // blah....
    lowstate_msg.version[0] = 1;
    lowstate_msg.version[1] = 0;
    lowstate_msg.mode_pr = 0;
    lowstate_msg.mode_machine = 0;
    lowstate_msg.tick = 0;
    lowstate_msg.imu_state.quaternion[0] = 1.0f;
    lowstate_msg.imu_state.quaternion[1] = 0.0f;
    lowstate_msg.imu_state.quaternion[2] = 0.0f;
    lowstate_msg.imu_state.quaternion[3] = 0.0f;
    lowstate_msg.imu_state.gyroscope[0] = 0.0f;
    lowstate_msg.imu_state.gyroscope[1] = 0.0f;
    lowstate_msg.imu_state.gyroscope[2] = 0.0f;
    lowstate_msg.imu_state.accelerometer[0] = 0.0f;
    lowstate_msg.imu_state.accelerometer[1] = 0.0f;
    lowstate_msg.imu_state.accelerometer[2] = 0.0f;
    lowstate_msg.imu_state.rpy[0] = 0.0f;
    lowstate_msg.imu_state.rpy[1] = 0.0f;
    lowstate_msg.imu_state.rpy[2] = 0.0f;
    lowstate_msg.imu_state.temperature = 0;
    lowstate_msg.motor_state->mode = 0;
    lowstate_msg.motor_state->q = 0.0f;
    lowstate_msg.motor_state->dq = 0.0f;
    lowstate_msg.motor_state->ddq = 0.0f;
    lowstate_msg.motor_state->tau_est = 0.0f;
    lowstate_msg.motor_state->temperature[0] = 0;
    lowstate_msg.motor_state->temperature[1] = 0;
    lowstate_msg.motor_state->vol = 0.0f;
    lowstate_msg.motor_state->sensor[0] = 0;
    lowstate_msg.motor_state->sensor[1] = 0;
    lowstate_msg.motor_state->motorstate = 0;

    lowstate_msg.crc = crc32_core((uint32_t *)&lowstate_msg, (sizeof(lowlevel_state) >> 2) - 1);

    // printf("=== [Publisher]  Writing : ");
    // // printf("Message (%" PRId32 ", %s)\n", msg.userID, msg.message);
    // fflush(stdout);

    lowstate_rc = dds_write(lowstate_writer, &lowstate_msg);
    if (lowstate_rc != DDS_RETCODE_OK)
      DDS_FATAL("dds_write: %s\n", dds_strretcode(-lowstate_rc));
  }

  /* Free the data location. */
  lowlevel_Cmd_free(lowcmd_samples[0], DDS_FREE_ALL);

  /* Deleting the participant will delete all its children recursively as well. */
  lowstate_rc = dds_delete(lowstate_participant);
  if (lowstate_rc != DDS_RETCODE_OK)
    DDS_FATAL("dds_delete: %s\n", dds_strretcode(-lowstate_rc));

  /* Deleting the participant will delete all its children recursively as well. */
  lowcmd_rc = dds_delete(lowcmd_participant);
  if (lowcmd_rc != DDS_RETCODE_OK)
    DDS_FATAL("dds_delete: %s\n", dds_strretcode(-lowcmd_rc));

  return EXIT_SUCCESS;
}
