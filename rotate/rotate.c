/*
 * rotate.c
 *
 *  Created on: 2017��6��10��
 *      Author: cc
 */

#include"rotate.h"
#include "hw_types.h"
#include "hw_memmap.h"
#include "hw_gpio.h"
#include "pin.h"
#include "rom.h"
#include "rom_map.h"
#include "gpio.h"
#include "prcm.h"
#include"timer.h"

// ����ʱ��Ƶ��
void SetFrequencyOfTimers(unsigned long ulBase, unsigned long ulTimer,
        			unsigned long ulConfig, unsigned char ucInvert, long long frequency){
	MAP_TimerConfigure(ulBase,ulConfig);
	if(frequency==0)
	{
		MAP_TimerPrescaleSet(ulBase,ulTimer,0);
	}
	else
	{
		MAP_TimerPrescaleSet(ulBase,ulTimer,(unsigned long)80000000/frequency/65535);
	}

	//
	// Inverting the timer output if required
	//
	MAP_TimerControlLevel(ulBase,ulTimer,ucInvert);

	//
	// Load value set to ~0.5 ms time period
	//
	if(frequency==0)
	{
		MAP_TimerLoadSet(ulBase,ulTimer,0);
	}
	else
	{
		MAP_TimerLoadSet(ulBase,ulTimer,(unsigned long)(80000000/frequency)-((unsigned long)(80000000/frequency)/65535)*65535);
	}
		// Match value set so as to output level 0
	//
	if(frequency==0)
	{
		MAP_TimerPrescaleMatchSet(ulBase,ulTimer,0);
		MAP_TimerMatchSet(ulBase,ulTimer,0);
	}
	else
	{
		MAP_TimerPrescaleMatchSet(ulBase,ulTimer,(unsigned long)(80000000/frequency)/(2*65535));
		MAP_TimerMatchSet(ulBase,ulTimer,(unsigned long)(80000000/frequency)/2-(unsigned long)(80000000/frequency)/(2*65535)*65535);
	}
}


/*
 *  ���÷��򣬷�װMAP_GPIOPinWrite
 *  param dir  ���� ȡֵ'-' ��+��
 *  param gpio base
 *  param addr gpio addr
 */
void SetDirection(char dir,long long base,int addr){
	if(dir=='-'){
		MAP_GPIOPinWrite(base,addr,0);
	}
	else{
		MAP_GPIOPinWrite(base,addr,addr);
	}
}

/*
 *  ���÷��򣬷�װSetDirection��MAP_GPIOPinWrite
 *  param dir  ���� ȡֵ'-' ��+��
 *  param id ������
 */
void ConfigureDir(char dir,int id){
	switch(id){
	case 1:
		SetDirection(dir,GPIOA1_BASE,0x20);
		break;
	case 2:
		SetDirection(dir,GPIOA1_BASE,0x10);
		break;
	case 3:
		SetDirection(dir,GPIOA0_BASE,0x40);
		break;
	case 4:
		SetDirection(dir,GPIOA0_BASE,0x10);
		break;
	case 5:
		SetDirection(dir,GPIOA1_BASE,0x40);
		break;
	default:break;
	}
}
// ��ʼ��ʱ��Ƶ�ʣ��Ӷ����õ���ٶ�
void ConfigureFrq(){
	SetFrequencyOfTimers(TIMERA3_BASE, TIMER_A,
					(TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM | TIMER_CFG_B_PWM), 1, 15*100);//1
	SetFrequencyOfTimers(TIMERA3_BASE, TIMER_B,//6.25=100/16
					(TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_PWM | TIMER_CFG_B_PWM), 1, 15*100);//2
	SetFrequencyOfTimers(TIMERA2_BASE, TIMER_B,//6.25=100/16
					(TIMER_CFG_SPLIT_PAIR | TIMER_CFG_A_CAP_TIME | TIMER_CFG_B_PWM), 1, 15*100);//64
}
void InitRotate(){
	MAP_GPIOPinWrite(GPIOA0_BASE,0x8,0);//EN
	ConfigureFrq();
}

