

/*******************************************************************************
 * Include guard
 ******************************************************************************/
#ifndef SOURCE_SENDER_TASK_H_
#define SOURCE_SENDER_TASK_H_

/*******************************************************************************
 * Header file includes
 ******************************************************************************/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

/*******************************************************************************
* Global constants
*******************************************************************************/

/*******************************************************************************
 * Data structure and enumeration
 ******************************************************************************/

/*******************************************************************************
 * Global variable
 ******************************************************************************/
extern QueueHandle_t xQueue;

/*******************************************************************************
 * Function prototype
 ******************************************************************************/
void task_sender(void *pvParameters);


#endif /* SENDER_TASK_H_ */


/* [] END OF FILE  */