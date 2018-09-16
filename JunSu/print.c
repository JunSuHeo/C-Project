/*
모듈의 기능 : 각종 출력해주는 기능
버전 : v1.6
개발자 : 김중재
최종 수정일 : 2018. 6. 9
*/

#include "print.h"

void PrintLoading()		//로딩화면 출력
{
	system("cls");

	printf("\n\n\n\n\n\n\n\n\n\n");

	puts("          ■                ■■■              ■        ■■■■        ■    ■■        ■        ■■■■    ");
	puts("          ■              ■      ■            ■        ■      ■      ■    ■■        ■      ■        ■  ");
	puts("          ■            ■          ■        ■  ■      ■        ■    ■    ■  ■      ■    ■              ");
	puts("          ■            ■          ■        ■  ■      ■        ■    ■    ■  ■      ■    ■              ");
	puts("          ■            ■          ■      ■      ■    ■        ■    ■    ■    ■    ■    ■    ■■■■  ");
	puts("          ■            ■          ■      ■      ■    ■        ■    ■    ■    ■    ■    ■          ■  ");
	puts("          ■            ■          ■      ■■■■■    ■        ■    ■    ■      ■  ■    ■          ■  ");
	puts("          ■            ■          ■    ■          ■  ■        ■    ■    ■      ■  ■    ■          ■  ");
	puts("          ■              ■      ■      ■          ■  ■      ■      ■    ■        ■■      ■      ■■  ");
	puts("          ■■■■■■      ■■■        ■          ■  ■■■■        ■    ■        ■■        ■■■  ■  ");

	Sleep(1000);
	system("cls");
	printf("\n\n\n\n\n\n\n\n");
	printf("                                                                준수오니?게임에 오신것을 환영합니다.\n\n");
	printf("                                                         준수오니?게임은 방탈출게임과 비슷한 게임입니다.\n");
	printf("                                           방안에있는 물건들에는 각각의 단서가 숨어있을수도 있고 단서가 없을수도 있습니다.\n\n");
	printf("                                                              현재 우리의 시간 4분은 게임의 하루입니다.\n");
	printf("                                                             0 분 ~ 0분 59초 : 00:00A.M. ~ 06:00A.M.(낮)\n");
	printf("                                                             1분 ~ 1분 59초 : 06:00A.M. ~ 12:00P.M.(낮)\n");
	printf("                                                             2분 ~ 2분 59초 : 12:00P.M. ~ 06:00P.M.(밤)\n");
	printf("                                                             3분 ~ 3분 59초 : 06:00P.M. ~ 12:00A.M.(밤)\n\n");
	printf("                                                             밤이되면 학교 건물에 출입을 하지 못합니다.\n");
	printf("                                        하루가 지나면 다시 방으로 돌아오게되며, 그때까지 찾은 단서들은 그대로 유지가 됩니다.\n");
	printf("                                       게임 클리어는 과제제출을 하는것이고 과제제출을 할수있게 단서를 찾고, 과제를 모으세요!\n\n\n");
	printf("                                                             made by 허준수, 정윤재, 이완석, 김중재\n\n\n");

	system("pause");
}

