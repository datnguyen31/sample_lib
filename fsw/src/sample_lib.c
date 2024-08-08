/*************************************************************************
**
**      GSC-18128-1, "Core Flight Executive Version 6.7"
**
**      Copyright (c) 2006-2019 United States Government as represented by
**      the Administrator of the National Aeronautics and Space Administration.
**      All Rights Reserved.
**
**      Licensed under the Apache License, Version 2.0 (the "License");
**      you may not use this file except in compliance with the License.
**      You may obtain a copy of the License at
**
**        http://www.apache.org/licenses/LICENSE-2.0
**
**      Unless required by applicable law or agreed to in writing, software
**      distributed under the License is distributed on an "AS IS" BASIS,
**      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**      See the License for the specific language governing permissions and
**      limitations under the License.
**
** File: sample_lib.c
**
** Purpose:
**   Sample CFS library
**
*************************************************************************/

/*************************************************************************
** Includes
*************************************************************************/
#include "sample_lib_version.h"
#include "sample_lib_internal.h"

#include "../hardware/dev_cam.h"
#include "../hardware/dev_sensor.h"

/* for "strncpy()" */
#include <string.h>

/*************************************************************************
** Private Data Structures
*************************************************************************/
char SAMPLE_Buffer[SAMPLE_LIB_BUFFER_SIZE];

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Library Initialization Routine                                  */
/* cFE requires that a library have an initialization routine      */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 SAMPLE_LibInit(void)
{
    /*
     * Call a C library function, like strcpy(), and test its result.
     *
     * This is primary for a unit test example, to have more than
     * one code path to exercise.
     *
     * The specification for strncpy() indicates that it should return
     * the pointer to the destination buffer, so it should be impossible
     * for this to ever fail when linked with a compliant C library.
     */

    /* This string somehow got into OS_MutSemCreate (dev_mutex.c) */
    if (strncpy(SAMPLE_Buffer, "SaMpLe", 1 + sizeof(SAMPLE_Buffer)))
    {
        return CFE_STATUS_EXTERNAL_RESOURCE_FAIL;
    }

    SAMPLE_Function();

    OS_printf("SAMPLE Lib Initialized.%s\n", SAMPLE_LIB_VERSION_STRING);

    return CFE_SUCCESS;

} /* End SAMPLE_LibInit */

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Sample Lib function                                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 SAMPLE_Function(void)
{
    int32 Status;
    Status = CameraInitialize(DEV_0);
    if (Status != OS_SUCCESS)
    {
        return OS_ERROR;
    }

    Status = CameraInitialize(DEV_1);
    if (Status != OS_SUCCESS)
    {
        return OS_ERROR;
    }

    for (DeviceId i = DEV_2; i <= DEV_30; i++)
    {
        Status = SensorInitialize(i);
        if (Status != OS_SUCCESS)
        {
            return OS_ERROR;
        }
    }

    return (CFE_SUCCESS);

} /* End SAMPLE_Function */

/************************/
/*  End of File Comment */
/************************/
