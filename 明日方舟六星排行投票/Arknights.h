#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LEN 30
#define MAX 86
typedef struct winRate
{
	double winRate;
	int index;
}WinRate;
void PrintSort(char* name[MAX], WinRate winRate[MAX]);
void Voke(char* name[MAX], int mark[MAX], int count[MAX]);
void Rank(char* name[MAX], int mark[MAX], int count[MAX], WinRate* winRate);
void BubbleSort(char* name[MAX], WinRate* winRate);
void Swap(WinRate* winRate, int i, int j);