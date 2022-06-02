#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "callendar.h"
#include "favorites.h"

int menu(void);

int main(void) {


	menu();

	return 0;
}

int menu(void) {

	int menuNum;
	printf("1. 다이어리\n2. 즐겨찾기\n3. 검색\n\n");
	printf("넘어갈 페이지 번호를 입력하세요:");		scanf("%d", &menuNum);


	switch (menuNum) {
	case 1:
		system("cls");
		callendar();		// 1. 다이어리 페이지로 이동
		break;
	case 2:
		system("cls");
		favorites();		// 2. 즐겨찾기 페이지로 이동
		break;
	case 3:
		system("cls");
		search();		// 3. 검색 페이지로 이동
		break;
	default:
		printf("페이지 번호를 정확하게 입력해주세요\n");
		printf("넘어갈 페이지 번호를 입력하세요:");		scanf("%d", &menuNum);
	}
}