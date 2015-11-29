#include <iostream>
#include "chapter_02.h"

using namespace std;

int main()
{
	auto c = new Chapter_02();

	cout << c->multiply0(2, 2) << endl;

	system("pause");

	return 0;
}