#ifndef __CRUD_H__
# define __CRUD_H__
#include <stdio.h>
#include "callendar.h"

int recordCreat(void);
int recordRead(void);
int recordUpdate(void);
int recordDelete(void);



int crud(int crudNum) {


		switch (crudNum) {
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
		}
	
}


// 기록 생성
int recordCreat(void)  // 문자열을 입력 받아 yyyy-mm-dd.txt파일을 생성, 쓰기를 실행한다
{
	FILE* write;
	char str[1000];
	char filename[15];
	printf("Today\'s Date [yyyy-mm-dd]: ");
	fflush(stdin);
	scanf("%s", &filename); 
	strcat(filename, ".txt");
	write = fopen(filename, "a+"); 

	printf("기록할 내용을 입력하시오(종료하려면 Enter 후 Ctrl + z 입력 후 다시 Enter) : \n");
	while (fgets(str, sizeof(str), stdin) != NULL);
	fputs(str, write);

	fclose(write);
	return 0;
}

	


// 기록 읽기
int recordRead(void) // 입력된 날짜 yyyy-mm-dd.txt파일의 글자를 순서대로 도트창에 출력한다.
{
	FILE* read;
	char line[1000];
	char line2[1000];
	char filename[15];
	printf("Diary's Date [yyyy-mm-dd]: ");
	scanf("%s", filename);
	strcat(filename, ".txt");
	read = fopen(filename, "r");
	fflush(stdin);

	while (fgets(line, 500, read) != NULL) {
		sscanf(line, "%[^\n]", line2);
		printf("%s", line);


		fclose(read);
		return 0;
	}
}


// 기록 수정
int recordUpdate(void) {

}


// 기록 삭제
int recordDelete(void) {

}

#endif