#ifndef _IMU_TASK_H_
#define _IMU_TASK_H_

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"


#define IMU_MSG_LENGTH              11u
#define IMU_MSG_LENGTH_2            (IMU_MSG_LENGTH * 2.f)
#define IMU_MSG_LENGTH_3            (IMU_MSG_LENGTH * 3.f)
#define IMU_MSG_SOF                 0x55
#define IMU_CMD_ID_SEGMENT_OFFSET   0x01

#define IMU_ACCEL_CMD_ID            0x51
#define IMU_GYRO_CMD_ID             0x52
#define IMU_MAG_CMD_ID              0x53

typedef struct {
    __packed struct {
    float x;
    float y;
    float z;
    } acc;
    
    __packed struct {
    float x;
    float y;
    float z;
    } gyro;
    
    __packed struct {
    float x;
    float y;
    float z;
    } mag;
} imu_t;

void imu_task_init(void);
void imu_download_msg_process(uint8_t * buffer);
void imu_msg_unpack_handler(uint8_t * buffer);

#endif