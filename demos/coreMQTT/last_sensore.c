
#include "sender_task.h"
#include "cy_pdl.h"
#include "cybsp.h"
#include "cyhal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "cy_retarget_io.h"
#include "cycfg.h"
#include "timers.h"
#include <stdio.h>
#include "last_sensore.h"
/***************************************
*            Constants
****************************************/
#define CMD_TO_CMD_DELAY        (1000UL)
#define PACKET_SOP_POS          (0UL)
#define PACKET_CMD_POS          (1UL)
#define PACKET_STS_POS          (1UL)

/* Start and end of packet markers */
#define PACKET_EOP_POS          (2UL)
#define PACKET_SOP              (0x01UL)
#define PACKET_EOP              (0x17UL)

/* I2C slave address to communicate with */
#define I2C_SLAVE_ADDR          (0x77)

/* I2C bus frequency */
#define I2C_FREQ                (400000UL)

/* I2C slave interrupt priority */
#define I2C_SLAVE_IRQ_PRIORITY  (7u)

/* Command valid status */
#define STS_CMD_DONE            (0x00UL)
#define STS_CMD_FAIL            (0xFFUL)

/* Buffer and packet size */
#define PACKET_SIZE             (3UL)


void getTwosComplement(uint32_t *raw, uint8_t length)
{
	  if (*raw & ((uint32_t)1 << (length - 1)))
		   {
				*raw -= (uint32_t)1 << length;
		   }
}



/*******************************************************************************
 * Global variable
 ******************************************************************************/
/* Queue handle used for LED data */
QueueHandle_t sensor_command_data_q;


void Leer_temp(){


	__attribute__ ((unused)) cy_rslt_t result;
	int32_t temp1_tosend;


	#if ((I2C_MODE == I2C_MODE_BOTH) || (I2C_MODE == I2C_MODE_MASTER))
		cyhal_i2c_t mI2C;
		cyhal_i2c_cfg_t mI2C_cfg;


		mI2C_cfg.is_slave = false;
		mI2C_cfg.address = 0;
		mI2C_cfg.frequencyhal_hz = I2C_FREQ;
		result = cyhal_i2c_init( &mI2C, mI2C_SDA, mI2C_SCL, NULL);

	#endif


	//for(;;){


	//printf("Task_sensor\r\n");

	#if ((I2C_MODE == I2C_MODE_BOTH) || (I2C_MODE == I2C_MODE_MASTER))

	//								 printf(">> Reading value..... \r\n");

					//Paso 1. Leer los registros del 0x10 al 0x20.- COEF

					uint8_t array1[] = {0x10};
					uint8_t array2[0x11];

					cyhal_i2c_master_write( &mI2C, I2C_SLAVE_ADDR, array1 , 1 , 0, false);
					cyhal_i2c_master_read( &mI2C, I2C_SLAVE_ADDR, array2 , 0x11 , 0, true);

					 // Paso 2. Escribir en 0x06 (PRS_CFG)

					 uint8_t paso2[] = {0x06, 0x01};
					 cyhal_i2c_master_write( &mI2C, I2C_SLAVE_ADDR, paso2, 2 , 0, true);


					  //FALL0- Paso 3. Escribir en 0x07 (TMP_CFG)
					 uint8_t paso3[] =  {0x07, 0x80};
					 cyhal_i2c_master_write( &mI2C, I2C_SLAVE_ADDR, paso3, 2 , 0, true );


					 //Paso 5 Write 0x02 to reg 0x08 (MEAS_CFG)
					 uint8_t paso5[] = {0x08, 0x02};
					 cyhal_i2c_master_write( &mI2C, I2C_SLAVE_ADDR, paso5, 2, 0, true);

					 //Paso 6. Read reg 0x03 to reg 0x05 (TMP_B2, TMP_B1; TMP_B0)

					 uint8_t array3[] = {0x03};
					 uint8_t array4[0x03];

					 cyhal_i2c_master_write( &mI2C, I2C_SLAVE_ADDR, array3, 1, 0, false);
					 cyhal_i2c_master_read( &mI2C, I2C_SLAVE_ADDR, array4, 0x03, 0, true);

					uint32_t c0 = ((uint32_t)array2[0] << 4) | (((uint32_t)array2[1] >> 4) & 0x0F);


					getTwosComplement(&c0, 12);

	//								printf("%u\r\n", (unsigned int)c0);

					int32_t c1 = (((uint32_t)array2[1] & 0x0F) << 8) | (uint32_t)array2[2];

					getTwosComplement(&c1, 12);


	//								printf("%u\r\n", ( int)c1);

					uint32_t Traw = (array4[0]<<16)|(array4[1]<<8)|(array4[2]);
	//								printf("%u\r\n", (unsigned int)Traw);

					//scale temperature according to scaling table and oversampling
					double temp = Traw / 524288.0 ;
	//								printf("%f\r\n", (double)temp);

					//Calculate compensated temperature
					double temp1 = c0 * 0.5 + c1 * temp;

					/*The queue was created to hold values of type int32_t so cast the
					 * parameter to the required type.
					 */
					temp1_tosend= (int32_t) temp1;

//					printf("La temperatura es: \r\n");
//
//					printf("%f\r\n", (double)temp1_tosend);

					xTaskCreate(task_sender, "Sender Task", 1000 , temp1_tosend, 1, NULL);

	#endif

}

