#pragma once

#include <cmath>
#include <iostream>
#include <random>
#include <complex>
#include <stdexcept>

using namespace std;

const float EPSILON = 0.00001f;

template<typename T>
class Vector {
	T* _data;
	int _size;
public:
	Vector() : _data(nullptr), _size(0) {}

	Vector(int size, T* vector) {
		if (size <= 0) {
			throw out_of_range("Size of vector cannot be negative or zero");
		}
		_size = size;
		_data = new T[size];
		for (int i = 0; i < size; ++i) {
			_data[i] = vector[i];
		}
	}

	Vector(const int size, const T& min_value, const T& max_value) {
		if (size <= 0) {
			throw out_of_range("Size of vector cannot be negative or zero");
		}
		_size = size;
		_data = new T[size];
		for (int i(0); i < size; ++i) {
			_data[i] = (T)((double)min_value + (double)(rand()) / RAND_MAX * (max_value - min_value));
		}
	}

	Vector(int size) {
		if (size <= 0) {
			throw out_of_range("Size of vector cannot be negative or zero");
		}
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

	T& operator[](const int index) const {
		if (index < 0 || index >= get_size()) {
			throw out_of_range("[Vector::operator[]] Index out of size");
		}
		return _data[index];
	}

	Vector<T> operator=(const Vector<T>& rhs) {
		if (rhs.get_size() != _size) {
			throw runtime_error("[Vector::operator=] Different size.");
		}
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

	friend std::ostream& operator<<(std::ostream& stream, Vector<T>& lhs) {
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
		if (rhs.get_size() != rhs.get_size()) {
			throw runtime_error("[Vector::operator+] Different size.");
		}
		int size = rhs.get_size();
		Vector<T> temp(*this);
		for (int i = 0; i < temp.get_size(); ++i) {
			temp[i] = _data[i] + rhs._data[i];
		}
		return temp;
	}

	template<typename T>
	Vector<T> operator-(const Vector<T>& rhs) {
		if (rhs.get_size() != rhs.get_size()) {
			throw runtime_error("[Vector::operator+] Different size.");
		}
		Vector<T> temp(*this);

		for (int i = 0; i < temp.get_size(); ++i) {
			temp[i] = _data[i] - rhs._data[i];
		}
		return temp;
	}

	template<typename T>
	T operator*(const Vector<T>& rhs) {
		if (rhs.get_size() != rhs.get_size()) {
			throw runtime_error("[Vector::operator+] Different size.");
		}
		T value = 0;

		for (int i = 0; i < rhs.get_size(); ++i) {
			value += _data[i] * rhs._data[i];
		}
		return value;
	}

	template<typename T>
	Vector<T> operator*(const T value) {
		Vector<T> temp(*this);
		for (int i = 0; i < temp.get_size(); ++i) {
			temp._data[i] = value * _data[i];
		}
		return temp;
	}

	template<typename T>
	Vector<T> operator/(const T value) {
		Vector<T> temp(*this);
		for (int i = 0; i < temp.get_size(); ++i) {
			temp._data[i] = _data[i] / value;
		}
		return temp;
	}
	template<typename T>
	bool operator==(const Vector<T>& rhs) {
		if (get_size() == rhs.get_size()) {
			for (int i = 0; i < get_size(); ++i) {
				double val = (_data[i] - rhs._data[i]);
				if (std::abs(val) > EPSILON) {
					return false;
				}
			}
			return true;
		}
		return false;
	}

	template<typename T>
	bool operator!=(const Vector<T>& rhs) {
		return !(*this == rhs);
	}

	T& get_element(const int index) {
		return _data[index];
	}
};

template<typename T>
Vector<T> operator*(const T value, const Vector<T>& lhs) {
	Vector<T> temp(lhs);
	return temp * value;
}

template<typename T>
	Vector<double> find_norm(const Vector<T> other) {
		if (other.get_size() < 2) {
			Vector<double> temp(1);
			return temp;
		}
		Vector<T> temp(other);
		Vector<double> norm(other.get_size());
		norm.get_element(0) = double(((-1) * temp.get_element(1)) / temp.get_element(0));
		norm.get_element(1) = 1.0;
		for (int i = 2; i < norm.get_size(); ++i) {
			norm.get_element(i) = 0.0;
		}

		for (int i = 0; i < norm.get_size(); ++i) {
			norm.get_element(i) = norm.get_element(i) / norm.abs();
		}
		return norm;
	}

	//=============================================================================
	//=============================================================================
	//=============================================================================

	template<typename T>
	class Vector<complex<T>> {
		complex<T>* _data;
		int _size;
	public:
		Vector() : _data(nullptr), _size(0) {}

		Vector(int size, complex<T>* vector) {
			if (size <= 0) {
				throw out_of_range("Size of vector cannot be negative or zero");
			}
			_size = size;
			_data = new complex<T>[size];
			for (int i = 0; i < size; ++i) {
				_data[i] = vector[i];
			}
		}

		Vector(const int size, const T& min_value, const T& max_value) {
			if (size <= 0) {
				throw out_of_range("Size of vector cannot be negative or zero");
			}
			_size = size;
			_data = new complex<T>[size];
			for (int i(0); i < size; ++i) {
				T re = min_value + (T)(rand()) / RAND_MAX * (max_value - min_value);
				T im = min_value + (T)(rand()) / RAND_MAX * (max_value - min_value);
				_data[i] = complex<T>(re, im);
			}
		}

		Vector(int size) {
			if (size <= 0) {
				throw out_of_range("Size of vector cannot be negative or zero");
			}
			_data = new complex<T>[size];
			for (int i = 0; i < size; ++i) {
				_data[i] = complex<T>(0,0);
			}
			_size = size;
		}

		int get_size() const {
			return _size;
		}

		Vector(const Vector<complex<T>>& other) :
			_data(new complex<T>[other._size]),
			_size(other._size)
		{
			for (int i = 0; i < _size; ++i) {
				_data[i] = other._data[i];
			}
		}

		complex<T>& operator[](const int index) const {
			if (index < 0 || index >= get_size()) {
				throw out_of_range("[Vector::operator[]] Index out of size");
			}
			return _data[index];
		}

		Vector<complex<T>> operator=(const Vector<complex<T>>& rhs) {
			if (rhs.get_size() != _size) {
				throw runtime_error("[Vector::operator=] Different size.");
			}
			Vector<complex<T>> copy(rhs);
			swap(copy);
			return *this;
		}

		void swap(Vector<complex<T>> other) {
			std::swap(_data, other._data);
			std::swap(_size, other._size);
		}

		double abs() {
			double value = 0;
			for (int i = 0; i < _size; ++i) {
				value += std::abs(_data[i]);

			}
			return sqrt(value);
		}

		friend std::ostream& operator<<(std::ostream& stream, Vector<complex<T>>& lhs) {
			Vector<complex<T>> temp(lhs);
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

		Vector<complex<T>> operator+(const Vector<complex<T>>& rhs) {
			if (rhs.get_size() != rhs.get_size()) {
				throw runtime_error("[Vector::operator+] Different size.");
			}
			int size = rhs.get_size();
			Vector<complex<T>> temp(*this);
			for (int i = 0; i < temp.get_size(); ++i) {
				temp[i] = _data[i] + rhs._data[i];
			}
			return temp;
		}

		template<typename T>
		Vector<complex<T>> operator-(const Vector<complex<T>>& rhs) {
			if (rhs.get_size() != rhs.get_size()) {
				throw runtime_error("[Vector::operator+] Different size.");
			}
			Vector<complex<T>> temp(*this);

			for (int i = 0; i < temp.get_size(); ++i) {
				temp[i] = _data[i] - rhs._data[i];
			}
			return temp;
		}

		template<typename T>
		complex<T> operator*(const Vector<complex<T>>& rhs) {
			if (rhs.get_size() != rhs.get_size()) {
				throw runtime_error("[Vector::operator+] Different size.");
			}
			complex<T> value = complex<T>(0, 0);

			for (int i = 0; i < rhs.get_size(); ++i) {
				value += (_data[i] * complex<T>(rhs._data[i].real(), rhs._data[i].imag() * (-1)));
			}
			return value;
		}

		template<typename T>
		Vector<complex<T>> operator*(const complex<T> value) {
			Vector<complex<T>> temp(*this);
			for (int i = 0; i < temp.get_size(); ++i) {
				temp._data[i] = value * _data[i];
			}
			return temp;
		}

		template<typename T>
		Vector<complex<T>> operator/(const complex<T> value) {
			Vector<complex<T>> temp(*this);
			for (int i = 0; i < temp.get_size(); ++i) {
				temp._data[i] = _data[i] / value;
			}
			return temp;
		}
		template<typename T>
		bool operator==(const Vector<complex<T>>& rhs) {
			if (get_size() == rhs.get_size()) {
				for (int i = 0; i < get_size(); ++i) {
					auto val = (_data[i] - rhs._data[i]);
					if (std::abs(val) > EPSILON) {
						return false;
					}
				}
				return true;
			}
			return false;
		}

		template<typename T>
		bool operator!=(const Vector<complex<T>>& rhs) {
			return !(*this == rhs);
		}

		complex<T>& get_element(const int index) {
			return _data[index];
		}
	};

	template<typename T>
	Vector<complex<T>> operator*(const complex<T> value, const Vector<complex<T>>& lhs) {
		Vector<complex<T>> temp(lhs);
		return temp * value;
	}

	template<typename T>
	Vector<complex<double>> find_norm(const Vector<complex<T>> other) {
		if (other.get_size() < 2) {
			Vector<complex<double>> temp(1);
			return temp;
		}
		Vector<T> temp(other);
		Vector<double> norm(other.get_size());
		norm.get_element(0) = complex<double>((-1) * temp.get_element(1));
		norm.get_element(1) = 1.0;
		for (int i = 2; i < norm.get_size(); ++i) {
			norm.get_element(i) = 0.0;
		}

		for (int i = 0; i < norm.get_size(); ++i) {
			norm.get_element(i) = norm.get_element(i) / norm.abs();
		}
		return norm;
	}


