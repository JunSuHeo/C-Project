/*
����� ��� : �α���
���� : v1.5
������ : �̿ϼ�
���� ������ : 2018. 6. 4
*/

#ifndef __LOGIN_H__
#define __LOGIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "playgame.h"
#include "print.h"
#include "Util.h"

#define TRUE 1
#define FALSE -1

typedef struct member {
	char ID[100];
	char Password[50];
	int birth;
	char name[16];
}member;

void JoinMember();		//ȸ������
int CheckID();			//ȸ������ Ȯ��
void LogIn();			//�α���
void FindMember();		//ȸ������ ã��
void LogInData();
void Rank(int idx);

#endif