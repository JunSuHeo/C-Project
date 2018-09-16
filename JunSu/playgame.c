/*
모듈의 기능 : 게임 플레이
버전 : v1.11
개발자 : 허준수
최종 수정일 : 2018. 6. 9
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
		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");	//처음 캐릭터 출력

		hThread = _beginthreadex(NULL, 0, Thread, &player, 0, NULL);
	}
	
	while (player.finish != TRUE) {		//게임이 끝날때까지 반복.
		key = getch();		//키입력 대기

		if (key == 'p')						//p를 누르면 일시정지
		{
			break;
		}

		else if (key == '1')
		{
			EventPhone(player);
		}

		else if (key == 72)					//키보드 윗방향
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//캐릭터의 뒷모습을 출력한다.
			img(player.x, player.y, 1280, 720, L"./image/Character/back1.bmp");
			
			count++;

			while (GetKeyState(VK_UP) < 0) {	//키보드가 눌려있는 상태이면

				state = CheckEventUp(&player);	//위쪽으로 갔을때 충돌확인

				if (state == TRUE)			//충돌이 없다면 캐릭터 계속 출력
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

		else if (key == 75)					//키보드 왼쪽방향
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//캐릭터의 왼쪽모습을 출력한다.
			img(player.x, player.y, 1280, 720, L"./image/Character/left1.bmp");

			count++;
			
			while (GetKeyState(VK_LEFT) < 0) {	//키보드가 눌려있는 상태이면

				state = CheckEventLeft(&player);		//왼쪽으로 갔을때 충돌 확인

				if (state == TRUE)					//충돌이 없다면
				{
					
					if (count == 1)					//캐릭터 출력
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

		else if (key == 77)					//키보드 오른쪽방향
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//캐릭터의 오른쪽모습을 출력한다.
			img(player.x, player.y, 1280, 720, L"./image/Character/right1.bmp");

			count++;

			while (GetKeyState(VK_RIGHT) < 0) {	//키보드가 눌려있는 상태이면

				state = CheckEventRight(&player);		//오른쪽으로 갈때 충돌 확인

				if (state == TRUE)						//충돌이 없다면
				{
					if (count == 1)						//캐릭터 출력
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

		else if (key == 80)					//키보드 아래방향
		{
			count = 1;

			img(player.x, player.y, 1280, 720, L"./image/Character/erase.bmp");			//캐릭터의 앞모습을 출력한다.
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");

			count++;

			while (GetKeyState(VK_DOWN) < 0) {	//키보드가 눌려있는 상태이면

				state = CheckEventDown(&player);		//아래로 갔을때 충돌 확인

				if (state == TRUE)					//충돌이 없다면
				{
					if (count == 1)					//캐릭터 출력
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
	player.x = 20;				//초기값 설정.
	player.y = 10;
	player.location = ROOM;
	player.tutorial_school = TRUE;
	player.tutorial_professor = TRUE;
	player.tutorial_quest1 = TRUE;		//완석퀘스트
	player.tutorial_quest2 = TRUE;		//윤재퀘스트
	player.tutorial_quest3 = TRUE;		//중재퀘스트
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