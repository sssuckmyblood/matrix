	//////////////////////////////////////////////////////////////////////////////////
	//																				//																 
	// Файл связывающий интерфейс WinForms с функциями анализа матриц и классом		//	
	// В нем реализованны методы описанные в конце файла Main.h						//										
	// Это:																			//
	// Обработка конопок															//
	// Обработка ComboBox															//
	// Фоновые асинхронные воркеры												    //
	// Обработчики изменений ячеек таблиц											//				 					
	//  																			//
	//////////////////////////////////////////////////////////////////////////////////


#include "analyze.h" // Подключаем прототипы функций  анализа
#include "Main.h"

double** mas = nullptr;  // матрица для анализа
int saddle_i = 0;        // индексы седловой точки
int saddle_j = 0;		// индексы седловой точки
int n = 0;
int m = 0;
int start_r = 0;        // переменные рандома
int end_r = 0;			// переменные рандома 
int i_1 = 0;			// переменные для задания интервала сортировки
int j_1 = 0;
int i_2 = 0;
int j_2 = 0;
int len = 0;

matr A; // объекты матриц для калькулятора
matr B;
matr C;


System::Void matrix::Main::exit_Click(System::Object^ sender, System::EventArgs^ e)
{
	//Если матрица была создана, чистим память.
	if (n != 0 || m != 0)
		del_mas(mas, n); 
	Application::Exit();
	return System::Void();
}

System::Void matrix::Main::OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
	//Если матрица была создана, чистим память.
	if (n != 0 || m != 0)
		del_mas(mas, n);
	Application::Exit();

	return System::Void();
}

	//////////////////////////////////////////////////////////////////////////////////
	//																				//																 										//				 					
	//				Метод инициализации матрицы для анализа							//
	// 																				//
	//////////////////////////////////////////////////////////////////////////////////

System::Void matrix::Main::create_Click(System::Object^ sender, System::EventArgs^ e) {

	if (n != 0 || m != 0) {
		del_mas(mas, n);
		saddle_i = 0;
		saddle_j = 0;
		i_1 = 0;
		j_1 = 0;
		i_2 = 0;
		j_2 = 0;
		len = 0;
		color_worker->RunWorkerAsync();
	}
	n = Convert::ToInt32(numeric_N->Value);
	m = Convert::ToInt32(numeric_M->Value);
	start_r = 0;
	end_r = 0;
	mas = init_mas(mas, n, m);

	mas_data_Show();
	
	return System::Void();
}

// обработчик изменений ячейки таблицы для анализа
System::Void matrix::Main::mas_data_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		mas[e->RowIndex][e->ColumnIndex] = Convert::ToDouble(mas_data->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
	
	return System::Void();
}

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//																																//																 										//				 					
	//				Метод генерации матрицы для анализа	-> вызывает асинхронную функцию которая не блокирует приложение				//
	// 																																//
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

System::Void matrix::Main::random_Click(System::Object^ sender, System::EventArgs^ e)
{
	
	if (n == 0 || m == 0) 
		MessageBox::Show("Матрица не создана!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else if (Convert::ToInt32(random_start->Value) > Convert::ToInt32(random_end->Value)) MessageBox::Show("Некорректные границы рандома!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else {
		rand_mas->RunWorkerAsync();

	}
	return System::Void();
}

System::Void matrix::Main::rand_mas_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e){
	srand(time(NULL));
	color_worker->RunWorkerAsync();
	saddle_i = 0;
	saddle_j = 0;
	i_1 = 0;
	j_1 = 0;
	i_2 = 0;
	j_2 = 0;
	len = 0;
	start_r = Convert::ToInt32(random_start->Value);
	end_r = Convert::ToInt32(random_end->Value);

	// рандомим массив пока в нем не будет найдена седловая точка (нужно для показательности поиска седловой точки)

	while (saddle_i == 0 || saddle_j == 0) {
		random_mas(mas, n, m, start_r, end_r);
		saddle_find(mas, n, m, saddle_i, saddle_j);
	}

	mas_data_Show();
}

	//////////////////////////////////////////////////////////////////////////////////
	//																				//																 										//				 					
	//						Вызывем поиск индексов седловой точки					//
	// 																				//
	//////////////////////////////////////////////////////////////////////////////////
