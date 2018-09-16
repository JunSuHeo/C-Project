/*
����� ��� : ���� �÷���
���� : v1.11
������ : ���ؼ�
���� ������ : 2018. 6. 9
*/

#include "playgame.h"
#include "EventItem.h"
#include "EventSchool.h"
#include "EventHome.h"
#include "EventE87.h"
#include "EventHakyeon.h"
#include "EventS14.h"
#include "Event.h"
#include "print.h"
#include "Util.h"

extern Player player;

int PlayGame(short tutorial)
{
	HANDLE hThread = NULL;
	char key;
	int count = 1;
	int state;
	char subkey;
	
	if (tutorial == -1)
	{
		switch (player.location)
		{
		case ROOM :
			if (player.sun == TRUE)
			{
				PrintRoom_Sun(player);
				img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			}

			else
			{
				PrintRoom_Moon(player);
				img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			}
			break;
		case SCHOOL :
			PrintSchool(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		case JEONSAN :
			PrintJeonsan(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		case S14 :
			PrintS14(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		case E87 :
			PrintE87(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		case HAKYEON :
			PrintHakyeon(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		}

		hThread = _beginthreadex(NULL, 0, Thread, &player, 0, NULL);
	}

	else {
		InitPlayer();
		PrintRoom_Sun(player);
		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");	//ó�� ĳ���� ���

		hThread = _beginthreadex(NULL, 0, Thread, &player, 0, NULL);
	}
	
	while (player.finish != TRUE) {		//������ ���������� �ݺ�.
		key = getch();		//Ű�Է� ���

		if (key == 'p')						//p�� ������ �Ͻ�����
		{
			break;
		}

		else if (key == '1')
		{
			EventPhone(player);
		}

		else if (key == 72)					//Ű���� ������
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//ĳ������ �޸���� ����Ѵ�.
			img(player.x, player.y, 1280, 720, L"./image/Character/back1.bmp");
			
			count++;

			while (GetKeyState(VK_UP) < 0) {	//Ű���尡 �����ִ� �����̸�

				state = CheckEventUp(&player);	//�������� ������ �浹Ȯ��

				if (state == TRUE)			//�浹�� ���ٸ� ĳ���� ��� ���
				{
					
					if (count == 1)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, --player.y, 1280, 720, L"./image/Character/back1.bmp");
					
						Sleep(100);
					}
					else if (count == 2)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, --player.y, 1280, 720, L"./image/Character/back2.bmp");
					
						Sleep(100);
					}
					else if (count == 3)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, --player.y, 1280, 720, L"./image/Character/back3.bmp");
						
						Sleep(100);
					}
					else if (count == 4)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, --player.y, 1280, 720, L"./image/Character/back4.bmp");
						
						Sleep(100);
					}

					count++;
					if (count == 5)
						count = 1;
				}
			}
		}

		else if (key == 75)					//Ű���� ���ʹ���
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//ĳ������ ���ʸ���� ����Ѵ�.
			img(player.x, player.y, 1280, 720, L"./image/Character/left1.bmp");

			count++;
			
			while (GetKeyState(VK_LEFT) < 0) {	//Ű���尡 �����ִ� �����̸�

				state = CheckEventLeft(&player);		//�������� ������ �浹 Ȯ��

				if (state == TRUE)					//�浹�� ���ٸ�
				{
					
					if (count == 1)					//ĳ���� ���
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x -= 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/left1.bmp");
						
						Sleep(100);
					}
					else if (count == 2)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x -= 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/left2.bmp");
						Sleep(100);
					}
					else if (count == 3)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x -= 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/left3.bmp");
						Sleep(100);
					}
					else if (count == 4)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x -= 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/left4.bmp");
						Sleep(100);
					}

					count++;
					if (count == 5)
						count = 1;
				}
			}
		}

		else if (key == 77)					//Ű���� �����ʹ���
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//ĳ������ �����ʸ���� ����Ѵ�.
			img(player.x, player.y, 1280, 720, L"./image/Character/right1.bmp");

			count++;

			while (GetKeyState(VK_RIGHT) < 0) {	//Ű���尡 �����ִ� �����̸�

				state = CheckEventRight(&player);		//���������� ���� �浹 Ȯ��

				if (state == TRUE)						//�浹�� ���ٸ�
				{
					if (count == 1)						//ĳ���� ���
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x += 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/right1.bmp");
						Sleep(100);
					}
					else if (count == 2)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x += 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/right2.bmp");
						Sleep(100);
					}
					else if (count == 3)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x += 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/right3.bmp");
						Sleep(100);
					}
					else if (count == 4)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						player.x += 2;
						img(player.x, player.y, 1280, 720, L"./image/Character/right4.bmp");
						Sleep(100);
					}
					count++;
					if (count == 5)
						count = 1;
				}
			}

		}

		else if (key == 80)					//Ű���� �Ʒ�����
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//ĳ������ �ո���� ����Ѵ�.
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");

			count++;

			while (GetKeyState(VK_DOWN) < 0) {	//Ű���尡 �����ִ� �����̸�

				state = CheckEventDown(&player);		//�Ʒ��� ������ �浹 Ȯ��

				if (state == TRUE)					//�浹�� ���ٸ�
				{
					if (count == 1)					//ĳ���� ���
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, ++player.y, 1280, 720, L"./image/Character/front1.bmp");
						Sleep(100);
					}
					else if (count == 2)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, ++player.y, 1280, 720, L"./image/Character/front2.bmp");
						Sleep(100);
					}
					else if (count == 3)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, ++player.y, 1280, 720, L"./image/Character/front3.bmp");
						Sleep(100);
					}
					else if (count == 4)
					{
						img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");
						img(player.x, ++player.y, 1280, 720, L"./image/Character/front4.bmp");
						Sleep(100);
					}
					
					count++;
					if (count == 5)
						count = 1;
				}
			}

		}
	}
	SuspendThread(hThread);

	if (player.finish == TRUE) return FALSE;
	else return TRUE;
}

void InitPlayer()
{
	player.x = 20;				//�ʱⰪ ����.
	player.y = 10;
	player.location = ROOM;
	player.tutorial_school = TRUE;
	player.tutorial_professor = TRUE;
	player.tutorial_quest1 = TRUE;		//�ϼ�����Ʈ
	player.tutorial_quest2 = TRUE;		//��������Ʈ
	player.tutorial_quest3 = TRUE;		//��������Ʈ
	player.finish = FALSE;				
	player.sun = TRUE;
	player.item.phone = TRUE;
	player.item.usb = FALSE;
	player.item.water = FALSE;
	player.item.piece1 = FALSE;
	player.item.piece2 = FALSE;
	player.item.piece3 = FALSE;
	player.item.piece4 = FALSE;
	player.item.piece5 = FALSE;
	player.item.quest1 = FALSE;
	player.item.quest2 = FALSE;
	player.item.quest3 = FALSE;
	player.item.report = FALSE;
	player.item.shoes = FALSE;
	player.item.card = FALSE;
	player.play_time.day = 0;
	player.play_time.minuite = 0;
	player.play_time.second = 0;
}