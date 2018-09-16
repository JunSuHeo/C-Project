/*
모듈의 기능 : E8-7에서의 충돌처리
버전 : v1.3
개발자 : 정윤재
최종 수정일 : 2018. 6. 3
*/

#ifndef  __EVENTE87_H__
#define __EVENTE87_H__

#include "playgame.h"

int CheckEventE87(int x, int y);

void EventDoor5To2(Player *player);			//E8-7에서 학교
void EventNPCKIM(Player *player);			//NPC 중재
void EventProfessor1(Player *player);		//NPC 이재성교수님

#endif 
