#ifndef __FAVORITES_H__
# define __FAVORITES_H__
#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "callendar.h"
#include "crud.h"

void search2(char fname[30000000], char word[100]);

int favoritesList[99999999];

int favorites(void) {

	for (int i = 0; i < sizeof(favoritesList) / sizeof(favoritesList[0]); i++) {
		if (favoritesList[i] == NULL) {
			continue;
		}
		printf("-----즐겨찾기 파일목록-----\n");
		printf("%d\n", favoritesList[i]);
		printf("---------------------------\n");
	}
	
		printf("즐겨찾기 내용을 보고 싶나요?\n");
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
		
	return 0;
}


// 탐색할 단어 찾기(1번째 과정)
void search(void) {

	char word[100];

	printf("탐색할 단어: ");
	scanf("%s", word);

	printf("------------------------------------------------");


	for (int i = 20000000; i < 21000000; i++) {	// 있는 파일을에서 특정 단어 찾기
		FILE* fp = NULL;

		char buffer[1000];

		int count = 0;
		char numChar[100];
		//파일열기
		// i 정수를 문자열로 바꿔서 합쳐야 함
		sprintf(numChar, "%d", i);	// 정수를 문자열로 바꿈
		strcat(numChar, ".txt");
		search2(numChar, word);

	}

	printf("\n\n\n");
	menu();	// 메뉴로 돌아가기
	return 0;
}


// 탐색할 단어 찾기(2번째 과정)
void search2(char fname[30000000], char word[100]){

	
	FILE* fp = NULL;
	char buffer[1000];
	int count = 0;
	fp = fopen(fname, "r");

	if (fp == NULL) {
		return 0;
	}
	
	while (fgets(buffer, 1000, fp) != NULL) {
		count++;
		if (strstr(buffer, word) != NULL) {

			printf("\n%d줄 : %s", count, buffer);

		}
	}

	printf("\n%s에서 발견\n", fname);
	printf("------------------------------------------------");

	fclose(fp);
	
	return 0;

}



#endif