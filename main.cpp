#include <iostream>
#include <locale>
#include <fstream>
#include <windows.h>
#include <chrono>
#include "matrix.hpp"

void save_info(std::string file_name, size_t matrix_size, std::chrono::milliseconds duration) {
	std::ofstream file;

	file.open(file_name);

  	if (!file.is_open()) {
    	throw std::exception("Ошибка при открытии файла!");
	}

	file << "Размер матриц: " << matrix_size << "x" << matrix_size << "\n";
	file << "Объём работы: " << Matrix<float>::total_operations() << " операций\n";
	file << "Время выполнения: " << duration.count() << " мс\n";
	
	file.close();
	 
}

int main() {
	SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "ru_RU.UTF-8");

	try{
		Matrix<float> matrix_a = read_from_file<float>("matrixA.txt");
		Matrix<float> matrix_b = read_from_file<float>("matrixB.txt");

		auto start = std::chrono::high_resolution_clock::now();

		Matrix<float> result = matrix_a * matrix_b;

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
		
		save_to_file(result, "result.txt");
		save_info("info.txt", matrix_a.rows(), duration);
	}
	catch (std::exception& ex){
		std::cout << ex.what();
	}
	return 0;
}