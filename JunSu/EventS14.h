/*
모듈의 기능 : S1-4에서의 충돌처리
버전 : v1.4
개발자 : 김중재
최종 수정일 : 2018. 6. 3
*/

#ifndef __EVENTS14_H__
#define __EVENTS14_h__

#include "playgame.h"

int CheckEventS14(int x, int y);

void EventDoor4To2(Player *player);		//학교로 가는 문
void EventAssistant(Player player);		//조교님NPC
void EventProfessor3(Player player);	//NPC교수님
void EventProfessor4(Player *player);	//NPC지도교수님
void EventNPCLEE(Player *player);		//NPC완석
void EventGetWater(Player *player);		//준水 획득

#endif