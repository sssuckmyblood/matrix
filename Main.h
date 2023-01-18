#pragma once
#include "matrix_class.h" // Подключаем класс матриц
namespace matrix {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ exit;

	private: System::ComponentModel::BackgroundWorker^ rand_mas;
	private: System::ComponentModel::BackgroundWorker^ color_worker;
	private: System::Windows::Forms::TabControl^ tab_view;

	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::NumericUpDown^ random_start;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ random;
	private: System::Windows::Forms::NumericUpDown^ random_end;
	private: System::Windows::Forms::GroupBox^ groupBox5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::NumericUpDown^ sort2_j;
	private: System::Windows::Forms::NumericUpDown^ sort2_i;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::NumericUpDown^ sort1_i;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Button^ sort;
	private: System::Windows::Forms::NumericUpDown^ sort1_j;
	private: System::Windows::Forms::GroupBox^ groupBox4;
	private: System::Windows::Forms::Button^ saddle;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::NumericUpDown^ numeric_N;
	private: System::Windows::Forms::NumericUpDown^ numeric_M;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ create;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ mas_data;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::GroupBox^ groupBox6;
	private: System::Windows::Forms::Button^ gen_A;
	private: System::Windows::Forms::Button^ create_A;
	private: System::Windows::Forms::NumericUpDown^ n_A;
	private: System::Windows::Forms::NumericUpDown^ m_A;
	private: System::Windows::Forms::DataGridView^ A_matr;


	private: System::Windows::Forms::GroupBox^ groupBox8;
	private: System::Windows::Forms::DataGridView^ C_matr;






