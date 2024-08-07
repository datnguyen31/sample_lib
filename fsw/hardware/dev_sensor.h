#ifndef DEV_SENSOR_H
#define DEV_SENSOR_H

#include "../public_inc/dev_type.h"

int32 SensorInitialize(DeviceId ID);
int32 SensorCapture(DeviceId ID);

#endif