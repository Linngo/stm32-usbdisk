/**
 * @file    usb_comm.h
 * @brief
 * @date    4 sty 2015
 * @author  Michal Ksiezopolski
 *
 *
 * @verbatim
 * Copyright (c) 2014 Michal Ksiezopolski.
 * All rights reserved. This program and the
 * accompanying materials are made available
 * under the terms of the GNU Public License
 * v3.0 which accompanies this distribution,
 * and is available at
 * http://www.gnu.org/licenses/gpl.html
 * @endverbatim
 */
#ifndef INC_USB_COMM_H_
#define INC_USB_COMM_H_

void USB_COMM_RxCallback(uint8_t c);
uint8_t USB_COMM_TxCallback(uint8_t* c);
uint8_t USB_COMM_GetFrame(uint8_t* buf, uint8_t* len);
uint8_t USB_COMM_Getc(void);
void USB_COMM_Puts(char* str);
void USB_COMM_Init(uint32_t baud);

#endif /* INC_USB_COMM_H_ */
