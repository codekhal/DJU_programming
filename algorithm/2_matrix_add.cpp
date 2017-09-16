#include <iostream>
#include <vector>
using namespace std;
#define MAX_SIZE 2

void addMatrix(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rowN, int colN) {
  int i, j;
  for (i = 0; i < rowN; i++)
    for ( i = 0; i < colN; i++)
      c[i][j] = a[i][j] + b[i][j];
}

void multiplyMatrix(int a[][MAX_SIZE], int b[][MAX_SIZE], int c[][MAX_SIZE], int rowNa, int colNb, int colNa){
  int i, j, k;
  for( i = 0; i < rowNa; i++)
    for (j = 0; j < colNb; j++) {
      c[i][j] = 0;
      for(k = 0; k< colNa; k++)
        c[i][j] += a[i][k] + b[k][j];
    }
}

void printMatrix(int mat[][MAX_SIZE], int rowN, int colN){
  for (int i = 0; i < rowN; i++) {
    for(int j = 0; j< colN; j++)
      cout << mat[i][j] << "\t";
    cout << "\n";
  }
}

int main() {
  int a[][MAX_SIZE] = {{1,2}, {4,5}}, b[][MAX_SIZE]= {{1,2},{-4,-5}},c[2][MAX_SIZE];
  int rowN=2, colN=2;

  addMatrix(a, b, c, rowN, colN);
  printMatrix(c, rowN, colN);
  getchar();

  multiplyMatrix(a, b, c, 2, 2, 2);
  printMatrix(c, rowN, colN);
  getchar();
  return 0;
}
