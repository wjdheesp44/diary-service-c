#ifndef __FAVORITES_H__
# define __FAVORITES_H__
#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "callendar.h"
#include "crud.h"

int favoritesList[99999999];

int favorites(void) {

	for (int i = 0; i < sizeof(favoritesList) / sizeof(favoritesList[0]); i++) {
		if (favoritesList[i] == NULL) {
			continue;
		}
		printf("%d\n", favoritesList[i]);
	}

	/*
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
	*/
	return 0;
}



/*
void search(void) {

	FILE* fp;
	char str[1000], ans[1000];
	int num = 0, pass = 0;
	char numChar[100];

	printf("검색할 단어를 입력하세요:");
	gets(ans);
	
	for (int i = 0; i < 100000000; i++) {
		//파일열기
		// i 정수를 문자열로 바꿔서 합쳐야 함
		sprintf(numChar, "%d", i);	// 정수를 문자열로 바꿈
		//printf("%s", strcat(i, ".txt"));	내일 해결
		fp = fopen(strcat(i, ".txt"), "r");
		if (fp == NULL) {
			printf("파일 읽기모드 열기에 실패했습니다");
			return -1;
		}

		//문자열 검색
		while (!feof(fp)) {
			num++;
			fgets(str, 100, fp);// str에 한 행씩 문자열을 입력받습니다

			if (strstr(str, ans) != NULL) {
				printf("문자열을 찾았습니다.");
				printf("%d행 %s", num, str);
				pass++;
			}
		}

		if (pass == 0) printf("문자열을 찾을 수 없습니다");
		fclose(fp);
	}
	
	
	
}
*/




#endif