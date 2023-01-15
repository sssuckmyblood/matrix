#include "analyze.h" // Подключаем прототипы функций
#include "matrix.h"  // Подключаем класс матриц
#include "Main.h"
int** mas = nullptr; 
int saddle_i = 0;
int saddle_j = 0;
int n = 0;
int m = 0;
int start_r = 0;
int end_r = 0;
int i_1 = 0;
int j_1 = 0;
int i_2 = 0;
int j_2 = 0;
int len = 0;


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

	mas_data->RowCount = n;
	mas_data->ColumnCount = m;
	mas_data_Show();

	return System::Void();
}
System::Void matrix::Main::mas_data_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		mas[e->RowIndex][e->ColumnIndex] = Convert::ToInt32(mas_data->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
	
	return System::Void();
}
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

	while (saddle_i == 0 || saddle_j == 0) {
		random_mas(mas, n, m, start_r, end_r);
		saddle_find(mas, n, m, saddle_i, saddle_j);
	}

	mas_data_Show();
}


System::Void matrix::Main::saddle_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (n == 0 || m == 0)
		MessageBox::Show("Матрица не создана!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);

	else {
		saddle_find(mas, n, m, saddle_i, saddle_j);
		if (saddle_i != 0 || saddle_j != 0) {
			mas_data->Rows[saddle_i]->Cells[saddle_j]->Style->BackColor = Color::Red;
			mas_data_Show();

		} 
			
	}
	return System::Void();
}

System::Void matrix::Main::sort_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (n == 0 || m == 0)
		MessageBox::Show("Матрица не создана!", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
	else if(i_1 == Convert::ToInt32(sort1_i->Value) && j_1 == Convert::ToInt32(sort1_j->Value) && i_2 == Convert::ToInt32(sort2_i->Value) && j_2 == Convert::ToInt32(sort2_j->Value))
		MessageBox::Show("Данный диапазон уже отсортирован", "Ошибка!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	else {
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
		len = sort_mas(mas, n, m, i_1, j_1, i_2, j_2, len);
		sort_i_draw = i_1;
	    sort_j_draw = j_1;
		sort_i_draw--;
		sort_j_draw--;

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


System::Void matrix::Main::mas_data_Show() {
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
		this->ClientSize = System::Drawing::Size(1457, 606);
	else
		this->ClientSize = System::Drawing::Size(770, 470);
}


/*
int main() {

	setlocale(LC_ALL, ".1251");
	
	cout << "\n" << "\t" << "Размер массива: " << endl;
	cout << "Введите n="; cin >> n; cout << "Введите m="; cin >> m;
  
	mas = init_mas(mas, n, m);
	write_mas(mas, n, m);
	read_mas(mas, n, m);
	del_mas(mas, n);


	return 0;
}
*/