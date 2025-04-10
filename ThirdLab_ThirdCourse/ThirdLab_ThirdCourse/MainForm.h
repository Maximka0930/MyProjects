#pragma once
#include "Dijkstra.h"
#include "Floid.h"
#include "SecondTask.h"


namespace ThirdLabThirdCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			count_of_cities = 0;
			help_array_cities = new int[10] {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

			// Установка высоты ячеек
			dataGridView1->RowCount = 2; // для двух массивов
			// Установка высоты для всех существующих строк
			for (int i = 0; i < dataGridView1->Rows->Count; i++) {
				dataGridView1->Rows[i]->Height = 50;
			}

			// Увеличение размера текста в ячейках
			dataGridView1->DefaultCellStyle->Font = gcnew System::Drawing::Font("Arial", 20); // "Arial" — шрифт, 16 — размер


		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ btn_FirstTask;
	private: System::Windows::Forms::Button^ btn_SecondTask;
	private: System::Windows::Forms::Label^ lbl_SecondTaskResult;
	private: System::Windows::Forms::Label^ lbl_SecondTask_1;
	private: System::Windows::Forms::Button^ btn_DecisionSecondTask;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox8;
	private: System::Windows::Forms::CheckBox^ checkBox7;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::Label^ lbl_SecondTaskPath;
	private: System::Windows::Forms::Label^ lbl_SecondTask_2;
	private: System::Windows::Forms::TextBox^ txt_SecondTask_FirstCity;
	private: System::Windows::Forms::Label^ lbl_FirstTask_1;
	private: System::Windows::Forms::Button^ btn_DecisionFirstTask;
	private: System::Windows::Forms::Label^ lbl_FirstTask_Dijkstra;
	private: System::Windows::Forms::Label^ lbl_FirstTask_Floid;
	private: System::Windows::Forms::TextBox^ txt_FirstTask_Vertex;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;













	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_FirstTask = (gcnew System::Windows::Forms::Button());
			this->btn_SecondTask = (gcnew System::Windows::Forms::Button());
			this->lbl_SecondTaskResult = (gcnew System::Windows::Forms::Label());
			this->lbl_SecondTask_1 = (gcnew System::Windows::Forms::Label());
			this->btn_DecisionSecondTask = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox8 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox7 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->lbl_SecondTaskPath = (gcnew System::Windows::Forms::Label());
			this->lbl_SecondTask_2 = (gcnew System::Windows::Forms::Label());
			this->txt_SecondTask_FirstCity = (gcnew System::Windows::Forms::TextBox());
			this->lbl_FirstTask_1 = (gcnew System::Windows::Forms::Label());
			this->btn_DecisionFirstTask = (gcnew System::Windows::Forms::Button());
			this->lbl_FirstTask_Dijkstra = (gcnew System::Windows::Forms::Label());
			this->lbl_FirstTask_Floid = (gcnew System::Windows::Forms::Label());
			this->txt_FirstTask_Vertex = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(33, 32);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(362, 362);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btn_FirstTask
			// 
			this->btn_FirstTask->BackColor = System::Drawing::Color::White;
			this->btn_FirstTask->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_FirstTask->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_FirstTask->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_FirstTask->Location = System::Drawing::Point(450, 33);
			this->btn_FirstTask->Margin = System::Windows::Forms::Padding(2);
			this->btn_FirstTask->Name = L"btn_FirstTask";
			this->btn_FirstTask->Size = System::Drawing::Size(175, 40);
			this->btn_FirstTask->TabIndex = 1;
			this->btn_FirstTask->Text = L"Задание №1";
			this->btn_FirstTask->UseVisualStyleBackColor = false;
			this->btn_FirstTask->Click += gcnew System::EventHandler(this, &MainForm::btn_FirstTask_Click);
			// 
			// btn_SecondTask
			// 
			this->btn_SecondTask->BackColor = System::Drawing::Color::White;
			this->btn_SecondTask->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_SecondTask->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_SecondTask->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_SecondTask->Location = System::Drawing::Point(650, 33);
			this->btn_SecondTask->Margin = System::Windows::Forms::Padding(2);
			this->btn_SecondTask->Name = L"btn_SecondTask";
			this->btn_SecondTask->Size = System::Drawing::Size(175, 40);
			this->btn_SecondTask->TabIndex = 2;
			this->btn_SecondTask->Text = L"Задание №2";
			this->btn_SecondTask->UseVisualStyleBackColor = false;
			this->btn_SecondTask->Click += gcnew System::EventHandler(this, &MainForm::btn_SecondTask_Click);
			// 
			// lbl_SecondTaskResult
			// 
			this->lbl_SecondTaskResult->AutoSize = true;
			this->lbl_SecondTaskResult->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_SecondTaskResult->Location = System::Drawing::Point(445, 356);
			this->lbl_SecondTaskResult->Name = L"lbl_SecondTaskResult";
			this->lbl_SecondTaskResult->Size = System::Drawing::Size(271, 25);
			this->lbl_SecondTaskResult->TabIndex = 3;
			this->lbl_SecondTaskResult->Text = L"Наикротчайшая сумма путь: ";
			// 
			// lbl_SecondTask_1
			// 
			this->lbl_SecondTask_1->AutoSize = true;
			this->lbl_SecondTask_1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_SecondTask_1->Location = System::Drawing::Point(445, 131);
			this->lbl_SecondTask_1->Name = L"lbl_SecondTask_1";
			this->lbl_SecondTask_1->Size = System::Drawing::Size(187, 25);
			this->lbl_SecondTask_1->TabIndex = 4;
			this->lbl_SecondTask_1->Text = L"Выбранные города:";
			// 
			// btn_DecisionSecondTask
			// 
			this->btn_DecisionSecondTask->BackColor = System::Drawing::Color::White;
			this->btn_DecisionSecondTask->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_DecisionSecondTask->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_DecisionSecondTask->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_DecisionSecondTask->Location = System::Drawing::Point(445, 310);
			this->btn_DecisionSecondTask->Margin = System::Windows::Forms::Padding(2);
			this->btn_DecisionSecondTask->Name = L"btn_DecisionSecondTask";
			this->btn_DecisionSecondTask->Size = System::Drawing::Size(150, 30);
			this->btn_DecisionSecondTask->TabIndex = 5;
			this->btn_DecisionSecondTask->Text = L"Решить";
			this->btn_DecisionSecondTask->UseVisualStyleBackColor = false;
			this->btn_DecisionSecondTask->Click += gcnew System::EventHandler(this, &MainForm::btn_DecisionSecondTask_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(450, 171);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(118, 21);
			this->checkBox1->TabIndex = 6;
			this->checkBox1->Text = L"Первый город";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(450, 196);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(114, 21);
			this->checkBox2->TabIndex = 7;
			this->checkBox2->Text = L"Второй город";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox3->Location = System::Drawing::Point(450, 221);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(112, 21);
			this->checkBox3->TabIndex = 8;
			this->checkBox3->Text = L"Третий город";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox3_CheckedChanged);
			// 
			// checkBox4
			// 
			this->checkBox4->AutoSize = true;
			this->checkBox4->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox4->Location = System::Drawing::Point(450, 246);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(136, 21);
			this->checkBox4->TabIndex = 9;
			this->checkBox4->Text = L"Четвертый город";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox4->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox4_CheckedChanged);
			// 
			// checkBox8
			// 
			this->checkBox8->AutoSize = true;
			this->checkBox8->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox8->Location = System::Drawing::Point(595, 246);
			this->checkBox8->Name = L"checkBox8";
			this->checkBox8->Size = System::Drawing::Size(123, 21);
			this->checkBox8->TabIndex = 13;
			this->checkBox8->Text = L"Восьмой город";
			this->checkBox8->UseVisualStyleBackColor = true;
			this->checkBox8->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox8_CheckedChanged);
			// 
			// checkBox7
			// 
			this->checkBox7->AutoSize = true;
			this->checkBox7->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox7->Location = System::Drawing::Point(595, 221);
			this->checkBox7->Name = L"checkBox7";
			this->checkBox7->Size = System::Drawing::Size(124, 21);
			this->checkBox7->TabIndex = 12;
			this->checkBox7->Text = L"Седьмой город";
			this->checkBox7->UseVisualStyleBackColor = true;
			this->checkBox7->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox7_CheckedChanged);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox6->Location = System::Drawing::Point(595, 196);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(116, 21);
			this->checkBox6->TabIndex = 11;
			this->checkBox6->Text = L"Шестой город";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox6->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox6_CheckedChanged);
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox5->Location = System::Drawing::Point(595, 171);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(109, 21);
			this->checkBox5->TabIndex = 10;
			this->checkBox5->Text = L"Пятый город";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox5->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox5_CheckedChanged);
			// 
			// lbl_SecondTaskPath
			// 
			this->lbl_SecondTaskPath->AutoSize = true;
			this->lbl_SecondTaskPath->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_SecondTaskPath->Location = System::Drawing::Point(445, 391);
			this->lbl_SecondTaskPath->Name = L"lbl_SecondTaskPath";
			this->lbl_SecondTaskPath->Size = System::Drawing::Size(59, 25);
			this->lbl_SecondTaskPath->TabIndex = 14;
			this->lbl_SecondTaskPath->Text = L"Путь:";
			// 
			// lbl_SecondTask_2
			// 
			this->lbl_SecondTask_2->AutoSize = true;
			this->lbl_SecondTask_2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_SecondTask_2->Location = System::Drawing::Point(445, 93);
			this->lbl_SecondTask_2->Name = L"lbl_SecondTask_2";
			this->lbl_SecondTask_2->Size = System::Drawing::Size(307, 25);
			this->lbl_SecondTask_2->TabIndex = 15;
			this->lbl_SecondTask_2->Text = L"Город, из которого выходит Оля:";
			// 
			// txt_SecondTask_FirstCity
			// 
			this->txt_SecondTask_FirstCity->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txt_SecondTask_FirstCity->Location = System::Drawing::Point(758, 93);
			this->txt_SecondTask_FirstCity->Name = L"txt_SecondTask_FirstCity";
			this->txt_SecondTask_FirstCity->Size = System::Drawing::Size(28, 29);
			this->txt_SecondTask_FirstCity->TabIndex = 16;
			this->txt_SecondTask_FirstCity->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::txt_SecondTask_FirstCity_KeyDown);
			// 
			// lbl_FirstTask_1
			// 
			this->lbl_FirstTask_1->AutoSize = true;
			this->lbl_FirstTask_1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_FirstTask_1->Location = System::Drawing::Point(445, 93);
			this->lbl_FirstTask_1->Name = L"lbl_FirstTask_1";
			this->lbl_FirstTask_1->Size = System::Drawing::Size(97, 25);
			this->lbl_FirstTask_1->TabIndex = 17;
			this->lbl_FirstTask_1->Text = L"Вершина:";
			// 
			// btn_DecisionFirstTask
			// 
			this->btn_DecisionFirstTask->BackColor = System::Drawing::Color::White;
			this->btn_DecisionFirstTask->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_DecisionFirstTask->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_DecisionFirstTask->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_DecisionFirstTask->Location = System::Drawing::Point(445, 310);
			this->btn_DecisionFirstTask->Margin = System::Windows::Forms::Padding(2);
			this->btn_DecisionFirstTask->Name = L"btn_DecisionFirstTask";
			this->btn_DecisionFirstTask->Size = System::Drawing::Size(150, 30);
			this->btn_DecisionFirstTask->TabIndex = 18;
			this->btn_DecisionFirstTask->Text = L"Решить";
			this->btn_DecisionFirstTask->UseVisualStyleBackColor = false;
			this->btn_DecisionFirstTask->Click += gcnew System::EventHandler(this, &MainForm::btn_DecisionFirstTask_Click);
			// 
			// lbl_FirstTask_Dijkstra
			// 
			this->lbl_FirstTask_Dijkstra->AutoSize = true;
			this->lbl_FirstTask_Dijkstra->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_FirstTask_Dijkstra->Location = System::Drawing::Point(445, 356);
			this->lbl_FirstTask_Dijkstra->Name = L"lbl_FirstTask_Dijkstra";
			this->lbl_FirstTask_Dijkstra->Size = System::Drawing::Size(201, 25);
			this->lbl_FirstTask_Dijkstra->TabIndex = 19;
			this->lbl_FirstTask_Dijkstra->Text = L"Алгоритм Дейкстры: ";
			// 
			// lbl_FirstTask_Floid
			// 
			this->lbl_FirstTask_Floid->AutoSize = true;
			this->lbl_FirstTask_Floid->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_FirstTask_Floid->Location = System::Drawing::Point(445, 391);
			this->lbl_FirstTask_Floid->Name = L"lbl_FirstTask_Floid";
			this->lbl_FirstTask_Floid->Size = System::Drawing::Size(183, 25);
			this->lbl_FirstTask_Floid->TabIndex = 20;
			this->lbl_FirstTask_Floid->Text = L"Алгоритм Флойда: ";
			// 
			// txt_FirstTask_Vertex
			// 
			this->txt_FirstTask_Vertex->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->txt_FirstTask_Vertex->Location = System::Drawing::Point(540, 93);
			this->txt_FirstTask_Vertex->Name = L"txt_FirstTask_Vertex";
			this->txt_FirstTask_Vertex->Size = System::Drawing::Size(28, 29);
			this->txt_FirstTask_Vertex->TabIndex = 21;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6, this->Column7, this->Column8
			});
			this->dataGridView1->Location = System::Drawing::Point(430, 145);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 40;
			this->dataGridView1->RowTemplate->Height = 40;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->Size = System::Drawing::Size(400, 100);
			this->dataGridView1->TabIndex = 22;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Column1";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			this->Column1->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column1->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Column2";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			this->Column2->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column2->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column2->Width = 50;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Column3";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			this->Column3->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column3->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column3->Width = 50;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Column4";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			this->Column4->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column4->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column4->Width = 50;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Column5";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			this->Column5->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column5->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column5->Width = 50;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Column6";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			this->Column6->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column6->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column6->Width = 50;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Column7";
			this->Column7->Name = L"Column7";
			this->Column7->ReadOnly = true;
			this->Column7->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column7->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column7->Width = 50;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Column8";
			this->Column8->Name = L"Column8";
			this->Column8->ReadOnly = true;
			this->Column8->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Column8->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Column8->Width = 50;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(856, 432);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->txt_FirstTask_Vertex);
			this->Controls->Add(this->lbl_FirstTask_Floid);
			this->Controls->Add(this->lbl_FirstTask_Dijkstra);
			this->Controls->Add(this->btn_DecisionFirstTask);
			this->Controls->Add(this->lbl_FirstTask_1);
			this->Controls->Add(this->txt_SecondTask_FirstCity);
			this->Controls->Add(this->lbl_SecondTask_2);
			this->Controls->Add(this->lbl_SecondTaskPath);
			this->Controls->Add(this->checkBox8);
			this->Controls->Add(this->checkBox7);
			this->Controls->Add(this->checkBox6);
			this->Controls->Add(this->checkBox5);
			this->Controls->Add(this->checkBox4);
			this->Controls->Add(this->checkBox3);
			this->Controls->Add(this->checkBox2);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->btn_DecisionSecondTask);
			this->Controls->Add(this->lbl_SecondTask_1);
			this->Controls->Add(this->lbl_SecondTaskResult);
			this->Controls->Add(this->btn_SecondTask);
			this->Controls->Add(this->btn_FirstTask);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(872, 471);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(872, 471);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №3";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion
