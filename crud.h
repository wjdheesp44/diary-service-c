#ifndef __CRUD_H__
# define __CRUD_H__
#include <stdio.h>
#include "callendar.h"

int recordCreat(void);
int recordRead(void);
int recordUpdate(void);
int recordDelete(void);

int crud(int crudNum);




int crud(int crudNum) {
	switch(crudNum) {
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
		int recordNum;
		scanf("%d", &recordNum);
		crud(recordNum);
	}
}


// 기록 생성
int recordCreat(void) {

	return 0;
}


// 기록 읽기
int recordRead(void) {
	return 0;
}


// 기록 수정
int recordUpdate(void) {
	return 0;
}


// 기록 삭제
int recordDelete(void) {
	return 0;
}

#endif
