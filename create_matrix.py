import argparse
import numpy as np
import random


def generate_matrix(size: int, filename: str, seed: int) -> None:
    """Генерация случайной матрицы и сохранение в файл"""
    if seed is not None:
        np.random.seed(seed)
    
    matrix = np.random.rand(size, size) * 10
    
    with open(filename, 'w', encoding='utf-8') as file:
        file.writelines(f"{size} {size}\n")
        
        for i in range(size):
            for j in range(size):
                file.write(f"{matrix[i][j]:.4f} ")
            file.write("\n")


def get_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser()
    parser.add_argument('-s', '--size', help='Размерность матриц')

    return parser.parse_args()


def main() -> None:
    size = int(get_args().size)
    seedA = random.randint(1, 100)
    seedB = random.randint(40, 140)

    generate_matrix(size, "matrixA.txt", seedA)
    generate_matrix(size, "matrixB.txt", seedB)


if __name__ == "__main__":
    main()