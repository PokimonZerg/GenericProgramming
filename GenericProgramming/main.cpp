#include <iostream>
#include "chapter_02.h"

using namespace std;

int main()
{
	auto c = new Chapter_02();

	for (int i = 0; i < 100; i++)
	{
		c->exercise_2_1(i, 2);

		cout << "=========================" << endl;
	}

	//c->multiply_opt(7, 2);



	system("pause");

	return 0;
}