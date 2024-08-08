#include "dev_mutex.h"
#include "cfe.h"

#include <sys/types.h>
#include <unistd.h>
#include <string.h>

#define DEV_0_STR  "AAA"
#define DEV_1_STR  "AAB"
#define DEV_2_STR  "AAC"
#define DEV_3_STR  "AAD"
#define DEV_4_STR  "AAE"
#define DEV_5_STR  "AAF"
#define DEV_6_STR  "AAG"
#define DEV_7_STR  "AAH"
#define DEV_8_STR  "AAI"
#define DEV_9_STR  "AAJ"
#define DEV_10_STR "AAK"
#define DEV_11_STR "AAL"
#define DEV_12_STR "AAM"
#define DEV_13_STR "AAN"
#define DEV_14_STR "AAO"
#define DEV_15_STR "AAP"
#define DEV_16_STR "AAQ"
#define DEV_17_STR "AAR"
#define DEV_18_STR "AAS"
#define DEV_19_STR "AAT"
#define DEV_20_STR "AAU"
#define DEV_21_STR "AAV"
#define DEV_22_STR "AAW"
#define DEV_23_STR "AAX"
#define DEV_24_STR "AAY"
#define DEV_25_STR "AAZ"
#define DEV_26_STR "ABA"
#define DEV_27_STR "ABB"
#define DEV_28_STR "ABC"
#define DEV_29_STR "ABD"
#define DEV_30_STR "ABE"

