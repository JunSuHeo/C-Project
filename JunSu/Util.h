/*
����� ��� : ���� �÷����ϱ����� �ʿ��� ���� ���
���� : v1.4
������ : ������
���������� : 2018. 6. 9
*/
#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>   //mmsystem.h���� ��Ŭ���
#include <conio.h>
#include <process.h>
#pragma comment(lib,"winmm.lib")   //winmm.lib�� ��ũ�ϰų� ����
#include <time.h>

#include "playgame.h"
#include "print.h"

#define FALSE 0

void erase_cursor(void);      //Ŀ�� ����� �Լ�
void img(int x, int y, int mx, int my, wchar_t *temp);      //�̹��� ����Լ�
void gotoxy(int x, int y);      //Ŀ���̵�/unsigned __stdcall Sound(void *arg);
unsigned __stdcall Thread(Player *player);      //�������Լ�
void sound();		//���ǽ���
void SoundStop();	//��������
unsigned __stdcall Thread2();

#endif