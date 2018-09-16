/*
모듈의 기능 : E8-7에서의 충돌처리
버전 : v1.3
개발자 : 정윤재
최종 수정일 : 2018. 6. 3
*/

#include "EventE87.h"

int CheckEventE87(int x, int y)
{
	if (x >= X_MAX)
		return BLOCK;
	else if (y > Y_MAX)
		return BLOCK;
	else if (x <= 6)
		return BLOCK;
	else if (y < 3)
		return BLOCK;

	else if ((x == 156) && (y >= 19 && y <= 26))
		return DOOR5TO2;      //문(E87에서 나가짐)

	else if ((x > 30 && x < 54) && (y >= 3 && y < 12))
		return FALSE;      //책상
	else if ((x > 60 && x < 80) && (y >= 3 && y < 12))
		return FALSE;      //책상
	else if ((x > 88 && x < 108) && (y >= 3 && y < 12))
		return FALSE;      //책상
	else if ((x > 118 && x < 138) && (y >= 3 && y < 12))
		return FALSE;      //책상

	else if ((x > 30 && x < 50) && (y > 14 && y < 27))
		return FALSE;      //책상
	else if ((x > 60 && x < 80) && (y > 14 && y < 27))
		return FALSE;      //책상
	else if ((x > 88 && x < 108) && (y > 14 && y < 27))
		return FALSE;      //책상
	else if ((x > 118 && x < 138) && (y > 14 && y < 27))
		return FALSE;      //책상

	else if ((x > 30 && x < 50) && (y > 29 && y < 42))
		return FALSE;      //책상
	else if ((x > 60 && x < 80) && (y > 29 && y < 42))
		return FALSE;      //책상
	else if ((x > 88 && x < 108) && (y > 29 && y < 42))
		return FALSE;      //책상
	else if ((x > 118 && x < 138) && (y > 29 && y < 42))
		return FALSE;      //책상

	else if ((x > 6 && x < 14) && (y > 9 && y < 35))
		return FALSE;      //칠판
	else if ((x >= 14 && x < 22) && (y > 24 && y < 35))
		return NPCPROFESSOR1;      //교수님
	else if ((x == 54) && (y >= 3 && y < 6))
		return NPCKIM;      //중재 만남

	else
		return TRUE;
}

void EventDoor5To2(Player * player)
{
	player->location = SCHOOL;

	player->x = 40;
	player->y = 20;

	system("cls");

	PrintSchool(*player);
}

void EventNPCKIM(Player * player)
{
	char key;

	if (player->tutorial_quest3 == TRUE) {
		player->tutorial_quest3 = FALSE;
		img(0, 0, 1280, 720, L"./image/Map/E87/EventKIM1.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/E87/EventKIM2.bmp");
				key = getch();

				img(0, 0, 1280, 720, L"./image/Map/E87/EventKIM3.bmp");
				key = getch();

				img(0, 0, 1280, 720, L"./image/Map/E87/EventKIM4.bmp");
				key = getch();

				img(0, 0, 1280, 720, L"./image/Map/E87/EventGetQuest.bmp");
				key = getch();

				system("cls");      //화면 지우고

				PrintE87(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

	else if (player->item.shoes == TRUE)
	{
		img(0, 0, 1280, 720, L"./image/Map/E87/EventQuestO1.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/E87/EventQuestO2.bmp");
				getch();
				system("cls");      //화면 지우고

				player->item.shoes = FALSE;
				player->item.quest3 = TRUE;

				PrintE87(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}

	else {
		img(0, 0, 1280, 720, L"./image/Map/E87/EventQuestX.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				system("cls");      //화면 지우고

				PrintE87(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
				break;
			}
		}
	}
}

void EventProfessor1(Player * player)
{
	char key;
	char subkey[3] = { 0 };
	int correct[3] = { 0,0,0 };

	img(0, 0, 1280, 720, L"./image/Map/E87/EventProfessor.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			if (correct[0] == 0) {
				img(0, 0, 1280, 720, L"./image/Map/E87/EventQuestion1.bmp");
				subkey[0] = getch();
			}
			if (subkey[0] == '4') correct[0] = 1;
			else {
				img(0, 0, 1280, 720, L"./image/Map/E87/EventWrong.bmp");
				getch();
			}
			
			if (correct[0] == 1)
			{
				if (correct[1] == 0) {
					img(0, 0, 1280, 720, L"./image/Map/E87/EventQuestion2.bmp");
					subkey[1] = getch();
				}

				if (subkey[1] == '4') correct[1] = 1;
				else {
					img(0, 0, 1280, 720, L"./image/Map/E87/EventWrong.bmp");
					getch();
				}

				if (correct[1] == 1)
				{
					if (correct[2] == 0) {
						img(0, 0, 1280, 720, L"./image/Map/E87/EventQuestion3.bmp");
						subkey[2] = getch();
					}
					if (subkey[2] == '4') correct[2] = 1;
					else {
						img(0, 0, 1280, 720, L"./image/Map/E87/EventWrong.bmp");
						getch();
					}
					if (correct[2] == 1)
					{

						img(0, 0, 1280, 720, L"./image/Map/E87/EventCorrect1.bmp");
						getch();
						img(0, 0, 1280, 720, L"./image/Map/E87/EventCorrect2.bmp");
						getch();
						img(0, 0, 1280, 720, L"./image/Map/E87/GetPiece.bmp");
						getch();

						player->item.piece3 = TRUE;

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

						PrintE87(*player);
						img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
						break;
					}
					
				}
			}

			
		}
	}
}
