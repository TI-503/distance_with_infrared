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

	MAP_GPIOPinWrite(GPIOA0_BASE, 0x8, 0);//EN

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

	MAP_GPIOPinWrite(GPIOA0_BASE, 0x8, 0);//EN

	ConfigureDir('-',1);
	ConfigureDir('+',2);

	MAP_TimerEnable(TIMERA3_BASE,TIMER_A);
	MAP_TimerDisable(TIMERA3_BASE,TIMER_B);

	moveState=3;
}

// 向右直行
void Right(){

	MAP_GPIOPinWrite(GPIOA0_BASE, 0x8, 0);//EN

	ConfigureDir('+',1);
	ConfigureDir('-',2);

	MAP_TimerEnable(TIMERA3_BASE,TIMER_A);
	MAP_TimerDisable(TIMERA3_BASE,TIMER_B);

	moveState=4;
}
// 向前直行
void Forward(){

	MAP_GPIOPinWrite(GPIOA0_BASE, 0x8, 0);//EN

	ConfigureDir('+',3);
	ConfigureDir('-',4);

	MAP_TimerDisable(TIMERA3_BASE,TIMER_A);
	MAP_TimerEnable(TIMERA3_BASE,TIMER_B);

	moveState=1;
}
// 向后直行
void Backward(){

	MAP_GPIOPinWrite(GPIOA0_BASE, 0x8, 0);//EN


	ConfigureDir('-',3);
	ConfigureDir('+',4);

	MAP_TimerDisable(TIMERA3_BASE,TIMER_A);
	MAP_TimerEnable(TIMERA3_BASE,TIMER_B);

	moveState=2;
}
// 停止
void Pause(){

	MAP_GPIOPinWrite(GPIOA0_BASE, 0x8, 0x8);//EN stop the  electricity noise

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
		MAP_UtilsDelay(sec*80000000/6);
	}
	else
	{
		osi_Sleep((unsigned int)(sec*1000));
	}
}


float timeOfWheelRotateAngle(float angle)
{
	float frequency = 1500.0;// 15 * 100.0;

	float stepPerDegree = 8.88888889; // 3200.0 / 360.0;

	float totalStep = stepPerDegree * angle;

	float time = totalStep / frequency;
	return time;
}

float timeOfDistance(float distance_cm)
{
	float perimeter = 23.8761042; // cm
	// larger wheel 23.8761042
	// origin wheel 18.2212374

	float ring = distance_cm / perimeter;
	float angle = ring * 360.0;

	return timeOfWheelRotateAngle(angle);
}
float timeOfCarRotateAngle(float carAngle)
{
	float carPerimeter= 147.654855; //135.088484;
	// larger wheel 47 * M_PI = 147.654855

	float dis = carPerimeter * carAngle / 360.0;

	return timeOfDistance(dis)+0.12;
}
// 转指定角度
void RotateAngle(float angle)
{
	Report("%f\r\n",angle);
	char dir='+';
	if(angle>=0)	// 顺时针
	{
		dir='+';
	}
	else	//逆时针
	{
		angle=-angle;
		dir='-';
	}

	float sec = timeOfCarRotateAngle(angle);

	Report("dir %c, angle %f, sec %f\r\n", dir, angle, sec);
	Rotate(dir);
	MAP_UtilsDelay(80000000 / 6 * sec);
	Report("done");
	Pause();
}
