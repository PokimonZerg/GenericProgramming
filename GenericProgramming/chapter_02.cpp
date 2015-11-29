#include "chapter_02.h"

int Chapter_02::multiply0(int n, int a)
{
	if (n == 1) return a;

	return this->multiply0(n - 1, a) + a;
}

int Chapter_02::multiply1(int n, int a)
{
	return 0;
}

bool Chapter_02::odd(int n)
{
	return n & 0x1;
}

int Chapter_02::half(int n)
{
	return n >> 1;
}