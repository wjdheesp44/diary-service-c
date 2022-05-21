#ifndef __CRUD_H__
# define __CRUD_H__
#include <stdio.h>
#include <time.h>
#include "callendar.h"

int recordCreat(void);
int recordRead(void);
int recordUpdate(void);
int recordDelete(void);



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
	char str[1000];
	char filename[15];
	int i = 0;
	float t;
	FILE* write; 

	printf("원하는 년, 월, 일을 입력하시오 [yyyy-mm-dd]: ");
	fflush(stdin);
	scanf("%s", &filename); 
	strcat(filename, ".txt");
	write = fopen(filename, "a+"); 

	t = clock();

	printf("기록할 내용을 입력하시오(종료하려면 Enter 후 Ctrl + z 입력 후 다시 Enter) : \n");
	while (fgets(str, sizeof(str), stdin) != NULL);
	fputs(str, write);
	
	t = clock() - t;
	t /= 1000;
	printf("%.f초 %d초", t / 60, (int)t % 60);
	fprintf(write, "%.f분 %d초", t / 60, (int)t % 60);
	
	printf("\n또 다른 날을 기록하고 싶나요? ( 네 = 1 or 아니오 = 0 )");
	
	i++;

	while (i >= 0) {
		int yn;
		scanf("%d", &yn);
		if (yn == 0) {
			break;
		}
		if (yn == 1) {
			char str[1000];
			char filename[15];
			FILE* write; 
			float t;


			printf("원하는 년, 월, 일을 입력하시오 [yyyy-mm-dd]: ");
			fflush(stdin);
			scanf("%s", &filename);
			strcat(filename, ".txt");
			write = fopen(filename, "a+");

			t = clock();

			printf("기록할 내용을 입력하시오(종료하려면 Enter 후 Ctrl + z 입력 후 다시 Enter) : \n");
			while (fgets(str, sizeof(str), stdin) != NULL);
			fputs(str, write);

			t = clock() - t;
			t /= 1000;
			printf("%.f초 %d초", t / 60, (int)t % 60);
			fprintf(write, "%.f분 %d초", t / 60, (int)t % 60);
			break;
		}
	}
	fclose(write);
}


// 기록 읽기
int recordRead(void) // 입력된 날짜 yyyy-mm-dd.txt파일의 글자를 순서대로 도트창에 출력한다.
{
	FILE* read;
	char line[1000];
	char line2[1000];
	char filename[15];
	int i = 0;
	printf("원하는 년, 월, 일을 입력하시오 [yyyy-mm-dd]: ");
	scanf("%s", filename);
	strcat(filename, ".txt");
	read = fopen(filename, "r");
	fflush(stdin);

	while (fgets(line, 500, read) != NULL) {
		sscanf(line, "%[^\n]", line2);
		printf("%s", line);
	}

	printf("또 다른 날의 기록을 읽고싶나요? ( 네 = 1 or 아니오 = 0 )");
	i++;

	while (i >= 0) {
		int yn = 0;
		scanf("%d", &yn);
		if (yn == 0) {
			break;
		}
		if (yn == 1) {
			FILE* read;
			char line[1000];
			char line2[1000];
			char filename[15];
			printf("원하는 년, 월, 일을 입력하시오 [yyyy-mm-dd]: ");
			scanf("%s", filename);
			strcat(filename, ".txt");
			read = fopen(filename, "r");
			fflush(stdin);

			while (fgets(line, 500, read) != NULL) {
				sscanf(line, "%[^\n]", line2);
				printf("%s", line);
			}
			break;
		}
	}
		fclose(read);
}


// 기록 수정
int recordUpdate(void) {

}


// 기록 삭제
int recordDelete(void) {   // 삭제를 원하는 파일의 날짜를 yyyy-mm-dd 형식으로 받아 삭제 한다.

	printf("삭제하고 싶은 파일 yyyy-mm-dd로 입력하시오 : ");
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

	i++;
	printf("또 다른 날의 기록을 삭제하고싶나요? ( 네 = 1 or 아니오 = 0 )");
	while (i >= 0)
	{
		int yn = 0;
		scanf("%d", &yn);
		if (yn == 0) {
			break;
		}
		if (yn == 1) {
			printf("삭제하고 싶은 파일 yyyy-mm-dd로 입력하시오 : ");
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
			break;
		}
	}
}

#endif