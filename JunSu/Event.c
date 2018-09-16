/*
모듈의 기능 : 충돌처리
버전 : v1.3
개발자 : 허준수
최종 수정일 : 2018. 5. 29
*/
#include "Event.h"
#include "EventE87.h"
#include "EventHakyeon.h"
#include "EventHome.h"
#include "EventJeonsan.h"
#include "EventS14.h"
#include "EventSchool.h"

int CheckEventUp(Player *player)
{
	int state;

	if (player->location == ROOM)      //플레이어의 위치가 방이라면
	{
		state = CheckEventRoom(player->x, player->y - 1);      //방안에서의 충돌 확인

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case BED:      //침대 충돌이 있다면
			EventBed(player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case WINDOW:   //창문 충돌이 있다면
			EventWindow(*player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case TOILET:   //화장실 충돌이 있다면
			EventToilet(*player);      //화장실 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case CLOTH:      //옷장 충돌이 있다면
			EventCloth(*player);   //옷장 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR1TO2:      //문 충돌이 있다면
			EventDoor1To2(player);   //문 충돌과 관련된 함수
			return FALSE;      //충돌 발생
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x, player->y - 1);
		switch (state) {
		case DOOR2TO1:		//집으로가는 문과의 충돌
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//전산정보원으로가는 문과의 충돌
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4로 가는 문과의 충돌
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7로 가는 문과의 충돌
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//학연산으로 가는 문과의 충돌
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL :			//NPC여자
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1 :			//NPC남자1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2 :			//NPC남자2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default :
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x, player->y - 1);
		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR3TO2:		//학교가는문
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR ://문현주교수님
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB :			//USB찾음
			EventUSB(player);
			return FALSE;
			break;
		case USB1 :			//가짜 USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET :		//지갑찾음
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //플레이어의 위치가 방이라면
	{
		state = CheckEventE87(player->x, player->y - 1);      //방안에서의 충돌 확인

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case DOOR5TO2:	//학교가는문
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM :		//중재한테 가면
			EventNPCKIM(player);	//중재관한이벤트 실행
			return FALSE;
			break;				
		case NPCPROFESSOR1 :	//이재성교수님한테 가면
			EventProfessor1(player);	//이재성교수님관한 이벤트 실행
			return FALSE;
			break;			
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x, player->y - 1);      //방에서의 충돌 확인

		switch (state) {
		case BLOCK:		//벽 충돌
			return FALSE;
			break;
		case DOOR6TO2:	//학교가는문 충돌
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD :	//CGAC칠판 충돌
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND :		//대머리NPC 충돌
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON :		//NPC윤재 충돌
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET :		//캐비넷 충돌
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1 :	//칠판충돌
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT :		//프린터기충돌
			EventPrint(player);
			return FALSE;
			break;
		case TRUE :
			return TRUE;
		default :
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x, player->y - 1);

		switch (state)
		{
		case BLOCK :		//벽충돌
			return FALSE;
			break;
		case NPCPROFESSOR2 :	//조교님충돌
			EventAssistant(*player);	
			return FALSE;
			break;
		case NPCPROFESSOR3:		//교수님 충돌
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//지도교수님 충돌
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//완석 충돌
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER :			//냉장고 충돌
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE :			//충돌
			return FALSE;
			break;
		case DOOR4TO2 :			//학교가는문 충돌
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE :			//충돌없음
			return TRUE;
			break;
		}
	}
}

int CheckEventDown(Player *player)
{
	int state;

	if (player->location == ROOM)      //플레이어의 위치가 방이라면
	{
		state = CheckEventRoom(player->x, player->y + 1);      //방안에서의 충돌 확인

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case BED:      //침대 충돌이 있다면
			EventBed(player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case WINDOW:   //창문 충돌이 있다면
			EventWindow(*player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case TOILET:   //화장실 충돌이 있다면
			EventToilet(*player);      //화장실 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case CLOTH:      //옷장 충돌이 있다면
			EventCloth(*player);   //옷장 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR1TO2:      //문 충돌이 있다면
			EventDoor1To2(player);   //문 충돌과 관련된 함수
			return FALSE;      //충돌 발생
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x, player->y + 1);
		switch (state) {
		case DOOR2TO1:		//집으로가는 문과의 충돌
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//전산정보원으로가는 문과의 충돌
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4로 가는 문과의 충돌
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7로 가는 문과의 충돌
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//학연산으로 가는 문과의 충돌
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL:			//NPC여자
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1:			//NPC남자1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2:			//NPC남자2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default:
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x, player->y + 1);
		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR3TO2:		//학교가는문
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR://문현주교수님
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB:			//USB찾음
			EventUSB(player);
			return FALSE;
			break;
		case USB1:			//가짜 USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET:		//지갑찾음
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //플레이어의 위치가 방이라면
	{
		state = CheckEventE87(player->x, player->y + 1);      //방안에서의 충돌 확인

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case DOOR5TO2:	//학교가는문
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM:		//중재한테 가면
			EventNPCKIM(player);	//중재관한이벤트 실행
			return FALSE;
			break;
		case NPCPROFESSOR1:	//이재성교수님한테 가면
			EventProfessor1(player);	//이재성교수님관한 이벤트 실행
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x, player->y + 1);      //방에서의 충돌 확인

		switch (state) {
		case BLOCK:		//벽 충돌
			return FALSE;
			break;
		case DOOR6TO2:	//학교가는문 충돌
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD:	//CGAC칠판 충돌
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND:		//대머리NPC 충돌
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON:		//NPC윤재 충돌
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET:		//캐비넷 충돌
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1:	//칠판충돌
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT:		//프린터기충돌
			EventPrint(player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
		default:
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x, player->y + 1);

		switch (state)
		{
		case BLOCK:		//벽충돌
			return FALSE;
			break;
		case NPCPROFESSOR2:	//조교님충돌
			EventAssistant(*player);
			return FALSE;
			break;
		case NPCPROFESSOR3:		//교수님 충돌
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//지도교수님 충돌
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//완석 충돌
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER:			//냉장고 충돌
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE:			//충돌
			return FALSE;
			break;
		case DOOR4TO2:			//학교가는문 충돌
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE:			//충돌없음
			return TRUE;
			break;
		}
	}
}

int CheckEventLeft(Player *player)
{
	int state;

	if (player->location == ROOM)      //플레이어의 위치가 방이라면
	{
		state = CheckEventRoom(player->x - 2, player->y);      //방안에서의 충돌 확인

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case BED:      //침대 충돌이 있다면
			EventBed(player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case WINDOW:   //창문 충돌이 있다면
			EventWindow(*player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case TOILET:   //화장실 충돌이 있다면
			EventToilet(*player);      //화장실 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case CLOTH:      //옷장 충돌이 있다면
			EventCloth(*player);   //옷장 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR1TO2:      //문 충돌이 있다면
			EventDoor1To2(player);   //문 충돌과 관련된 함수
			return FALSE;      //충돌 발생
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x - 2, player->y);
		switch (state) {
		case DOOR2TO1:		//집으로가는 문과의 충돌
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//전산정보원으로가는 문과의 충돌
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4로 가는 문과의 충돌
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7로 가는 문과의 충돌
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//학연산으로 가는 문과의 충돌
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL:			//NPC여자
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1:			//NPC남자1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2:			//NPC남자2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default:
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x - 2, player->y);
		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR3TO2:		//학교가는문
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR://문현주교수님
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB:			//USB찾음
			EventUSB(player);
			return FALSE;
			break;
		case USB1:			//가짜 USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET:		//지갑찾음
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //플레이어의 위치가 방이라면
	{
		state = CheckEventE87(player->x - 2, player->y);

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case DOOR5TO2:	//학교가는문
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM:		//중재한테 가면
			EventNPCKIM(player);	//중재관한이벤트 실행
			return FALSE;
			break;
		case NPCPROFESSOR1:	//이재성교수님한테 가면
			EventProfessor1(player);	//이재성교수님관한 이벤트 실행
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x - 2, player->y);

		switch (state) {
		case BLOCK:		//벽 충돌
			return FALSE;
			break;
		case DOOR6TO2:	//학교가는문 충돌
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD:	//CGAC칠판 충돌
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND:		//대머리NPC 충돌
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON:		//NPC윤재 충돌
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET:		//캐비넷 충돌
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1:	//칠판충돌
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT:		//프린터기충돌
			EventPrint(player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
		default:
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x - 2, player->y);

		switch (state)
		{
		case BLOCK:		//벽충돌
			return FALSE;
			break;
		case NPCPROFESSOR2:	//조교님충돌
			EventAssistant(*player);
			return FALSE;
			break;
		case NPCPROFESSOR3:		//교수님 충돌
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//지도교수님 충돌
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//완석 충돌
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER:			//냉장고 충돌
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE:			//충돌
			return FALSE;
			break;
		case DOOR4TO2:			//학교가는문 충돌
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE:			//충돌없음
			return TRUE;
			break;
		}
	}
}

int CheckEventRight(Player *player)
{
	int state;

	if (player->location == ROOM)      //플레이어의 위치가 방이라면
	{
		state = CheckEventRoom(player->x + 2, player->y);      //방안에서의 충돌 확인

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case BED:      //침대 충돌이 있다면
			EventBed(player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case WINDOW:   //창문 충돌이 있다면
			EventWindow(*player);      //침대 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case TOILET:   //화장실 충돌이 있다면
			EventToilet(*player);      //화장실 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case CLOTH:      //옷장 충돌이 있다면
			EventCloth(*player);   //옷장 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR1TO2:      //문 충돌이 있다면
			EventDoor1To2(player);   //문 충돌과 관련된 함수
			return FALSE;      //충돌 발생
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x + 2, player->y);
		switch (state) {
		case DOOR2TO1:		//집으로가는 문과의 충돌
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//전산정보원으로가는 문과의 충돌
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4로 가는 문과의 충돌
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7로 가는 문과의 충돌
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//학연산으로 가는 문과의 충돌
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL:			//NPC여자
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1:			//NPC남자1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2:			//NPC남자2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default:
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x + 2, player->y);
		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case COMPUTER:   //컴퓨터 충돌이 있다면
			EventComputer(player);   //컴퓨터 충돌에 관련된 함수
			return FALSE;      //충돌 발생
			break;
		case DOOR3TO2:		//학교가는문
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR://문현주교수님
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB:			//USB찾음
			EventUSB(player);
			return FALSE;
			break;
		case USB1:			//가짜 USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET:		//지갑찾음
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //플레이어의 위치가 방이라면
	{
		state = CheckEventE87(player->x + 2, player->y);

		switch (state) {
		case BLOCK:      //벽 충돌이 있다면
			return FALSE;   //충돌발생
			break;
		case DOOR5TO2:	//학교가는문
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM:		//중재한테 가면
			EventNPCKIM(player);	//중재관한이벤트 실행
			return FALSE;
			break;
		case NPCPROFESSOR1:	//이재성교수님한테 가면
			EventProfessor1(player);	//이재성교수님관한 이벤트 실행
			return FALSE;
			break;
		case TRUE:      //충돌이 없다면
			return TRUE;
			break;
		case FALSE:      //충돌 발생
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x + 2, player->y);

		switch (state) {
		case BLOCK:		//벽 충돌
			return FALSE;
			break;
		case DOOR6TO2:	//학교가는문 충돌
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD:	//CGAC칠판 충돌
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND:		//대머리NPC 충돌
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON:		//NPC윤재 충돌
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET:		//캐비넷 충돌
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1:	//칠판충돌
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT:		//프린터기충돌
			EventPrint(player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
		default:
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x + 2, player->y);

		switch (state)
		{
		case BLOCK:		//벽충돌
			return FALSE;
			break;
		case NPCPROFESSOR2:	//조교님충돌
			EventAssistant(*player);
			return FALSE;
			break;
		case NPCPROFESSOR3:		//교수님 충돌
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//지도교수님 충돌
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//완석 충돌
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER:			//냉장고 충돌
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE:			//충돌
			return FALSE;
			break;
		case DOOR4TO2:			//학교가는문 충돌
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE:			//충돌없음
			return TRUE;
			break;
		}
	}
}