from matrix_multiplication import *
from matrix import *
from color import *


def main():
    # output("МАТРИЦА A", BLUE)
    # n = int(input(GREEN + "Введите кол-во строк: "))
    # m = int(input(GREEN + "Введите кол-во столбцов: "))
    # output("Введите матрицу:", GREEN)
    # matrixA = Matrix(n, m, [[int(j) for j in input(GREEN).split()]
    #                         for i in range(n)])

    # output("МАТРИЦА B", BLUE)
    # k = int(input(GREEN + "Введите кол-во строк: "))
    # l = int(input(GREEN + "Введите кол-во столбцов: "))
    # output("Введите матрицу:", GREEN)
    # matrixB = Matrix(k, l, [[int(j) for j in input(GREEN).split()]
    #                         for i in range(k)])

    # if m != k:
    #     output("Некорректные размеры матриц!", RED)
    #     return

    # matrixC = WinogradOptimization(matrixA, matrixB)
    # matrixC.output()

    matrixA = Matrix(3, 2, [[2, 3], [1, 0], [2, 2]])
    matrixB = Matrix(2, 4, [[2, 2, 1, 9], [4, 2, 8, 1]])
    matrixC = WinogradMult(matrixA, matrixB)
    matrixC.output()

    # matrixA = Matrix(3, 3, [[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    # matrixB = Matrix(3, 3, [[1, 0, 0], [0, 1, 0], [0, 0, 1]])
    # matrixC = WinogradOptimization(matrixA, matrixB)
    # matrixC.output()


if __name__ == "__main__":
    main()
