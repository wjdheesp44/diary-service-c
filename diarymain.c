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
	printf("1. ���̾\n2. ���ã��\n3. �˻�\n\n");
	printf("�Ѿ ������ ��ȣ�� �Է��ϼ���:");		scanf("%d", &menuNum);


	switch (menuNum) {
	case 1:
		system("cls");
		callendar();		// 1. ���̾ �������� �̵�
		break;
	case 2:
		system("cls");
		favorites();		// 2. ���ã�� �������� �̵�
		break;
	case 3:
		system("cls");
		search();		// 3. �˻� �������� �̵�
		break;
	default:
		printf("������ ��ȣ�� ��Ȯ�ϰ� �Է����ּ���\n");
		printf("�Ѿ ������ ��ȣ�� �Է��ϼ���:");		scanf("%d", &menuNum);
	}
}