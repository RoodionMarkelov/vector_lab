// vector_lab.cpp: определяет точку входа для приложения.
//
#include "vector_lab.h"

using namespace std;

int main()
{
	Vector<int> a;
	Vector<float> b(2);
	Vector<float> c(b);

	double a1[] = { 3.0, 4.0, 0.7 };
	Vector<double> d1(3, a1);

	int a2[] = { 3, 4, 0 };
	Vector<int> d2(3, a2);

	float a3[] = { 3.0f, 4.0f, 0.5f };
	Vector<float> d3(3, a3);

	//=====================================
	//Constructor + .abs()
	//=====================================

	std::cout << a.get_size() << endl;
	std::cout << b.get_size() << endl;
	std::cout << c.get_size() << endl;
	std::cout << d1.get_size() << endl;
	std::cout << "Vector: " << b << endl;
	std::cout << "Vector: " << d1 << endl;
	std::cout << "Vector: " << d2 << endl;
	std::cout << "Vector: " << d3 << endl;
	std::cout << "abs: " << d1.abs() << endl;
	std::cout << "abs: " << d2.abs() << endl;
	std::cout << "abs: " << d3.abs() << endl;

	//=======================================
	//Operator
	//=======================================

	Vector<double> v1 = d1 + d1;
	Vector<int> v2 = d2 + d2;
	Vector<float> v3 = d3 + d3;

	std::cout << "Vector: " << v1 << endl;
	std::cout << "Vector: " << v2 << endl;
	std::cout << "Vector: " << v3 << endl;

	Vector<double> v11 = d1 - d1;
	Vector<int> v22 = d2 - d2;
	Vector<float> v33 = d3 - d3;

	std::cout << "Vector: " << v11 << endl;
	std::cout << "Vector: " << v22 << endl;
	std::cout << "Vector: " << v33 << endl;

	return 0;
}
