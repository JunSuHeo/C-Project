/*
����� ��� : �α���
���� : v1.5
������ : �̿ϼ�
���� ������ : 2018. 6. 4
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
	////-----���
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
	////���� ���̵��
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
	////������ ���̵��
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
	printf("    �̸�   ");
	gotoxy(67, 19);
	gotoxy(67, 19);
	printf("  ������� ");
	gotoxy(37, 23);
	printf("     ID    ");
	gotoxy(67, 23);
	printf("  PASSWORD ");
	gotoxy(36, 21);//�̸�
	printf("���� �̸��� �Է��ϼ���");
	gotoxy(66, 21);//�������
	printf("  -���� ���ڸ� �Է��ϼ��� ");
	gotoxy(36, 25);//PASSWORD
	printf("(5���� �̻� Ư������ ����)");
	gotoxy(67, 25);//
	printf("����/���ڸ� �����Ͽ� �Է��ϼ���");
	gotoxy(36, 17);
	printf("                 < �ؼ����� ȸ�����Զ�>");
	gotoxy(31, 27);
	printf("<�ؼ�����> ���Խ� ���� �̿���, �������� ���� �� �̿뿡 ��� ���ǵȴ�");
	gotoxy(50, 19);
	scanf(" %[^\n]s", name);
	gotoxy(80, 19);
	scanf("%d", &birth);
	gotoxy(50, 23);
	scanf(" %[^\n]s", ID);
	gotoxy(80, 23);
	scanf(" %[^\n]s", password);
	
	fp = fopen("member.txt", "r");		//������ �б���� ����

	
	
	if (fp == NULL)						//������ ���ٸ�,
	{
		fp = fopen("member.txt", "w");	//������� ������ ���Ӱ� �����.
		fprintf(fp, "%s %d %s %s",name, birth, ID, password);	//���Ͽ� �̸�, �������, ID, Password�� �Է��Ѵ�.

		fclose(fp);
	}
	
	else			//������ �����Ѵٸ�,
	{
		while (fscanf(fp, "%s %d %s %s", tmp.name, &tmp.birth, tmp.ID, tmp.Password) != EOF)
			count++;

		if (count >= 5) {
			printf("���̻� ȸ���� ����� �����ϴ�.");
			Sleep(2000);
		}
		else {
			fp = fopen("member.txt", "a+");	//������ ���ٿ��� ����.
			fprintf(fp, "\n%s %d %s %s", name, birth, ID, password);		//���Ͽ� �̸�, �������, ID, Password�� �Է��Ѵ�.

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

	fp = fopen("member.txt", "r");		//������ �б���� ����.

	if (fp != NULL)		//������ �����Ѵٸ�
	{
		while (i < 5)		//������ ���پ� �д´�.
		{
			fscanf(fp,"%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
			i++;
		}

		for (i = 0; i < 5; i++)
			if (!strcmp(mem[i].ID, CheckID) && !strcmp(mem[i].Password, CheckPassword)) {	//ID�� Password�� �´��� üũ�Ѵ�.
				boolean = 1;		//ID�� Password�� ��ġ�Ѵٸ� boolean�� 1�� �Ѵ�.
				break;
			}

		fclose(fp);
	}

	else		//������ �������� �ʴ´ٸ�
		printf("ȸ���� �������� �ʽ��ϴ�.");

	if (boolean == 1)	//ID�� Password�� ��ġ�ϴ� ȸ���� ã�Ҵٸ�,
		return i;	

	else				//ID�� Password�� ��ġ���� �ʴ´ٸ�
		return FALSE;	//FALSE ��ȯ
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

		if (num != FALSE)		//�α��ο� �����Ѵٸ�,
		{
			PrintLoading();			//�ε�ȭ�� ���
			system("cls");
			sound();
			erase_cursor();		//Ŀ�������
			save = PlayGame(TRUE);				//���� ����

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
		else						//�α��ο� �����Ѵٸ�
		{
			gotoxy(50, 38);
			printf("�ùٸ��� ���� ID �Ǵ� ��й�ȣ�Դϴ�.\n");
			printf("�ٽ� �Է��Ͻ÷��� 1�� ��������");

			key = getch();

			if (key == '1') {
				count++;

				if (count == 3) {

					printf("\n���̵�� �н����带 ã���ðڽ��ϱ�? (Yes : y, No : n)");
					printf("\n �ʱ� ȭ������ �Ѿ�÷��� rŰ�� ��������.\n");
					subkey = getch();

					if (subkey == 'y')		//ã�⸦ ���ϸ�
					{
						FindMember();		//ã�� �Լ� ����
						count = 0;
					}

					else if (subkey == 'n') count = 0;	//������ ������ �Ѿ��.

					else if (subkey == 'r')	break;	//���ư��� ��ư
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
										//ID�� Password�� ã������ ȸ������ �Է�
	printf("�̸��� �Է��ϼ��� : ");  scanf(" %[^\n]s", name);
	printf("��������� �Է��ϼ��� : ");  scanf("%d", &birth);

	fp = fopen("member.txt", "r");		//������ �б���� ����

	if (fp != NULL)			//������ �����Ѵٸ�
	{
		while (i < 5)		//���پ� �޴´�.
		{
			fscanf(fp, "%s %d %s %s", mem[i].name, &mem[i].birth, mem[i].ID, mem[i].Password);
			i++;
		}

		for (i = 0; i < 5; i++)		
			if (!strcmp(mem[i].name, name) && (mem[i].birth == birth)) {	//��ġ�ϴ� ȸ�������� �ִٸ�,
				boolean = 1;		//boolean���� 1
				break;
			}

		if (boolean == 1)		//��ġ�ϴ� ȸ�������� �ִٸ�,
		{
			system("cls");
			printf("ID : %s\n", mem[i].ID);		//ID�� Password�� ������ش�.
			printf("PassWord : %s\n", mem[i].Password);
			Sleep(2000);
		}

		else {
			printf("��ġ�ϴ� ȸ���� �����ϴ�!\n");
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

		if (num != FALSE)		//�α��ο� �����Ѵٸ�,
		{
			PrintLoading();			//�ε�ȭ�� ���
			system("cls");
			erase_cursor();		//Ŀ�������
			sound();
			save = PlayGame(FALSE);				//���� ����

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
		else						//�α��ο� �����Ѵٸ�
		{
			printf("�ùٸ��� ���� ID �Ǵ� ��й�ȣ�Դϴ�.\n");
			printf("�ٽ� �Է��Ͻ÷��� 1�� ��������");

			key = getch();

			if (key == '1') {
				count++;

				if (count == 3) {

					printf("\n���̵�� �н����带 ã���ðڽ��ϱ�? (Yes : y, No : n)");
					printf("\n �ʱ� ȭ������ �Ѿ�÷��� rŰ�� ��������.\n");
					subkey = getch();

					if (subkey == 'y')		//ã�⸦ ���ϸ�
					{
						FindMember();		//ã�� �Լ� ����
						count = 0;
					}

					else if (subkey == 'n') count = 0;	//������ ������ �Ѿ��.

					else if (subkey == 'r')	break;	//���ư��� ��ư
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