	private: System::Windows::Forms::GroupBox^ groupBox7;
	private: System::Windows::Forms::Button^ gen_B;
	private: System::Windows::Forms::Button^ create_B;
	private: System::Windows::Forms::NumericUpDown^ n_B;
	private: System::Windows::Forms::NumericUpDown^ m_B;
	private: System::Windows::Forms::DataGridView^ B_matr;
	private: System::Windows::Forms::Button^ mul;
	private: System::Windows::Forms::Label^ label12;







	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->exit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->rand_mas = (gcnew System::ComponentModel::BackgroundWorker());
			this->color_worker = (gcnew System::ComponentModel::BackgroundWorker());
			this->tab_view = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->mul = (gcnew System::Windows::Forms::Button());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->C_matr = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->gen_B = (gcnew System::Windows::Forms::Button());
			this->create_B = (gcnew System::Windows::Forms::Button());
			this->n_B = (gcnew System::Windows::Forms::NumericUpDown());
			this->m_B = (gcnew System::Windows::Forms::NumericUpDown());
			this->B_matr = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->gen_A = (gcnew System::Windows::Forms::Button());
			this->create_A = (gcnew System::Windows::Forms::Button());
			this->n_A = (gcnew System::Windows::Forms::NumericUpDown());
			this->m_A = (gcnew System::Windows::Forms::NumericUpDown());
			this->A_matr = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->random_start = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->random = (gcnew System::Windows::Forms::Button());
			this->random_end = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->sort2_j = (gcnew System::Windows::Forms::NumericUpDown());
			this->sort2_i = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->sort1_i = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->sort = (gcnew System::Windows::Forms::Button());
			this->sort1_j = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->saddle = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->numeric_N = (gcnew System::Windows::Forms::NumericUpDown());
			this->numeric_M = (gcnew System::Windows::Forms::NumericUpDown());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->create = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->mas_data = (gcnew System::Windows::Forms::DataGridView());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->tab_view->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_matr))->BeginInit();
			this->groupBox7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->n_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->m_B))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_matr))->BeginInit();
			this->groupBox6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->n_A))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->m_A))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A_matr))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->random_start))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->random_end))->BeginInit();
			this->groupBox5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort2_j))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort2_i))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort1_i))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort1_j))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_N))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_M))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mas_data))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exit });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(7, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(1681, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// exit
			// 
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(54, 20);
			this->exit->Text = L"Выход";
			this->exit->Click += gcnew System::EventHandler(this, &Main::exit_Click);
			// 
			// rand_mas
			// 
			this->rand_mas->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Main::rand_mas_DoWork);
			// 
			// color_worker
			// 
			this->color_worker->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &Main::color_worker_DoWork);
			// 
			// tab_view
			// 
			this->tab_view->Controls->Add(this->tabPage1);
			this->tab_view->Controls->Add(this->tabPage2);
			this->tab_view->Location = System::Drawing::Point(0, 31);
			this->tab_view->Name = L"tab_view";
			this->tab_view->SelectedIndex = 0;
			this->tab_view->Size = System::Drawing::Size(1681, 621);
			this->tab_view->TabIndex = 18;
			this->tab_view->Selecting += gcnew System::Windows::Forms::TabControlCancelEventHandler(this, &Main::tab_view_Selecting);
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label12);
			this->tabPage1->Controls->Add(this->mul);
			this->tabPage1->Controls->Add(this->groupBox8);
			this->tabPage1->Controls->Add(this->groupBox7);
			this->tabPage1->Controls->Add(this->groupBox6);
			this->tabPage1->Location = System::Drawing::Point(4, 24);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1673, 593);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Калькулятор";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// mul
			// 
			this->mul->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->mul->Location = System::Drawing::Point(542, 188);
			this->mul->Name = L"mul";
			this->mul->Size = System::Drawing::Size(28, 23);
			this->mul->TabIndex = 3;
			this->mul->Text = L"*";
			this->mul->UseVisualStyleBackColor = true;
			this->mul->Click += gcnew System::EventHandler(this, &Main::mul_Click);
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->C_matr);
			this->groupBox8->Location = System::Drawing::Point(1143, 18);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(527, 433);
			this->groupBox8->TabIndex = 2;
			this->groupBox8->TabStop = false;
			this->groupBox8->Text = L"Матрица C";
			// 
			// C_matr
			// 
			this->C_matr->AllowUserToAddRows = false;
			this->C_matr->AllowUserToDeleteRows = false;
			this->C_matr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->C_matr->ColumnHeadersVisible = false;
			this->C_matr->Location = System::Drawing::Point(7, 22);
			this->C_matr->Name = L"C_matr";
			this->C_matr->ReadOnly = true;
			this->C_matr->RowHeadersVisible = false;
			this->C_matr->Size = System::Drawing::Size(513, 327);
			this->C_matr->TabIndex = 0;
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->gen_B);
			this->groupBox7->Controls->Add(this->create_B);
			this->groupBox7->Controls->Add(this->n_B);
			this->groupBox7->Controls->Add(this->m_B);
			this->groupBox7->Controls->Add(this->B_matr);
			this->groupBox7->Location = System::Drawing::Point(577, 18);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(527, 433);
			this->groupBox7->TabIndex = 1;
			this->groupBox7->TabStop = false;
			this->groupBox7->Text = L"Матрица B";
			// 
			// gen_B
			// 
			this->gen_B->Location = System::Drawing::Point(26, 383);
			this->gen_B->Name = L"gen_B";
			this->gen_B->Size = System::Drawing::Size(126, 28);
			this->gen_B->TabIndex = 4;
			this->gen_B->Text = L"Сгенерировать";
			this->gen_B->UseVisualStyleBackColor = true;
			this->gen_B->Click += gcnew System::EventHandler(this, &Main::gen_B_Click);
			// 
			// create_B
			// 
			this->create_B->Location = System::Drawing::Point(364, 383);
			this->create_B->Name = L"create_B";
			this->create_B->Size = System::Drawing::Size(126, 28);
			this->create_B->TabIndex = 3;
			this->create_B->Text = L"Создать";
			this->create_B->UseVisualStyleBackColor = true;
			this->create_B->Click += gcnew System::EventHandler(this, &Main::create_B_Click);
			// 
			// n_B
			// 
			this->n_B->Location = System::Drawing::Point(190, 357);
			this->n_B->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->n_B->Name = L"n_B";
			this->n_B->Size = System::Drawing::Size(69, 21);
			this->n_B->TabIndex = 2;
			this->n_B->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// m_B
			// 
			this->m_B->Location = System::Drawing::Point(266, 357);
			this->m_B->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->m_B->Name = L"m_B";
			this->m_B->Size = System::Drawing::Size(69, 21);
			this->m_B->TabIndex = 1;
			this->m_B->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// B_matr
			// 
			this->B_matr->AllowUserToAddRows = false;
			this->B_matr->AllowUserToDeleteRows = false;
			this->B_matr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->B_matr->ColumnHeadersVisible = false;
			this->B_matr->Location = System::Drawing::Point(7, 22);
			this->B_matr->Name = L"B_matr";
			this->B_matr->ReadOnly = true;
			this->B_matr->RowHeadersVisible = false;
			this->B_matr->Size = System::Drawing::Size(513, 327);
			this->B_matr->TabIndex = 0;
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->gen_A);
			this->groupBox6->Controls->Add(this->create_A);
			this->groupBox6->Controls->Add(this->n_A);
			this->groupBox6->Controls->Add(this->m_A);
			this->groupBox6->Controls->Add(this->A_matr);
			this->groupBox6->Location = System::Drawing::Point(9, 18);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(527, 433);
			this->groupBox6->TabIndex = 0;
			this->groupBox6->TabStop = false;
			this->groupBox6->Text = L"Матрица A";
			// 
			// gen_A
			// 
			this->gen_A->Location = System::Drawing::Point(26, 383);
			this->gen_A->Name = L"gen_A";
			this->gen_A->Size = System::Drawing::Size(126, 28);
			this->gen_A->TabIndex = 4;
			this->gen_A->Text = L"Сгенерировать";
			this->gen_A->UseVisualStyleBackColor = true;
			this->gen_A->Click += gcnew System::EventHandler(this, &Main::gen_A_Click);
			// 
			// create_A
			// 
			this->create_A->Location = System::Drawing::Point(364, 383);
			this->create_A->Name = L"create_A";
			this->create_A->Size = System::Drawing::Size(126, 28);
			this->create_A->TabIndex = 3;
			this->create_A->Text = L"Создать";
			this->create_A->UseVisualStyleBackColor = true;
			this->create_A->Click += gcnew System::EventHandler(this, &Main::create_A_Click);
			// 
			// n_A
			// 
			this->n_A->Location = System::Drawing::Point(190, 357);
			this->n_A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->n_A->Name = L"n_A";
			this->n_A->Size = System::Drawing::Size(69, 21);
			this->n_A->TabIndex = 2;
			this->n_A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// m_A
			// 
			this->m_A->Location = System::Drawing::Point(266, 357);
			this->m_A->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->m_A->Name = L"m_A";
			this->m_A->Size = System::Drawing::Size(69, 21);
			this->m_A->TabIndex = 1;
			this->m_A->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// A_matr
			// 
			this->A_matr->AllowUserToAddRows = false;
			this->A_matr->AllowUserToDeleteRows = false;
			this->A_matr->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->A_matr->ColumnHeadersVisible = false;
			this->A_matr->Location = System::Drawing::Point(7, 22);
			this->A_matr->Name = L"A_matr";
			this->A_matr->ReadOnly = true;
			this->A_matr->RowHeadersVisible = false;
			this->A_matr->Size = System::Drawing::Size(513, 327);
			this->A_matr->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->groupBox3);
			this->tabPage2->Controls->Add(this->groupBox5);
			this->tabPage2->Controls->Add(this->groupBox4);
			this->tabPage2->Controls->Add(this->groupBox2);
			this->tabPage2->Controls->Add(this->groupBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 24);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1673, 593);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Анализ";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label4);
			this->groupBox3->Controls->Add(this->random_start);
			this->groupBox3->Controls->Add(this->label5);
			this->groupBox3->Controls->Add(this->random);
			this->groupBox3->Controls->Add(this->random_end);
			this->groupBox3->Location = System::Drawing::Point(405, 207);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(216, 208);
			this->groupBox3->TabIndex = 19;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Заполнить матрицу";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(20, 21);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(35, 24);
			this->label4->TabIndex = 8;
			this->label4->Text = L"От";
			// 
			// random_start
			// 
			this->random_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->random_start->Location = System::Drawing::Point(131, 18);
			this->random_start->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, System::Int32::MinValue });
			this->random_start->Name = L"random_start";
			this->random_start->Size = System::Drawing::Size(70, 29);
			this->random_start->TabIndex = 9;
			this->random_start->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(20, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(35, 24);
			this->label5->TabIndex = 10;
			this->label5->Text = L"До";
			// 
			// random
			// 
			this->random->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->random->Location = System::Drawing::Point(24, 125);
			this->random->Name = L"random";
			this->random->Size = System::Drawing::Size(176, 38);
			this->random->TabIndex = 12;
			this->random->Text = L"Рандом";
			this->random->UseVisualStyleBackColor = true;
			this->random->Click += gcnew System::EventHandler(this, &Main::random_Click);
			// 
			// random_end
			// 
			this->random_end->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->random_end->Location = System::Drawing::Point(131, 66);
			this->random_end->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 150, 0, 0, 0 });
			this->random_end->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->random_end->Name = L"random_end";
			this->random_end->Size = System::Drawing::Size(70, 29);
			this->random_end->TabIndex = 11;
			this->random_end->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label11);
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Controls->Add(this->label8);
			this->groupBox5->Controls->Add(this->sort2_j);
			this->groupBox5->Controls->Add(this->sort2_i);
			this->groupBox5->Controls->Add(this->label6);
			this->groupBox5->Controls->Add(this->sort1_i);
			this->groupBox5->Controls->Add(this->label7);
			this->groupBox5->Controls->Add(this->sort);
			this->groupBox5->Controls->Add(this->sort1_j);
			this->groupBox5->Location = System::Drawing::Point(639, 84);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(216, 330);
			this->groupBox5->TabIndex = 18;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Сортировка";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label11->Location = System::Drawing::Point(37, 25);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(122, 20);
			this->label11->TabIndex = 18;
			this->label11->Text = L"От 1 элемента";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label10->Location = System::Drawing::Point(37, 147);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(122, 20);
			this->label10->TabIndex = 17;
			this->label10->Text = L"До 2 элемента";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label9->Location = System::Drawing::Point(20, 230);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(87, 24);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Столбец";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label8->Location = System::Drawing::Point(20, 181);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(74, 24);
			this->label8->TabIndex = 15;
			this->label8->Text = L"Строка";
			// 
			// sort2_j
			// 
			this->sort2_j->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort2_j->Location = System::Drawing::Point(131, 227);
			this->sort2_j->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->sort2_j->Name = L"sort2_j";
			this->sort2_j->Size = System::Drawing::Size(70, 29);
			this->sort2_j->TabIndex = 14;
			this->sort2_j->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// sort2_i
			// 
			this->sort2_i->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort2_i->Location = System::Drawing::Point(131, 179);
			this->sort2_i->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->sort2_i->Name = L"sort2_i";
			this->sort2_i->Size = System::Drawing::Size(70, 29);
			this->sort2_i->TabIndex = 13;
			this->sort2_i->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(20, 60);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(74, 24);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Строка";
			// 
			// sort1_i
			// 
			this->sort1_i->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort1_i->Location = System::Drawing::Point(131, 58);
			this->sort1_i->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->sort1_i->Name = L"sort1_i";
			this->sort1_i->Size = System::Drawing::Size(70, 29);
			this->sort1_i->TabIndex = 9;
			this->sort1_i->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(20, 107);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(87, 24);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Столбец";
			// 
			// sort
			// 
			this->sort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort->Location = System::Drawing::Point(7, 277);
			this->sort->Name = L"sort";
			this->sort->Size = System::Drawing::Size(202, 38);
			this->sort->TabIndex = 12;
			this->sort->Text = L"Отсортировать";
			this->sort->UseVisualStyleBackColor = true;
			this->sort->Click += gcnew System::EventHandler(this, &Main::sort_Click);
			// 
			// sort1_j
			// 
			this->sort1_j->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->sort1_j->Location = System::Drawing::Point(131, 105);
			this->sort1_j->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->sort1_j->Name = L"sort1_j";
			this->sort1_j->Size = System::Drawing::Size(70, 29);
			this->sort1_j->TabIndex = 11;
			this->sort1_j->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->saddle);
			this->groupBox4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox4->Location = System::Drawing::Point(671, 7);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(156, 70);
			this->groupBox4->TabIndex = 17;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Седловая точка";
			// 
			// saddle
			// 
			this->saddle->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->saddle->Location = System::Drawing::Point(13, 22);
			this->saddle->Name = L"saddle";
			this->saddle->Size = System::Drawing::Size(133, 36);
			this->saddle->TabIndex = 0;
			this->saddle->Text = L"Вычислить";
			this->saddle->UseVisualStyleBackColor = true;
			this->saddle->Click += gcnew System::EventHandler(this, &Main::saddle_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->numeric_N);
			this->groupBox2->Controls->Add(this->numeric_M);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Controls->Add(this->create);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->groupBox2->Location = System::Drawing::Point(405, 7);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(216, 167);
			this->groupBox2->TabIndex = 15;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Создать матрицу";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(22, 24);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 24);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Строки";
			// 
			// numeric_N
			// 
			this->numeric_N->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numeric_N->Location = System::Drawing::Point(127, 22);
			this->numeric_N->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_N->Name = L"numeric_N";
			this->numeric_N->Size = System::Drawing::Size(76, 29);
			this->numeric_N->TabIndex = 3;
			this->numeric_N->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// numeric_M
			// 
			this->numeric_M->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numeric_M->Location = System::Drawing::Point(127, 70);
			this->numeric_M->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numeric_M->Name = L"numeric_M";
			this->numeric_M->Size = System::Drawing::Size(76, 29);
			this->numeric_M->TabIndex = 4;
			this->numeric_M->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(22, 70);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(89, 24);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Столбцы";
			// 
			// create
			// 
			this->create->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->create->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->create->Location = System::Drawing::Point(21, 120);
			this->create->Name = L"create";
			this->create->Size = System::Drawing::Size(182, 37);
			this->create->TabIndex = 7;
			this->create->Text = L"Создать";
			this->create->UseVisualStyleBackColor = true;
			this->create->Click += gcnew System::EventHandler(this, &Main::create_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->mas_data);
			this->groupBox1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->groupBox1->Location = System::Drawing::Point(9, 7);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(374, 400);
			this->groupBox1->TabIndex = 14;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Матрица";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(127, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Матрица:";
			// 
			// mas_data
			// 
			this->mas_data->AllowUserToAddRows = false;
			this->mas_data->AllowUserToDeleteRows = false;
			this->mas_data->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->mas_data->Location = System::Drawing::Point(7, 60);
			this->mas_data->Name = L"mas_data";
			this->mas_data->Size = System::Drawing::Size(360, 316);
			this->mas_data->TabIndex = 2;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label12->Location = System::Drawing::Point(1110, 188);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(28, 29);
			this->label12->TabIndex = 4;
			this->label12->Text = L"=";
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1681, 654);
			this->Controls->Add(this->tab_view);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.25F));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->MinimumSize = System::Drawing::Size(896, 536);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Матрицы";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Main::OnFormClosing);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tab_view->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->C_matr))->EndInit();
			this->groupBox7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->n_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->m_B))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->B_matr))->EndInit();
			this->groupBox6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->n_A))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->m_A))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->A_matr))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->random_start))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->random_end))->EndInit();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort2_j))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort2_i))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort1_i))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sort1_j))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_N))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric_M))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mas_data))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void create_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void random_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void mas_data_Show();
private: System::Void mas_data_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);



private: System::Void OnFormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);


private: System::Void saddle_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void rand_mas_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);

private: System::Void sort_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void color_worker_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e);



private: System::Void tab_view_Selecting(System::Object^ sender, System::Windows::Forms::TabControlCancelEventArgs^ e);

private: System::Void create_A_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void create_B_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void gen_A_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void gen_B_Click(System::Object^ sender, System::EventArgs^ e);
private: System::Void matr_data_Show(matr& data, System::Windows::Forms::DataGridView^ table);
private: System::Void mul_Click(System::Object^ sender, System::EventArgs^ e);
};
}