void PrintMenu()		//메뉴 출력
{
	int x = 1;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (int i = 1; i < 12; i++)
	{
		b[i] = 0xa0 + i;
	}
	gotoxy(30, 18);
	printf("%c%c", a, b[3]);
	for (int i = 0; i < 69; i++)
	{
		gotoxy(31 + i, 18);
		printf("%c%c", a, b[1]);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoxy(30, 19 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(100, 18);
	printf("%c%c", a, b[4]);
	for (int i = 0; i < 7; i++)
	{
		gotoxy(100, 19 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(30, 26);
	printf("%c%c", a, b[6]);
	gotoxy(100, 26);
	printf("%c%c", a, b[5]);
	for (int i = 0; i < 68; i++)
	{
		gotoxy(32 + i, 26);
		printf("%c%c", a, b[1]);
	}
	//
	gotoxy(35, 20);
	printf("%c%c", a, b[3]);
	gotoxy(95, 20);
	printf("%c%c", a, b[4]);
	gotoxy(35, 24);
	printf("%c%c", a, b[6]);
	gotoxy(95, 24);
	printf("%c%c", a, b[5]);
	//
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 20);
		printf("%c%c", a, b[1]);
	}
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 24);
		printf("%c%c", a, b[1]);
	}
	//
	for (int i = 0; i < 3; i++)
	{
		gotoxy(35, 21 + i);
		printf("%c%c", a, b[2]);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(95, 21 + i);
		printf("%c%c", a, b[2]);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(65, 21 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(65, 20);
	printf("%c%c", a, b[8]);
	gotoxy(65, 24);
	printf("%c%c", a, b[10]);
	gotoxy(46, 22);
	printf("1. 로그인");
	gotoxy(75, 22);
	printf("2. 불러오기");
	gotoxy(36, 25);
	printf("3. 회원가입");
	gotoxy(65, 25);
	printf("4. 랭킹보기");
}

void PrintIntro()		//인트로 출력
{
	system("cls");
	printf("\n\n\n");
	puts("                        ■■■■■■■                 ■                ■■■           ■                  ■");
	puts("                            ■  ■                   ■  ■             ■    ■          ■                  ■");
	puts("                           ■    ■                 ■    ■          ■        ■        ■                  ■");
	puts("                          ■      ■               ■      ■         ■        ■        ■                  ■");
	puts("                         ■        ■             ■        ■        ■        ■        ■                  ■");
	puts("                                                                        ■    ■          ■                  ■");
	puts("                      ■■■■■■■■■        ■■■■■■■■         ■■■           ■                  ■");
	puts("                              ■                       ■                  ■             ■                  ■");
	puts("                      ■      ■                       ■                  ■             ■■■■■■■■    ■");
	puts("                      ■      ■                       ■                  ■                                 ■");
	puts("                      ■■■■■■■■■               ■           ■■■■■■■■                          ■");
}

void PrintAt(int x, int y, char *str)	//위치 지정해서 출력
{
	gotoxy(x, y);
	printf("%s", str);
}

void PrintRoom_Sun(Player player)		//방 출력
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/Room/Room_Sun.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/Room/Room_Sun.bmp");
}

void PrintRoom_Moon(Player player)
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/Room/Room_Moon.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/Room/Room_Moon.bmp");
}

void PrintInventory(Player player)		//인벤토리 출력
{
	int x, y;

	x = 125;
	y = 0;

	PrintAt(x, y++, "       인벤토리  ");
	PrintAt(x, y++, "    <해당숫자 입력>");
	if (player.item.phone == TRUE)   PrintAt(x, y++, "       1. 핸드폰");
	if (player.item.usb == TRUE)   PrintAt(x, y++, "       2. USB");
	if (player.item.water == TRUE)   PrintAt(x, y++, "       3. 준水");
	if (player.item.shoes == TRUE)   PrintAt(x, y++, "       4. 축구화");
	if (player.item.piece1 == TRUE)   PrintAt(x, y++, "       5. 기억의조각1");
	if (player.item.piece2 == TRUE)   PrintAt(x, y++, "       6. 기억의조각2");
	if (player.item.piece3 == TRUE)   PrintAt(x, y++, "       7. 기억의조각3");
	if (player.item.piece4 == TRUE)   PrintAt(x, y++, "       8. 기억의조각4");
	if (player.item.piece5 == TRUE)   PrintAt(x, y++, "       9. 기억의조각5");
	if (player.item.card == TRUE)   PrintAt(x, y++, "       10. 학생증");
	if (player.item.quest1 == TRUE) PrintAt(x, y++, "       11. 과제의조각1");
	if (player.item.quest2 == TRUE) PrintAt(x, y++, "       12. 과제의조각2");
	if (player.item.quest3 == TRUE) PrintAt(x, y++, "       13. 과제의조각3");
	if (player.item.report == TRUE) PrintAt(x, y++, "       14. 과제");
}

