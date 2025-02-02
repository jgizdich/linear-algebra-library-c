/**

  Copyright (c) 2023-2025 John G. Gizdich III

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
#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MAX_NUMBER_OF_ROWS            1000
#define MAX_NUMBER_OF_COLUMNS         1000

typedef struct {
  uint8_t  data[MAX_NUMBER_OF_ROWS][MAX_NUMBER_OF_COLUMNS];
  uint32_t numberOfRows;
  uint32_t numberOfColumns;
  uint32_t initializedSignature;
} MATRIX;

typedef enum {
  matrixSuccess,
  matrixFailure
} MATRIX_STATUS;

MATRIX_STATUS setMatrixSize(MATRIX *matrix, uint32_t numberOfRows, uint32_t numberOfColumns);
MATRIX_STATUS insertMatrixDataEntry(MATRIX *matrix, uint16_t row, uint16_t col, int16_t dataEntry);
MATRIX_STATUS initializeMatrixWithSingleValue(MATRIX *matrix, uint8_t initialValue);
MATRIX_STATUS initializeMatrixWithIncrementalValues(MATRIX *matrix);
MATRIX_STATUS transposeMatrix(MATRIX *matrix);
MATRIX_STATUS multiplyMatrixWithScalar(MATRIX *matrix, uint8_t scalar);
MATRIX_STATUS multiplyMatrices(MATRIX *matrixA, MATRIX *matrixB, MATRIX *matrixResults);
MATRIX_STATUS addMatrices(MATRIX *matrixA, MATRIX *matrixB, MATRIX *matrixResults);

#endif // _MATRIX_H_