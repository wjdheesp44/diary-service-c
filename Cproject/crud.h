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
		printf("��ȣ�� ����� �Է����ּ���:"); 
		int recordNum;
		scanf("%d", &recordNum);
		crud(recordNum);
	}
}


// ��� ����
int recordCreat(void) {

	return 0;
}


// ��� �б�
int recordRead(void) {
	return 0;
}


// ��� ����
int recordUpdate(void) {
	return 0;
}


// ��� ����
int recordDelete(void) {
	return 0;
}

#endif