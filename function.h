
#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;

int** init_mas(int* [], int, int);

void random_mas(int* mas[], int n, int m, int start, int end);

void del_mas(int* [], int);

void saddle_find(int* [], int, int, int&, int&);

int sort_mas(int* [], int, int, int, int, int, int, int);

int cmp(const void*, const void*);