private: System::Void btn_FirstTask_Click(System::Object^ sender, System::EventArgs^ e) {
		lbl_FirstTask_1->Visible = true;
		lbl_FirstTask_Dijkstra->Visible = true;
		lbl_FirstTask_Floid->Visible = true;
		btn_DecisionFirstTask->Visible = true;
		txt_FirstTask_Vertex->Visible = true;
		dataGridView1->Visible = true;



		lbl_SecondTask_1->Visible = false;
		lbl_SecondTask_2->Visible = false;
		lbl_SecondTaskResult->Visible = false;
		lbl_SecondTaskPath->Visible = false;
		btn_DecisionSecondTask->Visible = false;
		checkBox1->Visible = false;
		checkBox2->Visible = false;
		checkBox3->Visible = false;
		checkBox4->Visible = false;
		checkBox5->Visible = false;
		checkBox6->Visible = false;
		checkBox7->Visible = false;
		checkBox8->Visible = false;
		txt_SecondTask_FirstCity->Visible = false;

	}

private: System::Void btn_SecondTask_Click(System::Object^ sender, System::EventArgs^ e) {
	lbl_SecondTask_1->Visible = true;
	lbl_SecondTask_2 -> Visible = true;
	lbl_SecondTaskResult->Visible = true;
	lbl_SecondTaskPath->Visible = true;
	btn_DecisionSecondTask->Visible = true;
	checkBox1->Visible = true;
	checkBox2->Visible = true;
	checkBox3->Visible = true;
	checkBox4->Visible = true;
	checkBox5->Visible = true;
	checkBox6->Visible = true;
	checkBox7->Visible = true;
	checkBox8->Visible = true;
	txt_SecondTask_FirstCity->Visible = true;

	lbl_FirstTask_1->Visible = false;
	lbl_FirstTask_Dijkstra->Visible = false;
	lbl_FirstTask_Floid->Visible = false;
	btn_DecisionFirstTask->Visible = false;
	txt_FirstTask_Vertex->Visible = false;
	dataGridView1->Visible = false;
	}

