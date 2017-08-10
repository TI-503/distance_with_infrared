/*
 * move.h
 *
 *  Created on: 2017年6月10日
 *      Author: cc
 */

#ifndef ROTATE_MOVE_H_
#define ROTATE_MOVE_H_

int moveState;
int os_m;
void SetOs(int value);
void Rotate(char dir);// 原地转圈
void Left();// 向左直行
void Right();// 向右直行
void Forward();// 向前直行
void Backward();// 向后直行
void Pause();// 停止
void delaySec(float sec);
int isMoving();// 是否正在移动

// motor
float timeOfWheelRotateAngle(float angle);
float timeOfDistance(float distance);
float timeOfCarRotateAngle(float carAngle);
// 转指定角度
void RotateAngle(float angle);

#endif /* ROTATE_MOVE_H_ */
