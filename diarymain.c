#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "callendar.h"


int main(void) {

	// 0. 메뉴 페이지

	int menuNum;
	printf("1. 다이어리\n2. 즐겨찾기\n\n");
	printf("넘어갈 페이지 번호를 입력하세요:");		scanf("%d", &menuNum);


	switch (menuNum) {
	case 1:
		system("cls");
		callendar();		// 1. 다이어리 페이지로 이동
		break;
	// 2. 즐겨찾기 들어갈 예정
	default:
		printf("페이지 번호를 정확하게 입력해주세요\n");
		printf("넘어갈 페이지 번호를 입력하세요:");		scanf("%d", &menuNum);
	}

	
	return 0;
}
