#include "dev_sensor.h"
#include "../mutex/dev_mutex.h"
#include "cfe.h"

Sensor_t sensorHandler[29] = {{.Id = DEV_2},  {.Id = DEV_3},  {.Id = DEV_4},  {.Id = DEV_5},  {.Id = DEV_6},
                              {.Id = DEV_7},  {.Id = DEV_8},  {.Id = DEV_9},  {.Id = DEV_10}, {.Id = DEV_11},
                              {.Id = DEV_12}, {.Id = DEV_13}, {.Id = DEV_14}, {.Id = DEV_15}, {.Id = DEV_16},
                              {.Id = DEV_17}, {.Id = DEV_18}, {.Id = DEV_19}, {.Id = DEV_20}, {.Id = DEV_21},
                              {.Id = DEV_22}, {.Id = DEV_23}, {.Id = DEV_24}, {.Id = DEV_25}, {.Id = DEV_26},
                              {.Id = DEV_27}, {.Id = DEV_28}, {.Id = DEV_29}, {.Id = DEV_30}};

int32 SensorInitialize(DeviceId ID)
{
    return mutexInitialize(&sensorHandler[ID - DEV_2].mutex, sensorHandler[ID - DEV_2].Id);
}

int32 SensorCapture(DeviceId ID)
{
    return OS_SUCCESS;
}
