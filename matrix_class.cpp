#include "matrix_class.h"


matr::matr() {
	
	mass = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		mass[i] = new double[size_M];

	for (int i = 0; i < size_N; i++) {
		for (int j = 0; j < size_M; j++) {
		     mass[i][j] = 0;
		}
	}

}

matr::matr(int n, int m) {
	if (size_N != 0 && size_M != 0 ) {
	for (int i = 0; i < size_N; i++) //   для каждой строки
	{
		delete[] mass[i]; //  , удаление памяти выделенно

	}
	delete[] mass;
	}
	size_N = n;
	size_M = m;
	mass = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		mass[i] = new double[size_M];

	for (int i = 0; i < size_N; i++) {
		for (int j = 0; j < size_M; j++) {
			mass[i][j] = 0;
		}
	}
}
void matr::set_size(int n, int m) {
	if (size_N != 0 && size_M != 0) {
		for (int i = 0; i < size_N; i++) //   для каждой строки
		{
			delete[] mass[i]; //  , удаление памяти выделенно

		}
		delete[] mass;
	}
	size_N = n;
	size_M = m;
	mass = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		mass[i] = new double[size_M];

	for (int i = 0; i < size_N; i++) {
		for (int j = 0; j < size_M; j++) {
			mass[i][j] = 0;
		}
	}
}

matr::matr(const matr& B) {
	size_N = B.size_N;
	size_M = B.size_M;
	for (int i = 0; i < size_N; i++) //   для каждой строки
	{
		delete[] mass[i]; //  , удаление памяти выделенно

	}
	delete[] mass;
	mass = new double* [size_N];
	for (int i = 0; i < size_N; i++)
		mass[i] = new double[size_M];

	for (int i = 0; i < size_N; i++) {
		for (int j = 0; j < size_M; j++) {
			mass[i][j] = B.mass[i][j];
		}
	}
}

matr matr::matrix_multiplicat(matr& A, matr& B) {
	matr result = matr(A.size_N, B.size_M);
	for (int i = 0; i < A.size_N; i++) {
		for (int j = 0; j < B.size_M; j++) {
			for (int k = 0; k < A.size_M; k++)
				// C = A*B;
				result.mass[i][j] += A.mass[i][k] * B.mass[k][j];
		}
	}
	return result;
}


void matr::gen_matr() {
	srand(time(NULL));
	for (int i = 0; i < size_N; i++) {
		for (int j = 0; j < size_M; j++) {
			mass[i][j] = rand() % 10;
		}
	}

}

matr::~matr() {
	for (int i = 0; i < size_N; i++) //   для каждой строки
	{
		delete[] mass[i]; //  , удаление памяти выделенно
		
	}
	delete[] mass; //  , удаление памяти выделенной
}