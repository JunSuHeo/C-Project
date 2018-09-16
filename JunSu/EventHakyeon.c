/*
모듈의 기능 : 학연산에서의 충돌처리
버전 : v1.4
개발자 : 김중재
최종 수정일 : 2018. 6. 5
*/
#include "EventHakyeon.h"

int CheckEventHakyeon(int x, int y)
{
	if (x >= X_MAX)
		return BLOCK;
	else if (y > Y_MAX)
		return BLOCK;
	else if (x <= 6)
		return BLOCK;
	else if (y < 3)
		return BLOCK;

	else if ((x >= 66 && x < 80) && (y > 3 && y < 29))
		return BLOCK;      //벽1
	else if ((x > 86 && x < 100) && (y > 3 && y < 13))
		return BLOCK;      //벽2
	else if ((x > 86 && x < 100) && (y > 17 && y <= Y_MAX))
		return BLOCK;      //벽3

	else if ((x > 6 && x < 16) && (y > 3 && y < 13))
		return PRINT;      //복사기
	else if ((x > 36 && x <= 66) && (y > 3 && y < 13))
		return BLACKBOARD1;      //칠판
	else if ((x > 6 && x < 18) && (y > 15 && y < 28))
		return FALSE;      //책상1
	else if ((x > 6 && x <= 22) && (y > 29 && y < 42))
		return FALSE;      //컴퓨터
	else if ((x >= 22 && x < 40) && (y > 29 && y < 42))
		return NPCBLOND;      //대머리
	else if ((x > 58 && x < 80) && (y > 32 && y <= Y_MAX))
		return FALSE;      //벤치 + 벽4
	else if ((x >= 100 && x < 122) && (y > 3 && y < 10))
		return FALSE;      //책장
	else if ((x >= 122 && x < 128) && (y > 3 && y < 7))
		return FALSE;      //시계
	else if ((x > 130 && x <= 148) && (y > 3 && y < 11))
		return BLACKBOARD;      //씨각칠판
	else if ((x >= 148 && x <= X_MAX) && (y >= 11 && y < 16))
		return NPCYOON;      //윤재 만남
	else if ((x > 114 && x < 144) && (y > 18 && y < 32))
		return FALSE;      //책상2
	else if ((x >= 100 && x < 106) && (y > 29 && y <= 33))
		return FALSE;      //휴지통
	else if ((x >= 106 && x < 110) && (y > 33 && y <= Y_MAX))
		return FALSE;      //소파
	else if ((x > 140 && x <= X_MAX) && (y > 35 && y <= Y_MAX))
		return CABINET;      //사물함
	else if ((x >= 80 && x <= 86) && (y == 41))
		return DOOR6TO2;      //문


	else
		return TRUE;
}

void EventDoor6To2(Player * player)
{
	player->location = SCHOOL;

	player->x = 82;
	player->y = 15;

	system("cls");

	PrintSchool(*player);
}

void EventCGAC(Player * player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventCGAC1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventCGAC2.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventRemeber5.bmp");
			getch();

			player->item.piece5 = TRUE;

			if (player->item.piece1 == TRUE && player->item.piece2 == TRUE && player->item.piece3 == TRUE && player->item.piece4 == TRUE && player->item.piece5 == TRUE)
			{
				player->item.piece1 = FALSE;
				player->item.piece2 = FALSE;
				player->item.piece3 = FALSE;
				player->item.piece4 = FALSE;
				player->item.piece5 = FALSE;
				player->item.card = TRUE;
			}
			
			system("cls");      //화면 지우고

			PrintHakyeon(*player);

			img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventPrint(Player * player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventPrint.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			if (player->item.quest1 == TRUE && player->item.quest2 == TRUE && player->item.quest3 == TRUE)
			{
				player->item.report = TRUE;
				player->item.quest1 = FALSE;
				player->item.quest2 = FALSE;
				player->item.quest3 = FALSE;

				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventPrintO.bmp");
				getch();

				system("cls");      //화면 지우고

				PrintHakyeon(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}

			else
			{
				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventPrintX.bmp");
				getch();

				system("cls");      //화면 지우고

				PrintHakyeon(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}

		}
	}



}

void EventNPCBlond(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventBlond.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {

			system("cls");      //화면 지우고

			PrintHakyeon(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventBlackboard(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventBlackboard.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {

			system("cls");      //화면 지우고

			PrintHakyeon(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventNPCYOON(Player * player)
{
	char key;
	
	if (player->tutorial_quest2 == TRUE) {
		player->tutorial_quest2 = FALSE;
		img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventYoon1.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventYoon2.bmp");
				key = getch();

				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventYoon3.bmp");
				key = getch();

				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventYoon4.bmp");
				key = getch();

				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventGetQuest.bmp");
				key = getch();

				system("cls");      //화면 지우고

				PrintHakyeon(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

	else if (player->item.usb == TRUE)
	{
		img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventQuestO1.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventQuestO2.bmp");
				getch();
				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventQuestO3.bmp");
				getch();
				system("cls");      //화면 지우고

				player->item.usb = FALSE;
				player->item.quest2 = TRUE;

				PrintHakyeon(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

	else {
		img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventQuestX.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				system("cls");      //화면 지우고

				PrintHakyeon(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

}

void EventCabinet(Player * player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventCabinet1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventCabinet2.bmp");
			getch();
			system("cls");      //화면 지우고

			player->item.shoes = TRUE;

			PrintHakyeon(*player);

			img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}
