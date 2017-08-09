//*****************************************************************************
//
// Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/ 
// 
// 
//  Redistribution and use in source and binary forms, with or without 
//  modification, are permitted provided that the following conditions 
//  are met:
//
//    Redistributions of source code must retain the above copyright 
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the 
//    documentation and/or other materials provided with the   
//    distribution.
//
//    Neither the name of Texas Instruments Incorporated nor the names of
//    its contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
//  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
//  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
//  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
//  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
//  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
//  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
//  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
//  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
//  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//*****************************************************************************

// This file was automatically generated on 7/21/2014 at 3:06:20 PM
// by TI PinMux version 3.0.334
//
//*****************************************************************************

#include "pinmux.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "pin.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "prcm.h"
#include "timer.h"
//*****************************************************************************
void
PinMuxConfig(void)
{
    //
    // Enable Peripheral Clocks 
    //
    MAP_PRCMPeripheralClkEnable(PRCM_UARTA0, PRCM_RUN_MODE_CLK);

    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA0, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA1, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA2, PRCM_RUN_MODE_CLK);
    MAP_PRCMPeripheralClkEnable(PRCM_GPIOA3, PRCM_RUN_MODE_CLK);

    MAP_PRCMPeripheralClkEnable(PRCM_TIMERA0, PRCM_RUN_MODE_CLK);//PWM计时
	MAP_PRCMPeripheralClkEnable(PRCM_TIMERA1, PRCM_RUN_MODE_CLK);//舵机计时
	MAP_PRCMPeripheralClkEnable(PRCM_TIMERA2, PRCM_RUN_MODE_CLK);//2B
	MAP_PRCMPeripheralClkEnable(PRCM_TIMERA3, PRCM_RUN_MODE_CLK);//3A 3B

    //
    // Configure PIN_55 for UART0 UART0_TX
    //
    MAP_PinTypeUART(PIN_55, PIN_MODE_3);

    //
    // Configure PIN_57 for UART0 UART0_RX
    //
    MAP_PinTypeUART(PIN_57, PIN_MODE_3);


    MAP_PinTypeGPIO(PIN_58, PIN_MODE_0, false);//en	使能
    MAP_GPIODirModeSet(GPIOA0_BASE, 0x8, GPIO_DIR_MODE_OUT);

    MAP_PinTypeGPIO(PIN_04,PIN_MODE_0,false);//dir1	1号电机
    MAP_GPIODirModeSet(GPIOA1_BASE,0x20,GPIO_DIR_MODE_OUT);

    MAP_PinTypeGPIO(PIN_03,PIN_MODE_0,false);//dir2    2号电机
    MAP_GPIODirModeSet(GPIOA1_BASE,0x10,GPIO_DIR_MODE_OUT);

    MAP_PinTypeGPIO(PIN_61,PIN_MODE_0,false);//dir3    3号电机
    MAP_GPIODirModeSet(GPIOA0_BASE,0x40,GPIO_DIR_MODE_OUT);

	MAP_PinTypeGPIO(PIN_59,PIN_MODE_0,false);//dir4	4号电机
	MAP_GPIODirModeSet(GPIOA0_BASE,0x10,GPIO_DIR_MODE_OUT);


    MAP_PinTypeTimer(PIN_01, PIN_MODE_3);//1PWM			时钟
	MAP_PinTypeTimer(PIN_02, PIN_MODE_3);//2PWM		时钟
	MAP_PinTypeTimer(PIN_64, PIN_MODE_3);//3PWM		时钟

	MAP_TimerDisable(TIMERA3_BASE,TIMER_A);
	MAP_TimerDisable(TIMERA3_BASE,TIMER_B);
	MAP_TimerDisable(TIMERA2_BASE,TIMER_B);

	MAP_PinTypeGPIO(PIN_62,PIN_MODE_0,false);//trig
	MAP_GPIODirModeSet(GPIOA0_BASE,0x80,GPIO_DIR_MODE_OUT);

	MAP_PinTypeGPIO(PIN_53,PIN_MODE_0,false);//echo
	MAP_GPIODirModeSet(GPIOA3_BASE,0x40,GPIO_DIR_MODE_IN);

	MAP_PinTypeGPIO(PIN_05,PIN_MODE_0,false);//dir for distance
	MAP_GPIODirModeSet(GPIOA1_BASE,0x40,GPIO_DIR_MODE_OUT);


    //
    // Configure PIN_08 for GPIO Input 左
    //
    PinTypeGPIO(PIN_08, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA2_BASE, 0x2, GPIO_DIR_MODE_IN);

    //
    // Configure PIN_15 for GPIO Input	前左
    //
    PinTypeGPIO(PIN_15, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA2_BASE, 0x40, GPIO_DIR_MODE_IN);

    //
    // Configure PIN_18 for GPIO Input 前
    //
    PinTypeGPIO(PIN_18, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA3_BASE, 0x10, GPIO_DIR_MODE_IN);


    //
    // Configure PIN_50 for GPIO Input 右前
    //
    PinTypeGPIO(PIN_50, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA0_BASE, 0x1, GPIO_DIR_MODE_IN);
    //
    // Configure PIN_45 for GPIO Input 右
    //
    PinTypeGPIO(PIN_45, PIN_MODE_0, false);
    GPIODirModeSet(GPIOA3_BASE, 0x80, GPIO_DIR_MODE_IN);

}
