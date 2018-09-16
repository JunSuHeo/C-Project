/*
����� ��� : �б������� �浹ó��
���� : v1.3
������ : �̿ϼ�
���� ������ : 2018. 6. 3
*/

#ifndef __EVENTSCHOOL_H__
#define __EVENTSCHOOL_H__

#include "playgame.h"

int CheckEventSchool(int x, int y);		//�б����� �̺�Ʈ

void EventDoor2To1(Player *player);			//�б����� ��
void EventDoor2To3(Player *player);			//�б����� ����������
void EventDoor2To4(Player *player);			//�б����� S1-4
void EventDoor2To5(Player *player);			//�б����� E8-7
void EventDoor2To6(Player *player);			//�б����� �п���

void EventGirl(Player player);		//����NPC
void EventMan1(Player player);		//����1NPC
void EventMan2(Player player);		//����2NPC

#endif