#ifndef __FAVORITES_H__
# define __FAVORITES_H__
#pragma warning(disable:4996)
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "callendar.h"
#include "crud.h"

void search2(char fname[30000000], char word[100]);

int favoritesList[99999999];

int favorites(void) {

	for (int i = 0; i < sizeof(favoritesList) / sizeof(favoritesList[0]); i++) {
		if (favoritesList[i] == NULL) {
			continue;
		}
		printf("-----���ã�� ���ϸ��-----\n");
		printf("%d\n", favoritesList[i]);
		printf("---------------------------\n");
	}
	
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
		
	return 0;
}


// Ž���� �ܾ� ã��(1��° ����)
void search(void) {

	char word[100];

	printf("Ž���� �ܾ�: ");
	scanf("%s", word);

	printf("------------------------------------------------");


	for (int i = 20000000; i < 21000000; i++) {	// �ִ� ���������� Ư�� �ܾ� ã��
		FILE* fp = NULL;

		char buffer[1000];

		int count = 0;
		char numChar[100];
		//���Ͽ���
		// i ������ ���ڿ��� �ٲ㼭 ���ľ� ��
		sprintf(numChar, "%d", i);	// ������ ���ڿ��� �ٲ�
		strcat(numChar, ".txt");
		search2(numChar, word);

	}

	printf("\n\n\n");
	menu();	// �޴��� ���ư���
	return 0;
}


// Ž���� �ܾ� ã��(2��° ����)
void search2(char fname[30000000], char word[100]){

	
	FILE* fp = NULL;
	char buffer[1000];
	int count = 0;
	fp = fopen(fname, "r");

	if (fp == NULL) {
		return 0;
	}
	
	while (fgets(buffer, 1000, fp) != NULL) {
		count++;
		if (strstr(buffer, word) != NULL) {

			printf("\n%d�� : %s", count, buffer);

		}
	}

	printf("\n%s���� �߰�\n", fname);
	printf("------------------------------------------------");

	fclose(fp);
	
	return 0;

}



#endif