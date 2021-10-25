/******************************************************************************
* File Name: sender_task.c
*******************************************************************************/

/*******************************************************************************
 * Header file includes
 ******************************************************************************/
#include "sender_task.h"
#include "cybsp.h"
#include "cyhal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "cycfg.h"
#include <stdio.h>

/*******************************************************************************
* Global constants
*******************************************************************************/

/*******************************************************************************

*******************************************************************************/
QueueHandle_t xQueue;

/*******************************************************************************
*
*******************************************************************************/
void task_sender(void *pvParameters)
{
	int32_t ValueToSend;
	BaseType_t xStatus;
	const TickType_t xDelay= pdMS_TO_TICKS(5000);

	/*Two instances of this task are created so the value that is sent to the queue is passed in
	 via the task parameter- this way each instance can use a different value. The queue was created
	 to hold values of type int32_t, so cast the parameter to the requierd type*/
     //printf("Task_sender.\r\n");

      ValueToSend = (int32_t) pvParameters;
      /*As per most task, this task is implemented within an infinite loop*/
      for (;;)
      {


	   /*Send the value to the queue.
	    The first parameter is the queue to which data is being sent. The queue was created before the
	    scheduler was started, so before this task started to execute.

	    The second parameter is the address of the data to be sent, in this case the address of
	    ValueToSend.

	    The third parameter is the Block Time- the time the task should be kept in the Blocked state
	    to wait for space to become available on the queue should the queue already be full.
	    In this case a block time is not specified because the queue should never contain more than
	    one item, and therefore never be full.*/
	   xStatus= xQueueSendToBack(xQueue, &ValueToSend, 0);

	   if(xStatus != pdPASS){

		  // vPrintString("Could not sent to the queue.\r\n");
	   }

//	   printf("Enviada: \r\n");
//
//	   printf("%ld\r\n", ValueToSend );

	   vTaskDelay(xDelay);
   }


}
