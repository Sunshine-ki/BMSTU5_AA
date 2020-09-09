import numpy as np
import math


def OutputMatrix(matrix, strFirst, strSecond):
    # TODO: Добавить в вывод матрицы вывод строк.
    print("\nMatrix:\n")
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            print(matrix[i][j], end=" ")
        print("")
    print("\n__________\n")


def LevenshteinDistance(strFirst, strSecond):
    n, m = len(strFirst), len(strSecond)
    matrix = np.full((n + 1, m + 1), math.inf)

    matrix[0][0] = 0
    for i in range(1, n + 1):
        matrix[i][0] = i
    for i in range(1, m + 1):
        matrix[0][i] = i

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            matrix[i][j] = min(
                matrix[i - 1][j - 1] +
                int(not(strFirst[i-1] == strSecond[j-1])),
                matrix[i - 1][j] + 1,
                matrix[i][j - 1] + 1)

    OutputMatrix(matrix, strFirst, strSecond)
