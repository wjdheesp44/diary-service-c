#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include "callendar.h"


int main(void) {

	// 0. �޴� ������

	int menuNum;
	printf("1. ���̾\n2. ���ã��\n\n");
	printf("�Ѿ ������ ��ȣ�� �Է��ϼ���:");		scanf("%d", &menuNum);


	switch (menuNum) {
	case 1:
		system("cls");
		callendar();		// 1. ���̾ �������� �̵�
		break;
	// 2. ���ã�� �� ����
	default:
		printf("������ ��ȣ�� ��Ȯ�ϰ� �Է����ּ���\n");
		printf("�Ѿ ������ ��ȣ�� �Է��ϼ���:");		scanf("%d", &menuNum);
	}

	
	return 0;
}