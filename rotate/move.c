/*
 * move.c
 *
 *  Created on: 2017年6月10日
 *      Author: cc
 */

#include"move.h"
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


// 原地转圈
void Rotate(char dir){
	int i=0;
	for(i=1;i<=4;i++){
		ConfigureDir(dir,i);
	}
	MAP_TimerEnable(TIMERA3_BASE,TIMER_A);
	MAP_TimerEnable(TIMERA3_BASE,TIMER_B);

	moveState=dir;
}

// 向左直行
void Left(){
	ConfigureDir('-',1);
	ConfigureDir('+',2);

	MAP_TimerEnable(TIMERA3_BASE,TIMER_A);
	MAP_TimerDisable(TIMERA3_BASE,TIMER_B);

	moveState=3;
}

// 向右直行
void Right(){
	ConfigureDir('+',1);
	ConfigureDir('-',2);

	MAP_TimerEnable(TIMERA3_BASE,TIMER_A);
	MAP_TimerDisable(TIMERA3_BASE,TIMER_B);

	moveState=4;
}
// 向前直行
void Forward(){
	ConfigureDir('+',3);
	ConfigureDir('-',4);

	MAP_TimerDisable(TIMERA3_BASE,TIMER_A);
	MAP_TimerEnable(TIMERA3_BASE,TIMER_B);

	moveState=1;
}
// 向后直行
void Backward(){
	ConfigureDir('-',3);
	ConfigureDir('+',4);

	MAP_TimerDisable(TIMERA3_BASE,TIMER_A);
	MAP_TimerEnable(TIMERA3_BASE,TIMER_B);

	moveState=2;
}
// 停止
void Pause(){
	MAP_TimerDisable(TIMERA3_BASE,TIMER_A);
	MAP_TimerDisable(TIMERA3_BASE,TIMER_B);

	moveState=0;
}


void SetOs(int value)
{
	if(value==0)
	{
		os_m=0;
	}
	else
	{
		os_m=1;
	}
}
int isMoving()
{
	return moveState;
}
void delaySec(float sec)
{
	if(os_m==0)
	{
		MAP_UtilsDelay(sec*8000000);
	}
	else
	{
		osi_Sleep((unsigned int)(sec*1000));
	}
}
