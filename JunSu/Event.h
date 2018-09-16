/*
모듈의 기능 : 충돌처리
버전 : v1.3
개발자 : 허준수
최종 수정일 : 2018. 5. 29
*/
#ifndef __EVENT_H__
#define __EVENT_H__

#include "playgame.h"

int CheckEventUp(Player *player);			//위방향 이벤트
int CheckEventDown(Player *player);			//아래방향 이벤트
int CheckEventLeft(Player *player);			//왼방향 이벤트
int CheckEventRight(Player* player);			//오른방향 이벤트

#endif // ! __EVENT_H__