/*
모듈의 기능 : 로그인
버전 : v1.5
개발자 : 이완석
최종 수정일 : 2018. 6. 4
*/

#include "login.h"

Player player;

void JoinMember()
{
	FILE *fp;
	FILE *fp1;
	member tmp;
	char ID[100];
	char password[50];
	char name[16];
	int birth;
	int count = 0;
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
	gotoxy(35, 18);
	printf("%c%c", a, b[3]);
	gotoxy(35, 19);
	printf("%c%c", a, b[2]);
	gotoxy(35, 20);
	printf("%c%c", a, b[6]);
	//
	gotoxy(35, 22);
	printf("%c%c", a, b[3]);
	gotoxy(35, 23);
	printf("%c%c", a, b[2]);
	gotoxy(35, 24);
	printf("%c%c", a, b[6]);
	////
	gotoxy(95, 18);
	printf("%c%c", a, b[4]);
	gotoxy(95, 19);
	printf("%c%c", a, b[2]);
	gotoxy(95, 20);
	printf("%c%c", a, b[5]);
	//
	gotoxy(95, 22);
	printf("%c%c", a, b[4]);
	gotoxy(95, 23);
	printf("%c%c", a, b[2]);
	gotoxy(95, 24);
	printf("%c%c", a, b[5]);
	////
	////-----

	for (int i = 0; i < 59; i++)
	{
		gotoxy(36 + i, 22);
		printf("%c%c", a, b[1]);
	}
	////-----가운데
	gotoxy(65, 18);
	printf("%c%c", a, b[8]);
	gotoxy(65, 19);
	printf("%c%c", a, b[2]);
	gotoxy(65, 20);
	printf("%c%c", a, b[10]);
	//
	gotoxy(65, 22);
	printf("%c%c", a, b[8]);
	gotoxy(65, 23);
	printf("%c%c", a, b[2]);
	gotoxy(65, 24);
	printf("%c%c", a, b[10]);
	////왼쪽 아이디바
	gotoxy(48, 18);
	printf("%c%c", a, b[8]);
	gotoxy(48, 19);
	printf("%c%c", a, b[2]);
	gotoxy(48, 20);
	printf("%c%c", a, b[10]);
	//
	gotoxy(48, 22);
	printf("%c%c", a, b[8]);
	gotoxy(48, 23);
	printf("%c%c", a, b[2]);
	gotoxy(48, 24);
	printf("%c%c", a, b[10]);
	////오른쪽 아이디바
	gotoxy(78, 18);
	printf("%c%c", a, b[8]);
	gotoxy(78, 19);
	printf("%c%c", a, b[2]);
	gotoxy(78, 20);
	printf("%c%c", a, b[10]);
	//
	gotoxy(78, 22);
	printf("%c%c", a, b[8]);
	gotoxy(78, 23);
	printf("%c%c", a, b[2]);
	gotoxy(78, 24);
	printf("%c%c", a, b[10]);
	////
	gotoxy(37, 19);
	printf("    이름   ");
	gotoxy(67, 19);
	gotoxy(67, 19);
	printf("  생년월일 ");
	gotoxy(37, 23);
	printf("     ID    ");
	gotoxy(67, 23);
	printf("  PASSWORD ");
	gotoxy(36, 21);//이름
	printf("본인 이름을 입력하세요");
	gotoxy(66, 21);//생년월일
	printf("  -없이 숫자만 입력하세요 ");
	gotoxy(36, 25);//PASSWORD
	printf("(5글자 이상 특수문자 제외)");
	gotoxy(67, 25);//
	printf("영문/숫자를 조합하여 입력하세요");
	gotoxy(36, 17);
	printf("                 < 준수오니 회원가입란>");
	gotoxy(31, 27);
	printf("<준수오니> 가입시 서비스 이용약관, 개인정보 수집 및 이용에 모두 동의된다");
	gotoxy(50, 19);
	scanf(" %[^\n]s", name);
	gotoxy(80, 19);
	scanf("%d", &birth);
	gotoxy(50, 23);
	scanf(" %[^\n]s", ID);
	gotoxy(80, 23);
	scanf(" %[^\n]s", password);
	
	fp = fopen("member.txt", "r");		//파일을 읽기모드로 연다

	
	
	if (fp == NULL)						//파일이 없다면,
	{
		fp = fopen("member.txt", "w");	//쓰기모드로 파일을 새롭게 만든다.
		fprintf(fp, "%s %d %s %s",name, birth, ID, password);	//파일에 이름, 생년월일, ID, Password를 입력한다.

		fclose(fp);
	}
	
	else			//파일이 존재한다면,
	{
		while (fscanf(fp, "%s %d %s %s", tmp.name, &tmp.birth, tmp.ID, tmp.Password) != EOF)
			count++;

		if (count >= 5) {
			printf("더이상 회원을 만들수 없습니다.");
			Sleep(2000);
		}
		else {
			fp = fopen("member.txt", "a+");	//파일을 덧붙여서 쓴다.
			fprintf(fp, "\n%s %d %s %s", name, birth, ID, password);		//파일에 이름, 생년월일, ID, Password를 입력한다.

			fclose(fp);
		}
	}
}

