#ifndef __CRUD_H__
# define __CRUD_H__
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "callendar.h"
#include "favorites.h"
#define CLOCKS_PER_SEC 1000


int recordCreat(void);
int recordRead(void);
int recordUpdate(void);
int recordDelete(void);
int menu(void);


int crud(int crudNum) {


	switch (crudNum) {
	case 0:
		exit(0);
	case 1:
		recordCreat();
		break;
	case 2:
		recordRead();
		break;
	case 3:
		recordUpdate();
		break;
	case 4:
		recordDelete();
		break;
	case 5:
		menu();
		break;
	default:
		printf("번호를 제대로 입력해주세요:");
		static int recordNum;
		scanf_s("%d", &recordNum);
		crud(recordNum);
		break;
	}
}


// 기록 생성
int recordCreat(void)  // 문자열을 입력 받아 yyyy-mm-dd.txt파일을 생성, 쓰기를 실행한다
{
	int i = 0;

	char str[1000];
	char filename[15];
	FILE* write;
	clock_t start, finish;
	double duration;

	printf("원하는 년, 월, 일을 입력하시오 [yyyymmdd]: ");
	fflush(stdin);
	scanf("%s", &filename);

	int filenameFavorites = atoi(filename);		// 파일명 정수로 변환

	strcat(filename, ".txt");
	write = fopen(filename, "a+");

	start = clock();


	printf("기록할 내용을 입력하시오(종료하려면 Enter 후 Ctrl + z 입력 후 다시 Enter) : \n");
	while (fgets(str, sizeof(str), stdin) != NULL);
	fputs(str, write);


	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	if (duration > 5) {
		favoritesList[filenameFavorites] = filenameFavorites;		// 5초보다 오래 있으면 즐겨찾기 추가
	}

	//printf("%.f분 %d초", duration / 60, (int)duration % 60);
	//fprintf(write, "%.f분 %d초", duration / 60, (int)duration % 60);

	fclose(write);
}

// 기록 읽기
int recordRead(void) // 입력된 날짜 yyyymmdd.txt파일의 글자를 순서대로 도트창에 출력한다.
{
	FILE* read;
	char line[1000];
	char line2[1000];
	char filename[15];
	int i = 0;
	printf("원하는 년, 월, 일을 입력하시오 [yyyymmdd]: ");
	scanf("%s", filename);
	strcat(filename, ".txt");
	read = fopen(filename, "r");
	fflush(stdin);

	while (fgets(line, 500, read) != NULL) {
		sscanf(line, "%[^\n]", line2);
		printf("%s", line);
	}

	fclose(read);
}


// 기록 수정
int recordUpdate(void) {

}


// 기록 삭제
int recordDelete(void) {   // 삭제를 원하는 파일의 날짜를 yyyy-mm-dd 형식으로 받아 삭제 한다.

	printf("삭제하고 싶은 파일 yyyymmdd로 입력하시오 : ");
	char filename[15];
	int i = 0;

	scanf("%s", filename);
	strcat(filename, ".txt");

	int nResult = remove(filename);

	if (nResult == 0)
	{
		printf("기록 삭제 성공 \n");
	}
	else if (nResult == -1)
	{
		perror("기록 삭제 실패  \n");
	}
}

int menu(void) {

	int menuNum;
	printf("1. 다이어리\n2. 즐겨찾기\n\n");
	printf("넘어갈 페이지 번호를 입력하세요:");		scanf("%d", &menuNum);


	switch (menuNum) {
	case 1:
		system("cls");
		callendar();		// 1. 다이어리 페이지로 이동
		break;
		// 2. 즐겨찾기 들어갈 예정
	case 2:
		system("cls");
		favorites();
		break;
	default:
		printf("페이지 번호를 정확하게 입력해주세요\n");
		printf("넘어갈 페이지 번호를 입력하세요:");		scanf("%d", &menuNum);
	}
}

#endif