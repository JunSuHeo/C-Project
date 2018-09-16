/*
����� ��� : ���� ������ִ� ���
���� : v1.6
������ : ������
���� ������ : 2018. 6. 9
*/

#ifndef __PRINT_H__
#define __PRINT_H__

#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "Util.h"
#include "playgame.h"

void PrintLoading();		//�ε�ȭ�� ���
void PrintMenu();			//�޴� ���
void PrintAt(int x, int y, char *str);		//��ġ���� ���
void PrintIntro();			//��Ʈ�� ���
void PrintRoom_Sun(Player player);			//�� ���
void PrintRoom_Moon(Player player);
void PrintInventory(Player player);		//�κ��丮 ���
void PrintSleep();			//�ڴ¸�� ���
void PrintHowToPlay();		//����Ű ���
void PrintSchool(Player player);	//�б����
void PrintJeonsan(Player player);	//�������������
void PrintE87(Player player);		//E8-7���
void PrintHakyeon(Player player);	//�п������
void PrintS14(Player player);		//S1-4���
void PrintRank();					//��ŷ���
void PrintLogIn();					//�α��� �ڽ����
void Ending();						//����ȭ�����
void firecracker_wall();			//�Ҳɳ������
void firecracker_up();				//�Ҳɳ������
void firecracker1();				//�Ҳɳ������
void firecracker2();				//�Ҳɳ������
void firecracker3();				//�Ҳɳ������
void firecracker4();				//�Ҳɳ������
void firecracker5();				//�Ҳɳ������
void firecracker6();				//�Ҳɳ������
void firecracker7();				//�Ҳɳ������
void firecracker8();				//�Ҳɳ������
	
#endif