/*
����� ��� : �浹ó��
���� : v1.3
������ : ���ؼ�
���� ������ : 2018. 5. 29
*/
#include "Event.h"
#include "EventE87.h"
#include "EventHakyeon.h"
#include "EventHome.h"
#include "EventJeonsan.h"
#include "EventS14.h"
#include "EventSchool.h"

int CheckEventUp(Player *player)
{
	int state;

	if (player->location == ROOM)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventRoom(player->x, player->y - 1);      //��ȿ����� �浹 Ȯ��

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case BED:      //ħ�� �浹�� �ִٸ�
			EventBed(player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case WINDOW:   //â�� �浹�� �ִٸ�
			EventWindow(*player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case TOILET:   //ȭ��� �浹�� �ִٸ�
			EventToilet(*player);      //ȭ��� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case CLOTH:      //���� �浹�� �ִٸ�
			EventCloth(*player);   //���� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR1TO2:      //�� �浹�� �ִٸ�
			EventDoor1To2(player);   //�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x, player->y - 1);
		switch (state) {
		case DOOR2TO1:		//�����ΰ��� ������ �浹
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//�������������ΰ��� ������ �浹
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4�� ���� ������ �浹
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7�� ���� ������ �浹
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//�п������� ���� ������ �浹
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL :			//NPC����
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1 :			//NPC����1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2 :			//NPC����2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default :
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x, player->y - 1);
		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR3TO2:		//�б����¹�
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR ://�����ֱ�����
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB :			//USBã��
			EventUSB(player);
			return FALSE;
			break;
		case USB1 :			//��¥ USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET :		//����ã��
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventE87(player->x, player->y - 1);      //��ȿ����� �浹 Ȯ��

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case DOOR5TO2:	//�б����¹�
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM :		//�������� ����
			EventNPCKIM(player);	//��������̺�Ʈ ����
			return FALSE;
			break;				
		case NPCPROFESSOR1 :	//���缺���������� ����
			EventProfessor1(player);	//���缺�����԰��� �̺�Ʈ ����
			return FALSE;
			break;			
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x, player->y - 1);      //�濡���� �浹 Ȯ��

		switch (state) {
		case BLOCK:		//�� �浹
			return FALSE;
			break;
		case DOOR6TO2:	//�б����¹� �浹
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD :	//CGACĥ�� �浹
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND :		//��Ӹ�NPC �浹
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON :		//NPC���� �浹
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET :		//ĳ��� �浹
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1 :	//ĥ���浹
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT :		//�����ͱ��浹
			EventPrint(player);
			return FALSE;
			break;
		case TRUE :
			return TRUE;
		default :
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x, player->y - 1);

		switch (state)
		{
		case BLOCK :		//���浹
			return FALSE;
			break;
		case NPCPROFESSOR2 :	//�������浹
			EventAssistant(*player);	
			return FALSE;
			break;
		case NPCPROFESSOR3:		//������ �浹
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//���������� �浹
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//�ϼ� �浹
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER :			//����� �浹
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE :			//�浹
			return FALSE;
			break;
		case DOOR4TO2 :			//�б����¹� �浹
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE :			//�浹����
			return TRUE;
			break;
		}
	}
}

