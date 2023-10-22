#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 100

void populateArr(int size, int matrix[][MAX_SIZE], ifstream& filein);
void printArr(int size, int matrix[][MAX_SIZE]);
void addArr(int size, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]);
void multiplyArr(int size, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]);
void subArr(int size, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]);

int main()
{
    ifstream filein;
    filein.open("matrix_input.txt");
    
    if(!filein){
        throw std::runtime_error("File not found");
    }
        
    int size;
    filein >> size;
        
    if (size > MAX_SIZE){
        throw std::runtime_error("The matrix is too large");
    }
        
    int matrix1[MAX_SIZE][MAX_SIZE];
    int matrix2[MAX_SIZE][MAX_SIZE];
    
    
    populateArr(size, matrix1, filein);
    populateArr(size, matrix2, filein);
    
    filein.close();
    
    cout << "Matrix A: \n";
    printArr(size, matrix1);
    cout << "\nMatrix B: \n";
    printArr(size, matrix2);
    
    cout << "\n";
    addArr(size, matrix1, matrix2);
    cout << "\n";
    multiplyArr(size, matrix1, matrix2);
    cout << "\n";
    subArr(size, matrix1, matrix2);
    
    return 0;
}

void populateArr(int size, int matrix[][MAX_SIZE], ifstream& filein){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            filein >> matrix[i][j];
        }
    }
}

void printArr(int size, int matrix[][MAX_SIZE]){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            int num = matrix[i][j];
            int numWidth = 1;
            if (num < 0) {
                numWidth++;
                num = -num;
            }
            while (num >= 10) {
                numWidth++;
                num /= 10;
            }
            for (int k = 0; k < 4 - numWidth; k++) {
                cout << ' '; // Pad with spaces
            }
            cout << matrix[i][j] << ' ';
        }
        cout << "\n";
    }
}

void addArr(int size, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]){
    int matrix3[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    cout << "Summed Array (A + B): \n";
    printArr(size, matrix3);
}

void multiplyArr(int size, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]){
    int matrix3[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix3[i][j] = 0;
            for (int k = 0; k < size; k++) {
                matrix3[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    cout << "Product Array (A * B): \n";
    printArr(size, matrix3);
}

void subArr(int size, int matrix1[][MAX_SIZE], int matrix2[][MAX_SIZE]){
    int matrix3[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix3[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    cout << "Difference Array (A - B): \n";
    printArr(size, matrix3);
}