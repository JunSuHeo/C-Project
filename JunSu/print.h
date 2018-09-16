/*
모듈의 기능 : 각종 출력해주는 기능
버전 : v1.6
개발자 : 김중재
최종 수정일 : 2018. 6. 9
*/

#ifndef __PRINT_H__
#define __PRINT_H__

#include <stdio.h>
#include <Windows.h>
#include <time.h>

#include "Util.h"
#include "playgame.h"

void PrintLoading();		//로딩화면 출력
void PrintMenu();			//메뉴 출력
void PrintAt(int x, int y, char *str);		//위치지정 출력
void PrintIntro();			//인트로 출력
void PrintRoom_Sun(Player player);			//방 출력
void PrintRoom_Moon(Player player);
void PrintInventory(Player player);		//인벤토리 출력
void PrintSleep();			//자는모양 출력
void PrintHowToPlay();		//조작키 출력
void PrintSchool(Player player);	//학교출력
void PrintJeonsan(Player player);	//전산정보원출력
void PrintE87(Player player);		//E8-7출력
void PrintHakyeon(Player player);	//학연산출력
void PrintS14(Player player);		//S1-4출력
void PrintRank();					//랭킹출력
void PrintLogIn();					//로그인 박스출력
void Ending();						//엔딩화면출력
void firecracker_wall();			//불꽃놀이출력
void firecracker_up();				//불꽃놀이출력
void firecracker1();				//불꽃놀이출력
void firecracker2();				//불꽃놀이출력
void firecracker3();				//불꽃놀이출력
void firecracker4();				//불꽃놀이출력
void firecracker5();				//불꽃놀이출력
void firecracker6();				//불꽃놀이출력
void firecracker7();				//불꽃놀이출력
void firecracker8();				//불꽃놀이출력
	
#endif