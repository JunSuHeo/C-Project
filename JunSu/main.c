#include "login.h"
#include "print.h"
#include "Util.h"
#include "playgame.h"

void MakeData();
void ChooseData();

Player player;

void main()
{
	char key;
	int save = 0;
	system("mode con:cols=155 lines=37");		// 콘솔 창 크기설정
	
	MakeData();

	while (1)
	{
		system("cls");
		PrintIntro();		//인트로 출력
		PrintMenu();		//메뉴 출력
		key = getch();		//키입력 받기

		if (key == 'q')		//q누르면 종료
			break;

		switch (key)
		{
		case '1':		//2번누르면 로그인
			LogIn();
			break;
		case '2':
			ChooseData();
			LogInData();
			break;
		case '3':		//1번누르면 회원가입
			JoinMember();
			break;
		case '4' :
			PrintRank();
			break;
		default :
			break;
		}
	}
}

void MakeData() 
{
	FILE *fp;

	fp = fopen("data1.txt", "r");
	fp = fopen("data2.txt", "r");
	fp = fopen("data3.txt", "r");		
	fp = fopen("data4.txt", "r");		
	fp = fopen("data5.txt", "r");		

	fclose(fp);
}

void ChooseData()
{
	FILE *fp;
	FILE *fp1;
	member mem[5] = {"0", "0", 0, "0"};
	char key;
	int i = 0;

	fp = fopen("member.txt", "r");

	if (fp != NULL)		//파일이 존재한다면
	{
		while (i < 5)		//파일을 한줄씩 읽는다.
		{
			fscanf(fp, "%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
			i++;
		}

		fclose(fp);
	}

	else		//파일이 존재하지 않는다면
		printf("회원이 존재하지 않습니다.");

	system("cls");

	printf("1. %s\n", mem[0].name);
	printf("2. %s\n", mem[1].name);
	printf("3. %s\n", mem[2].name);
	printf("4. %s\n", mem[3].name);
	printf("5. %s\n", mem[4].name);

	printf("불러오기할 회원을 고르세요 : ");	key = getch();

	switch (key)
	{
	case '1' :
		fp1 = fopen("data1.txt", "r");

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",&i, &player.y, &player.finish, &player.location,
			&player.sun, &player.tutorial_quest1, &player.tutorial_quest2, &player.tutorial_quest3, &player.tutorial_professor, &player.tutorial_school, &player.item.phone,
			&player.item.piece1, &player.item.piece2, &player.item.piece3, &player.item.piece4,
			&player.item.piece5, &player.item.usb, &player.item.water, &player.item.quest1, &player.item.quest2, &player.item.quest3,
			&player.item.report, &player.item.shoes, &player.item.card, &player.play_time.day, &player.play_time.minuite, &player.play_time.second);
		fclose(fp1);
		player.x = i;
		break;

	case '2' :
		fp1 = fopen("data2.txt", "r");

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i, &player.y, &player.finish, &player.location,
			&player.sun, &player.tutorial_quest1, &player.tutorial_quest2, &player.tutorial_quest3, &player.tutorial_professor, &player.tutorial_school, &player.item.phone,
			&player.item.piece1, &player.item.piece2, &player.item.piece3, &player.item.piece4,
			&player.item.piece5, &player.item.usb, &player.item.water, &player.item.quest1, &player.item.quest2, &player.item.quest3,
			&player.item.report, &player.item.shoes, &player.item.card, &player.play_time.day, &player.play_time.minuite, &player.play_time.second);
		fclose(fp1);
		player.x = i;
		break;

	case '3' :
		fp1 = fopen("data3.txt", "r");

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i, &player.y, &player.finish, &player.location,
			&player.sun, &player.tutorial_quest1, &player.tutorial_quest2, &player.tutorial_quest3, &player.tutorial_professor, &player.tutorial_school, &player.item.phone,
			&player.item.piece1, &player.item.piece2, &player.item.piece3, &player.item.piece4,
			&player.item.piece5, &player.item.usb, &player.item.water, &player.item.quest1, &player.item.quest2, &player.item.quest3,
			&player.item.report, &player.item.shoes, &player.item.card, &player.play_time.day, &player.play_time.minuite, &player.play_time.second);
		fclose(fp1);
		player.x = i;
		break;
	case '4' :
		fp1 = fopen("data4.txt", "r");

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i, &player.y, &player.finish, &player.location,
			&player.sun, &player.tutorial_quest1, &player.tutorial_quest2, &player.tutorial_quest3, &player.tutorial_professor, &player.tutorial_school, &player.item.phone,
			&player.item.piece1, &player.item.piece2, &player.item.piece3, &player.item.piece4,
			&player.item.piece5, &player.item.usb, &player.item.water, &player.item.quest1, &player.item.quest2, &player.item.quest3,
			&player.item.report, &player.item.shoes, &player.item.card, &player.play_time.day, &player.play_time.minuite, &player.play_time.second);
		fclose(fp1);
		player.x = i;
		break;
	case '5' :
		fp1 = fopen("data5.txt", "r");

		fscanf(fp1, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d", &i, &player.y, &player.finish, &player.location,
			&player.sun, &player.tutorial_quest1, &player.tutorial_quest2, &player.tutorial_quest3, &player.tutorial_professor, &player.tutorial_school, &player.item.phone,
			&player.item.piece1, &player.item.piece2, &player.item.piece3, &player.item.piece4,
			&player.item.piece5, &player.item.usb, &player.item.water, &player.item.quest1, &player.item.quest2, &player.item.quest3,
			&player.item.report, &player.item.shoes, &player.item.card, &player.play_time.day, &player.play_time.minuite, &player.play_time.second);
		fclose(fp1);
		player.x = i;
		break;
	}
}