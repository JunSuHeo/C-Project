/*
모듈의 기능 : 학교에서의 충돌처리
버전 : v1.3
개발자 : 이완석
최종 수정일 : 2018. 6. 3
*/
#include "EventSchool.h"

int CheckEventSchool(int x, int y)
{
	if (x >= X_MAX)
		return BLOCK;
	else if (y >= Y_MAX)
		return BLOCK;
	else if (x <= 6)
		return BLOCK;
	else if (y < 3)
		return BLOCK;

	else if ((x > 138 && x <= 156) && (y > 10 && y < 27))
		return DOOR2TO1;      //집으로가는문
	else if ((x > 104 && x < 140) && (y > 29 && y < Y_MAX))
		return DOOR2TO3;      //전산정보원
	else if ((x > 36 && x < 62) && (y > 32 && y < Y_MAX))
		return DOOR2TO4;      //S1-4
	else if ((x >= 8 && x < 26) && (y > 12 && y < 30))
		return DOOR2TO5;      //E8-7
	else if ((x >= 26 && x < 36) && (y > 12 && y < 27))
		return DOOR2TO5;      //E8-7
	else if ((x >= 64 && x < 72) && (y >= 3 && y < 11))
		return FALSE;      //학연 건물
	else if ((x >= 72 && x <= 92) && (y >= 11 && y <= 13))
		return DOOR2TO6;   //학연 문
	else if ((x > 92 && x <= 100) && (y >= 3 && y < 11))
		return FALSE;      //학연 건물
	else if ((x >= 148 && x <= X_MAX) && (y >= 8 && y < 10))
		return FALSE;      //가로등


	else if ((x > 6 && x <= 62) && (y >= 3 && y < 8))
		return FALSE;      //나무1
	else if ((x >= 102 && x <= 148) && (y >= 3 && y < 8))
		return FALSE;      //나무2
	else if ((x >= 140 && x <= 156) && (y > 36 && y < Y_MAX))
		return FALSE;      //나무
	else if ((x >= 62 && x <= 104) && (y > 36 && y < Y_MAX))
		return FALSE;      //나무
	else if ((x >= 30 && x <= 36) && (y > 36 && y < Y_MAX))
		return FALSE;      //나무
	else if ((x > 6 && x < 16) && (y >= 8 && y <= 12))
		return GIRL;      //Girl
	else if ((x > 84 && x < 104) && (y > 14 && y < 25))
		return MAN1;      //NPC2
	else if ((x > 76 && x < 96) && (y > 31 && y <= 36))
		return MAN2;      //NPC3

	else
		return TRUE;
}

void EventDoor2To1(Player * player)
{
	char key;
	char Password[5];
	int i = 0;

	player->x -= 2;

	img(0, 0, 1280, 720, L"./image/Map/Room/Password.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			for (i = 0; i < 3; i++)
				Password[i] = getch();
			break;
		}
	}

	for (i = 0; i < 4; i++)
	{
		if (Password[i] == '1' + i + 1)
			continue;
		else
			break;
	}

	if (i == 3)
	{
		player->location = ROOM;

		player->x = 12;
		player->y = 19;

		system("cls");

		if (player->sun == TRUE)
			PrintRoom_Sun(*player);
		else
			PrintRoom_Moon(*player);
	}

	else
	{
		img(0, 0, 1280, 720, L"./image/Map/Room/WrongPassword.bmp");

		rewind(stdin);
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}
			else
				PrintSchool(*player);
				break;
		}
	}
}

void EventDoor2To3(Player * player)
{
	char key;
	if (player->sun == FALSE)
	{
		if (player->item.card == TRUE) {
			img(0, 0, 1280, 720, L"./image/Map/School/Correct.bmp");
			key = getch();

			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}

				else {
					player->location = JEONSAN;
					player->x = 126;
					player->y = 5;

					system("cls");

					PrintJeonsan(*player);
					break;
				}
			}

			
		}
		else
		{
			img(0, 0, 1280, 720, L"./image/Map/School/Wrong.bmp");
			key = getch();
			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}
				else
					break;
			}
			system("cls");
			PrintSchool(*player);
		}
	}
	else
	{
		player->location = JEONSAN;
		player->tutorial_professor = TRUE;
		player->x = 126;
		player->y = 5;

		system("cls");

		PrintJeonsan(*player);
	}
	
}

void EventDoor2To4(Player * player)
{
	char key;

	if (player->sun == FALSE)
	{
		if (player->item.card == TRUE) {
			img(0, 0, 1280, 720, L"./image/Map/School/Correct.bmp");
			getch();

			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}

				else {
					player->location = S14;
					player->x = 38;
					player->y = 6;

					system("cls");

					PrintS14(*player);
					break;
				}
			}
		}
		else
		{
			img(0, 0, 1280, 720, L"./image/Map/School/Wrong.bmp");
			key = getch();
			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}
				else
					break;
			}
			system("cls");
			PrintSchool(*player);
		}
	}
	else
	{
		player->location = S14;
		player->x = 38;
		player->y = 6;

		system("cls");

		PrintS14(*player);
	}

	
}

void EventDoor2To5(Player * player)
{
	char key;
	if (player->sun == FALSE)
	{
		if (player->item.card == TRUE) {
			img(0, 0, 1280, 720, L"./image/Map/School/Correct.bmp");
			key = getch();

			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}

				else {
					player->location = E87;
					player->x = 148;
					player->y = 22;

					system("cls");

					PrintE87(*player);
					break;
				}
			}
		}
		else
		{
			img(0, 0, 1280, 720, L"./image/Map/School/Wrong.bmp");
			key = getch();
			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}
				else
					break;
			}

			system("cls");
			PrintSchool(*player);
		}
	}
	else
	{
		player->location = E87;
		player->x = 148;
		player->y = 22;

		system("cls");

		PrintE87(*player);
	}

	
}

void EventDoor2To6(Player *player)
{
	char key;
	if (player->sun == FALSE)
	{
		if (player->item.card == TRUE) {
			img(0, 0, 1280, 720, L"./image/Map/School/Correct.bmp");
			key = getch();

			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}

				else {
					player->location = HAKYEON;

					player->x = 84;
					player->y = 39;

					system("cls");

					PrintHakyeon(*player);
					break;
				}
			}

			
		}
		else
		{
			img(0, 0, 1280, 720, L"./image/Map/School/Wrong.bmp");
			key = getch();
			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}
				else
					break;
			}
			system("cls");
			PrintSchool(*player);
		}
	}
	else
	{
		player->location = HAKYEON;

		player->x = 84;
		player->y = 39;

		system("cls");

		PrintHakyeon(*player);
	}

	
}

void EventGirl(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/School/EventNPC_Girl.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			system("cls");      //화면 지우고

			PrintSchool(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventMan1(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/School/EventNPC_Man2.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			system("cls");      //화면 지우고

			PrintSchool(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}

void EventMan2(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/School/EventNPC_Man1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			system("cls");      //화면 지우고

			PrintSchool(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
			break;
		}
	}
}
