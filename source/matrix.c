/**

  Copyright (c) 2023 John G. Gizdich III

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

**/
#include <stdint.h>
#include "matrix.h"

MATRIX_STATUS setMatrixSize(MATRIX *matrix, uint32_t rows, uint32_t columns) {
  if (matrix == 0) {
    return matrixFailure;
  }

  matrix->rows = rows;
  matrix->columns = columns;

  return matrixSuccess;
}

MATRIX_STATUS initializeMatrixWithSingleValue(MATRIX *matrix, uint8_t initialValue) {
  if (matrix == 0) {
    return matrixFailure;
  }

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->data[i][j] = initialValue;
    }
  }

  return matrixSuccess;
}

MATRIX_STATUS initializeMatrixWithIncrementalValues(MATRIX *matrix) {
  int8_t value = 0;
  
  if (matrix == 0) {
    return matrixFailure;
  }

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->data[i][j] = value++;
    }
  }

  return matrixSuccess;
}

static MATRIX_STATUS copyMatrix(MATRIX *matrixA, MATRIX *matrixB) {
  if ((matrixA == 0) || (matrixB == 0)) {
    return matrixFailure;
  }

  matrixB->rows = matrixA->rows;
  matrixB->columns = matrixA->columns;

  for (int i = 0; i < matrixA->rows; i++) {
    for (int j = 0; j < matrixA->columns; j++) {
      matrixB->data[i][j] = matrixA->data[i][j];
    }
  }

  return matrixSuccess;
}

MATRIX_STATUS transposeMatrix(MATRIX *matrix) {
  MATRIX tempMatrix;
  MATRIX_STATUS matrixStatus;

  if (matrix == 0) {
    matrixStatus = matrixFailure;

    return matrixStatus;
  }

  matrixStatus = copyMatrix(matrix, &tempMatrix);

  if (matrixStatus != matrixSuccess) {
    return matrixStatus;
  }

  matrix->rows = tempMatrix.columns;
  matrix->columns = tempMatrix.rows;

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->data[i][j] = tempMatrix.data[j][i];
    }
  }

  return matrixSuccess;
}

/*******************************************

  Start of matrix multiplication functions

********************************************/

MATRIX_STATUS multiplyMatrixWithScalar(MATRIX *matrix, uint8_t scalar) {
  if (matrix == 0) {
    return matrixFailure;
  }

  for (int i = 0; i < matrix->rows; i++) {
    for (int j = 0; j < matrix->columns; j++) {
      matrix->data[i][j] *= scalar;
    }
  }

  return matrixSuccess;
}

static uint8_t canMatricesBeMultiplied(MATRIX *matrixA, MATRIX *matrixB) {
  uint8_t matricesAreNotNull,
          matrixAColumnsMatchWithMatrixBRows;

  matricesAreNotNull                  = (matrixA != 0) && (matrixB != 0);
  matrixAColumnsMatchWithMatrixBRows  = (matrixA->columns == matrixB->rows);

  return (matricesAreNotNull && matrixAColumnsMatchWithMatrixBRows);
}

MATRIX_STATUS multiplyMatrices(MATRIX *matrixA, MATRIX *matrixB, MATRIX *matrixResults) {
  uint8_t sum;

  if (!canMatricesBeMultiplied(matrixA, matrixB) || matrixResults == 0) {
    return matrixFailure;
  }

  setMatrixSize(matrixResults, matrixA->rows, matrixB->columns);

  initializeMatrixWithSingleValue(matrixResults, 0);

  for (int i = 0; i < matrixA->rows; i++) {
    for (int j = 0; j < matrixB->columns; j++) {
      sum = 0;
      for (int k = 0; k < matrixB->rows; k++) {
        // Read column by column for Matrix A and read row by row for Matrix B per iteration.
        // Perform dot product to fill the output matrix.
        sum += matrixA->data[i][k] * matrixB->data[k][j];
      }

      matrixResults->data[i][j] = sum;
    }
  }

  return matrixSuccess;
}

/*******************************************

  End of matrix multiplication functions

********************************************/

/*******************************************

  Start of matrix addition functions

********************************************/

static uint8_t canMatricesBeAddedOrSubtracted(MATRIX *matrixA, MATRIX *matrixB) {
  uint8_t matricesAreNotNull,
          matricesRowsAndColumnsMatch;

  matricesAreNotNull          = (matrixA != 0) && (matrixB != 0);
  matricesRowsAndColumnsMatch = (matrixA->rows == matrixB->rows) && (matrixA->columns == matrixB->columns);

  return (matricesAreNotNull && matricesRowsAndColumnsMatch);
}

MATRIX_STATUS addMatrices(MATRIX *matrixA, MATRIX *matrixB, MATRIX *matrixResults) {
  if (!canMatricesBeAddedOrSubtracted(matrixA, matrixB) || matrixResults == 0) {
    return matrixFailure;
  }

  setMatrixSize(matrixResults, matrixA->rows, matrixB->columns);

  for (int i = 0; i < matrixResults->rows; i++) {
    for (int j = 0; j < matrixResults->columns; j++) {
      matrixResults->data[i][j] = matrixA->data[i][j] + matrixB->data[i][j];
    }
  }

  return matrixSuccess;
}

MATRIX_STATUS SubtractMatrices(MATRIX *matrixA, MATRIX *matrixB, MATRIX *matrixResults) {
  if (!canMatricesBeAddedOrSubtracted(matrixA, matrixB) || matrixResults == 0) {
    return matrixFailure;
  }

  setMatrixSize(matrixResults, matrixA->rows, matrixB->columns);

  for (int i = 0; i < matrixResults->rows; i++) {
    for (int j = 0; j < matrixResults->columns; j++) {
      matrixResults->data[i][j] = matrixA->data[i][j] - matrixB->data[i][j];
    }
  }

  return matrixSuccess;
}

/*******************************************

  End of matrix addition functions

********************************************/
