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
	char str[1000];
	char filename[15];
	int i = 0;
	float t;
	FILE* write; 

	printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyy-mm-dd]: ");
	fflush(stdin);
	scanf("%s", &filename); 
	strcat(filename, ".txt");
	write = fopen(filename, "a+"); 

	t = clock();

	printf("����� ������ �Է��Ͻÿ�(�����Ϸ��� Enter �� Ctrl + z �Է� �� �ٽ� Enter) : \n");
	while (fgets(str, sizeof(str), stdin) != NULL);
	fputs(str, write);
	
	t = clock() - t;
	t /= 1000;
	printf("%.f�� %d��", t / 60, (int)t % 60);
	fprintf(write, "%.f�� %d��", t / 60, (int)t % 60);
	
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
			float t;


			printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyy-mm-dd]: ");
			fflush(stdin);
			scanf("%s", &filename);
			strcat(filename, ".txt");
			write = fopen(filename, "a+");

			t = clock();

			printf("����� ������ �Է��Ͻÿ�(�����Ϸ��� Enter �� Ctrl + z �Է� �� �ٽ� Enter) : \n");
			while (fgets(str, sizeof(str), stdin) != NULL);
			fputs(str, write);

			t = clock() - t;
			t /= 1000;
			printf("%.f�� %d��", t / 60, (int)t % 60);
			fprintf(write, "%.f�� %d��", t / 60, (int)t % 60);
			break;
		}
	}
	fclose(write);
}


// ��� �б�
int recordRead(void) // �Էµ� ��¥ yyyy-mm-dd.txt������ ���ڸ� ������� ��Ʈâ�� ����Ѵ�.
{
	FILE* read;
	char line[1000];
	char line2[1000];
	char filename[15];
	int i = 0;
	printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyy-mm-dd]: ");
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
			printf("���ϴ� ��, ��, ���� �Է��Ͻÿ� [yyyy-mm-dd]: ");
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

	printf("�����ϰ� ���� ���� yyyy-mm-dd�� �Է��Ͻÿ� : ");
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
			printf("�����ϰ� ���� ���� yyyy-mm-dd�� �Է��Ͻÿ� : ");
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

#endif