int CheckEventDown(Player *player)
{
	int state;

	if (player->location == ROOM)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventRoom(player->x, player->y + 1);      //��ȿ����� �浹 Ȯ��

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case BED:      //ħ�� �浹�� �ִٸ�
			EventBed(player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case WINDOW:   //â�� �浹�� �ִٸ�
			EventWindow(*player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case TOILET:   //ȭ��� �浹�� �ִٸ�
			EventToilet(*player);      //ȭ��� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case CLOTH:      //���� �浹�� �ִٸ�
			EventCloth(*player);   //���� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR1TO2:      //�� �浹�� �ִٸ�
			EventDoor1To2(player);   //�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x, player->y + 1);
		switch (state) {
		case DOOR2TO1:		//�����ΰ��� ������ �浹
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//�������������ΰ��� ������ �浹
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4�� ���� ������ �浹
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7�� ���� ������ �浹
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//�п������� ���� ������ �浹
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL:			//NPC����
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1:			//NPC����1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2:			//NPC����2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default:
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x, player->y + 1);
		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR3TO2:		//�б����¹�
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR://�����ֱ�����
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB:			//USBã��
			EventUSB(player);
			return FALSE;
			break;
		case USB1:			//��¥ USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET:		//����ã��
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventE87(player->x, player->y + 1);      //��ȿ����� �浹 Ȯ��

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case DOOR5TO2:	//�б����¹�
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM:		//�������� ����
			EventNPCKIM(player);	//��������̺�Ʈ ����
			return FALSE;
			break;
		case NPCPROFESSOR1:	//���缺���������� ����
			EventProfessor1(player);	//���缺�����԰��� �̺�Ʈ ����
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x, player->y + 1);      //�濡���� �浹 Ȯ��

		switch (state) {
		case BLOCK:		//�� �浹
			return FALSE;
			break;
		case DOOR6TO2:	//�б����¹� �浹
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD:	//CGACĥ�� �浹
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND:		//��Ӹ�NPC �浹
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON:		//NPC���� �浹
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET:		//ĳ��� �浹
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1:	//ĥ���浹
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT:		//�����ͱ��浹
			EventPrint(player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
		default:
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x, player->y + 1);

		switch (state)
		{
		case BLOCK:		//���浹
			return FALSE;
			break;
		case NPCPROFESSOR2:	//�������浹
			EventAssistant(*player);
			return FALSE;
			break;
		case NPCPROFESSOR3:		//������ �浹
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//���������� �浹
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//�ϼ� �浹
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER:			//����� �浹
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE:			//�浹
			return FALSE;
			break;
		case DOOR4TO2:			//�б����¹� �浹
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE:			//�浹����
			return TRUE;
			break;
		}
	}
}

int CheckEventLeft(Player *player)
{
	int state;

	if (player->location == ROOM)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventRoom(player->x - 2, player->y);      //��ȿ����� �浹 Ȯ��

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case BED:      //ħ�� �浹�� �ִٸ�
			EventBed(player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case WINDOW:   //â�� �浹�� �ִٸ�
			EventWindow(*player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case TOILET:   //ȭ��� �浹�� �ִٸ�
			EventToilet(*player);      //ȭ��� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case CLOTH:      //���� �浹�� �ִٸ�
			EventCloth(*player);   //���� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR1TO2:      //�� �浹�� �ִٸ�
			EventDoor1To2(player);   //�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x - 2, player->y);
		switch (state) {
		case DOOR2TO1:		//�����ΰ��� ������ �浹
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//�������������ΰ��� ������ �浹
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4�� ���� ������ �浹
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7�� ���� ������ �浹
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//�п������� ���� ������ �浹
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL:			//NPC����
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1:			//NPC����1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2:			//NPC����2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default:
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x - 2, player->y);
		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR3TO2:		//�б����¹�
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR://�����ֱ�����
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB:			//USBã��
			EventUSB(player);
			return FALSE;
			break;
		case USB1:			//��¥ USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET:		//����ã��
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventE87(player->x - 2, player->y);

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case DOOR5TO2:	//�б����¹�
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM:		//�������� ����
			EventNPCKIM(player);	//��������̺�Ʈ ����
			return FALSE;
			break;
		case NPCPROFESSOR1:	//���缺���������� ����
			EventProfessor1(player);	//���缺�����԰��� �̺�Ʈ ����
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x - 2, player->y);

		switch (state) {
		case BLOCK:		//�� �浹
			return FALSE;
			break;
		case DOOR6TO2:	//�б����¹� �浹
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD:	//CGACĥ�� �浹
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND:		//��Ӹ�NPC �浹
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON:		//NPC���� �浹
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET:		//ĳ��� �浹
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1:	//ĥ���浹
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT:		//�����ͱ��浹
			EventPrint(player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
		default:
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x - 2, player->y);

		switch (state)
		{
		case BLOCK:		//���浹
			return FALSE;
			break;
		case NPCPROFESSOR2:	//�������浹
			EventAssistant(*player);
			return FALSE;
			break;
		case NPCPROFESSOR3:		//������ �浹
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//���������� �浹
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//�ϼ� �浹
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER:			//����� �浹
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE:			//�浹
			return FALSE;
			break;
		case DOOR4TO2:			//�б����¹� �浹
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE:			//�浹����
			return TRUE;
			break;
		}
	}
}

int CheckEventRight(Player *player)
{
	int state;

	if (player->location == ROOM)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventRoom(player->x + 2, player->y);      //��ȿ����� �浹 Ȯ��

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case BED:      //ħ�� �浹�� �ִٸ�
			EventBed(player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case WINDOW:   //â�� �浹�� �ִٸ�
			EventWindow(*player);      //ħ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case TOILET:   //ȭ��� �浹�� �ִٸ�
			EventToilet(*player);      //ȭ��� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case CLOTH:      //���� �浹�� �ִٸ�
			EventCloth(*player);   //���� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR1TO2:      //�� �浹�� �ִٸ�
			EventDoor1To2(player);   //�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == SCHOOL)
	{
		state = CheckEventSchool(player->x + 2, player->y);
		switch (state) {
		case DOOR2TO1:		//�����ΰ��� ������ �浹
			EventDoor2To1(player);
			return FALSE;
			break;
		case DOOR2TO3:		//�������������ΰ��� ������ �浹
			EventDoor2To3(player);
			return FALSE;
			break;
		case DOOR2TO4:		//S1-4�� ���� ������ �浹
			EventDoor2To4(player);
			return FALSE;
			break;
		case DOOR2TO5:		//E8-7�� ���� ������ �浹
			EventDoor2To5(player);
			return FALSE;
			break;
		case DOOR2TO6:		//�п������� ���� ������ �浹
			EventDoor2To6(player);
			return FALSE;
			break;
		case GIRL:			//NPC����
			EventGirl(*player);
			return FALSE;
			break;
		case MAN1:			//NPC����1
			EventMan1(*player);
			return FALSE;
			break;
		case MAN2:			//NPC����2
			EventMan2(*player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
			break;
		default:
			return FALSE;
			break;
		}

	}

	else if (player->location == JEONSAN)
	{
		state = CheckEventJeonsan(player->x + 2, player->y);
		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case COMPUTER:   //��ǻ�� �浹�� �ִٸ�
			EventComputer(player);   //��ǻ�� �浹�� ���õ� �Լ�
			return FALSE;      //�浹 �߻�
			break;
		case DOOR3TO2:		//�б����¹�
			EventDoor3To2(player);
			return FALSE;
			break;
		case NPCPROFESSOR://�����ֱ�����
			EventNPCProfessor(player);
			return FALSE;
			break;
		case USB:			//USBã��
			EventUSB(player);
			return FALSE;
			break;
		case USB1:			//��¥ USB
			EventUSB1(*player);
			return FALSE;
			break;
		case WALLET:		//����ã��
			EventWallet(player);
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == E87)      //�÷��̾��� ��ġ�� ���̶��
	{
		state = CheckEventE87(player->x + 2, player->y);

		switch (state) {
		case BLOCK:      //�� �浹�� �ִٸ�
			return FALSE;   //�浹�߻�
			break;
		case DOOR5TO2:	//�б����¹�
			EventDoor5To2(player);
			return FALSE;
			break;
		case NPCKIM:		//�������� ����
			EventNPCKIM(player);	//��������̺�Ʈ ����
			return FALSE;
			break;
		case NPCPROFESSOR1:	//���缺���������� ����
			EventProfessor1(player);	//���缺�����԰��� �̺�Ʈ ����
			return FALSE;
			break;
		case TRUE:      //�浹�� ���ٸ�
			return TRUE;
			break;
		case FALSE:      //�浹 �߻�
			return FALSE;
			break;
		default:
			return FALSE;
			break;
		}
	}

	else if (player->location == HAKYEON)
	{
		state = CheckEventHakyeon(player->x + 2, player->y);

		switch (state) {
		case BLOCK:		//�� �浹
			return FALSE;
			break;
		case DOOR6TO2:	//�б����¹� �浹
			EventDoor6To2(player);
			return FALSE;
			break;
		case BLACKBOARD:	//CGACĥ�� �浹
			EventCGAC(player);
			return FALSE;
			break;
		case NPCBLOND:		//��Ӹ�NPC �浹
			EventNPCBlond(*player);
			return FALSE;
			break;
		case NPCYOON:		//NPC���� �浹
			EventNPCYOON(player);
			return FALSE;
			break;
		case CABINET:		//ĳ��� �浹
			EventCabinet(player);
			return FALSE;
			break;
		case BLACKBOARD1:	//ĥ���浹
			EventBlackboard(*player);
			return FALSE;
			break;
		case PRINT:		//�����ͱ��浹
			EventPrint(player);
			return FALSE;
			break;
		case TRUE:
			return TRUE;
		default:
			return FALSE;
		}
	}

	else if (player->location == S14)
	{
		state = CheckEventS14(player->x + 2, player->y);

		switch (state)
		{
		case BLOCK:		//���浹
			return FALSE;
			break;
		case NPCPROFESSOR2:	//�������浹
			EventAssistant(*player);
			return FALSE;
			break;
		case NPCPROFESSOR3:		//������ �浹
			EventProfessor3(*player);
			return FALSE;
			break;
		case NPCPROFESSOR4:		//���������� �浹
			EventProfessor4(player);
			return FALSE;
			break;
		case NPCLEE:			//�ϼ� �浹
			EventNPCLEE(player);
			return FALSE;
			break;
		case REFREGER:			//����� �浹
			EventGetWater(player);
			return FALSE;
			break;
		case FALSE:			//�浹
			return FALSE;
			break;
		case DOOR4TO2:			//�б����¹� �浹
			EventDoor4To2(player);
			return FALSE;
			break;
		case TRUE:			//�浹����
			return TRUE;
			break;
		}
	}
}