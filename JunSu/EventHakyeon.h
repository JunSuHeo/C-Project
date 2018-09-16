/*
모듈의 기능 : 학연산에서의 충돌처리
버전 : v1.4
개발자 : 김중재
최종 수정일 : 2018. 6. 5
*/

#ifndef __EVENTHAKYEON_H__
#define __EVENTHAKYEON_H__

#define BLACKBOARD 62	//씨각칠판
#define BLACKBOARD1 63	//용지칠판
#define NPCBLOND 64		//대머리NPC
#define NPCYOON 65		//윤재NPC
#define CABINET 66		//캐비넷
#define PRINT 67		//프린터

#include "playgame.h"

int CheckEventHakyeon(int x, int y);	//학연산에서 이벤트

void EventDoor6To2(Player *player);		//학교로 가는 문
void EventCGAC(Player *player);			//기억의조각 이벤트
void EventPrint(Player *player);		//과제프린트
void EventNPCBlond(Player player);		//대머리NPC
void EventBlackboard(Player player);	//칠판이벤트
void EventNPCYOON(Player *player);		//윤재NPC
void EventCabinet(Player *player);		//축구화찾기

#endif