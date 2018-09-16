/*
����� ��� : S1-4������ �浹ó��
���� : v1.4
������ : ������
���� ������ : 2018. 6. 3
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
		return BLOCK;      //��1
	else if ((x > 76 && x <= X_MAX) && (y > 13 && y < 20))
		return BLOCK;      //��2
	else if ((x > 44 && x < 68) && (y > 22 && y <= Y_MAX))
		return BLOCK;      //��3
	else if ((x >= 68 && x < 98) && (y > 22 && y < 29))
		return BLOCK;      //��5
	else if ((x > 104 && x < 128) && (y > 22 && y <= Y_MAX))
		return BLOCK;      //��6
	else if ((x >= 128 && x < 154) && (y > 22 && y < 29))
		return BLOCK;      //��4

	else if ((x > 6 && x < 30) && (y >= 3 && y < 10))
		return FALSE;      //å��1
	else if ((x > 6 && x < 30) && (y >= 3 && y < 10))
		return FALSE;      //å��2
	else if ((x > 6 && x < 30) && (y >= 3 && y < 10))
		return FALSE;      //å��3

	else if ((x >= 70 && x < 86) && (y >= 3 && y < 8))
		return REFREGER;      //�����
	else if ((x > 104 && x < 142) && (y >= 3 && y < 8))
		return FALSE;      //ĥ��
	else if ((x > 142 && x < 158) && (y >= 3 && y < 13))
		return NPCPROFESSOR2;      //����
	else if ((x >= 158 && x <= X_MAX) && (y >= 3 && y < 8))
		return FALSE;      //��ǻ��
	else if ((x > 6 && x < 18) && (y > 32 && y <= Y_MAX))
		return FALSE;      //����1
	else if ((x > 36 && x <= 52) && (y > 31 && y <= Y_MAX))
		return FALSE;      //��ġ
	else if ((x > 55 && x < 68) && (y > 29 && y < 38))
		return FALSE;      //����2
	else if ((x > 84 && x <= 104) && (y > 35 && y <= Y_MAX))
		return FALSE;      //å��2
	else if ((x >= 115 && x < 128) && (y > 29 && y < 38))
		return FALSE;      //����3
	else if ((x > 55 && x < 70) && (y >= 38 && y <= Y_MAX))
		return NPCPROFESSOR3;      //����2
	else if ((x >= 115 && x < 130) && (y >= 38 && y <= Y_MAX))
		return NPCPROFESSOR4;      //����3
	else if ((x > 142 && x <= X_MAX) && (y > 35 && y <= Y_MAX))
		return FALSE;      //å��3
	else if ((x > 36 && x < 42) && (y < 4))
		return DOOR4TO2;      //��

	else if ((x > 36 && x <= 52) && (y > 21 && y < 31))
		return NPCLEE;      //�ϼ�����

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
			system("cls");      //ȭ�� �����

			PrintS14(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
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
			system("cls");      //ȭ�� �����

			PrintS14(player);

			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
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
			system("cls");      //ȭ�� �����

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

			img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
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
				system("cls");      //ȭ�� �����

				player->tutorial_quest1 = FALSE;

				PrintS14(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
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
				system("cls");      //ȭ�� �����

				player->item.water = FALSE;
				player->item.quest1 = TRUE;

				PrintS14(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
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
				system("cls");      //ȭ�� �����

				PrintS14(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
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
			system("cls");      //ȭ�� �����

			player->item.water = TRUE;

			PrintS14(*player);

			img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
			break;
		}
	}
}