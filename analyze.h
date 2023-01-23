//////////////////////////////////////////////////////////////////////////////////
//																				//																 										//				 					
//				Описания функций для анализа									//
// 																				//
//////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

double** init_mas(double* [], int, int);

void random_mas(double* mas[], int n, int m, int start, int end);

void del_mas(double* [], int);

void saddle_find(double* [], int, int, int&, int&);

int sort_mas(double* [], int, int, int, int, int, int, int);

int cmp(const void*, const void*);


