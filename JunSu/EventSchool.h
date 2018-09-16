/*
모듈의 기능 : 학교에서의 충돌처리
버전 : v1.3
개발자 : 이완석
최종 수정일 : 2018. 6. 3
*/

#ifndef __EVENTSCHOOL_H__
#define __EVENTSCHOOL_H__

#include "playgame.h"

int CheckEventSchool(int x, int y);		//학교에서 이벤트

void EventDoor2To1(Player *player);			//학교에서 방
void EventDoor2To3(Player *player);			//학교에서 전산정보원
void EventDoor2To4(Player *player);			//학교에서 S1-4
void EventDoor2To5(Player *player);			//학교에서 E8-7
void EventDoor2To6(Player *player);			//학교에서 학연산

void EventGirl(Player player);		//여자NPC
void EventMan1(Player player);		//남자1NPC
void EventMan2(Player player);		//남자2NPC

#endif