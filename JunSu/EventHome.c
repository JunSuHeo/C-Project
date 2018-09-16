/*
모듈의 기능 : 방에서의 충돌처리
버전 : v1.2
개발자 : 허준수
최종 수정일 : 2018. 6. 1
*/
#include "EventHome.h"

int CheckEventRoom(int x, int y)
{
	if (x >= X_MAX)
		return BLOCK;
	else if (y >= Y_MAX)
		return BLOCK;
	else if (x <= 6)
		return BLOCK;
	else if (y < 3)
		return BLOCK;

	else if ((x > 32 && x < 50) && (y > 2 && y < 16))   // 벽1
		return BLOCK;
	else if ((x > 122 && x < 138) && (y > 4 && y < 16))   // 벽3
		return BLOCK;
	else if ((x > 116 && x <= X_MAX) && (y > 16 && y < 24))   // 벽4
		return BLOCK;
	else if ((x > 110 && x < 128) && (y > 27 && y <= Y_MAX))// 벽5
		return BLOCK;

	else if ((x > 6 && x <= 32) && (y > 2 && y < 10))   // 부엌
		return FALSE;
	else if ((x > 58 && x < 88) && (y > 2 && y < 7))   // 창문
		return WINDOW;
	else if ((x > 102 && x <= 122) && (y > 2 && y < 5))   // 에어컨
		return FALSE;
	else if ((x >= 138 && x <= X_MAX) && (y > 2 && y < 16))   // 화장실
		return TOILET;
	else if ((x >= 8 && x < 10) && (y > 16 && y < 22))   // 문
		return DOOR1TO2;
	else if ((x >56 && x < 88) && (y > 18 && y < 30))   // 책상
		return FALSE;
	else if ((x >140 && x <= X_MAX) && (y >= 24 && y < 31))   // 옷장
		return CLOTH;
	else if ((x > 6 && x < 16) && (y > 33 && y <= Y_MAX))   // 나무
		return FALSE;
	else if ((x > 58 && x < 86) && (y > 34 && y <= Y_MAX))   // TV
		return FALSE;
	else if ((x >= 128 && x < 140) && (y > 34 && y <= Y_MAX))   // 컴퓨터
		return COMPUTER;
	else if ((x > 144 && x <= X_MAX) && (y > 33 && y <= Y_MAX))   // 침대
		return BED;

	else
		return TRUE;
}


void EventBed(Player *player)
{
	char key;

	if (player->sun == TRUE)      //낮이라면 낮일때 침대이벤트 출력
		img(0, 0, 1280, 720, L"./image/Map/Room/BedEvent_Sun.bmp");
	else if (player->sun == FALSE)   //밤이라면 밤일때 침대이벤트 출력
		img(0, 0, 1280, 720, L"./image/Map/Room/BedEvent_Moon.bmp");

	key = getch();      //키입력 대기

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {

			if (key == '1') {      //잠을 잔다고 선택한다면
				PrintSleep();   //잠자는 모션

				system("cls");      //화면 지우고

				player->play_time.day += 1;
				player->play_time.minuite = 0;
				player->play_time.second = 0;

				player->sun = TRUE;

				PrintRoom_Sun(*player);

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");      //캐릭터 다시 출력
				break;
			}

			else {      //선택을 안하면
				system("cls");      //화면 지우고

				if (player->sun == TRUE)            //낮에 있었다면
					PrintRoom_Sun(*player);               //낮일때 방 출력

				else if (player->sun == FALSE) {      //밤에 있었다면

					PrintRoom_Moon(*player);               //밤일때 방 출력
				}

				img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");      //캐릭터 다시 출력
				break;

			}
		}
	}
}

void EventToilet(Player player)
{
	char key;

	if (player.sun == TRUE) {      //낮에 화장실에 왔다면 낮에 해당하는 이벤트 출력
		img(0, 0, 1280, 720, L"./image/Map/Room/ToiletEvent_Sun.bmp");
		img(140, 16, 1280, 720, L"./image/Character/Back1.bmp");
	}
	else {                     //밤에 화장실에 왔다면 밤에 해당하는 이벤트 출력
		img(0, 0, 1280, 720, L"./image/Map/Room/ToiletEvent_Moon.bmp");
		img(140, 16, 1280, 720, L"./image/Character/Back1.bmp");
	}

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}


		else {
			system("cls");      //화면 지우고

			if (player.sun == TRUE)      //낮일때는 시간이 낮인 방 출력
				PrintRoom_Sun(player);
			else if (player.sun == FALSE)   //밤일때는 시간이 밤인 방 출력
				PrintRoom_Moon(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		}
	}
}

