#include <stdint.h>
#include "matrix.h"

void initializeMatrixWithSingleValue(uint32_t matrix[MAX_NUMBER_OF_ROWS][MAX_NUMBER_OF_COLUMNS], uint32_t rows, uint32_t columns, uint32_t initialValue) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] = initialValue;
    }
  }
}

void multiplyMatrixWithScalar(uint32_t scalar, uint32_t matrix[MAX_NUMBER_OF_ROWS][MAX_NUMBER_OF_COLUMNS], uint32_t rows, uint32_t columns) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix[i][j] *= scalar;
    }
  }
}