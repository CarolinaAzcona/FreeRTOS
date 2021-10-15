/******************************************************************************
* File Name: receiver_task.c
*********************************************************************************/



#include "receiver_task.h"
#include "cybsp.h"
#include "cyhal.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "cycfg.h"
#include <stdio.h>
#include "timers.h"
#include "cy_retarget_io.h"
/*******************************************************************************
* Global constants
*******************************************************************************/


/*******************************************************************************
 * Global variable
 ******************************************************************************/
/* Queue handle used for LED data */
QueueHandle_t xQueue;

/*******************************************************************************
* Function Name: task_receiver
********************************************************************************
* Summary:
*  Task that controls the LED.
*
* Parameters:
*  void *param : Task parameter defined during task creation (unused)
*
*******************************************************************************/
void task_receiver(void *pvParameters)
{
	int32_t ReceivedValue;
	BaseType_t xStatus;
	const TickType_t xTicksToWait= pdMS_TO_TICKS(100);

    printf("Task_receiver.\r\n");
/*This task is also implemented within an infinite loop*/
	for (;;)
	{
	   /*This call should always find the queue empty because this task will inmediatly remove
		* any data that is written to the queue.*/


		if(uxQueueMessagesWaiting(xQueue)!=0){

		  //vPrintString("Queue should have been empty.\r\n");
	   }
		   /*Receive data from the queue

		The first parameter is the queue from which data is to be received. The
		queue is created before the scheduler is started, and therefore before this task runs for the
		first time.

		The second parameter is the buffer into which the received data will be placed. In this case the buffer
		is simply the addres of a variable that has the required size to hold the received data.

		The last parameter is the block time - the maximum amount of time that the task will remain in the
		blocked state to wait for data to be avaible should the queue already be empty.*/
	    xQueueReceive(xQueue, &ReceivedValue, xTicksToWait);
	    printf("Recibida: \r\n");

	    printf("%ld\r\n", ReceivedValue );

		if(xStatus==pdPASS){
		/*Data was succesfully received from the queue, print out the received value.*/
			//vPrintStringAndNumber("Received=", ReceivedValue);

		}
		else{
			 /*Data was not received from the queue evenn after 100 ms.
			 This must be an error as the sending tasks are free runing and will be
			 continuously writing to the queue.*/
		 //vPrintString("Could not receive from the queue.\r\n") ;



		}

	}
}

/* END OF FILE [] */
