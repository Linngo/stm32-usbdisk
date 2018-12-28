//#include "delay.h"
#include "usart.h"
//#include "exfuns.h" 
#include "spi.h"
#include "malloc.h"

#include <stdio.h>
#include <string.h>

#include <timers.h>
#include <comm.h>
#include <led.h>
// USB includes
#include "usbd_msc_core.h"
#include "usbd_usr.h"
#include "usb_conf.h"
#include "usbd_desc.h"
#include "usb_comm.h"

#include "uart2.h"

void softTimerCallback(void);

#define DEBUG

#ifdef DEBUG
#define print(str, args...) printf(""str"%s",##args,"")
#define println(str, args...) printf("MAIN--> "str"%s",##args,"\r\n")
#else
#define print(str, args...) (void)0
#define println(str, args...) (void)0
#endif

__ALIGN_BEGIN USB_OTG_CORE_HANDLE USB_OTG_dev __ALIGN_END; ///< USB device handle

int main(void)
{ 
	int8_t timerID;
	uint32_t softTimer;
	uint8_t buf[255]; // buffer for receiving commands from PC
  uint8_t len;      // length of command
	
//	delay_init(168);		  //初始化延时函数
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2	
//	uart_init(115200);

//	SPI1_Init();
//	SPI1_SetSpeed(SPI_BaudRatePrescaler_4);		//设置为21M时钟,高速模式
	
	COMM_Init(115200); // initialize communication with PC
//  uart_send(buf,72);
	
	TIMER_Init(1000); // Initialize timer Frequency of the SysTick set at 1kHz.
		// Add a soft timer with callback running every 1000ms
	timerID = TIMER_AddSoftTimer(1000, softTimerCallback);
	TIMER_StartSoftTimer(timerID); // start the timer
	
	LED_Init(LED0); // Add an LED
	LED_Init(LED1); // Add an LED
	LED_Init(LED2); // Add an LED
	LED_Init(LED3); // Add an LED
	
	  // test another way of measuring time delays
  softTimer = TIMER_GetTime(); // get start time for delay

//  USB_COMM_Init(115200); // initialize buffers for USB COM port
	
	USBD_Init(&USB_OTG_dev,USB_OTG_FS_CORE_ID,&USR_desc,&USBD_MSC_cb,&USR_cb);  

	while (1) {

	  // test delay method
	  if (TIMER_DelayTimer(1000, softTimer)) {
	    LED_Toggle(LED3);
	    softTimer = TIMER_GetTime(); // get start time for delay
	  }

	  // check for new frames from PC
//	  if (!COMM_GetFrame(buf, &len)) {
//	    println("Got frame of length %d: %s", (int)len, (char*)buf);

//	    // control LED0 from terminal
//	    if (!strcmp((char*)buf, ":LED0 ON")) {
//	      LED_ChangeState(LED0, LED_ON);
//	    }
//	    if (!strcmp((char*)buf, ":LED0 OFF")) {
//	      LED_ChangeState(LED0, LED_OFF);
//	    }
//	  }

//    if (!USB_COMM_GetFrame(buf, &len)) {
//      println("Got frame of length %d: %s", (int)len, (char*)buf);

//      // control LED0 from terminal

////      if(!strcmp((char*)buf, "ATE1 E0")) {
////        println("Got AT command");
////        USB_COMM_Puts("OK\r\n");
////      }

//      // AT commands
//      if (buf[0] == 'A' && buf[1] == 'T') {
//        println("Got AT command");
////        USB_COMM_Puts("OK\r\n");
//      }

//      if (!strcmp((char*)buf, ":LED0 ON")) {
//        LED_ChangeState(LED0, LED_ON);
//      }
//      if (!strcmp((char*)buf, ":LED0 OFF")) {
//        LED_ChangeState(LED0, LED_OFF);
//      }
//    }
	//	TIMER_SoftTimersUpdate(); // run timers
//		KEYS_Update(); // run keyboard
	}
}


void softTimerCallback(void) {

  static uint8_t counter;
//	char* str = "Test string sent from STM32F4!!!\r\n";
  switch (counter % 3) {

  case 0:
    LED_ChangeState(LED1, LED_OFF);
    LED_ChangeState(LED2, LED_OFF);
    break;

  case 1:
    LED_ChangeState(LED1, LED_ON);
    LED_ChangeState(LED2, LED_OFF);
    break;

  case 2:
    LED_ChangeState(LED1, LED_OFF);
    LED_ChangeState(LED2, LED_ON);
    break;

  }

  // print a string to USB COM port
  
 // USB_COMM_Puts(str);

  println("Test string sent from STM32F4!!!"); // Print test string
	counter++;
}
