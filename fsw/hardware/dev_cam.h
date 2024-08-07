#ifndef DEV_CAM_H
#define DEV_CAM_H

#include "../public_inc/dev_type.h"

int32 CameraInitialize(DeviceId ID);
int32 CameraCapture(DeviceId ID);

#endif