#pragma once

#include<iostream>
#include<conio.h>
#include<windows.h>
#include <string>

using namespace std;

struct tm* now = localtime();
void getdate(int da_day, int da_mon, int da_year)
{
	da_day = tm_mday;
	da_mon = tm_mon;
	da_year = tm_year;

}

