/*
모듈의 기능 : 방에서의 충돌처리
버전 : v1.2
개발자 : 허준수
최종 수정일 : 2018. 6. 1
*/
#ifndef __EVENTHOME_H__
#define __EVENTHOME_H__

#include "playgame.h"

int CheckEventRoom(int x, int y);		//방에서 이벤트

void EventBed(Player *player);				//침대갈때 이벤트
void EventToilet(Player player);			//옷장갈때 이벤트
void EventWindow(Player player);			//창문갈때 이벤트
void EventCloth(Player player);				//옷장갈때 이벤트
void EventComputer(Player *player);			//컴퓨터갈때 이벤트

void EventDoor1To2(Player *player);			//방에서 학교

#endif // ! __EVENTHOME_H__