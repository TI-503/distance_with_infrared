/*
 * move.h
 *
 *  Created on: 2017��6��10��
 *      Author: cc
 */

#ifndef ROTATE_MOVE_H_
#define ROTATE_MOVE_H_

int moveState;
int os_m;
void SetOs(int value);
void Rotate(char dir);// ԭ��תȦ
void Left();// ����ֱ��
void Right();// ����ֱ��
void Forward();// ��ǰֱ��
void Backward();// ���ֱ��
void Pause();// ֹͣ
void delaySec(float sec);
int isMoving();// �Ƿ������ƶ�

// motor
float timeOfWheelRotateAngle(float angle);
float timeOfDistance(float distance);
float timeOfCarRotateAngle(float carAngle);
// תָ���Ƕ�
void RotateAngle(float angle);

#endif /* ROTATE_MOVE_H_ */