void getDeviceString(int32 id, char *deviceID)
{
    switch (id)
    {
        case DEV_0:
            CFE_PSP_MemCpy(deviceID, DEV_0_STR, 1 + strlen(DEV_0_STR)); // The same as memcpy
            break;
        case DEV_1:
            CFE_PSP_MemCpy(deviceID, DEV_1_STR, 1 + strlen(DEV_1_STR)); // The same as memcpy
            break;
        case DEV_2:
            CFE_PSP_MemCpy(deviceID, DEV_2_STR, 1 + strlen(DEV_2_STR)); // The same as memcpy
            break;
        case DEV_3:
            CFE_PSP_MemCpy(deviceID, DEV_3_STR, 1 + strlen(DEV_3_STR)); // The same as memcpy
            break;
        case DEV_4:
            CFE_PSP_MemCpy(deviceID, DEV_4_STR, 1 + strlen(DEV_4_STR)); // The same as memcpy
            break;
        case DEV_5:
            CFE_PSP_MemCpy(deviceID, DEV_5_STR, 1 + strlen(DEV_5_STR)); // The same as memcpy
            break;
        case DEV_6:
            CFE_PSP_MemCpy(deviceID, DEV_6_STR, 1 + strlen(DEV_6_STR)); // The same as memcpy
            break;
        case DEV_7:
            CFE_PSP_MemCpy(deviceID, DEV_7_STR, 1 + strlen(DEV_7_STR)); // The same as memcpy
            break;
        case DEV_8:
            CFE_PSP_MemCpy(deviceID, DEV_8_STR, 1 + strlen(DEV_8_STR)); // The same as memcpy
            break;
        case DEV_9:
            CFE_PSP_MemCpy(deviceID, DEV_9_STR, 1 + strlen(DEV_9_STR)); // The same as memcpy
            break;
        case DEV_10:
            CFE_PSP_MemCpy(deviceID, DEV_10_STR, 1 + strlen(DEV_10_STR)); // The same as memcpy
            break;
        case DEV_11:
            CFE_PSP_MemCpy(deviceID, DEV_11_STR, 1 + strlen(DEV_11_STR)); // The same as memcpy
            break;
        case DEV_12:
            CFE_PSP_MemCpy(deviceID, DEV_12_STR, 1 + strlen(DEV_12_STR)); // The same as memcpy
            break;
        case DEV_13:
            CFE_PSP_MemCpy(deviceID, DEV_13_STR, 1 + strlen(DEV_13_STR)); // The same as memcpy
            break;
        case DEV_14:
            CFE_PSP_MemCpy(deviceID, DEV_14_STR, 1 + strlen(DEV_14_STR)); // The same as memcpy
            break;
        case DEV_15:
            CFE_PSP_MemCpy(deviceID, DEV_15_STR, 1 + strlen(DEV_15_STR)); // The same as memcpy
            break;
        case DEV_16:
            CFE_PSP_MemCpy(deviceID, DEV_16_STR, 1 + strlen(DEV_16_STR)); // The same as memcpy
            break;
        case DEV_17:
            CFE_PSP_MemCpy(deviceID, DEV_17_STR, 1 + strlen(DEV_17_STR)); // The same as memcpy
            break;
        case DEV_18:
            CFE_PSP_MemCpy(deviceID, DEV_18_STR, 1 + strlen(DEV_18_STR)); // The same as memcpy
            break;
        case DEV_19:
            CFE_PSP_MemCpy(deviceID, DEV_19_STR, 1 + strlen(DEV_19_STR)); // The same as memcpy
            break;
        case DEV_20:
            CFE_PSP_MemCpy(deviceID, DEV_20_STR, 1 + strlen(DEV_20_STR)); // The same as memcpy
            break;
        case DEV_21:
            CFE_PSP_MemCpy(deviceID, DEV_21_STR, 1 + strlen(DEV_21_STR)); // The same as memcpy
            break;
        case DEV_22:
            CFE_PSP_MemCpy(deviceID, DEV_22_STR, 1 + strlen(DEV_22_STR)); // The same as memcpy
            break;
        case DEV_23:
            CFE_PSP_MemCpy(deviceID, DEV_23_STR, 1 + strlen(DEV_23_STR)); // The same as memcpy
            break;
        case DEV_24:
            CFE_PSP_MemCpy(deviceID, DEV_24_STR, 1 + strlen(DEV_24_STR)); // The same as memcpy
            break;
        case DEV_25:
            CFE_PSP_MemCpy(deviceID, DEV_25_STR, 1 + strlen(DEV_25_STR)); // The same as memcpy
            break;
        case DEV_26:
            CFE_PSP_MemCpy(deviceID, DEV_26_STR, 1 + strlen(DEV_26_STR)); // The same as memcpy
            break;
        case DEV_27:
            CFE_PSP_MemCpy(deviceID, DEV_27_STR, 1 + strlen(DEV_27_STR)); // The same as memcpy
            break;
        case DEV_28:
            CFE_PSP_MemCpy(deviceID, DEV_28_STR, 1 + strlen(DEV_28_STR)); // The same as memcpy
            break;
        case DEV_29:
            CFE_PSP_MemCpy(deviceID, DEV_29_STR, 1 + strlen(DEV_29_STR)); // The same as memcpy
            break;
        case DEV_30:
            CFE_PSP_MemCpy(deviceID, DEV_30_STR, 1 + strlen(DEV_30_STR)); // The same as memcpy
            break;
        default:
            deviceID[0] = '\0';
            break;
    }
}

int32 mutexInitialize(MutexHandler_t *hwMutex, DeviceId ID)
{
    int32 Status = OS_SUCCESS;
    char  mutex_name[OS_MAX_API_NAME];
    char  deviceID[OS_MAX_API_NAME];

    CFE_PSP_MemSet(deviceID, 0, OS_MAX_API_NAME); // The same as memset
    getDeviceString(ID, deviceID);

    if (deviceID == NULL)
    {
        return OS_ERROR;
    }

    CFE_PSP_MemSet(mutex_name, 0, OS_MAX_API_NAME);         // The same as memset
    CFE_PSP_MemCpy(mutex_name, deviceID, 1 + strlen(deviceID)); // The same as memcpy

    Status = OS_MutSemCreate(&hwMutex->mutex, mutex_name, 0);

    printf("OS_MutSemCreate(%u - %s): %d\n", ID, mutex_name, Status);

    return Status;
}