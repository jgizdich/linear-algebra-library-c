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