System::Void matrix::Main::saddle_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (n == 0 || m == 0)
		MessageBox::Show("Матрица не создана!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);

	else {
		saddle_find(mas, n, m, saddle_i, saddle_j);
		if (saddle_i != 0 || saddle_j != 0) {
			mas_data->Rows[saddle_i]->Cells[saddle_j]->Style->BackColor = Color::Red;
			mas_data_Show();

		} else
			MessageBox::Show("Седловая точка не существует!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);

			
	}
	return System::Void();
}

	//////////////////////////////////////////////////////////////////////////////////
	//																				//																 										//				 					
	//				Метод сортировки матрицы										//
	// 																				//
	//////////////////////////////////////////////////////////////////////////////////
System::Void matrix::Main::sort_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (n == 0 || m == 0)
		MessageBox::Show("Матрица не создана!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else if(i_1 == Convert::ToInt32(sort1_i->Value) && j_1 == Convert::ToInt32(sort1_j->Value) && i_2 == Convert::ToInt32(sort2_i->Value) && j_2 == Convert::ToInt32(sort2_j->Value))
		MessageBox::Show("Данный диапазон уже отсортирован", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {

		// очищаем выделение интервала
		int sort_i_draw = i_1;
		int sort_j_draw = j_1;
		sort_i_draw--;
		sort_j_draw--;

		int h = sort_j_draw;
		int count_h = 0;
		int break_remas_h = 0;
		for (int i = sort_i_draw; i < n; i++) {
			for (int j = h; j < m; j++) {
				if (count_h != len) {
					if (mas_data->Rows[i]->Cells[j]->Style->BackColor != Color::Empty)
						mas_data->Rows[i]->Cells[j]->Style->BackColor = Color::Empty;
					count_h++;
				}
				else {
					break_remas_h++;
					break;
				}

			}
			if (break_remas_h != 0) {
				len = 0;
				break;
			}
			h = 0;

		}


		i_1 = Convert::ToInt32(sort1_i->Value);
		j_1 = Convert::ToInt32(sort1_j->Value);
		i_2 = Convert::ToInt32(sort2_i->Value);
		j_2 = Convert::ToInt32(sort2_j->Value);
		//len = ((m - j_1) + (n * ((i_2 - 1) - i_1)) + j_2) + 1;
		len = sort_mas(mas, n, m, i_1, j_1, i_2, j_2, len); // вызываем сортировку по убыванию в указанном диапазоне
		sort_i_draw = i_1;
	    sort_j_draw = j_1;
		sort_i_draw--;
		sort_j_draw--;
		// выделяем серым отсортированный диапазон
		h = sort_j_draw;
		count_h = 0;
		break_remas_h = 0;
		for (int i = sort_i_draw; i < n; i++) {
			for (int j = h; j < m; j++) {
				if (count_h != len) {
					mas_data->Rows[i]->Cells[j]->Style->BackColor = Color::Gray;
					count_h++;
				}
				else {
					break_remas_h++;
					break;
				}

			}
			if (break_remas_h != 0) break;
			h = 0;

		}
		mas_data_Show();
		
		//color_worker->RunWorkerAsync();
	}
	return System::Void();
}

// фоновый воркер очистки всех цветовых выделений в DataGridView
System::Void matrix::Main::color_worker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mas_data->Rows[i]->Cells[j]->Style->BackColor != Color::Empty)
				mas_data->Rows[i]->Cells[j]->Style->BackColor = Color::Empty;
		}
	}
	return System::Void();
}

	//////////////////////////////////////////////////////////////////////////////////
	//																				//																 										//				 					
	//				Метод вывода матрицы анализа в DataGridView						//
	// 																				//
	//////////////////////////////////////////////////////////////////////////////////
System::Void matrix::Main::mas_data_Show() {
	mas_data->RowCount = n;
	mas_data->ColumnCount = m;
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			mas_data->Rows[i]->HeaderCell->Value = Convert::ToString(i + 1);
			mas_data->Columns[j]->HeaderCell->Value = Convert::ToString(j + 1);
			mas_data->Rows[i]->Cells[j]->Value = mas[i][j];
		}
	}
	mas_data->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	mas_data->AutoResizeColumns();
	mas_data->ClearSelection();

}


System::Void matrix::Main::tab_view_Selecting(System::Object^ sender, System::Windows::Forms::TabControlCancelEventArgs^ e) {
	if(tab_view->SelectedIndex == 0)
		this->ClientSize = System::Drawing::Size(1687, 555);
	else
		this->ClientSize = System::Drawing::Size(770, 470);
}

// создаем матрицу A
System::Void matrix::Main::create_A_Click(System::Object^ sender, System::EventArgs^ e) {
	A.set_size(Convert::ToInt32(n_A->Value), Convert::ToInt32(m_A->Value));
	matr_data_Show(A, A_matr);
}

