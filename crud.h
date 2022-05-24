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
		printf("��ȣ�� ����� �Է����ּ���:");
		static int recordNum;
		scanf_s("%d", &recordNum);
		crud(recordNum);
		break;
	}
}


// ��� ����
int recordCreat(void)  // ���ڿ��� �Է� �޾� yyyy-mm-dd.txt������ ����, ���⸦ �����Ѵ�
{
	int i = 0;

	char str[1000];
	char filename[15];
	FILE* write;
	clock_t start, finish;
	double duration;

	printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyymmdd]: ");
	fflush(stdin);
	scanf("%s", &filename);

	int filenameFavorites = atoi(filename);		// ���ϸ� ������ ��ȯ

	strcat(filename, ".txt");
	write = fopen(filename, "a+");

	start = clock();


	printf("����� ������ �Է��Ͻÿ�(�����Ϸ��� Enter �� Ctrl + z �Է� �� �ٽ� Enter) : \n");
	while (fgets(str, sizeof(str), stdin) != NULL);
	fputs(str, write);


	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	if (duration > 5) {
		favoritesList[filenameFavorites] = filenameFavorites;		// 5�ʺ��� ���� ������ ���ã�� �߰�
	}

	//printf("%.f�� %d��", duration / 60, (int)duration % 60);
	//fprintf(write, "%.f�� %d��", duration / 60, (int)duration % 60);

	printf("\n�� �ٸ� ���� ����ϰ� �ͳ���? ( �� = 1 or �ƴϿ� = 0 )");

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
			clock_t start, finish;
			double duration;

			printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyymmdd]: ");
			fflush(stdin);
			scanf("%s", &filename);

			int filenameFavorites = atoi(filename);		// ���ϸ� ������ ��ȯ

			strcat(filename, ".txt");
			write = fopen(filename, "a+");

			start = clock();


			printf("����� ������ �Է��Ͻÿ�(�����Ϸ��� Enter �� Ctrl + z �Է� �� �ٽ� Enter) : \n");
			while (fgets(str, sizeof(str), stdin) != NULL);
			fputs(str, write);


			finish = clock() - start;
			duration = (double)(finish - start) / CLOCKS_PER_SEC;

			if (duration > 5) {
				favoritesList[filenameFavorites] = filenameFavorites;		// 5�ʺ��� ���� ������ ���ã�� �߰�
			}

			//printf("%.f�� %d��", duration / 60, (int)duration % 60);
			//fprintf(write, "%.f�� %d��", duration / 60, (int)duration % 60);


			break;
		}
	}
	fclose(write);
}








// ��� �б�
int recordRead(void) // �Էµ� ��¥ yyyymmdd.txt������ ���ڸ� ������� ��Ʈâ�� ����Ѵ�.
{
	FILE* read;
	char line[1000];
	char line2[1000];
	char filename[15];
	int i = 0;
	printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyymmdd]: ");
	scanf("%s", filename);
	strcat(filename, ".txt");
	read = fopen(filename, "r");
	fflush(stdin);

	while (fgets(line, 500, read) != NULL) {
		sscanf(line, "%[^\n]", line2);
		printf("%s", line);
	}

	printf("�� �ٸ� ���� ����� �а�ͳ���? ( �� = 1 or �ƴϿ� = 0 )");
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
			printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyymmdd]: ");
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


// ��� ����
int recordUpdate(void) {

}


// ��� ����
int recordDelete(void) {   // ������ ���ϴ� ������ ��¥�� yyyy-mm-dd �������� �޾� ���� �Ѵ�.

	printf("�����ϰ� ���� ���� yyyymmdd�� �Է��Ͻÿ� : ");
	char filename[15];
	int i = 0;

	scanf("%s", filename);
	strcat(filename, ".txt");

	int nResult = remove(filename);

	if (nResult == 0)
	{
		printf("��� ���� ���� \n");
	}
	else if (nResult == -1)
	{
		perror("��� ���� ����  \n");
	}

	i++;
	printf("�� �ٸ� ���� ����� �����ϰ�ͳ���? ( �� = 1 or �ƴϿ� = 0 )");
	while (i >= 0)
	{
		int yn = 0;
		scanf("%d", &yn);
		if (yn == 0) {
			break;
		}
		if (yn == 1) {
			printf("�����ϰ� ���� ���� yyyymmdd�� �Է��Ͻÿ� : ");
			char filename[15];
			int i = 0;

			scanf("%s", filename);
			strcat(filename, ".txt");

			int nResult = remove(filename);

			if (nResult == 0)
			{
				printf("��� ���� ���� \n");
			}
			else if (nResult == -1)
			{
				perror("��� ���� ����  \n");
			}
			break;
		}
	}
}

int menu(void) {

	int menuNum;
	printf("1. ���̾\n2. ���ã��\n\n");
	printf("�Ѿ ������ ��ȣ�� �Է��ϼ���:");		scanf("%d", &menuNum);


	switch (menuNum) {
	case 1:
		system("cls");
		callendar();		// 1. ���̾ �������� �̵�
		break;
		// 2. ���ã�� �� ����
	case 2:
		system("cls");
		favorites();
		break;
	default:
		printf("������ ��ȣ�� ��Ȯ�ϰ� �Է����ּ���\n");
		printf("�Ѿ ������ ��ȣ�� �Է��ϼ���:");		scanf("%d", &menuNum);
	}
}

#endif