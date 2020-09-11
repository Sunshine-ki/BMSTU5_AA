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
                int(not(strFirst[i-1] == strSecond[j-1])),  # R
                matrix[i - 1][j] + 1,                       # D
                matrix[i][j - 1] + 1)                       # I

    OutputMatrix(matrix, strFirst, strSecond)



def LevenshteinDistanceRecursion(strFirst, strSecond):
    if (strFirst == "" or strSecond == ""):
        return abs(len(strFirst) - len(strSecond))

    temp = 0 if strFirst[-1] == strSecond[-1] else 1
    return min(
        LevenshteinDistanceRecursion(strFirst, strSecond[:-1]) + 1,           # I
        LevenshteinDistanceRecursion(strFirst[:-1], strSecond) + 1,           # D
        LevenshteinDistanceRecursion(strFirst[:-1], strSecond[:-1]) + temp    # R
    )
