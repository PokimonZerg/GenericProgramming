#pragma once

#include <vector>

class Chapter_02
{
public:
	int multiply0(int n, int a);
	int multiply1(int n, int a);
	int multiply2(int n, int a);
	int multiply3(int n, int a);
	int multiply4(int n, int a);
	int mult_acc0(int r, int n, int a);
	int mult_acc1(int r, int n, int a);
	int mult_acc2(int r, int n, int a);
	int mult_acc3(int r, int n, int a);
	int mult_acc4(int r, int n, int a);
	void exercise_2_1(int n, int a);
	int exercise_2_1_way1(int n, int a, int count, std::vector<int> bank);
	int exercise_2_1_way2(int n, int a, int count, std::vector<int> bank);

	bool odd(int n);
	int half(int n);
};