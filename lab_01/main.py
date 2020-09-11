from algorithms import *
from color import *


def main():
    output("Input first string:", TURQUOISE)  # Column
    strFirst = input(YELLOW)
    output("Input second string:", TURQUOISE)  # Row
    strSecond = input(YELLOW)
    # LevenshteinDistance(strFirst, strSecond)
    print("Result: ", LevenshteinDistanceRecursion(strFirst, strSecond))


if __name__ == "__main__":
    main()
