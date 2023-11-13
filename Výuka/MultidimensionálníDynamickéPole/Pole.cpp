// MultidimensionalDynamicArrays.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
//dú sčítání matic 
using namespace std;
struct Matrix {
    int rows;
    int cols;
    int** matrix;
};
Matrix initMatrix(int rows, int cols);
int** init2DArrray(int rows, int cols);
void print_2d_array(int** matix);

Matrix initMatrix()

int main()
{

    int rows, cols;
    cout << "rows1: ";
    cin >> rows;
    cout << "cols2: ";
    cin >> cols;
    Matrix matrix1=initMatrix(rows,cols);
    print_2d_array(matrix1.matrix, rows, cols);

    //init array of pointers in dynamic memory to arrrays of integer
    int** array = new int* [rows];

    //init each array of integers in dynamic memory
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }

    array[0][0] = 42;

    print_2d_array(array, rows, cols);

    //dealocation of each array of integers in dynamic memory
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }

    //dealocation of array of pointers in dynamic memory pointing to dealocated arrrays of integers
    delete[] array;
    array = NULL;

    //return 0;
}

void print_2d_array(int** arr, int rows, int cols) {
    /*
    * Tisk 2d pole.
    */
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            //cout << format("{}\t", arr[i][j]);
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}