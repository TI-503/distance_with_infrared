/*
 * rotate.h
 *
 *  Created on: 2017年6月10日
 *      Author: cc
 */

#ifndef ROTATE_ROTATE_H_
#define ROTATE_ROTATE_H_

void SetFrequencyOfTimers(unsigned long ulBase, unsigned long ulTimer,
        		unsigned long ulConfig, unsigned char ucInvert, long long frequency);	// 设置时钟频率
void ConfigureFrq();						// 设置时钟频率，从而设置4个电机速度
void ConfigureDir(char dir,int id);	// 设置方向
void InitRotate();		// 初始化
void SetFrq(int frequency);						// 设置时钟频率，从而设置4个电机速度
#endif /* ROTATE_ROTATE_H_ */
