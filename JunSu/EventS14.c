/*
모듈의 기능 : S1-4에서의 충돌처리
버전 : v1.4
개발자 : 김중재
최종 수정일 : 2018. 6. 3
*/
#include "EventS14.h"

int CheckEventS14(int x, int y)
{
	if (x > X_MAX)
		return BLOCK;
	else if (y > Y_MAX)
		return BLOCK;
	else if (x <= 6)
		return BLOCK;
	else if (y < 3)
		return BLOCK;

	else if ((x > 56 && x < 70) && (y >= 3 && y < 20))
		return BLOCK;      //벽1
	else if ((x > 76 && x <= X_MAX) && (y > 13 && y < 20))
		return BLOCK;      //벽2
	else if ((x > 44 && x < 68) && (y > 22 && y <= Y_MAX))
		return BLOCK;      //벽3
	else if ((x >= 68 && x < 98) && (y > 22 && y < 29))
		return BLOCK;      //벽5
	else if ((x > 104 && x < 128) && (y > 22 && y <= Y_MAX))
		return BLOCK;      //벽6
	else if ((x >= 128 && x < 154) && (y > 22 && y < 29))
		return BLOCK;      //벽4

	else if ((x > 6 && x < 30) && (y >= 3 && y < 10))
		return FALSE;      //책장1
	else if ((x > 6 && x < 30) && (y >= 3 && y < 10))
		return FALSE;      //책장2
	else if ((x > 6 && x < 30) && (y >= 3 && y < 10))
		return FALSE;      //책장3

	else if ((x >= 70 && x < 86) && (y >= 3 && y < 8))
		return REFREGER;      //냉장고
	else if ((x > 104 && x < 142) && (y >= 3 && y < 8))
		return FALSE;      //칠판
	else if ((x > 142 && x < 158) && (y >= 3 && y < 13))
		return NPCPROFESSOR2;      //조교
	else if ((x >= 158 && x <= X_MAX) && (y >= 3 && y < 8))
		return FALSE;      //컴퓨터
	else if ((x > 6 && x < 18) && (y > 32 && y <= Y_MAX))
		return FALSE;      //소파1
	else if ((x > 36 && x <= 52) && (y > 31 && y <= Y_MAX))
		return FALSE;      //벤치
	else if ((x > 55 && x < 68) && (y > 29 && y < 38))
		return FALSE;      //소파2
	else if ((x > 84 && x <= 104) && (y > 35 && y <= Y_MAX))
		return FALSE;      //책장2
	else if ((x >= 115 && x < 128) && (y > 29 && y < 38))
		return FALSE;      //소파3
	else if ((x > 55 && x < 70) && (y >= 38 && y <= Y_MAX))
		return NPCPROFESSOR3;      //교수2
	else if ((x >= 115 && x < 130) && (y >= 38 && y <= Y_MAX))
		return NPCPROFESSOR4;      //교수3
	else if ((x > 142 && x <= X_MAX) && (y > 35 && y <= Y_MAX))
		return FALSE;      //책장3
	else if ((x > 36 && x < 42) && (y < 4))
		return DOOR4TO2;      //문

	else if ((x > 36 && x <= 52) && (y > 21 && y < 31))
		return NPCLEE;      //완석만남

	else
		return TRUE;
}

void EventDoor4To2(Player * player)
{
	player->location = SCHOOL;

	player->x = 50;
	player->y = 30;

	system("cls");

	PrintSchool(*player);
}

void EventAssistant(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant2.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant3.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant4.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant5.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant6.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventAssistant7.bmp");
			getch();
			system("cls");      //화면 지우고

			PrintS14(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventProfessor3(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor1.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor2.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor3.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessorStop.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor4.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor5.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor6.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessorStop.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor7.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor8.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor9.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessorStop.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor10.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventWrong.bmp");
			getch();
			system("cls");      //화면 지우고

			PrintS14(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventProfessor4(Player * player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor1.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor2.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor3.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessorStop.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor4.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor5.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor6.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessorStop.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor7.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor8.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor9.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessorStop.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventProfessor10.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventCorrect.bmp");
			getch();
			img(0, 0, 1280, 720, L"./image/Map/S14/EventRemember2.bmp");
			getch();
			system("cls");      //화면 지우고

			player->item.piece2 = TRUE;

			if (player->item.piece1 == TRUE && player->item.piece2 == TRUE && player->item.piece3 == TRUE && player->item.piece4 == TRUE && player->item.piece5 == TRUE)
			{
				player->item.piece1 = FALSE;
				player->item.piece2 = FALSE;
				player->item.piece3 = FALSE;
				player->item.piece4 = FALSE;
				player->item.piece5 = FALSE;
				player->item.card = TRUE;
			}

			PrintS14(*player);

			img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}

	
}

void EventNPCLEE(Player * player)
{
	char key;

	if (player->tutorial_quest1 == TRUE) {
		img(0, 0, 1280, 720, L"./image/Map/S14/EventLee1.bmp");

		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/S14/EventLee2.bmp");
				getch();
				img(0, 0, 1280, 720, L"./image/Map/S14/EventLee3.bmp");
				getch();
				img(0, 0, 1280, 720, L"./image/Map/S14/EventGetQuest.bmp");
				getch();
				system("cls");      //화면 지우고

				player->tutorial_quest1 = FALSE;

				PrintS14(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

	else if (player->item.water == TRUE)
	{
		img(0, 0, 1280, 720, L"./image/Map/S14/EventQuestClear.bmp");

		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/S14/EventGetPiece.bmp");
				getch();
				system("cls");      //화면 지우고

				player->item.water = FALSE;
				player->item.quest1 = TRUE;

				PrintS14(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

	else
	{
		img(0, 0, 1280, 720, L"./image/Map/S14/EventQuest2.bmp");

		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				system("cls");      //화면 지우고

				PrintS14(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}
}

void EventGetWater(Player * player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/S14/EventRefregerator.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			system("cls");      //화면 지우고

			player->item.water = TRUE;

			PrintS14(*player);

			img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}