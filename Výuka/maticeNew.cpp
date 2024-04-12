#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Matrix {
    int rows;
    int cols;
    int** matrix;
};

void init2DArray(int**& arr, int rows, int cols) {
    arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }
}

void initMatrix(Matrix& m, int rows, int cols) {
    m.rows = rows;
    m.cols = cols;
    init2DArray(m.matrix, rows, cols);
}

void printMatrix(Matrix m) {
    for (int i = 0; i < m.rows; i++) {
        for (int j = 0; j < m.cols; j++) {
            cout << m.matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void perplus(Matrix m1, Matrix m2) {
    Matrix result;
    if (m1.rows == m2.rows && m1.cols == m2.cols) {
        initMatrix(result, m1.rows, m1.cols);
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.cols; j++) {
                result.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
            }
        }
        cout << "Result = " << endl;
        printMatrix(result);
    }
    else {
        cout << "Zle rozmery matic" << endl;
    }
}

void perminus(Matrix m1, Matrix m2) {
    Matrix result;
    if (m1.rows == m2.rows && m1.cols == m2.cols) {
        initMatrix(result, m1.rows, m1.cols);
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m1.cols; j++) {
                result.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
            }
        }
        cout << "Result = " << endl;
        printMatrix(result);
    }
    else {
        cout << "Zle rozmery matic" << endl;
    }
}

void pertimes(Matrix m1, Matrix m2) {
    if (m1.cols == m2.rows) {
        Matrix result;
        initMatrix(result, m1.rows, m2.cols);
        for (int i = 0; i < m1.rows; i++) {
            for (int j = 0; j < m2.cols; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < m1.cols; k++) {
                    result.matrix[i][j] += m1.matrix[i][k] * m2.matrix[k][j];
                }
            }
        }
        cout << "Result = " << endl;
        printMatrix(result);
    }
    else {
        cout << "Zle rozmery matic" << endl;
    }
}

int main() {
    Matrix m1, m2;
    int rows, cols;
    char operation;

    cout << "Riadky 1. M ";
    cin >> rows;

    cout << "Stlpce 1. M ";
    cin >> cols;

    initMatrix(m1, rows, cols);

    for (int i = 0; i < m1.rows; i++) {
        for (int j = 0; j < m1.cols; j++) {
            m1.matrix[i][j] = rand() % 10; // random cisla do desat
        }
    }

    cout << "M1" << endl;
    printMatrix(m1);

    cout << "Zvol operand (+, -, *): ";
    cin >> operation;

    cout << "Riadky 2. M ";
    cin >> rows;

    cout << "Stlpce 2. M ";
    cin >> cols;

    initMatrix(m2, rows, cols);

    for (int i = 0; i < m2.rows; i++) {
        for (int j = 0; j < m2.cols; j++) {
            m2.matrix[i][j] = rand() % 10; 
        }
    }

    cout << "M2" << endl;
    printMatrix(m2);

    switch (operation) {
    case '+':
        perplus(m1, m2);
        break;
    case '-':
        perminus(m1, m2);
        break;
    case '*':
        pertimes(m1, m2);
        break;
    default:
        cout << "Zly operand" << endl;
        break;
    }

    return 0;
}
