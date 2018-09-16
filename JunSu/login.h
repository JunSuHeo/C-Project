/*
모듈의 기능 : 로그인
버전 : v1.5
개발자 : 이완석
최종 수정일 : 2018. 6. 4
*/

#ifndef __LOGIN_H__
#define __LOGIN_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

#include "playgame.h"
#include "print.h"
#include "Util.h"

#define TRUE 1
#define FALSE -1

typedef struct member {
	char ID[100];
	char Password[50];
	int birth;
	char name[16];
}member;

void JoinMember();		//회원가입
int CheckID();			//회원정보 확인
void LogIn();			//로그인
void FindMember();		//회원정보 찾기
void LogInData();
void Rank(int idx);

#endif