
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include <stdint.h>

/*****************************************************************************
 *
 */
//extern int32_t temp1_tosend;
//void *voidPointer;


#ifndef SOURCE_SENSORE_H_
#define SOURCE_SENSORE_H_

/* This code example requires two I2C ports, one as master and the other one
 * as slave. Set the I2C_MODE macro depending on the kit. Some kits support two
 * I2C ports which you can configure in I2C_MODE_BOTH whereas some support only
 * one port in which case you can configure the kit in either I2C_MODE_MASTER or
 * I2C_MODE_SLAVE. See README.md to know more on the kit specific configuration.
 */
#define I2C_MODE_BOTH    0
#define I2C_MODE_MASTER  1
#define I2C_MODE_SLAVE   2

#define I2C_MODE                    (I2C_MODE_MASTER)


/* Structure used for storing LED data */

#if (I2C_MODE == I2C_MODE_MASTER)
    #define mI2C_SCL                    (CYBSP_I2C_SCL)
    #define mI2C_SDA                    (CYBSP_I2C_SDA)
#endif

#if (I2C_MODE == I2C_MODE_SLAVE)
    #define sI2C_SCL                    (CYBSP_I2C_SCL)
    #define sI2C_SDA                    (CYBSP_I2C_SDA)
#endif

#if (I2C_MODE == I2C_MODE_BOTH)
    #define sI2C_SCL                    (CYBSP_I2C_SCL)
    #define sI2C_SDA                    (CYBSP_I2C_SDA)

    #if defined (TARGET_CY8CPROTO_062S3_4343W)
        #define mI2C_SCL                (P5_0)
        #define mI2C_SDA                (P5_1)
    #elif defined (TARGET_CYW9P62S1_43012EVB_01)
        #define mI2C_SCL                (P0_2)
        #define mI2C_SDA                (P0_3)
    #elif defined (TARGET_CY8CKIT_062S4)
        #define mI2C_SCL                (P10_0)
        #define mI2C_SDA                (P10_1)
    #elif defined (TARGET_CY8CKIT_062S2_43012)   || \
          defined (TARGET_CYW9P62S1_43438EVB_01) || \
          defined (TARGET_CY8CKIT_062_BLE)       || \
          defined (TARGET_CY8CKIT_062_WIFI_BT)   || \
          defined (TARGET_CY8CPROTO_063_BLE)     || \
          defined (TARGET_CY8CPROTO_062_4343W)   || \
          defined (TARGET_CY8CKIT_064B0S2_4343W) || \
          defined (TARGET_CYSBSYSKIT_01)         || \
          defined (TARGET_CYSBSYSKIT_DEV_01)
        #define mI2C_SCL                (P9_0)
        #define mI2C_SDA                (P9_1)
    #else
        #error Unsupported kit. Define pins for I2C master or use in Master/Slave mode only.
    #endif
#endif


//*******************************************************************************
// * Function prototype
// ******************************************************************************/
double Leer_temp();


#endif
