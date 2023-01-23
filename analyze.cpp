#include "analyze.h"


// инициализируем матрицу
double** init_mas(double* mas[], int n, int m) {
	mas = new double* [n];

	for (int i = 0; i < n; i++)
		mas[i] = new double[m];


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//mas[i][j] = 1 + rand() % 100;
			mas[i][j] = 0;
		}
	}

	return mas;

}

// генерируем рандомные значения
void random_mas(double* mas[], int n, int m, int start, int end) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//mas[i][j] = 1 + rand() % 100;
			mas[i][j] = start + (rand() % (end-(start+1)));
		}
	}
	
}

void del_mas(double* mas[], int n)
{
	for (int i = 0; i < n; i++) 
	{
		delete[] mas[i]; 
		
		
	}
	delete[] mas;

}

// функция поиска седловой точки
void saddle_find(double* mas[], int n, int m, int &saddle_i, int &saddle_j) {
	
	double min = DBL_MAX;
	double max = DBL_MIN;
	double min_result = 0;
	double max_result = 0;
	int i;
	int j;
	int min_j = 0;
	int min_i = 0;
	int max_i = 0;

	
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (mas[i][j] < min) {
				min = mas[i][j];
				min_j = j;
			}
		}
		min_result = min;
		min_i = i;
		min = DBL_MAX;

		for (int k = 0; k < n; k++)
			if (mas[k][min_j] > max) {
				max = mas[k][min_j];
				max_i = k;
			}
		max_result = max;
		max = DBL_MIN;
		
		if (min_result == max_result && min_i == max_i) {
			saddle_i = max_i;
			saddle_j = min_j;

		}

	}


}

// функция сортировки интервала внутри матрицы алгоритмом qsort
int sort_mas(double* mas[], int n, int m, int i_1, int j_1, int i_2,int j_2, int len) {

	int sort1_i = i_1;
	int sort1_j = j_1;
	int sort2_i = i_2;
	int sort2_j = j_2;
	sort1_i--;
	sort1_j--;
	sort2_i--;
	sort2_j--;
	int x = sort1_j;
//	int count = 0;
	int break_remas = 0;
	for (int i = sort1_i; i < n; i++) {
		for (int j = x; j < m; j++) {
			len++;
			if (mas[i][j] == mas[sort2_i][sort2_j] && i == sort2_i && j == sort2_j) {
				break_remas++;
				break;
			}

		}
		if (break_remas != 0) break;
		x = 0;

	}
	double* mas_onerang = new double[len];
	 x = sort1_j;
	 int count = 0;
	 break_remas = 0;
	for (int i = sort1_i; i < n; i++) {
		for (int j = x; j < m; j++) {
			
			if (count != len) {
				mas_onerang[count] = mas[i][j];
				count++;
			} else {
				break_remas++;
				break;
			}

		}
		if (break_remas != 0) break;
		x = 0;

	}
	
	qsort(mas_onerang, len, sizeof(double), cmp);

	int y = sort1_j;
	int break_rewrite = 0;
	int c = 0;
	for (int i = sort1_i; i < n; i++) {
		for (int j = y; j < m; j++) {
			if (c != len) {
				mas[i][j] = mas_onerang[c];
				c++;
			}
			else {
				break_rewrite++;
				break;
			}
		}
		if (break_rewrite != 0) break;
		y = 0;

	}
	return len;
	delete[] mas_onerang;

}

// вспомогательная функция для qsort
int cmp(const void* arg1, const void* arg2) {
	double a = *(double*)arg1;

	double	b = *(double*)arg2;

	if (a > b) return -1;

	else if (a < b) return 1;

	else return 0;
}