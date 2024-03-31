// CalculateSum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "pch.h"
#include <iostream>

extern "C" int AdderASM(int a, int b, int c);
int AdderCPP(int a, int b, int c);

int main()
{
	int a = 17, b = 11, c = 14;
	int sum = AdderASM(a, b, c); //van ASM functie

	printf("a: %d\n", a);
	printf("b: %d\n", b);
	printf("c: %d\n", c);
	printf("sum: %d\n", sum);

	return 0;
}

int AdderCPP(int a, int b, int c)
{
	return a + b + c;
}