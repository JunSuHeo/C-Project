/*
모듈의 기능 : 아이템사용
버전 : v1.3
개발자 : 이완석
최종 수정일 : 2018. 6. 6
*/
#include "EventItem.h"

void EventPhone(Player player)
{
	char subkey;

	if (player.location == SCHOOL)
	{
		img(0, 0, 1280, 720, L"./image/Map/School/EventPocket.bmp");
		subkey = getch();

		if (subkey == '1')
		{
			img(0, 0, 1280, 720, L"./image/Map/School/EventPhone.bmp");
			subkey = getch();

			if (GetKeyState(VK_RIGHT) < 0)
			{
				img(0, 0, 1280, 720, L"./image/Map/School/EventPhoneSelect.bmp");

				subkey = getch();		//버퍼때문에 두번실행
				subkey = getch();

				if (subkey == '1')
				{
					subkey = 0;
					img(0, 0, 1280, 720, L"./image/Map/School/EventKakao.bmp");
					subkey = getch();
				}
			}
		}
		PrintSchool(player);
		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
	}

	else if (player.location == ROOM)
	{
		img(0, 0, 1280, 720, L"./image/Map/Room/EventPhone.bmp");
		subkey = getch();

		if (GetKeyState(VK_RIGHT) < 0)
		{
			img(0, 0, 1280, 720, L"./image/Map/Room/EventPhoneSelect.bmp");

			subkey = getch();		//버퍼때문에 두번실행
			subkey = getch();

			if (subkey == '1')
			{
				subkey = 0;
				img(0, 0, 1280, 720, L"./image/Map/Room/EventKakao.bmp");
				subkey = getch();
			}
		}

		if (player.sun == TRUE)	PrintRoom_Sun(player);

		else	PrintRoom_Moon(player);

		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
	}

	else if (player.location == S14)
	{
		img(0, 0, 1280, 720, L"./image/Map/S14/EventPhone.bmp");
		subkey = getch();

		if (GetKeyState(VK_RIGHT) < 0)
		{
			img(0, 0, 1280, 720, L"./image/Map/S14/EventPhoneSelect.bmp");

			subkey = getch();		//버퍼때문에 두번실행
			subkey = getch();

			if (subkey == '1')
			{
				subkey = 0;
				img(0, 0, 1280, 720, L"./image/Map/S14/EventKakao.bmp");
				subkey = getch();
			}
		}

		PrintS14(player);

		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
	}

	else if (player.location == JEONSAN)
	{
		img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventPhone.bmp");
		subkey = getch();

		if (GetKeyState(VK_RIGHT) < 0)
		{
			img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventPhoneSelect.bmp");

			subkey = getch();		//버퍼때문에 두번실행
			subkey = getch();

			if (subkey == '1')
			{
				subkey = 0;
				img(0, 0, 1280, 720, L"./image/Map/Jeonsan/EventKakao.bmp");
				subkey = getch();
			}
		}

		PrintJeonsan(player);

		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
	}

	else if (player.location == E87)
	{
		img(0, 0, 1280, 720, L"./image/Map/E87/EventPhone.bmp");
		subkey = getch();

		if (GetKeyState(VK_RIGHT) < 0)
		{
			img(0, 0, 1280, 720, L"./image/Map/E87/EventPhoneSelect.bmp");

			subkey = getch();		//버퍼때문에 두번실행
			subkey = getch();

			if (subkey == '1')
			{
				subkey = 0;
				img(0, 0, 1280, 720, L"./image/Map/E87/EventKakao.bmp");
				subkey = getch();
			}
		}

		PrintE87(player);

		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
	}

	else if (player.location == HAKYEON)
	{
		img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventPhone.bmp");
		subkey = getch();

		if (GetKeyState(VK_RIGHT) < 0)
		{
			img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventPhoneSelect.bmp");

			subkey = getch();		//버퍼때문에 두번실행
			subkey = getch();

			if (subkey == '1')
			{
				subkey = 0;
				img(0, 0, 1280, 720, L"./image/Map/Hakyeon/EventKakao.bmp");
				subkey = getch();
			}
		}

		PrintHakyeon(player);

		img(player.x, player.y, 1280, 720, L"./image/Character/front1.bmp");
	}
	
}
