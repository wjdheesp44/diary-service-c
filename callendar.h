//callendar.h  �޷� ����

#ifndef __CALLENDAR_H__
# define __CALLENDAR_H__
#include "crud.h"
#include <stdio.h>
#include <time.h>
#include <windows.h> // Sleep �Լ��� ����ϱ����� ���


//�Լ��� ����

void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int startDay(int year, int month);
int totalDates(int year, int month);
int numberOfDaysInMonth(int year, int month);
int leapYear(int year);


//year�� month�� ���� �޾� �ش� ���� ��� : title -> ���ϱ���, body -> ��¥ 
void printMonth(int year, int month) {
	printMonthTitle(year, month);
	printMonthBody(year, month);
}


//���� �⵵�� ���
void printMonthTitle(int year, int month) {
	printf(" %d%18d ", year, month);
	printMonthName(month);
	printf("\n---------------------------------------------\n");
	printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
}


//month�� ���� �޾� �ش� ���� ���� �̸��� ���
void printMonthName(int month) {
	char* printMonthName[13] = {0, "January", "February","March","April","May","June","July","August","September","October","November","December"};
	
	printf("%s", printMonthName[month]);
}


//year�� month�� ���� �޾� ���ϰ� ���� ���
void printMonthBody(int year, int month) {
	int startday = startDay(year, month);
	int numberofdaysinmonth = numberOfDaysInMonth(year, month);

	for (int i = 0; i < startday; i++) printf("      ");		// �ش� ���� ���� �� 
	for (int i = 1; i <= numberofdaysinmonth; i++) {	// ��¥ ��� �� �� �� �ѱ��
		printf("%6d", i);
		if ((i + startday) % 7 == 0) printf("\n");
	}
}


// �ش� ���� �����ϴ� ���� ���� �������� ã�� �Լ�
int startDay(int year, int month) {
	int startday1800 = 3;
	int totalnumberofdays = totalDates(year, month);
	return (startday1800 + totalnumberofdays) % 7;
}


// 1800�� 1�� 1�� ���� �ش� �ޱ��� �� ��ĥ�� �Ǵ��� ���
int totalDates(int year, int month) {
	int total = 0;
	for (int i = 1800; i < year; i++) {
		if (leapYear(i)) total += 366;
		else total += 365;
	}
	for (int i = 1; i < month; i++) {
		total = total + numberOfDaysInMonth(year, i);
	}

	return total;
}


//year�� month�� ���� �޾� �ش� �޿� ������ �ִ���
int numberOfDaysInMonth(int year, int month) {
	int monthdate[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2) {
		if (leapYear(year) == 1) return 29;
		else return 28;
	}
	return monthdate[month];

}


//year�� ���޹޾� �������� Ȯ��
int leapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return 1;
	else	return 0;
}


int callendar(void) {
	
		// 1. ���̾ ������

		int year, month;
		// ���� �Է�
		printf("year : ");
		scanf("%d", &year);

		// �� �Է�
		printf("month : ");
		scanf("%d", &month);
		printf("\n");

		printMonth(year, month);
		printf("\n\n");

		// ���̾�� ���
		int ch;
		while ((ch = getchar()) != EOF)
		{
			int recordNum;
			printf("  0. ���� 1. ��� ���� 2. ��� �б� 3. ��� ���� 4. ��� ���� \n\n  ��ȣ�� �Է����ּ��� : ");
			scanf("%d", &recordNum);
			crud(recordNum);
		}
}

#endif