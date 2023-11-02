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

	std::cout << "Operaror+: " << endl;
	std::cout << "Vector: " << v1 << endl;
	std::cout << "Vector: " << v2 << endl;
	std::cout << "Vector: " << v3 << endl;

	Vector<double> v11 = d1 - d1;
	Vector<int> v21 = d2 - d2;
	Vector<float> v31 = d3 - d3;

	std::cout << "Operaror-: " << endl;
	std::cout << "Vector: " << v11 << endl;
	std::cout << "Vector: " << v21 << endl;
	std::cout << "Vector: " << v31 << endl;

	Vector<double> v12 = d1 * 2.0;
	Vector<int> v22 = d2 * 2;
	Vector<float> v32 = d3 * 2.0f;
	std::cout << "Operaror* vector on val " << endl;
	std::cout << "Vector: " << v12 << endl;
	std::cout << "Vector: " << v22 << endl;
	std::cout << "Vector: " << v32 << endl;

	Vector<double> v13 = 2.0 * d1;
	Vector<int> v23 = 2 * d2;
	Vector<float> v33 = 2.0f * d3;

	std::cout << "Operaror* val on vector " << endl;
	std::cout << "Vector: " << v13 << endl;
	std::cout << "Vector: " << v23 << endl;
	std::cout << "Vector: " << v33 << endl;

	Vector<double> v14 = d1 / 2.0;
	Vector<int> v24 = d2 / 2;
	Vector<float> v34 = d3 / 2.0f;

	std::cout << "Operaror/ " << endl;
	std::cout << "Vector: " << v14 << endl;
	std::cout << "Vector: " << v24 << endl;
	std::cout << "Vector: " << v34 << endl;

	double a11[] = { 3.0, 4.0, 0.6 };
	Vector<double> d11(3, a11);

	int a22[] = { 3, 5, 0 };
	Vector<int> d22(3, a22);

	float a33[] = { 1.0f, 4.0f, 0.5f };
	Vector<float> d33(3, a33);

	std::cout << "Operaror bool: " << endl;
	std::cout << (d11 == d1) << endl;
	std::cout << (d1 == d1) << endl;
	std::cout << (d22 == d2) << endl;
	std::cout << (d2 == d2) << endl;
	std::cout << (d33 == d3) << endl;
	std::cout << (d3 == d3) << endl;
	std::cout << "Now reverse bool: " << endl;
	std::cout << (d11 != d1) << endl;
	std::cout << (d1 != d1) << endl;
	std::cout << (d22 != d2) << endl;
	std::cout << (d2 != d2) << endl;
	std::cout << (d33 != d3) << endl;
	std::cout << (d3 != d3) << endl;

	//==============================
	//find_norm
	//==============================
	Vector<double> vec1 = find_norm(d1);
	Vector<double> vec2 = find_norm(d2);
	Vector<double> vec3 = find_norm(d3);

	std::cout << "Vector: " << d1 << endl;
	std::cout << "Vector: " << d2 << endl;
	std::cout << "Vector: " << d3 << endl;
	std::cout << vec1 << endl;
	std::cout << vec2 << endl;
	std::cout << vec3 << endl;
	

	return 0;
}
