import numpy as np


def main() -> None:
    matrix_a = np.loadtxt("matrixA.txt", skiprows=1)
    matrix_b = np.loadtxt("matrixB.txt", skiprows=1)
    result1 = np.loadtxt("result.txt", skiprows=1)

    result2 = np.dot(matrix_a, matrix_b)

    if (np.allclose(result1, result2)):
        print("Умножение матриц выполнено правильно")
    else:
        print("Допущены ошибки при вычислении")


if __name__ == "__main__":
    main()