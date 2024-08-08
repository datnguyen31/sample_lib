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

// static void getDeviceString(int32 id, char *deviceID)
// {
//     switch (id)
//     {
//         case DEV_0:
//             CFE_PSP_MemCpy(deviceID, DEV_0_STR, strlen(DEV_0_STR)); // The same as memcpy
//             deviceID[strlen(DEV_0_STR)] = '\0';
//             break;
//         case DEV_1:
//             CFE_PSP_MemCpy(deviceID, DEV_1_STR, strlen(DEV_1_STR)); // The same as memcpy
//             deviceID[strlen(DEV_1_STR)] = '\0';
//             break;
//         case DEV_2:
//             CFE_PSP_MemCpy(deviceID, DEV_2_STR, strlen(DEV_2_STR)); // The same as memcpy
//             deviceID[strlen(DEV_2_STR)] = '\0';
//             break;
//         case DEV_3:
//             CFE_PSP_MemCpy(deviceID, DEV_3_STR, strlen(DEV_3_STR)); // The same as memcpy
//             deviceID[strlen(DEV_3_STR)] = '\0';
//             break;
//         case DEV_4:
//             CFE_PSP_MemCpy(deviceID, DEV_4_STR, strlen(DEV_4_STR)); // The same as memcpy
//             deviceID[strlen(DEV_4_STR)] = '\0';
//             break;
//         case DEV_5:
//             CFE_PSP_MemCpy(deviceID, DEV_5_STR, strlen(DEV_5_STR)); // The same as memcpy
//             deviceID[strlen(DEV_5_STR)] = '\0';
//             break;
//         case DEV_6:
//             CFE_PSP_MemCpy(deviceID, DEV_6_STR, strlen(DEV_6_STR)); // The same as memcpy
//             deviceID[strlen(DEV_6_STR)] = '\0';
//             break;
//         case DEV_7:
//             CFE_PSP_MemCpy(deviceID, DEV_7_STR, strlen(DEV_7_STR)); // The same as memcpy
//             deviceID[strlen(DEV_7_STR)] = '\0';
//             break;
//         case DEV_8:
//             CFE_PSP_MemCpy(deviceID, DEV_8_STR, strlen(DEV_8_STR)); // The same as memcpy
//             deviceID[strlen(DEV_8_STR)] = '\0';
//             break;
//         case DEV_9:
//             CFE_PSP_MemCpy(deviceID, DEV_9_STR, strlen(DEV_9_STR)); // The same as memcpy
//             deviceID[strlen(DEV_9_STR)] = '\0';
//             break;
//         case DEV_10:
//             CFE_PSP_MemCpy(deviceID, DEV_10_STR, strlen(DEV_10_STR)); // The same as memcpy
//             deviceID[strlen(DEV_10_STR)] = '\0';
//             break;
//         case DEV_11:
//             CFE_PSP_MemCpy(deviceID, DEV_11_STR, strlen(DEV_11_STR)); // The same as memcpy
//             deviceID[strlen(DEV_11_STR)] = '\0';
//             break;
//         case DEV_12:
//             CFE_PSP_MemCpy(deviceID, DEV_12_STR, strlen(DEV_12_STR)); // The same as memcpy
//             deviceID[strlen(DEV_12_STR)] = '\0';
//             break;
//         case DEV_13:
//             CFE_PSP_MemCpy(deviceID, DEV_13_STR, strlen(DEV_13_STR)); // The same as memcpy
//             deviceID[strlen(DEV_13_STR)] = '\0';
//             break;
//         case DEV_14:
//             CFE_PSP_MemCpy(deviceID, DEV_14_STR, strlen(DEV_14_STR)); // The same as memcpy
//             deviceID[strlen(DEV_14_STR)] = '\0';
//             break;
//         case DEV_15:
//             CFE_PSP_MemCpy(deviceID, DEV_15_STR, strlen(DEV_15_STR)); // The same as memcpy
//             deviceID[strlen(DEV_15_STR)] = '\0';
//             break;
//         case DEV_16:
//             CFE_PSP_MemCpy(deviceID, DEV_16_STR, strlen(DEV_16_STR)); // The same as memcpy
//             deviceID[strlen(DEV_16_STR)] = '\0';
//             break;
//         case DEV_17:
//             CFE_PSP_MemCpy(deviceID, DEV_17_STR, strlen(DEV_17_STR)); // The same as memcpy
//             deviceID[strlen(DEV_17_STR)] = '\0';
//             break;
//         case DEV_18:
//             CFE_PSP_MemCpy(deviceID, DEV_18_STR, strlen(DEV_18_STR)); // The same as memcpy
//             deviceID[strlen(DEV_18_STR)] = '\0';
//             break;
//         case DEV_19:
//             CFE_PSP_MemCpy(deviceID, DEV_19_STR, strlen(DEV_19_STR)); // The same as memcpy
//             deviceID[strlen(DEV_19_STR)] = '\0';
//             break;
//         case DEV_20:
//             CFE_PSP_MemCpy(deviceID, DEV_20_STR, strlen(DEV_20_STR)); // The same as memcpy
//             deviceID[strlen(DEV_20_STR)] = '\0';
//             break;
//         case DEV_21:
//             CFE_PSP_MemCpy(deviceID, DEV_21_STR, strlen(DEV_21_STR)); // The same as memcpy
//             deviceID[strlen(DEV_21_STR)] = '\0';
//             break;
//         case DEV_22:
//             CFE_PSP_MemCpy(deviceID, DEV_22_STR, strlen(DEV_22_STR)); // The same as memcpy
//             deviceID[strlen(DEV_22_STR)] = '\0';
//             break;
//         case DEV_23:
//             CFE_PSP_MemCpy(deviceID, DEV_23_STR, strlen(DEV_23_STR)); // The same as memcpy
//             deviceID[strlen(DEV_23_STR)] = '\0';
//             break;
//         case DEV_24:
//             CFE_PSP_MemCpy(deviceID, DEV_24_STR, strlen(DEV_24_STR)); // The same as memcpy
//             deviceID[strlen(DEV_24_STR)] = '\0';
//             break;
//         case DEV_25:
//             CFE_PSP_MemCpy(deviceID, DEV_25_STR, strlen(DEV_25_STR)); // The same as memcpy
//             deviceID[strlen(DEV_25_STR)] = '\0';
//             break;
//         case DEV_26:
//             CFE_PSP_MemCpy(deviceID, DEV_26_STR, strlen(DEV_26_STR)); // The same as memcpy
//             deviceID[strlen(DEV_26_STR)] = '\0';
//             break;
//         case DEV_27:
//             CFE_PSP_MemCpy(deviceID, DEV_27_STR, strlen(DEV_27_STR)); // The same as memcpy
//             deviceID[strlen(DEV_27_STR)] = '\0';
//             break;
//         case DEV_28:
//             CFE_PSP_MemCpy(deviceID, DEV_28_STR, strlen(DEV_28_STR)); // The same as memcpy
//             deviceID[strlen(DEV_28_STR)] = '\0';
//             break;
//         case DEV_29:
//             CFE_PSP_MemCpy(deviceID, DEV_29_STR, strlen(DEV_29_STR)); // The same as memcpy
//             deviceID[strlen(DEV_29_STR)] = '\0';
//             break;
//         case DEV_30:
//             CFE_PSP_MemCpy(deviceID, DEV_30_STR, strlen(DEV_30_STR)); // The same as memcpy
//             deviceID[strlen(DEV_30_STR)] = '\0';
//             break;
//         default:
//             deviceID[0] = '\0';
//             break;
//     }
// }

const char *dev_strs[] = {"AAA", "AAB", "AAC", "AAD", "AAE", "AAF", "AAG", "AAH", "AAI", "AAJ", "AAK",
                          "AAL", "AAM", "AAN", "AAO", "AAP", "AAQ", "AAR", "AAS", "AAT", "AAU", "AAV",
                          "AAW", "AAX", "AAY", "AAZ", "ABA", "ABB", "ABC", "ABD", "ABE"};

static void getDeviceString(int32 id, char *deviceID)
{
    if (id >= 0 && id <= 30)
    {
        CFE_PSP_MemCpy(deviceID, dev_strs[id], strlen(dev_strs[id])); // The same as memcpy
        deviceID[strlen(dev_strs[id])] = '\0';
    }
    else
    {
        deviceID[0] = '\0';
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
    CFE_PSP_MemCpy(mutex_name, deviceID, strlen(deviceID)); // The same as memcpy
    mutex_name[strlen(deviceID)] = '\0';

    Status = OS_MutSemCreate(&hwMutex->mutex, mutex_name, 0);

    printf("OS_MutSemCreate(%p - %s): %d\n", (void *)mutex_name, mutex_name, Status);

    return Status;
}