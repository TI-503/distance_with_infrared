/*
 * rotate.h
 *
 *  Created on: 2017��6��10��
 *      Author: cc
 */

#ifndef ROTATE_ROTATE_H_
#define ROTATE_ROTATE_H_

void SetFrequencyOfTimers(unsigned long ulBase, unsigned long ulTimer,
        		unsigned long ulConfig, unsigned char ucInvert, long long frequency);	// ����ʱ��Ƶ��
void ConfigureFrq();						// ����ʱ��Ƶ�ʣ��Ӷ�����4������ٶ�
void ConfigureDir(char dir,int id);	// ���÷���
void InitRotate();		// ��ʼ��

#endif /* ROTATE_ROTATE_H_ */
