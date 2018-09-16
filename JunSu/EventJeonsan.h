/*
모듈의 기능 : 전산정보원에서의 충돌처리
버전 : v1.3
개발자 : 정윤재
최종 수정일 : 2018. 6. 4
*/

#ifndef __EVENTJEONSAN_H__
#define __EVENTJEONSAN_H__

#include "playgame.h"

int CheckEventJeonsan(int x, int y);

void EventDoor3To2(Player *player);			//전산정보원에서 학교

void EventNPCProfessor(Player *player);		//문현주교수님 NPC
void EventUSB(Player *player);				//USB이벤트
void EventUSB1(Player player);				//가짜USB
void EventWallet(Player *player);			//지갑이벤트

#endif