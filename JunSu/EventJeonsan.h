/*
����� ��� : ���������������� �浹ó��
���� : v1.3
������ : ������
���� ������ : 2018. 6. 4
*/

#ifndef __EVENTJEONSAN_H__
#define __EVENTJEONSAN_H__

#include "playgame.h"

int CheckEventJeonsan(int x, int y);

void EventDoor3To2(Player *player);			//�������������� �б�

void EventNPCProfessor(Player *player);		//�����ֱ����� NPC
void EventUSB(Player *player);				//USB�̺�Ʈ
void EventUSB1(Player player);				//��¥USB
void EventWallet(Player *player);			//�����̺�Ʈ

#endif