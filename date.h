#pragma once

#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

int da_day;
int da_mon;
int da_year;

void getdate(int day, int month, int year)
{
	da_day = day;
	da_mon = month;
	da_year = year;
}