#pragma once

#include <vector>

class Chapter_02
{
public:
	int multiply0(int n, int a);
	int multiply1(int n, int a);
	void exercise_2_1(int n, int a);
	int exercise_2_1_way1(int n, int a, int count, std::vector<int> bank);
	int exercise_2_1_way2(int n, int a, int count, std::vector<int> bank);

	bool odd(int n);
	int half(int n);
};