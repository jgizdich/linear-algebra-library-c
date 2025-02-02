# Linear Algebra Library
This library performs linear algebra computations for your projects.

## Matrix Data Structure
This library provides a special data structure that forms a matrix, and the code snippet below declares one.

```
MATRIX matrix;
```

To set the size of the matrix that was declared above, it can be done so with the code snippet below.

```
setMatrixSize(&matrix, 2, 3);
```

The code snippet above is defining the matrix to be the size of 2x3 with the function, setMatrixSize. The code snippet below shows the function's declaration.

```
MATRIX_STATUS setMatrixSize(MATRIX *matrix, uint32_t rows, uint32_t columns);
```

The return type of that function is MATRIX_STATUS, and it is of enum data type where the function either returns matrixSuccess or matrixFailure. The enum, matrixSuccess, signifies that the matrix computation was successful while the enum, matrixFailure, signfies that there is an issue with the computation.

The data entries in a matrix can be populated as shown below where num is any signed integer value.

```
matrix->data[row][col] = num;
```
