/*
����� ��� : ���� �÷����ϱ����� �ʿ��� ���� ���
���� : v1.4
������ : ������
���������� : 2018. 6. 9
*/

#include "Util.h"

void erase_cursor(void)
{
	CONSOLE_CURSOR_INFO CurInfo;

	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void img(int x, int y, int mx, int my, wchar_t *temp)
{
	x = 8 * x;      //x��ġ
	y = 18 * y;      //y��ġ
	mx = 8 * mx;
	my = 18 * my;

	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	HBITMAP hImage, hOldBitmap;
	HDC hMemDC = CreateCompatibleDC(mydc);

	//�̹��� �ε�
	hImage = (HBITMAP)LoadImage(NULL, temp, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	//�̹��� ��� �κ�
	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);
	BitBlt(mydc, x, y, mx, my, hMemDC, 0, 0, SRCCOPY);

	//���� �޸� ����
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
	ReleaseDC(myconsole, mydc);
}

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

unsigned __stdcall Thread(Player *player)
{
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (int i = 1; i < 12; i++)
	{
		b[i] = 0xa0 + i;
	}

	while (1)
	{

		if (player->play_time.minuite != 4)
		{
			gotoxy(128, 17);
			printf("%c%c", a, b[3]);
			gotoxy(146, 17);
			printf("%c%c", a, b[4]);
			gotoxy(128, 22);
			printf("%c%c", a, b[6]);
			gotoxy(146, 22);
			printf("%c%c", a, b[5]);
			gotoxy(130, 18);
			printf("�Ϸ簡 �ݺ� ����");
			gotoxy(130, 19);
			printf("    %d�� °", player->play_time.day);
			gotoxy(130, 20);
			printf("���� �÷��� �ð�");
			gotoxy(130, 21);
			printf("   %2d��:%2d��", player->play_time.minuite, player->play_time.second);

			Sleep(1000);
			player->play_time.second++;

			if (player->play_time.second == 60)
			{
				player->play_time.second = 0;
				player->play_time.minuite++;
			}
		}

		else
		{
			player->play_time.day++;
			player->play_time.minuite = 0;
			player->play_time.second = 0;
			player->location = ROOM;
			PrintRoom_Sun(*player);
		}

		if (player->play_time.minuite == 2 && player->play_time.second == 0 )
		{
			player->sun = FALSE;

			if (player->location == ROOM)
				PrintRoom_Moon(*player);
		}

		else if (player->play_time.minuite == 0 && player->play_time.second%60 == 0)
		{
			player->sun = TRUE;

			if (player->location == ROOM)
				PrintRoom_Sun(*player);
		}
		/*player->play_time.day = current_day;
		player->play_time.minuite = current_minute;
		player->play_time.second = current_second;*/
	}

}

void sound()
{
	PlaySound(L"./sound/test.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
}

void SoundStop()
{
	PlaySound(NULL, 0, 0);
}

unsigned __stdcall Thread2()
{
	HANDLE hIn, hOut;
	DWORD dwNOER;
	INPUT_RECORD rec;

	hIn = GetStdHandle(STD_INPUT_HANDLE);
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	return 0;
}