// создаем матрицу B 
System::Void matrix::Main::create_B_Click(System::Object^ sender, System::EventArgs^ e)
{
	B.set_size(Convert::ToInt32(n_B->Value), Convert::ToInt32(m_B->Value));
	matr_data_Show(B, B_matr);
	
}

// генерируем матрицу A
System::Void matrix::Main::gen_A_Click(System::Object^ sender, System::EventArgs^ e) {
	A.gen_matr();
	matr_data_Show(A, A_matr);
}

// генерируем матрицу B
System::Void matrix::Main::gen_B_Click(System::Object^ sender, System::EventArgs^ e) {
	B.gen_matr();
	matr_data_Show(B, B_matr);
}

// C = A*B
System::Void matrix::Main::mul_Click(System::Object^ sender, System::EventArgs^ e) {
	if (B.get_n() * B.get_m() != A.get_n() * A.get_m()) {
		MessageBox::Show("Размеры матриц не совпадают!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	} else {
		C.matrix_multiplicat(A, B);
		matr_data_Show(C, C_matr);
	}
}

// C = A+B
System::Void matrix::Main::summ_Click(System::Object^ sender, System::EventArgs^ e) {
	if (B.get_n() * B.get_m() != A.get_n() * A.get_m()) {
		MessageBox::Show("Размеры матриц не совпадают!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
		C.matrix_summ(A, B);
		matr_data_Show(C, C_matr);
	}
}

// C = A-B
System::Void matrix::Main::sub_Click(System::Object^ sender, System::EventArgs^ e) {
	if (B.get_n() * B.get_m() != A.get_n() * A.get_m()) {
		MessageBox::Show("Размеры матриц не совпадают!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	else {
	     C.matrix_sub(A, B);
		matr_data_Show(C, C_matr);
	}
}


// обработчик изменений ячейки матрицы A для ручного ввода
System::Void matrix::Main::A_matr_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	A.get_matr()[e->RowIndex][e->ColumnIndex] = Convert::ToDouble(A_matr->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);

	return System::Void();
}

// обработчик изменений ячейки матрицы B для ручного ввода
System::Void matrix::Main::B_matr_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	B.get_matr()[e->RowIndex][e->ColumnIndex] = Convert::ToDouble(B_matr->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);

	return System::Void();
}

//////////////////////////////////////////////////////////////////////////////////
//																				//																 										//				 					
//				Метод вывода матриц в DataGridView								//
// 																				//
//////////////////////////////////////////////////////////////////////////////////

System::Void matrix::Main::matr_data_Show(matr& data, System::Windows::Forms::DataGridView^ table) {
	table->RowCount = data.get_n();
	table->ColumnCount = data.get_m();
	for (int i = 0; i < data.get_n(); i++) {

		for (int j = 0; j < data.get_m(); j++) {	
			table->Rows[i]->Cells[j]->Value = data.get_matr()[i][j];
		}
	}
	table->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	table->AutoResizeColumns();
	table->ClearSelection();
}

//////////////////////////////////////////////////////////////////////////////////
//																				//																 										//				 					
//				Метод связывающий вкладки анализа и калькулятора				//
// 																				//
//////////////////////////////////////////////////////////////////////////////////

System::Void matrix::Main::sel_matr_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	if (n != 0 || m != 0) {
		del_mas(mas, n);
		saddle_i = 0;
		saddle_j = 0;
		i_1 = 0;
		j_1 = 0;
		i_2 = 0;
		j_2 = 0;
		len = 0;
		color_worker->RunWorkerAsync();
	}
	if (sel_matr->SelectedIndex == 0) { // если выбрано A - то матрица для анализа = матрица A
		n = A.get_n();
		m = A.get_m();
		start_r = 0;
		end_r = 0;
		mas = new double* [n];

		for (int i = 0; i < n; i++)
			mas[i] = new double[m];

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				mas[i][j] = A.get_matr()[i][j];
			}
		}
		


	} else if (sel_matr->SelectedIndex == 1) {
		n = B.get_n();
		m = B.get_m();
		start_r = 0;
		end_r = 0;
		
		mas = new double* [n];

		for (int i = 0; i < n; i++)
			mas[i] = new double[m];

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				mas[i][j] = B.get_matr()[i][j];
			}
		}

		
	} else if (sel_matr->SelectedIndex == 2) {
		n = C.get_n();
		m = C.get_m();
		start_r = 0;
		end_r = 0;

		mas = new double* [n];

		for (int i = 0; i < n; i++)
			mas[i] = new double[m];

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				mas[i][j] = C.get_matr()[i][j];
			}
		}


	}

	mas_data_Show();
}