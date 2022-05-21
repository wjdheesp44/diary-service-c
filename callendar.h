//callendar.h  달력 구현

#ifndef __CALLENDAR_H__
# define __CALLENDAR_H__
#include "crud.h"
#include <stdio.h>
#include <time.h>
#include <windows.h> // Sleep 함수를 사용하기위해 사용


//함수의 원형

void printMonth(int year, int month);
void printMonthTitle(int year, int month);
void printMonthName(int month);
void printMonthBody(int year, int month);
int startDay(int year, int month);
int totalDates(int year, int month);
int numberOfDaysInMonth(int year, int month);
int leapYear(int year);


//year와 month를 전달 받아 해당 월을 출력 : title -> 요일까지, body -> 날짜 
void printMonth(int year, int month) {
	printMonthTitle(year, month);
	printMonthBody(year, month);
}


//월과 년도를 출력
void printMonthTitle(int year, int month) {
	printf(" %d%18d ", year, month);
	printMonthName(month);
	printf("\n---------------------------------------------\n");
	printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n\n");
}


//month를 전달 받아 해당 달의 영어 이름을 출력
void printMonthName(int month) {
	char* printMonthName[13] = {0, "January", "February","March","April","May","June","July","August","September","October","November","December"};
	
	printf("%s", printMonthName[month]);
}


//year와 month를 전달 받아 요일과 일을 출력
void printMonthBody(int year, int month) {
	int startday = startDay(year, month);
	int numberofdaysinmonth = numberOfDaysInMonth(year, month);

	for (int i = 0; i < startday; i++) printf("      ");		// 해당 달의 시작 일 
	for (int i = 1; i <= numberofdaysinmonth; i++) {	// 날짜 출력 후 한 주 넘기기
		printf("%6d", i);
		if ((i + startday) % 7 == 0) printf("\n");
	}
}


// 해당 월의 시작하는 날이 무슨 요일인지 찾는 함수
int startDay(int year, int month) {
	int startday1800 = 3;
	int totalnumberofdays = totalDates(year, month);
	return (startday1800 + totalnumberofdays) % 7;
}


// 1800년 1월 1일 부터 해당 달까지 총 며칠이 되는지 계산
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


//year와 month를 전달 받아 해당 달에 몇일이 있는지
int numberOfDaysInMonth(int year, int month) {
	int monthdate[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2) {
		if (leapYear(year) == 1) return 29;
		else return 28;
	}
	return monthdate[month];

}


//year를 전달받아 윤년인지 확인
int leapYear(int year) {
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) return 1;
	else	return 0;
}


int callendar(void) {
	
		// 1. 다이어리 페이지

		int year, month;
		// 연도 입력
		printf("year : ");
		scanf("%d", &year);

		// 월 입력
		printf("month : ");
		scanf("%d", &month);
		printf("\n");

		printMonth(year, month);
		printf("\n\n");

		// 다이어리에 기록
		int ch;
		while ((ch = getchar()) != EOF)
		{
			int recordNum;
			printf("  0. 종료 1. 기록 생성 2. 기록 읽기 3. 기록 수정 4. 기록 삭제 \n\n  번호를 입력해주세요 : ");
			scanf("%d", &recordNum);
			crud(recordNum);
		}
}

#endif