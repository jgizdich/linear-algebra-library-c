# Linear Algebra Library
This library performs linear algebra computations for your projects.

## Matrix Data Structure
This library provides a special data structure that forms a matrix, and the code snippet below declares one.

```C
MATRIX matrix;
```

To set the size of the matrix that was declared above, it can be done so with the code snippet below.

```C
setMatrixSize(&matrix, 2, 3);
```

The code snippet above is defining the matrix to be the size of 2x3 with the function, setMatrixSize. The code snippet below shows the function's declaration.

```C
MATRIX_STATUS setMatrixSize(MATRIX *matrix, uint32_t rows, uint32_t columns);
```

The return type of that function is MATRIX_STATUS, and it is of enum data type where the function either returns matrixSuccess or matrixFailure. The enum, matrixSuccess, signifies that the matrix computation was successful while the enum, matrixFailure, signfies that there is an issue with the computation.

The data entries in a matrix can be populated as shown below where num is any signed integer value.

```C
matrix->data[row][col] = num;
```

## Transpose
```math
A = \begin{bmatrix}1 & 2 & 3\\4 & 5 & 6 \end{bmatrix} \\\ \\\ A^T = \begin{bmatrix}1 & 4\\2 & 5\\3 & 6 \end{bmatrix}
```

A matrix can be transposed as shown above by using the transposeMatrix function. The declaration of that function is shown below.

```C
MATRIX_STATUS transposeMatrix(MATRIX *matrix, MATRIX *matrixResults);
```
The first parameter is an input matrix to be transposed, and the second parameter is the transposed version of the input matrix. The caller is expected to declare the output matrix as well and pass it by reference to this function. The function automatically sets the size of the newly transposed matrix and populates its data entry accordingly via the transpose operation rules.

## Scalar Multiplication
```math
cA = \begin{bmatrix}1c & 2c & 3c\\4c & 5c & 6c \end{bmatrix}
```
A matrix can be multiplied by any scalar value as shown above by using the multiplyMatrixWithScalar function. The declaration of that function is shown below.

```c
MATRIX_STATUS multiplyMatrixWithScalar(MATRIX *matrix, uint8_t scalar);
```

The first parameter is an input matrix to be multiplied by a scalar value, and the second parameter is the scalar value itself. This function overrides the input matrix's data by multiplying each entry in the matrix by the scalar value. Therefore, the first parameter is also an output matrix when the function returns to the caller. There is no need to declare another matrix for this function since the matrix's shape does not change.
