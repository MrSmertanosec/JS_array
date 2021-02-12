#include <iostream>
#include "My_type.cpp"
#include <string>

int main()
{
	JS_array arr;
	Test type;
	type.a = 1;
	double aa;
	std::cin >> aa;

	arr.push_back(type);
	arr.push_back(aa);
	arr.push_back('a');

	arr.print();

	arr.pop_back();

	arr.print();

	return 0;
}
