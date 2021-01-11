#
# Prog 3 multiples two matrices (taken in from the command line)
# and prints them with new lines
#
# Prog 3
# Dalton Tarde
# CS-320 Section 1
# October 19, 2020

import sys

# Verifies input from the command line using len(sys.argv)
# Declares A and B, calls to read_matrices to initialize them,
# and finally stores the return value as C
# Will then print A and B contents with print_matrix,
# and then call mult_matrices
# Error Condition: Output 'Usage: p3.py dataFileName', then sys.exit()
#
# @param input filename from the command line len(sys.argv)
# @return void
def main():
    printid()
    A = []
    B = []
    C = []  # to be returned

    if len(sys.argv) != 1:
        print("Usage: p3.py dataFileName")
        sys.exit()

    read_matrices(A, B)

    print("Matrix A contents:")
    print_matrix(A)
    print()

    print("Matrix B contents:")
    print_matrix(B)
    print()

    print("Matrix A * B is:")
    mult_matrices(A, B, C)

# Reads m, n, and p from the datafile, then matrices A and B are populated with values
# Matrix C is then allocated size m x p, and the values
# for m, n, and p are local values filled in by this function
# Parameter order: list matrix A, list matrix B, RETURN matrix C
# @param A,B
# @return printout
def read_matrices(A,B):
    matrice_values = []
    with open(sys.argv[1]) as f:
        parameters = f.read().splitlines()
        for i in f:
            matrice_values.append(i.split())
    m = int(parameters[1])  # row1
    n = int(parameters[2])  # col1/col2
    p = int(parameters[3])  # row2

    for i in range(m):
        A.append(list[i+3])

    for i in range(n):
        B.append(list[m+i+3])

    C = [[0 for i in range(m)] for j in range(p)]  # used to populate all of C (multiplied)
    return C

# Prints a matrix. Rows and columns should be preserved.
# Parameter order: list the matrix to print
# @param any matrix
# @return void
def print_matrix(matrix):
    print('\n'.join(['\t'.join([str(cell) for cell in row]) for row in matrix]))

# Matrices A and B are multiplied, and matrix C contains the result
# Parameter order: list Matrix A, list Matrix B, list Matrix C (all zeros at this point)
def mult_matrices(A, B, C):
    for i in range(len(A)):
        for j in range(len(B)):
            for k in range(len(B)):
                C[i][j] += A[i][k] * B[k][j]

def printid():
    print("Program 1A, cssc2670, Dalton Tarde")

if __name__ == '__main__':
    main()