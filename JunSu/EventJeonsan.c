/*
����� ��� : ���������������� �浹ó��
���� : v1.3
������ : ������
���� ������ : 2018. 6. 4
*/
#include "EventJeonsan.h"

int CheckEventJeonsan(int x, int y)
{
	if (x >= X_MAX)
		return BLOCK;
	else if (y > Y_MAX)
		return BLOCK;
	else if (x <= 6)
		return BLOCK;
	else if (y < 3)
		return BLOCK;

	else if ((x > 6 && x < 24) && (y > 4 && y < 15))
		return FALSE;      //å��
	else if ((x > 26 && x < 54) && (y > 4 && y < 15))
		return FALSE;      //å��
	else if ((x > 60 && x < 88) && (y > 4 && y < 15))
		return FALSE;      //å��
	else if ((x > 94 && x < 122) && (y > 4 && y < 15))
		return FALSE;      //å��
	else if ((x > 126 && x < 154) && (y > 4 && y < 15))
		return FALSE;      //å��

	else if ((x > 6 && x < 24) && (y > 17 && y < 28))
		return FALSE;      //å��
	else if ((x > 26 && x < 54) && (y > 17 && y < 28))
		return FALSE;      //å��
	else if ((x > 60 && x < 88) && (y > 17 && y < 28))
		return FALSE;      //å��
	else if ((x > 94 && x < 122) && (y > 17 && y < 28))
		return FALSE;      //å��
	else if ((x > 134 && x < 154) && (y > 17 && y < 28))
		return FALSE;      //å��
	else if ((x > 126 && x <= 140) && (y > 17 && y < 28))
		return FALSE;      //å��


	else if ((x > 6 && x <= 10) && (y == 30))
		return USB;      //USB�ִ� å��
	else if ((x > 94 && x <= 98) && y == 30)
		return USB1;
	else if ((x >= 134 && x <= 138) && (y == 17))
		return WALLET;      //�����ִ� å��


	else if ((x > 10 && x < 24) && (y > 29 && y < 40))
		return FALSE;      //å��
	else if ((x > 6 && x <= 10) && (y > 30 && y < 40))
		return FALSE;      //å��
	else if ((x > 26 && x < 54) && (y > 29 && y < 40))
		return FALSE;      //å��
	else if ((x > 60 && x < 88) && (y > 29 && y < 40))
		return FALSE;      //å��
	else if ((x > 94 && x < 122) && (y > 29 && y < 40))
		return FALSE;      //å��
	else if ((x > 126 && x < 154) && (y > 29 && y < 40))
		return FALSE;      //å��

	else if ((x > 114 && x < 134) && (y >= 3 && y < 4))
		return DOOR3TO2;      //��
	else if ((x > 54 && x < 94) && (y > 39 && y <= Y_MAX))
		return FALSE;      //ĥ��
	else if ((x >= 94 && x < 122) && (y >= 40 && y <= Y_MAX))
		return NPCPROFESSOR;      //������

	else
		return TRUE;
}
void EventDoor3To2(Player * player)
{
	player->location = SCHOOL;

	player->x = 124;
	player->y = 30;

	system("cls");

	PrintSchool(*player);
}

void EventNPCProfessor(Player * player)
{
	char key;
	int count = 0;

	if (player->tutorial_professor == TRUE) {
		player->tutorial_professor = FALSE;
		img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventProfessor1.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				system("cls");      //ȭ�� �����

				PrintJeonsan(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
				break;
			}
		}
	}

	else if (player->item.report == TRUE)
	{
		img(0, 0, 1280, 720, L"./image/Map/Jeonsan/Ending.bmp");
		player->finish = TRUE;
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				
				system("cls");      //ȭ�� �����

				break;
			}
		}
	}

	else {
		count = 0;
		img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventProfessor2.bmp");
		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}

			else {
				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventProfessor3.bmp");
				key = getch();
				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/Question1.bmp");
				key = getch();
				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/Question1Ans.bmp");
				key = getch();

				if (key == '3')
				{
					img(0, 0, 1280, 720, L"./image/Map/Jeonsan/Question2.bmp");
					key = getch();
					img(0, 0, 1280, 720, L"./image/Map/Jeonsan/Question2Ans.bmp");
					key = getch();
					if (key == '3')
					{
						img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventCorrect.bmp");
						getch();

						system("cls");      //ȭ�� �����

						PrintJeonsan(*player);

						img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //�����ִ��ڸ��� ĳ���� ���
						break;
					}
					else
					{
						count++;
						if (count == 1)
						{
							img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventWrong1.bmp");
							getch();
						}
						else if (count == 2)
						{
							img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventWrong2.bmp");
							getch();
							break;
						}
					}
				}

				else
				{
					count++;
					if (count == 1)
					{
						img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventWrong1.bmp");
						getch();
					}
					else if (count == 2)
					{
						img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventWrong2.bmp");
						getch();
						break;
					}
				}
				
			}
		}
	}
	system("cls");

	PrintJeonsan(*player);

	img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");
}

void EventUSB(Player * player)
{
	char key;

	

	img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventUSB1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}
		else
		{
			if (key == '1')
			{
				player->item.usb = TRUE;
				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventUSB2.bmp");

				key = getch();

				while (1) {
					if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
					{
						key = getch();
					}
					else
					{
						img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventUSBFind.bmp");

						key = getch();

						while (1) {
							if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
							{
								key = getch();
							}
							else
								break;
						}
					}
						break;
				}

				break;
			}

			else
				break;

		}

	}

	system("cls");

	PrintJeonsan(*player);

	img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");
}

void EventUSB1(Player player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventUSB1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}
		else
		{
			if (key == '1')
			{
				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventUSB2.bmp");

				key = getch();

				while (1) {
					if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
					{
						key = getch();
					}
					else
					{
						img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventUSBFake.bmp");

						key = getch();

						while (1) {
							if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
							{
								key = getch();
							}
							else
								break;
						}
					}
					break;
				}

				break;
			}

			else
				break;

		}

	}

	system("cls");

	PrintJeonsan(player);

	img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
}

void EventWallet(Player * player)
{
	char key;

	

	img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventWallet1.bmp");

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			key = getch();

		else
		{
			if (key == '1')
			{
				player->item.piece4 = TRUE;

				if (player->item.piece1 == TRUE && player->item.piece2 == TRUE && player->item.piece3 == TRUE && player->item.piece4 == TRUE && player->item.piece5 == TRUE)
				{
					player->item.piece1 = FALSE;
					player->item.piece2 = FALSE;
					player->item.piece3 = FALSE;
					player->item.piece4 = FALSE;
					player->item.piece5 = FALSE;
					player->item.card = TRUE;
				}

				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventWallet2.bmp");

				key = getch();

				while (1) {
					if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
					{
						key = getch();
					}
					else
						break;
				}

				break;
			}
			else
				break;

		}

	}

	system("cls");

	PrintJeonsan(*player);

	img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");
}