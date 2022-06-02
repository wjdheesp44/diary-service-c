#ifndef __CRUD_H__
# define __CRUD_H__
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "callendar.h"
#include "favorites.h"
#include "getfilelist.h"
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
		getfilelist();
		break;
	case 6:
		system("cls");
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

	fclose(read);
}


// ��� ����
int recordUpdate(void) { // �ܾ� A�� �Է¹޾� �ܾ� B�� �����Ѵ�.(�ܾ ���� ����)
	FILE* fp1, * fp2;
	char file1[100], file2[100];
	char buffer[100];
	char name1[100], name2[100];
	printf("ù��° ���� �̸��� �����ϰ���� �ܾ� : ");
	scanf("%s %s", file1, name1);
	strcat(file1, ".txt");
	printf("�����ϰ���� �ܾ� : ");
	scanf("%s", name2);
	// ù��° ������ �б� ���� ����.
	if ((fp1 = fopen(file1, "r")) == NULL) {
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", file1);
		exit(1);
	}
	// �ι�° ������ ���� ���� ����.
	if ((fp2 = fopen("temp.txt", "w")) == NULL) {
		fprintf(stderr, "���� %s�� �� �� �����ϴ�.\n", "temp.txt");
		exit(1);
	}
	// ù��° ������ �ι�° ���Ϸ� �����Ѵ�. 
	while (fgets(buffer, 100, fp1) != NULL) {
		char* pos = strtok(buffer, " ");
		strcat(name2, " ");
		while (pos != NULL) {
			if (strcmp(name1, pos) == 0)
				fprintf(fp2, name2); else
				fprintf(fp2, "%s ", pos);

			pos = strtok(NULL, " ");
		}
	}
	fclose(fp1);
	fclose(fp2);
	remove(file1);
	rename("temp.txt", file1);
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
}


#endif