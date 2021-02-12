#include <iostream>
#include <string>
#include <vector>

class Test
{

public:
	int a;

};

class My_type
{
private:
	void* ptr;
	std::string type;

public:
	template <typename T>
	My_type(T val)
	{
		get_type(val);
		ptr = new T(val);
	}

	~My_type()
	{
		delete ptr;
	}

	template <typename T>
	void get_type(T val)
	{
		if (typeid(val) == typeid(int))
		{
			this->type = "int";
		}

		if (typeid(val) == typeid(char))
		{
			this->type = "char";
		}

		if (typeid(val) == typeid(double))
		{
			this->type = "double";
		}

		if (typeid(val) == typeid(Test))
		{
			this->type = "Test";
		}
	}

	void print()
	{
		if (this->type == "int")
		{
			int* p = (int*) ptr;
			std::cout << *p << " ";
			return;
		}

		if (this->type == "char")
		{
			char* p = (char*) ptr;
			std::cout << *p << " ";
			return;
		}

		if (this->type == "double")
		{
			double* p = (double*)ptr;
			std::cout << *p << " ";
			return;
		}

		if (this->type == "Test")
		{
			Test* p = (Test*) ptr;
			std::cout << p->a << " ";
			return;
		}

	}

};


class JS_array
{
private:
	std::vector<My_type*> vec;

public:
	template <typename T>
	void push_back(T val)
	{
		vec.push_back(new My_type(val));
	}

	void pop_back()
	{
		vec[vec.size() - 1]->~My_type();
		vec.pop_back();
	}

	void print()
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			vec[i]->print();
		}
	}

	~JS_array()
	{
		for (int i = 0; i < vec.size(); ++i)
		{
			vec[i]->~My_type();
		}
	}
};

