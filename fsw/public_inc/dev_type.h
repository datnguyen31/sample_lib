#ifndef DEV_TYPE_H
#define DEV_TYPE_H

#include "common_types.h"

typedef enum
{
    CAMERA,
    SENSOR
} DeviceType;

typedef enum
{
    DEV_0,
    DEV_1,
    DEV_2,
    DEV_3,
    DEV_4,
    DEV_5,
    DEV_6,
    DEV_7,
    DEV_8,
    DEV_9,
    DEV_10,
    DEV_11,
    DEV_12,
    DEV_13,
    DEV_14,
    DEV_15,
    DEV_16,
    DEV_17,
    DEV_18,
    DEV_19,
    DEV_20,
    DEV_21,
    DEV_22,
    DEV_23,
    DEV_24,
    DEV_25,
    DEV_26,
    DEV_27,
    DEV_28,
    DEV_29,
    DEV_30
} DeviceId;

typedef struct
{
    uint32 mutex;
} MutexHandler_t;

/* Camera type that has image_str */
typedef struct
{
    MutexHandler_t mutex;
    DeviceId       Id;
    char           image_str[20];
} Camera_t;

/* Sensor does not contain image_str */
typedef struct
{
    MutexHandler_t mutex;
    DeviceId       Id;
} Sensor_t;

#endif