private: 
	int* cities;
	int* help_array_cities;

	int count_of_cities;
	int firstCity;

private: System::Void btn_DecisionSecondTask_Click(System::Object^ sender, System::EventArgs^ e) {
					
		SecondTask *scnd = new SecondTask();
		String^ path;

		bool _isCityChecked = false;
		firstCity = Convert::ToInt32(txt_SecondTask_FirstCity->Text) - 1; //Начальный и конечный город

		for (int i = 0; i < 8; i++)
		{
			if (help_array_cities[i] == firstCity)
			{
				_isCityChecked = true;
				help_array_cities[i] = -1;
				help_array_cities[0] = firstCity;
				help_array_cities[9] = firstCity;
				break;
			}
			else
			{
				_isCityChecked = false;
			}
		}

		int* cities = new int[count_of_cities + 2]; //Зам +1

		

		if (!_isCityChecked)
		{
			//MessageBox::Show("Город ne совпал");
			help_array_cities[0] = firstCity;
			help_array_cities[9] = firstCity;
		}


		int k = 0;
		for (int i = 0; i < 10; i++)
		{
			if (help_array_cities[i] != -1)
			{
				cities[k] = help_array_cities[i];
				k++;
			}
		}

		//cities[k-1] = 8;           // Предпоследний элемент
		//cities[k] = firstCity; // Последний элемент



		//MessageBox::Show(k.ToString());

		//MessageBox::Show(cities[k].ToString());
		//
		//for (int i = 0; i < count_of_cities+2; i++)
		//{
		//	MessageBox::Show(cities[i].ToString());
		//}


		int result = scnd->findShortestRoute(cities, k/*+1*/, path);
		lbl_SecondTaskResult->Text = "Наикротчайшая сумма путь: " + result;
		lbl_SecondTaskPath->Text = "Путь: " + path;

		delete[] cities;
	}