void PrintSleep()		//자는모양 출력
{
	int x = 0;
	int y = 0;
	int rnd;
	int i;

	srand((unsigned int)time(NULL));

	rnd = rand() & 4 + 1;		//랜덤값 구하고

	system("cls");

	for (i = 0; i < 10; i++) {		//자는모양 출력
		rnd = rand() & 4;
		PrintAt(x + rnd, y  , "         ■■■■■■■■■■■■■■                 ■■■■■■■■■■■■■■            ■■■■■■■■■■■■■■");
		PrintAt(x + rnd, y+1, "         ■■■■■■■■■■■■■■                 ■■■■■■■■■■■■■■            ■■■■■■■■■■■■■■");
		PrintAt(x + rnd, y+2, "                             ■■■■                                     ■■■■                                ■■■■");
		PrintAt(x + rnd, y+3, "                         ■■■■                                     ■■■■                                ■■■■");
		PrintAt(x + rnd, y+4, "                     ■■■■                                     ■■■■                                ■■■■");
		PrintAt(x + rnd, y+5, "                 ■■■■                                     ■■■■                                ■■■■");
		PrintAt(x + rnd, y+6, "             ■■■■                                     ■■■■                                ■■■■");
		PrintAt(x + rnd, y+7, "         ■■■■                                     ■■■■                                ■■■■");
		PrintAt(x + rnd, y+8, "         ■■■■■■■■■■■■■                   ■■■■■■■■■■■■■■            ■■■■■■■■■■■■■■");
		PrintAt(x + rnd, y+9, "         ■■■■■■■■■■■■■                   ■■■■■■■■■■■■■■            ■■■■■■■■■■■■■■");
		Sleep(500);
		system("cls");
	}
}

void PrintHowToPlay() {
	int x = 128;
	int y = 30;

	PrintAt(x, y++, "     방향키\n");
	PrintAt(x, y++, "       ▲    \n");
	PrintAt(x, y++, "     ◀  ▶  \n");
	PrintAt(x, y++, "       ▼    ");
}

void PrintSchool(Player player)
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/School/School.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/School/School.bmp");
}

void PrintJeonsan(Player player)
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/JeonSan/JeonSan.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/JeonSan/JeonSan.bmp");
}

void PrintE87(Player player)
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/E87/E87.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/E87/E87.bmp");
}

void PrintHakyeon(Player player)
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/Hakyeon/Hakyeon.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/Hakyeon/Hakyeon.bmp");
}

void PrintS14(Player player)
{
	PrintInventory(player);		//인벤토리 출력
	PrintHowToPlay();		//게임 방법 출력
	img(0, 0, 1500, 1100, L"./image/Map/S14/S14.bmp");
	img(0, 0, 1500, 1100, L"./image/Map/S14/S14.bmp");
}

void PrintRank()
{
	FILE *fp;
	char tmp_name[16];
	int tmp_time;
	int count = 0;
	int i = 0;
	char rank1_name[16] = {"\0"};
	int rank1_time = 100000;
	char rank2_name[16] = { "\0" };
	int rank2_time = 100000;
	char rank3_name[16] = { "\0" };
	int rank3_time = 100000;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (int i = 1; i < 12; i++)
	{
		b[i] = 0xa0 + i;
	}

	system("cls");
	PrintIntro();
	gotoxy(30, 18);
	printf("%c%c", a, b[3]);
	for (int i = 0; i < 69; i++)
	{
		gotoxy(31 + i, 18);
		printf("%c%c", a, b[1]);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoxy(30, 19 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(100, 18);
	printf("%c%c", a, b[4]);
	for (int i = 0; i < 7; i++)
	{
		gotoxy(100, 19 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(30, 26);
	printf("%c%c", a, b[6]);
	gotoxy(100, 26);
	printf("%c%c", a, b[5]);
	for (int i = 0; i < 68; i++)
	{
		gotoxy(32 + i, 26);
		printf("%c%c", a, b[1]);
	}
	//
	gotoxy(35, 20);
	printf("%c%c", a, b[3]);
	gotoxy(95, 20);
	printf("%c%c", a, b[4]);
	gotoxy(35, 24);
	printf("%c%c", a, b[7]);
	gotoxy(95, 24);
	printf("%c%c", a, b[9]);
	gotoxy(35, 26);
	printf("%c%c", a, b[10]);
	gotoxy(95, 26);
	printf("%c%c", a, b[10]);
	gotoxy(35, 25);
	printf("%c%c", a, b[2]);
	gotoxy(95, 25);
	printf("%c%c", a, b[2]);
	//
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 20);
		printf("%c%c", a, b[1]);
	}
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 24);
		printf("%c%c", a, b[1]);
	}
	//
	for (int i = 0; i < 3; i++)
	{
		gotoxy(35, 21 + i);
		printf("%c%c", a, b[2]);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(95, 21 + i);
		printf("%c%c", a, b[2]);
	}
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 22);
		printf("%c%c", a, b[1]);
	}
	//
	gotoxy(48, 20);
	printf("%c%c", a, b[8]);
	gotoxy(48, 21);
	printf("%c%c", a, b[2]);
	gotoxy(48, 22);
	printf("%c%c", a, b[11]);
	gotoxy(48, 23);
	printf("%c%c", a, b[2]);
	gotoxy(48, 24);
	printf("%c%c", a, b[7]);
	gotoxy(48, 25);
	printf("%c%c", a, b[2]);
	gotoxy(48, 26);
	printf("%c%c", a, b[10]);
	//
	gotoxy(36, 19);
	printf("                         < 랭킹 관>");
	gotoxy(37, 21);
	printf("     1등   ");
	gotoxy(37, 23);
	printf("     2등   ");
	gotoxy(37, 25);
	printf("     3등   ");

	fp = fopen("rank.txt", "r");

	if (fp == NULL)
	{
		system("cls");
		printf("아직까지 플레이를 완료한 회원이 없습니다!");
	}
	
	else
	{
		while (fscanf(fp, "%s %d", tmp_name, &tmp_time) != EOF) {
			count++;
			if (rank1_time > tmp_time) {
				rank1_time = tmp_time;
				strcpy(rank1_name, tmp_name);
			}
		}

		fclose(fp);

		fp = fopen("rank.txt", "r");

		while (fscanf(fp, "%s %d", tmp_name, &tmp_time) != EOF) {
			count++;
			if (rank2_time > tmp_time) {
				if (tmp_time == rank1_time)
					continue;
				else {
					rank2_time = tmp_time;
					strcpy(rank2_name, tmp_name);
				}
			}
		}

		fclose(fp);

		fp = fopen("rank.txt", "r");

		while (fscanf(fp, "%s %d", tmp_name, &tmp_time) != EOF) {
			count++;
			if (rank3_time > tmp_time) {
				if (tmp_time == rank1_time || tmp_time == rank2_time)
					continue;
				else {
					rank3_time = tmp_time;
					strcpy(rank3_name, tmp_name);
				}
			}
		}

		fclose(fp);

		gotoxy(50, 21);
		printf("%s  %d초", rank1_name, rank1_time);
		if (rank2_time != 100000)
		{
			gotoxy(50, 23);
			printf("%s  %d초", rank2_name, rank2_time);
		}
		if (rank3_time != 100000)
		{
			gotoxy(50, 25);
			printf("%s  %d초", rank3_name, rank3_time);
		}
	}

	Sleep(5000);
}

