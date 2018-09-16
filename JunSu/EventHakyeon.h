/*
����� ��� : �п��꿡���� �浹ó��
���� : v1.4
������ : ������
���� ������ : 2018. 6. 5
*/

#ifndef __EVENTHAKYEON_H__
#define __EVENTHAKYEON_H__

#define BLACKBOARD 62	//����ĥ��
#define BLACKBOARD1 63	//����ĥ��
#define NPCBLOND 64		//��Ӹ�NPC
#define NPCYOON 65		//����NPC
#define CABINET 66		//ĳ���
#define PRINT 67		//������

#include "playgame.h"

int CheckEventHakyeon(int x, int y);	//�п��꿡�� �̺�Ʈ

void EventDoor6To2(Player *player);		//�б��� ���� ��
void EventCGAC(Player *player);			//��������� �̺�Ʈ
void EventPrint(Player *player);		//��������Ʈ
void EventNPCBlond(Player player);		//��Ӹ�NPC
void EventBlackboard(Player player);	//ĥ���̺�Ʈ
void EventNPCYOON(Player *player);		//����NPC
void EventCabinet(Player *player);		//�౸ȭã��

#endif