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
			printf("��ȣ�� ����� �Է����ּ���:");
			static int recordNum;
			scanf_s("%d", &recordNum);
			crud(recordNum);
		}
	
}


// ��� ����
int recordCreat(void)  // ���ڿ��� �Է� �޾� yyyy-mm-dd.txt������ ����, ���⸦ �����Ѵ�
{
	FILE* write;
	char str[1000];
	char filename[15];
	printf("Today\'s Date [yyyy-mm-dd]: ");
	fflush(stdin);
	scanf("%s", &filename); 
	strcat(filename, ".txt");
	write = fopen(filename, "a+"); 

	printf("����� ������ �Է��Ͻÿ�(�����Ϸ��� Enter �� Ctrl + z �Է� �� �ٽ� Enter) : \n");
	while (fgets(str, sizeof(str), stdin) != NULL);
	fputs(str, write);

	fclose(write);
	return 0;
}

	


// ��� �б�
int recordRead(void) // �Էµ� ��¥ yyyy-mm-dd.txt������ ���ڸ� ������� ��Ʈâ�� ����Ѵ�.
{
	FILE* read;
	char line[1000];
	char line2[1000];
	char filename[15];
	printf("Diary's Date [yyyy-mm-dd]: ");
	scanf("%s", filename);
	strcat(filename, ".txt");
	read = fopen(filename, "r");
	fflush(stdin);

	while (fgets(line, 500, read) != NULL) {
		sscanf(line, "%[^\n]", line2);
		printf("%s", line);


		fclose(read);
		return 0;
	}
}


// ��� ����
int recordUpdate(void) {

}


// ��� ����
int recordDelete(void) {

}

#endif