#include "dev_cam.h"
#include "../mutex/dev_mutex.h"
#include "cfe.h"

#include <string.h>

Camera_t cameraHandler[2]  = {{.Id = DEV_0}, {.Id = DEV_1}};

#define IMAGE_STR "image_1.png"

const char image_strs[] = {IMAGE_STR};

int32 CameraCapture(DeviceId ID)
{
    CFE_PSP_MemCpy(cameraHandler[ID].image_str, image_strs, 1 + strlen(image_strs));

    return 0;
}

/**********************************************************************************/

int32 CameraInitialize(DeviceId ID)
{
    if(ID < DEV_2)
        return mutexInitialize(&cameraHandler[ID].mutex, cameraHandler[ID].Id);

    return OS_ERROR;
}

#define DEADBEEF "DEADBEEF"

void foo()
{
    // This will cause no problem
    char str1[20];
    const char *testString = DEADBEEF;
    memcpy(str1, testString, 1 + strlen(testString));

    // But this will cause the "string shifting" issue.
    // The number this issue happens equal to the time I pass the string literal directly.
    char str2[20];
    memcpy(str2, DEADBEEF, 1 + strlen(DEADBEEF));
}