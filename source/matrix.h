#ifndef _MATRIX_H_
#define _MATRIX_H_

#define MAX_NUMBER_OF_ROWS  1000
#define MAX_NUMBER_OF_COLUMNS 1000

void initializeMatrixWithSingleValue(uint32_t matrix[MAX_NUMBER_OF_ROWS][MAX_NUMBER_OF_COLUMNS], uint32_t rows, uint32_t columns, uint32_t initialValue);

void multiplyMatrixWithScalar(uint32_t scalar, uint32_t matrix[MAX_NUMBER_OF_ROWS][MAX_NUMBER_OF_COLUMNS], uint32_t rows, uint32_t columns);

#endif // _MATRIX_H_