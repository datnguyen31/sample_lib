#include "dev_mutex.h"
#include "cfe.h"

#include <sys/types.h>
#include <unistd.h>
#include <string.h>

const char *dev_strs[] = {"AAA", "AAB", "AAC", "AAD", "AAE", "AAF", "AAG", "AAH", "AAI", "AAJ", "AAK",
                          "AAL", "AAM", "AAN", "AAO", "AAP", "AAQ", "AAR", "AAS", "AAT", "AAU", "AAV",
                          "AAW", "AAX", "AAY", "AAZ", "ABA", "ABB", "ABC", "ABD", "ABE"};

static void getDeviceString(int32 id, char *deviceID)
{
    if (id >= 0 && id <= 30)
    {
        CFE_PSP_MemCpy(deviceID, dev_strs[id], 1 + strlen(dev_strs[id])); // The same as memcpy
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
    CFE_PSP_MemCpy(mutex_name, deviceID, 1 + strlen(deviceID)); // The same as memcpy

    Status = OS_MutSemCreate(&hwMutex->mutex, mutex_name, 0);

    printf("OS_MutSemCreate(%p - %s): %d\n", (void *)mutex_name, mutex_name, Status);

    return Status;
}