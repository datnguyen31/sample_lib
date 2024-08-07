#include "dev_cam.h"
#include "../mutex/dev_mutex.h"
#include "cfe.h"

#include <string.h>

Camera_t cameraHandler[2]  = {{.Id = DEV_0}, {.Id = DEV_1}};

void generateString(char array[20])
{
    CFE_PSP_MemSet(array, 0, OS_MAX_API_NAME);
    CFE_PSP_MemCpy(array, "image_1.png", strlen("image_1.png"));
    array[strlen("image_1.png")] = '\0';

    return;
}

int32 CameraCapture(DeviceId ID)
{
    generateString(cameraHandler[ID].image_str);

    return 0;
}

/**********************************************************************************/

int32 CameraInitialize(DeviceId ID)
{
    if(ID < DEV_2)
        return mutexInitialize(&cameraHandler[ID].mutex, cameraHandler[ID].Id);

    return OS_ERROR;
}
