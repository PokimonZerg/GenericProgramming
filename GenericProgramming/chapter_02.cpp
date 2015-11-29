#include <iostream>
#include <vector>
#include <algorithm>
#include "chapter_02.h"

int Chapter_02::multiply0(int n, int a)
{
	if (n == 1) return a;

	return this->multiply0(n - 1, a) + a;
}

int Chapter_02::multiply1(int n, int a)
{
	if (n == 1) return a;

	int result = this->multiply1(this->half(n), a + a);

	if (this->odd(n))
		result = result + a;

	return result;
}

void Chapter_02::exercise_2_1(int n, int a)
{
	if (n <= 1)
		return;

	auto way1 = exercise_2_1_way1(n, a, 0, std::vector<int>());
	auto way2 = exercise_2_1_way2(n, a, 0, std::vector<int>());

	std::cout << "[n = " << n << "] Optimal chains is: " << std::min(way1, way2) << std::endl;
}

int Chapter_02::exercise_2_1_way1(int n, int a, int count, std::vector<int> bank)
{
	if (!bank.empty() && bank.back() == n)
		return count;

	if (this->odd(n) && bank.empty())
	{
		count += 2;
		bank.push_back(3);
	}
	else
	{
		auto find_best_number = [&bank, n, a, &count]() -> bool
		{
			for (auto it = bank.begin(); it != bank.end(); ++it)
			{
				if (bank.back() + *it == n)
				{
					bank.push_back(n);
					count++;
					return true;
				}
				else if (bank.back() + *it > n && it != bank.begin())
				{
					bank.push_back(bank.back() + *(it - 1));
					count++;
					return true;
				}
				else if (bank.back() + *it > n && n - bank.back() == 2)
				{
					bank.push_back(n);
					count += 2;
					return true;
				}
				else if (bank.back() + *it > n && n - bank.back() == 1)
				{
					bank.push_back(n);
					count++;
					return true;
				}
			}

			return false;
		};

		if (bank.empty() || find_best_number() == false)
		{
			if (bank.empty())
			{
				bank.push_back(2);
			}
			else
			{
				bank.push_back(bank.back() * 2);
			}

			count++;
		}
	}

	return exercise_2_1_way1(n, a, count, bank);
}

int Chapter_02::exercise_2_1_way2(int n, int a, int count, std::vector<int> bank)
{
	if (!bank.empty() && bank.back() == n)
		return count;

	auto find_best_number = [&bank, n, a, &count]() -> bool
	{
		for (auto it = bank.begin(); it != bank.end(); ++it)
		{
			if (bank.back() + *it == n)
			{
				bank.push_back(n);
				count++;
				return true;
			}
			else if (bank.back() + *it > n && it != bank.begin())
			{
				bank.push_back(bank.back() + *(it - 1));
				count++;
				return true;
			}
			else if (bank.back() + *it > n && n - bank.back() == 2)
			{
				bank.push_back(n);
				count += 2;
				return true;
			}
			else if (bank.back() + *it > n && n - bank.back() == 1)
			{
				bank.push_back(n);
				count++;
				return true;
			}
		}

		return false;
	};

	if (bank.empty() || find_best_number() == false)
	{
		if (bank.empty())
		{
			bank.push_back(2);
		}
		else
		{
			bank.push_back(bank.back() * 2);
		}

		count++;
	}

	return exercise_2_1_way2(n, a, count, bank);
}

bool Chapter_02::odd(int n)
{
	return n & 0x1;
}

int Chapter_02::half(int n)
{
	return n >> 1;
}