void PrintLogIn()
{
	char ID[20];
	char PASSWORD[20];
	int x = 1;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (int i = 1; i < 12; i++)
	{
		b[i] = 0xa0 + i;
	}

	system("cls");
	printf("\n\n\n");
	puts("                        ■■■■■■■                 ■                ■■■           ■                  ■");
	puts("                            ■  ■                   ■  ■             ■    ■          ■                  ■");
	puts("                           ■    ■                 ■    ■          ■        ■        ■                  ■");
	puts("                          ■      ■               ■      ■         ■        ■        ■                  ■");
	puts("                         ■        ■             ■        ■        ■        ■        ■                  ■");
	puts("                                                                        ■    ■          ■                  ■");
	puts("                      ■■■■■■■■■        ■■■■■■■■         ■■■           ■                  ■");
	puts("                              ■                       ■                  ■             ■                  ■");
	puts("                      ■      ■                       ■                  ■             ■■■■■■■■    ■");
	puts("                      ■      ■                       ■                  ■                                 ■");
	puts("                      ■■■■■■■■■               ■           ■■■■■■■■                          ■");

	gotoxy(30, 18);
	printf("%c%c", a, b[3]);
	for (int i = 0; i < 69; i++)
	{
		gotoxy(31 + i, 18);
		printf("%c%c", a, b[1]);
	}
	for (int i = 0; i < 7; i++)
	{
		gotoxy(30, 19 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(100, 18);
	printf("%c%c", a, b[4]);
	for (int i = 0; i < 7; i++)
	{
		gotoxy(100, 19 + i);
		printf("%c%c", a, b[2]);
	}
	gotoxy(30, 26);
	printf("%c%c", a, b[6]);
	gotoxy(100, 26);
	printf("%c%c", a, b[5]);
	for (int i = 0; i < 68; i++)
	{
		gotoxy(32 + i, 26);
		printf("%c%c", a, b[1]);
	}
	//
	gotoxy(35, 20);
	printf("%c%c", a, b[3]);
	gotoxy(95, 20);
	printf("%c%c", a, b[4]);
	gotoxy(35, 24);
	printf("%c%c", a, b[6]);
	gotoxy(95, 24);
	printf("%c%c", a, b[5]);
	//
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 20);
		printf("%c%c", a, b[1]);
	}
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 24);
		printf("%c%c", a, b[1]);
	}
	//
	for (int i = 0; i < 3; i++)
	{
		gotoxy(35, 21 + i);
		printf("%c%c", a, b[2]);
	}
	for (int i = 0; i < 3; i++)
	{
		gotoxy(95, 21 + i);
		printf("%c%c", a, b[2]);
	}
	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 22);
		printf("%c%c", a, b[1]);
	}
	//
	gotoxy(48, 20);
	printf("%c%c", a, b[8]);
	gotoxy(48, 21);
	printf("%c%c", a, b[2]);
	gotoxy(48, 22);
	printf("%c%c", a, b[11]);
	gotoxy(48, 23);
	printf("%c%c", a, b[2]);
	gotoxy(48, 24);
	printf("%c%c", a, b[10]);
	gotoxy(36, 25);
	printf("           < 준수오니ID와 PASSWORD를 입력하시오 >");
	gotoxy(37, 21);
	printf("     ID    ");
	gotoxy(37, 23);
	printf("  PASSWORD ");
}