void EventWindow(Player player)
{
	char key;

	if (player.sun == TRUE)
	{
		img(0, 0, 1280, 720, L"./image/Map/Room/WindowEvent_Sun.bmp");
	}

	else if (player.sun == FALSE)
	{
		img(0, 0, 1280, 720, L"./image/Map/Room/WindowEvent1_Moon.bmp");
		key = getch();
		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}
			else {
				img(0, 0, 1280, 720, L"./image/Map/Room/WindowEvent2_Moon.bmp");
				break;
			}
		}
	}

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}
		else {
			system("cls");      //화면 지우고

			if (player.sun == TRUE)      //낮일때는 시간이 낮인 방 출력
				PrintRoom_Sun(player);
			else if (player.sun == FALSE)   //밤일때는 시간이 밤인 방 출력
				PrintRoom_Moon(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		}
	}
}

void EventCloth(Player player)
{
	char key;

	if (player.sun == TRUE)
	{
		img(0, 0, 1280, 720, L"./image/Map/Room/ClothEvent_Sun.bmp");
	}

	else if (player.sun == FALSE)
	{
		img(0, 0, 1280, 720, L"./image/Map/Room/ClothEvent_Moon.bmp");
	}

	key = getch();

	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}

		else {
			system("cls");      //화면 지우고

			if (player.sun == TRUE)      //낮일때는 시간이 낮인 방 출력
				PrintRoom_Sun(player);
			else if (player.sun == FALSE)   //밤일때는 시간이 밤인 방 출력
				PrintRoom_Moon(player);
			img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
			break;
		}
	}
}

void EventComputer(Player *player)
{
	char key;

	img(0, 0, 1280, 720, L"./image/Map/Room/EventComputer.bmp");
	key = getch();
	while (1) {
		if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
		{
			key = getch();
		}
		else
		{
			if (player->sun == TRUE)
			{
				img(0, 0, 1280, 720, L"./image/Map/Room/Remember1_Sun.bmp");
			}

			else if (player->sun == FALSE)
			{
				img(0, 0, 1280, 720, L"./image/Map/Room/Remember1_Moon.bmp");
			}

			key = getch();

			player->item.piece1 = TRUE;

			if (player->item.piece1 == TRUE && player->item.piece2 == TRUE && player->item.piece3 == TRUE && player->item.piece4 == TRUE && player->item.piece5 == TRUE)
			{
				player->item.piece1 = FALSE;
				player->item.piece2 = FALSE;
				player->item.piece3 = FALSE;
				player->item.piece4 = FALSE;
				player->item.piece5 = FALSE;
				player->item.card = TRUE;
			}

			while (1) {
				if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
				{
					key = getch();
				}

				else {
					system("cls");      //화면 지우고

					if (player->sun == TRUE)      //낮일때는 시간이 낮인 방 출력
						PrintRoom_Sun(*player);

					else if (player->sun == FALSE)   //밤일때는 시간이 밤인 방 출력
						PrintRoom_Moon(*player);

					img(player->x, player->y, 1280, 720, L"./image/Character/front1.bmp");   //원래있던자리에 캐릭터 출력
					break;
				}
			}
			break;
		}
	}
}

void EventDoor1To2(Player * player)
{
	char key;

	if (player->tutorial_school == TRUE)
	{
		player->tutorial_school = FALSE;

		img(0, 0, 1280, 720, L"./image/Map/School/first.bmp");

		key = getch();

		while (1) {
			if (GetKeyState(VK_UP) < 0 || GetKeyState(VK_DOWN) < 0 || GetKeyState(VK_LEFT) < 0 || GetKeyState(VK_RIGHT) < 0)
			{
				key = getch();
			}
			else
				break;
		}

		img(0, 0, 1280, 720, L"./image/Map/School/GotoHome.bmp");

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

	player->location = SCHOOL;

	player->x = 130;
	player->y = 20;

	system("cls");

	PrintSchool(*player);
}