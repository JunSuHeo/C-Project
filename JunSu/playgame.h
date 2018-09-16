/*
모듈의 기능 : 게임 플레이
버전 : v1.11
개발자 : 허준수
최종 수정일 : 2018. 6. 9
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

#define BLOCK 9		//벽

#define ROOM 10			//방
#define CLOTH 11		//주방
#define BED 12			//침대
#define COMPUTER 13		//책상
#define WINDOW 14		//창문
#define TOILET 15		//화장실
#define DOOR1TO2 16		//학교로 가는 문

#define SCHOOL 20		//학교
#define DOOR2TO1 21		//방으로 가는 문
#define DOOR2TO3 22		//전산정보원으로 가는 문
#define DOOR2TO4 23		//S1-4로 가는 문
#define	DOOR2TO5 24		//E8-7로 가는 문
#define DOOR2TO6 25		//학연산으로 가는 문
#define GIRL 26			//지나가는여자
#define MAN1 27			//지나가는남자1
#define MAN2 28			//지나가는남자2

#define JEONSAN 30	//전산정보원
#define DOOR3TO2 31	//학교로 가는 문
#define NPCPROFESSOR 32	//문현주교수님
#define USB 33		//USB
#define USB1 34		//USB훼이크
#define WALLET 35	//지갑

#define S14 40		//S1-4
#define DOOR4TO2 41	//학교로 가는 문
#define NPCPROFESSOR2 42	//조교님
#define NPCPROFESSOR3 43	//교수님2
#define NPCPROFESSOR4 44	//교수님3
#define NPCLEE 45		//완석이
#define REFREGER 46		//냉장고


#define E87	50		//E8-7
#define DOOR5TO2 51	//학교로 가는 문
#define NPCKIM 52	//중재
#define NPCPROFESSOR1 53	//교수님

#define HAKYEON	60	//학연산
#define DOOR6TO2 61	//학교로 가는 문
#define BLACKBOARD 62	//씨각칠판
#define BLACKBOARD1 63	//용지칠판
#define NPCBLOND 64		//대머리NPC
#define NPCYOON 65		//윤재NPC
#define CABINET 66		//캐비넷
#define PRINT 67		//프린터

typedef struct {
	int second;		//초
	int minuite;	//분
	int day;		//날짜
}Time;

typedef struct {
	short phone;	//TRUE = 획득, FALSE = 획득못함
	short piece1;	//TRUE = 획득, FALSE = 획득못함
	short piece2;	//TRUE = 획득, FALSE = 획득못함
	short piece3;	//TRUE = 획득, FALSE = 획득못함
	short piece4;	//TRUE = 획득, FALSE = 획득못함
	short piece5;	//TRUE = 획득, FALSE = 획득못함
	short quest1;	//TRUE = 획득, FALSE = 획득못함
	short quest2;	//TRUE = 획득, FALSE = 획득못함
	short quest3;	//TRUE = 획득, FALSE = 획득못함
	short usb;		//TRUE = 획득, FALSE = 획득못함
	short water;	//TRUE = 획득, FALSE = 획득못함
	short report;	//TRUE = 획득, FALSE = 획득못함
	short shoes;	//TRUE = 획득, FALSE = 획득못함
	short card;		//TRUE = 획득, FALSE = 획득못함
}Item;

typedef struct {
	short location;				//캐릭터 위치
	short tutorial_school;		//TRUE = 학교 처음 FALSE = 학교 처음아님
	short tutorial_professor;	//TRUE = 퀘스트 처음 FALSE = 퀘스트 처음아님
	short tutorial_quest1;	//TRUE = 퀘스트 처음 FALSE = 퀘스트 처음아님
	short tutorial_quest2;	//TRUE = 퀘스트 처음 FALSE = 퀘스트 처음아님
	short tutorial_quest3;	//TRUE = 퀘스트 처음 FALSE = 퀘스트 처음아님
	short finish;		//TRUE = 클리어 FALSE = 클리어못함
	int x;				//캐릭터 x좌표
	int y;				//캐릭터 y좌표
	short sun;	//TRUE = 낮, FALSE = 밤
	Item item;
	Time play_time;
}Player;

int PlayGame(short tutorial);
void InitPlayer();

#endif // ! __PLAYGAME_H__