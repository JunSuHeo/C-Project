/*
모듈의 기능 : 게임 플레이하기위해 필요한 각종 기능
버전 : v1.4
개발자 : 정윤재
최종수정일 : 2018. 6. 9
*/
#ifndef __UTIL_H__
#define __UTIL_H__

#include <stdio.h>
#include <Windows.h>
#include <mmsystem.h>   //mmsystem.h파일 인클루드
#include <conio.h>
#include <process.h>
#pragma comment(lib,"winmm.lib")   //winmm.lib을 링크하거나 선언
#include <time.h>

#include "playgame.h"
#include "print.h"

#define FALSE 0

void erase_cursor(void);      //커서 지우는 함수
void img(int x, int y, int mx, int my, wchar_t *temp);      //이미지 출력함수
void gotoxy(int x, int y);      //커서이동/unsigned __stdcall Sound(void *arg);
unsigned __stdcall Thread(Player *player);      //스레드함수
void sound();		//음악시작
void SoundStop();	//음악중지
unsigned __stdcall Thread2();

#endif