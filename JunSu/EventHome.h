/*
����� ��� : �濡���� �浹ó��
���� : v1.2
������ : ���ؼ�
���� ������ : 2018. 6. 1
*/
#ifndef __EVENTHOME_H__
#define __EVENTHOME_H__

#include "playgame.h"

int CheckEventRoom(int x, int y);		//�濡�� �̺�Ʈ

void EventBed(Player *player);				//ħ�밥�� �̺�Ʈ
void EventToilet(Player player);			//���尥�� �̺�Ʈ
void EventWindow(Player player);			//â������ �̺�Ʈ
void EventCloth(Player player);				//���尥�� �̺�Ʈ
void EventComputer(Player *player);			//��ǻ�Ͱ��� �̺�Ʈ

void EventDoor1To2(Player *player);			//�濡�� �б�

#endif // ! __EVENTHOME_H__