private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox1->Checked)
	{
		help_array_cities[1] = 0;
		count_of_cities++;
	}
	else
	{
		help_array_cities[1] = -1;
		count_of_cities--;
	}


}
private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox2->Checked && firstCity != 1)
	{
		help_array_cities[2] = 1;
		count_of_cities++;
	}
	else
	{
		help_array_cities[2] = -1;
		count_of_cities--;
	}
}
private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox3->Checked && firstCity != 2)
	{
		help_array_cities[3] = 2;
		count_of_cities++;

	}
	else
	{
		help_array_cities[3] = -1;
		count_of_cities--;
	}
}
private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox4->Checked && firstCity != 3)
	{
		help_array_cities[4] = 3;

		count_of_cities++;
	}
	else
	{
		help_array_cities[4] = -1;
		count_of_cities--;
	}
}
private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox5->Checked && firstCity != 4)
	{
		help_array_cities[5] = 4;
		count_of_cities++;
	}
	else
	{
		help_array_cities[5] = -1;
		count_of_cities--;
	}
}
private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox6->Checked && firstCity != 5)
	{
		help_array_cities[6] = 5;
		count_of_cities++;
	}
	else
	{
		help_array_cities[6] = -1;
		count_of_cities--;
	}
}
private: System::Void checkBox7_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox7->Checked && firstCity != 6)
	{
		help_array_cities[7] = 6;
		count_of_cities++;
	}
	else
	{
		help_array_cities[7] = -1;
		count_of_cities--;
	}
}
private: System::Void checkBox8_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (checkBox8->Checked && firstCity != 7)
	{
		help_array_cities[8] = 7;
		count_of_cities++;
	}
	else
	{
		help_array_cities[8] = -1;
		count_of_cities--;
	}
}


