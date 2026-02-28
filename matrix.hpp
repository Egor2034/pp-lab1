#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <concepts>

template <typename T> requires std::is_arithmetic_v<T>
class Matrix {
private:
	size_t _rows, _columns;
	T** _data;

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& other) {
		for (size_t i = 0; i < other.rows(); i++) {
			for (size_t j = 0; j < other.columns(); j++) {
				os << other(i, j) << " ";
			}
			os << "\n";
		}

		return os;
	}
public:
	Matrix() {
		_rows = 0;
		_columns = 0;
		_data = nullptr;
	}

	Matrix(size_t rows, size_t columns) : _rows(rows), _columns(columns) {
		_data = new T*[_rows];

		for (size_t i = 0; i < _rows; i++) {
			_data[i] = new T[_columns]();
		}
	}

	Matrix(const Matrix<T>& other) : Matrix(other.rows(), other.columns()) {
		for (size_t i = 0; i < _rows; i++) {
			for (size_t j = 0; j < _columns; j++) {
				_data[i][j] = other(i, j);
			}
		}
	}

	~Matrix() {
		for (size_t i = 0; i < _rows; i++) {
			delete[] _data[i];
		}
		delete[] _data;
	}

	void print() const {
		for (size_t i = 0; i < _rows; i++) {
			for (size_t j = 0; j < _columns; j++) {
				std::cout << _data[i][j] << " ";
			}
			std::cout << "\n";
		}
	}

	void fill() {
		for (size_t i = 0; i < _rows; i++) {
			for (size_t j = 0; j < _columns; j++) {
				std::cin >> _data[i][j];
			}
		}
	}

	size_t rows() const { return _rows; }
	size_t columns() const { return _columns; }

	T& operator()(size_t row, size_t column) {
		return _data[row][column];
	}

	const T& operator()(size_t row, size_t column) const {
		return _data[row][column];
	}

	Matrix operator*(const Matrix<T>& other) const {
		if (_columns != other.rows()) {
			throw std::invalid_argument("Число столбцов первой матрицы не равно числу строк второй!");
		}

		Matrix<T> matr(_rows, other.columns());

		for (size_t i = 0; i < _rows; i++) {
			for (size_t j = 0; j < other.columns(); j++) {
				for (size_t k = 0; k < _rows; k++) { 
					matr(i, j) += _data[i][k] * other(k, j);
				}
			}
		}

		return matr;
	}

};

#endif