/*
����� ��� : �浹ó��
���� : v1.3
������ : ���ؼ�
���� ������ : 2018. 5. 29
*/
#ifndef __EVENT_H__
#define __EVENT_H__

#include "playgame.h"

int CheckEventUp(Player *player);			//������ �̺�Ʈ
int CheckEventDown(Player *player);			//�Ʒ����� �̺�Ʈ
int CheckEventLeft(Player *player);			//�޹��� �̺�Ʈ
int CheckEventRight(Player* player);			//�������� �̺�Ʈ

#endif // ! __EVENT_H__