#ifndef __FAVORITES_H__
# define __FAVORITES_H__
#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "callendar.h"
#include "crud.h"

int favoritesList[99999999];

int favorites(void) {

	for (int i = 0; i < sizeof(favoritesList) / sizeof(favoritesList[0]); i++) {
		if (favoritesList[i] == NULL) {
			continue;
		}
		printf("%d\n", favoritesList[i]);
	}

	/*
	printf("���ã�� ������ ���� �ͳ���?\n");

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
	*/
	return 0;
}



/*
void search(void) {

	FILE* fp;
	char str[1000], ans[1000];
	int num = 0, pass = 0;
	char numChar[100];

	printf("�˻��� �ܾ �Է��ϼ���:");
	gets(ans);
	
	for (int i = 0; i < 100000000; i++) {
		//���Ͽ���
		// i ������ ���ڿ��� �ٲ㼭 ���ľ� ��
		sprintf(numChar, "%d", i);	// ������ ���ڿ��� �ٲ�
		//printf("%s", strcat(i, ".txt"));	���� �ذ�
		fp = fopen(strcat(i, ".txt"), "r");
		if (fp == NULL) {
			printf("���� �б��� ���⿡ �����߽��ϴ�");
			return -1;
		}

		//���ڿ� �˻�
		while (!feof(fp)) {
			num++;
			fgets(str, 100, fp);// str�� �� �྿ ���ڿ��� �Է¹޽��ϴ�

			if (strstr(str, ans) != NULL) {
				printf("���ڿ��� ã�ҽ��ϴ�.");
				printf("%d�� %s", num, str);
				pass++;
			}
		}

		if (pass == 0) printf("���ڿ��� ã�� �� �����ϴ�");
		fclose(fp);
	}
	
	
	
}
*/




#endif