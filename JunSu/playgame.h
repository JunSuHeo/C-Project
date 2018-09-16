/*
����� ��� : ���� �÷���
���� : v1.11
������ : ���ؼ�
���� ������ : 2018. 6. 9
*/

#ifndef __PLAYGAME_H__
#define __PLAYGAME_H__

#include <stdio.h>
#include <Windows.h>
#include <process.h>

#define X_MAX 158
#define Y_MAX 42

#define TRUE 1	
#define FALSE 0

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define BLOCK 9		//��

#define ROOM 10			//��
#define CLOTH 11		//�ֹ�
#define BED 12			//ħ��
#define COMPUTER 13		//å��
#define WINDOW 14		//â��
#define TOILET 15		//ȭ���
#define DOOR1TO2 16		//�б��� ���� ��

#define SCHOOL 20		//�б�
#define DOOR2TO1 21		//������ ���� ��
#define DOOR2TO3 22		//�������������� ���� ��
#define DOOR2TO4 23		//S1-4�� ���� ��
#define	DOOR2TO5 24		//E8-7�� ���� ��
#define DOOR2TO6 25		//�п������� ���� ��
#define GIRL 26			//�������¿���
#define MAN1 27			//�������³���1
#define MAN2 28			//�������³���2

#define JEONSAN 30	//����������
#define DOOR3TO2 31	//�б��� ���� ��
#define NPCPROFESSOR 32	//�����ֱ�����
#define USB 33		//USB
#define USB1 34		//USB����ũ
#define WALLET 35	//����

#define S14 40		//S1-4
#define DOOR4TO2 41	//�б��� ���� ��
#define NPCPROFESSOR2 42	//������
#define NPCPROFESSOR3 43	//������2
#define NPCPROFESSOR4 44	//������3
#define NPCLEE 45		//�ϼ���
#define REFREGER 46		//�����


#define E87	50		//E8-7
#define DOOR5TO2 51	//�б��� ���� ��
#define NPCKIM 52	//����
#define NPCPROFESSOR1 53	//������

#define HAKYEON	60	//�п���
#define DOOR6TO2 61	//�б��� ���� ��
#define BLACKBOARD 62	//����ĥ��
#define BLACKBOARD1 63	//����ĥ��
#define NPCBLOND 64		//��Ӹ�NPC
#define NPCYOON 65		//����NPC
#define CABINET 66		//ĳ���
#define PRINT 67		//������

typedef struct {
	int second;		//��
	int minuite;	//��
	int day;		//��¥
}Time;

typedef struct {
	short phone;	//TRUE = ȹ��, FALSE = ȹ�����
	short piece1;	//TRUE = ȹ��, FALSE = ȹ�����
	short piece2;	//TRUE = ȹ��, FALSE = ȹ�����
	short piece3;	//TRUE = ȹ��, FALSE = ȹ�����
	short piece4;	//TRUE = ȹ��, FALSE = ȹ�����
	short piece5;	//TRUE = ȹ��, FALSE = ȹ�����
	short quest1;	//TRUE = ȹ��, FALSE = ȹ�����
	short quest2;	//TRUE = ȹ��, FALSE = ȹ�����
	short quest3;	//TRUE = ȹ��, FALSE = ȹ�����
	short usb;		//TRUE = ȹ��, FALSE = ȹ�����
	short water;	//TRUE = ȹ��, FALSE = ȹ�����
	short report;	//TRUE = ȹ��, FALSE = ȹ�����
	short shoes;	//TRUE = ȹ��, FALSE = ȹ�����
	short card;		//TRUE = ȹ��, FALSE = ȹ�����
}Item;

typedef struct {
	short location;				//ĳ���� ��ġ
	short tutorial_school;		//TRUE = �б� ó�� FALSE = �б� ó���ƴ�
	short tutorial_professor;	//TRUE = ����Ʈ ó�� FALSE = ����Ʈ ó���ƴ�
	short tutorial_quest1;	//TRUE = ����Ʈ ó�� FALSE = ����Ʈ ó���ƴ�
	short tutorial_quest2;	//TRUE = ����Ʈ ó�� FALSE = ����Ʈ ó���ƴ�
	short tutorial_quest3;	//TRUE = ����Ʈ ó�� FALSE = ����Ʈ ó���ƴ�
	short finish;		//TRUE = Ŭ���� FALSE = Ŭ�������
	int x;				//ĳ���� x��ǥ
	int y;				//ĳ���� y��ǥ
	short sun;	//TRUE = ��, FALSE = ��
	Item item;
	Time play_time;
}Player;

int PlayGame(short tutorial);
void InitPlayer();

#endif // ! __PLAYGAME_H__