private: System::Void txt_SecondTask_FirstCity_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyCode == System::Windows::Forms::Keys::Enter) {
		
		firstCity = Convert::ToInt32(txt_SecondTask_FirstCity->Text) - 1; //Начальный и конечный город
		(firstCity == 0) ? checkBox1->Enabled = false, checkBox1->Checked = false : checkBox1->Enabled = true;
		(firstCity == 1) ? checkBox2->Enabled = false, checkBox2->Checked = false : checkBox2->Enabled = true;
		(firstCity == 2) ? checkBox3->Enabled = false, checkBox3->Checked = false : checkBox3->Enabled = true;
		(firstCity == 3) ? checkBox4->Enabled = false, checkBox4->Checked = false : checkBox4->Enabled = true;
		(firstCity == 4) ? checkBox5->Enabled = false, checkBox5->Checked = false : checkBox5->Enabled = true;
		(firstCity == 5) ? checkBox6->Enabled = false, checkBox6->Checked = false : checkBox6->Enabled = true;
		(firstCity == 6) ? checkBox7->Enabled = false, checkBox7->Checked = false : checkBox7->Enabled = true;
		(firstCity == 7) ? checkBox8->Enabled = false, checkBox8->Checked = false : checkBox8->Enabled = true;

		e->Handled = true; // предотвращает звуковой сигнал по умолчанию
	}
}

