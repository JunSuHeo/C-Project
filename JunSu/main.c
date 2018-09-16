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
	system("mode con:cols=155 lines=37");		// �ܼ� â ũ�⼳��
	
	MakeData();

	while (1)
	{
		system("cls");
		PrintIntro();		//��Ʈ�� ���
		PrintMenu();		//�޴� ���
		key = getch();		//Ű�Է� �ޱ�

		if (key == 'q')		//q������ ����
			break;

		switch (key)
		{
		case '1':		//2�������� �α���
			LogIn();
			break;
		case '2':
			ChooseData();
			LogInData();
			break;
		case '3':		//1�������� ȸ������
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

	if (fp != NULL)		//������ �����Ѵٸ�
	{
		while (i < 5)		//������ ���پ� �д´�.
		{
			fscanf(fp, "%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
			i++;
		}

		fclose(fp);
	}

	else		//������ �������� �ʴ´ٸ�
		printf("ȸ���� �������� �ʽ��ϴ�.");

	system("cls");

	printf("1. %s\n", mem[0].name);
	printf("2. %s\n", mem[1].name);
	printf("3. %s\n", mem[2].name);
	printf("4. %s\n", mem[3].name);
	printf("5. %s\n", mem[4].name);

	printf("�ҷ������� ȸ���� ������ : ");	key = getch();

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