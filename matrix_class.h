//////////////////////////////////////////////////////////////////////////////////
//																				//																 										//				 					
//				�������� ������ ������											//
// 																				//
//////////////////////////////////////////////////////////////////////////////////

#include <cstdlib> 
#include <ctime>
#include <memory>
class matr {

private:
		int size_N = 0;
		int size_M = 0;
		double** mass;

public:
	matr();
	matr(int, int);
	matr(const matr&);
	~matr();

	void matrix_multiplicat(matr&, matr&);    // ����� ���������
	void matrix_summ(matr&, matr&);			  // ����� ��������
	void matrix_sub(matr&, matr&);			  // ����� ��������� 

	double** get_matr() { return mass; }     // ������ ������� 
	int get_n() { return size_N; }
	int get_m() { return size_M; }


	void set_size(int, int);			
	void gen_matr();

};
