#include <iostream>
#include <locale>
#include <fstream>
#include <windows.h>
#include "matrix.hpp"

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");

	try{
		Matrix<float> ac = read_from_file<float>("matrixA.txt");
		Matrix<float> anb = read_from_file<float>("matrixB.txt");
		Matrix<float> result = ac * anb;
		save_to_file(result, "result.txt");
	}
	catch (std::exception& ex){
		std::cout << ex.what();
	}
	return 0;
}