private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	lbl_SecondTask_1->Visible = false;
	lbl_SecondTask_2->Visible = false;
	lbl_SecondTaskResult->Visible = false;
	lbl_SecondTaskPath->Visible = false;
	btn_DecisionSecondTask->Visible = false;
	checkBox1->Visible = false;
	checkBox2->Visible = false;
	checkBox3->Visible = false;
	checkBox4->Visible = false;
	checkBox5->Visible = false;
	checkBox6->Visible = false;
	checkBox7->Visible = false;
	checkBox8->Visible = false;
	txt_SecondTask_FirstCity->Visible = false;

	lbl_FirstTask_1->Visible = false;
	lbl_FirstTask_Dijkstra->Visible = false;
	lbl_FirstTask_Floid->Visible = false;
	btn_DecisionFirstTask->Visible = false;
	txt_FirstTask_Vertex->Visible = false;
	dataGridView1->Visible = false;
}


private: System::Void btn_DecisionFirstTask_Click(System::Object^ sender, System::EventArgs^ e) {
	
	int start = Convert::ToInt32(txt_FirstTask_Vertex->Text)-1;

	Dijkstra* dijkstra = new Dijkstra(start);
	Floid* floid = new Floid(start);

	int* dijkstra_array = new int[8];
	int* floid_array = new int[8];

	dijkstra_array = dijkstra->DecisionTask();
	floid_array = floid->DecisionTask();

	for (int i = 0; i < 8; i++) {
		dataGridView1->Rows[0]->Cells[i]->Value = dijkstra_array[i];
	}

	for (int i = 0; i < 8; i++) {
		dataGridView1->Rows[1]->Cells[i]->Value = floid_array[i];
	}

	lbl_FirstTask_Dijkstra->Text = "Алгоритм Дейкстры: " + dijkstra->steps.ToString() + " итераций";
	lbl_FirstTask_Floid->Text = "Алгоритм Флойда: "+ floid->steps.ToString() + " итераций";
}



};
}
