#include "matrix.h"

matrix::matrix() {
	size_N = 0;
	size_M = 0;
	matr = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		matr[i] = new double[size_M];

}

matrix::matrix(int n, int m) {
	size_N = n;
	size_M = m;

	matr = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		matr[i] = new double[size_M];
}

matrix::matrix(int n, int m, double** new_matr) {
	size_N = n;
	size_M = m;

	matr = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		matr[i] = new double[size_M];

	for (int i = 0; i < size_N; i++) {
		for (int j = 0; i < size_M; j++) {
			matr[i][j] = new_matr[i][j];
		}
	}
}

matrix::~matrix() {
	for (int i = 0; i < size_N; i++) //   для каждой строки
	{
		delete[] matr[i]; //  , удаление памяти выделенно
		
	}
	delete[] matr; //  , удаление памяти выделенной
}