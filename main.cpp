#include <iostream>
#include <vector>
#include <map>
#include <locale>
#include "matrix.hpp"

int main() {
	setlocale(LC_ALL, "RU");
	Matrix<int> matr_A(2, 2);
	Matrix<int> matr_B(2, 3);

	matr_A.fill();
	matr_B.fill();
	matr_A.print();
	matr_B.print();

	try {
		std::cout << (matr_A * matr_B);
	}
	catch (std::invalid_argument& error) {
		std::cout << error.what();
	}
	return 0;
}