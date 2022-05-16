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
int recordCreat(void)  // 문자열을 입력 받아 test.txt파일을 생성, 쓰기를 실행한다
{
	printf("기록할 내용을 입력하시오 : \n");
	FILE* write;
	char str[1000];
	write = fopen("test.txt", "w");
	scanf("%s", &str);
	fputs(str, write);

	fclose(write);
	return 0;
}



// 기록 읽기
int recordRead(void) // test.txt파일의 글자를 순서대로 도트창에 출력한다.
{
	char line[1000];

	FILE* read = fopen("test.txt", "r");
	if (read == NULL) {
		printf("파일열기 실패\n");
		return 1;
	}

	while (fgets(line, sizeof(line), read) != NULL) {
		printf("%s", line);
	}

	fclose(read);
	return 0;
}


// 기록 수정
int recordUpdate(void) {

}


// 기록 삭제
int recordDelete(void) {

}

#endif
