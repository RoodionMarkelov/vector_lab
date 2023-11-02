#pragma once

#include <iostream>
#include <stdexcept>

const float EPSILON = 0.00001f;

template<typename T>
class Vector {
	T* _data;
	int _size;
public:
	Vector() : _data(nullptr), _size(0) {}

	Vector(int size, T* vector) {
		_size = size;
		_data = new T[size];
		for (int i = 0; i < size; ++i) {
			_data[i] = vector[i];
		}
	}

	Vector(int size) {
		_data = new T[size];
		for (int i = 0; i < size; ++i) {
			_data[i] = 0;
		}
		_size = size;
	}

	int get_size() const {
		return _size;
	}

	Vector(const Vector<T>& other) :
		_data(new T[other._size]),
		_size(other._size)
	{
		for (int i = 0; i < _size; ++i) {
			_data[i] = other._data[i];
		}
	}

	T& operator[](const int index) const{
		/*if (index < 0 || _size <= index) {
			throw out_of_range("[Vector::operator[]] Index is out of range.");
		}*/
		return _data[index];
	}

	Vector<T> operator=(const Vector<T>& rhs) {
		/*if (rhs.get_size() != _size) {
			throw runtime_error("[Vector::operator=] Different size.");
		}*/
		Vector<T> copy(rhs);
		swap(copy);
		return *this;
	}

	void swap(Vector<T> other) {
		std::swap(_data, other._data);
		std::swap(_size, other._size);
	}

	double abs() {
		double value = 0;
		for (int i = 0; i < _size; ++i) {
			value += pow(double(_data[i]), 2);
		}
		return sqrt(value);
	}

	friend std::ostream& operator<<(std::ostream& stream, Vector& lhs) {
		Vector<T> temp(lhs);
		stream << "(";
		for (int i = 0; i < temp.get_size(); ++i) {
			if (i == temp.get_size() - 1) {
				stream << temp._data[i] << ")";
				continue;
			}
			stream << temp._data[i] << ",";
		}

		return stream;
	}

	~Vector() {
		delete[] _data;

		_data = nullptr;
		_size = 0;
	}


	template<typename T>
	Vector<T> operator+(const Vector<T>& rhs) {
		/*if (lhs.get_size() != rhs.get_size()) {
			throw runtime_error("[Vector::operator+] Different size.");
		}*/
		int size = rhs.get_size();
		Vector<T> temp(*this);
		for (int i = 0; i < temp.get_size(); ++i) {
			temp[i] = _data[i] + rhs._data[i];
		}
		return temp;
	}

	template<typename T>
	Vector<T> operator-(const Vector<T>& rhs) {
		/*if (lhs.get_size() != rhs.get_size()) {
			throw runtime_error("[Vector::operator+] Different size.");
		}*/
		Vector<T> temp(*this);

		for (int i = 0; i < temp.get_size(); ++i) {
			temp[i] = _data[i] - rhs._data[i];
		}
		return temp;
	}

};
