#include <iostream>
#include <cstdlib>

void matrixFilling(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            matrix[i][j] = rand() % 70 + 1;
        }
    }
}


void displayMatrix(int** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int rows, columns;
    std::cout << "Type the amount of rows: ";
    std::cin >> rows;
    std::cout << "Type the amount of columns: ";
    std::cin >> columns;

    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[columns];
    }

    matrixFilling(matrix, rows, columns);
    std::cout << "Matrix:" << std::endl;
    displayMatrix(matrix, rows, columns);

    int sum = 0;
    int size = std::min(rows, columns);
    for (int i = 0; i < size; ++i) {
        sum += matrix[i][size - 1 - i];
    }
    std::cout << "Summ of diagonal elements: " << sum << std::endl;



    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
    