int CheckID()
{
	FILE *fp;
	member mem[5];
	char ID[100] = "\0";
	char Password[50] = "\0";
	char name[16] = "\0";
	int birth = 0;
	int i = 0;
	short int boolean = 0;
	char CheckID[100];
	char CheckPassword[50];

	PrintLogIn();

	gotoxy(50, 21);
	scanf(" %[^\n]s", CheckID);

	gotoxy(50, 23);
	scanf(" %[^\n]s", CheckPassword);

	fp = fopen("member.txt", "r");		//파일을 읽기모드로 연다.

	if (fp != NULL)		//파일이 존재한다면
	{
		while (i < 5)		//파일을 한줄씩 읽는다.
		{
			fscanf(fp,"%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
			i++;
		}

		for (i = 0; i < 5; i++)
			if (!strcmp(mem[i].ID, CheckID) && !strcmp(mem[i].Password, CheckPassword)) {	//ID와 Password가 맞는지 체크한다.
				boolean = 1;		//ID와 Password가 일치한다면 boolean을 1로 한다.
				break;
			}

		fclose(fp);
	}

	else		//파일이 존재하지 않는다면
		printf("회원이 존재하지 않습니다.");

	if (boolean == 1)	//ID와 Password가 일치하는 회원을 찾았다면,
		return i;	

	else				//ID와 Password가 일치하지 않는다면
		return FALSE;	//FALSE 반환
}

void LogIn()
{
	FILE *fp;
	char key;
	int count = 0;
	char subkey = 0;
	int num = 0;
	int save = 0;

	while (subkey != 'r') {
		system("cls");

		num = CheckID();

		if (num != FALSE)		//로그인에 성공한다면,
		{
			PrintLoading();			//로딩화면 출력
			system("cls");
			sound();
			erase_cursor();		//커서지우기
			save = PlayGame(TRUE);				//게임 시작

			if (save == TRUE)
			{
				system("cls");
				SoundStop();
				

				switch (num)
				{
				case 0:
					fp = fopen("data1.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
						player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 1:
					fp = fopen("data2.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
						player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 2:
					fp = fopen("data3.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
						player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 3:
					fp = fopen("data4.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
						player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 4:
					fp = fopen("data5.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", 
						player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				}
				fclose(fp);
				break;
			}
			else
			{
				SoundStop();
				Ending();
				Rank(num);
				break;
			}
		}
		else						//로그인에 실패한다면
		{
			gotoxy(50, 38);
			printf("올바르지 않은 ID 또는 비밀번호입니다.\n");
			printf("다시 입력하시려면 1을 누르세요");

			key = getch();

			if (key == '1') {
				count++;

				if (count == 3) {

					printf("\n아이디와 패스워드를 찾으시겠습니까? (Yes : y, No : n)");
					printf("\n 초기 화면으로 넘어가시려면 r키를 누르세요.\n");
					subkey = getch();

					if (subkey == 'y')		//찾기를 원하면
					{
						FindMember();		//찾는 함수 실행
						count = 0;
					}

					else if (subkey == 'n') count = 0;	//원하지 않으면 넘어간다.

					else if (subkey == 'r')	break;	//돌아가기 버튼
				}
			}
		}
	}
}

void FindMember()
{
	FILE *fp;
	int i = 0;
	member mem[5];
	char name[16];
	int birth;
	short boolean;

	system("cls");
										//ID와 Password를 찾기위한 회원정보 입력
	printf("이름을 입력하세요 : ");  scanf(" %[^\n]s", name);
	printf("생년월일을 입력하세요 : ");  scanf("%d", &birth);

	fp = fopen("member.txt", "r");		//파일을 읽기모드로 연다

	if (fp != NULL)			//파일이 존재한다면
	{
		while (i < 5)		//한줄씩 받는다.
		{
			fscanf(fp, "%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
			i++;
		}

		for (i = 0; i < 5; i++)		
			if (!strcmp(mem[i].name, name) && (mem[i].birth == birth)) {	//일치하는 회원정보가 있다면,
				boolean = 1;		//boolean값을 1
				break;
			}

		if (boolean == 1)		//일치하는 회원정보가 있다면,
		{
			system("cls");
			printf("ID : %s\n", mem[i].ID);		//ID와 Password를 출력해준다.
			printf("PassWord : %s\n", mem[i].Password);
			Sleep(2000);
		}

		else {
			printf("일치하는 회원이 없습니다!\n");
			Sleep(2000);
		}

		fclose(fp);
	}
}

void LogInData()
{
	FILE *fp;
	char key;
	int count = 0;
	char subkey = 0;
	int num = 0;
	int save = 0;

	while (subkey != 'r') {
		system("cls");

		num = CheckID();

		if (num != FALSE)		//로그인에 성공한다면,
		{
			PrintLoading();			//로딩화면 출력
			system("cls");
			erase_cursor();		//커서지우기
			sound();
			save = PlayGame(FALSE);				//게임 시작

			if (save == TRUE)
			{
				system("cls");
				SoundStop();
				switch (num)
				{
				case 0:
					fp = fopen("data1.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 1:
					fp = fopen("data2.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 2:
					fp = fopen("data3.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite,
						player.play_time.second);
					break;
				case 3:
					fp = fopen("data4.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite, player.play_time.second);
					break;
				case 4:
					fp = fopen("data5.txt", "w+");
					fprintf(fp, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", player.x, player.y, player.finish, player.location, player.sun, player.tutorial_quest1,
						player.tutorial_quest2, player.tutorial_quest3, player.tutorial_professor, player.tutorial_school, player.item.phone,
						player.item.piece1, player.item.piece2, player.item.piece3, player.item.piece4,
						player.item.piece5, player.item.usb, player.item.water, player.item.quest1, player.item.quest2, player.item.quest3,
						player.item.report, player.item.shoes, player.item.card, player.play_time.day, player.play_time.minuite, player.play_time.second);
					break;
				}
				fclose(fp);
				break;
			}
			else
			{
				SoundStop();
				Ending();
				Rank(num);
				break;
			}
		}
		else						//로그인에 실패한다면
		{
			printf("올바르지 않은 ID 또는 비밀번호입니다.\n");
			printf("다시 입력하시려면 1을 누르세요");

			key = getch();

			if (key == '1') {
				count++;

				if (count == 3) {

					printf("\n아이디와 패스워드를 찾으시겠습니까? (Yes : y, No : n)");
					printf("\n 초기 화면으로 넘어가시려면 r키를 누르세요.\n");
					subkey = getch();

					if (subkey == 'y')		//찾기를 원하면
					{
						FindMember();		//찾는 함수 실행
						count = 0;
					}

					else if (subkey == 'n') count = 0;	//원하지 않으면 넘어간다.

					else if (subkey == 'r')	break;	//돌아가기 버튼
				}
			}
		}
	}
}

void Rank(int idx)
{
	member mem[5] = {"0"};
	FILE *fp;
	FILE *rank;
	Player tmp;
	int num;
	char name[16];
	int i = 0;
	


	num = player.play_time.day * 240 + player.play_time.minuite * 60 + player.play_time.second;

	fp = fopen("member.txt", "r");

	while (i < 5) {
		fscanf(fp, "%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
		i++;
	}

	fclose(fp);

	rank = fopen("rank.txt", "r");

	strcpy(name, mem[idx].name);

	if (rank == NULL)
	{
		rank = fopen("rank.txt", "w");

		fprintf(rank, "%s %d", name, num);
		fclose(rank);
	}

	else
	{
		rank = fopen("rank.txt", "a+");

		fprintf(rank, "\n%s %d", name, num);
		fclose(rank);
	}
}