void Ending()
{
	firecracker_up();
	firecracker1();
	firecracker2();
	firecracker3();
	firecracker4();
	firecracker5();
	firecracker6();
	firecracker7();
	firecracker8();
	for (int i = 0; i < 5; i++)
	{
		system("cls");
		firecracker1();
		firecracker2();
		firecracker3();
		firecracker4();
		firecracker5();
		firecracker6();
		firecracker7();
		firecracker8();
		Sleep(200);
	}
}


void firecracker_wall()
{
	int n = 40; //x
	int j = 26;//y
	int x = 1;
	unsigned char a = 0xa6;
	unsigned char b[12];

	for (int i = 1; i < 12; i++)
	{
		b[i] = 0xa0 + i;
	}
	//폭죽 기둥 
	//상단
	gotoxy(n + 2, j + 3);
	for (int i = 0; i < 6; i++)
		printf("%c%c", a, b[1]);
	//왼쪽
	gotoxy(n + 1, j + 3);
	printf("%c%c", a, b[3]);
	for (int k = 4; k < 7; k++)
	{
		gotoxy(n + 1, j + k);
		printf("%c%c", a, b[2]);
	}
	//바닥
	gotoxy(n + 1, j + 7);
	printf("%c%c", a, b[6]);
	gotoxy(n + 2, j + 7);
	for (int i = 0; i < 6; i++)
		printf("%c%c", a, b[1]);
	gotoxy(n + 7, j + 7);
	printf("%c%c", a, b[5]);
	//오른쪽
	for (int k = 4; k < 7; k++)
	{
		gotoxy(n + 7, j + k);
		printf("%c%c", a, b[2]);
	}
	gotoxy(n + 7, j + 3);
	printf("%c%c", a, b[4]);
	gotoxy(60, 30);
	printf("");
}
void firecracker_up()
{
	//45 30
	for (int i = 0; i < 28; i++)
	{
		system("cls");
		gotoxy(45, 28 - i);
		printf("★");
		firecracker_wall();
		Sleep(50);
	}
}
void firecracker1()
{
	int x = 0;
	int y = 0;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker2()
{
	int x = 20;
	int y = 5;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker3()
{
	int x = -20;
	int y = 5;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker4()
{
	int x = 0;
	int y = 10;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker5()
{
	int x = -24;
	int y = -4;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker6()
{
	int x = 24;
	int y = -4;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker7()
{
	int x = -22;
	int y = 16;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}
void firecracker8()
{
	int x = 22;
	int y = 16;
	gotoxy(45 + x, 8 + y);
	printf("★");
	for (int i = 0; i < 3; i++)
	{
		//위
		gotoxy(45 + x, 6 - i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 6 - i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 7 - i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 6 - i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 7 - i + y);
		printf("★");
		//아래
		gotoxy(45 + x, 10 + i + y);
		printf("★");
		gotoxy(43 + x - (2 * i), 10 + i + y);
		printf("★");
		gotoxy(41 + x - (2 * i), 9 + i + y);
		printf("★");
		gotoxy(47 + x + (2 * i), 10 + i + y);
		printf("★");
		gotoxy(49 + x + (2 * i), 9 + i + y);
		printf("★");
	}
}