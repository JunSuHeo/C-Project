/*
����� ��� : S1-4������ �浹ó��
���� : v1.4
������ : ������
���� ������ : 2018. 6. 3
*/

#ifndef __EVENTS14_H__
#define __EVENTS14_h__

#include "playgame.h"

int CheckEventS14(int x, int y);

void EventDoor4To2(Player *player);		//�б��� ���� ��
void EventAssistant(Player player);		//������NPC
void EventProfessor3(Player player);	//NPC������
void EventProfessor4(Player *player);	//NPC����������
void EventNPCLEE(Player *player);		//NPC�ϼ�
void EventGetWater(Player *player);		//��� ȹ��

#endif