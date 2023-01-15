
class matrix {

private:
		int size_N;
		int size_M;
		double** matr;

public:
	matrix();
	matrix(int, int);
	matrix(int, int, double**);  //? тоже ли самое что конструктор копирования
	~matrix();

	double** get_matr() { return matr; }
	int get_n() { return size_N; }
	int get_m() { return size_M; }

	void set_matr(double**);
	void set_n(int n) { size_N = n; };
	void set_m(int m) { size_M = m; };

};
