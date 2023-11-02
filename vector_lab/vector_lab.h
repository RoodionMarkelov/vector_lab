#pragma once

#include <iostream>

namespace lab {
	const float EPSILON = 0.00001f;

	template<typename T>
	class Vector {
		T* _data;
		int _size;
	public:
		Vector() : _data(nullptr), _size(0) {}

		Vector(int size, T* vector) {
			_size = size;
			_vect = new T[size];
			for (int i = 0; i < size; ++i) {
				_vect[i] = vector[i];
			}
		}

		Vector(int size) {
			_vect = new T[size];
			for (int i = 0; i < size; ++i) {
				_vect[i] = 0;
			}
			_size = size;
		}

		int get_size() const {
			return _size;
		}

	};
}