#pragma once
#include <string>
#include <Windows.h>
#include "DefaultLamppost.h"
#include "PaintImage.h"

namespace PWOOP {

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
			// Включаем двойной буферизацию для формы
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->SetStyle(ControlStyles::DoubleBuffer | ControlStyles::AllPaintingInWmPaint | ControlStyles::UserPaint, true);
			this->UpdateStyles();

			this->DoubleBuffered = true;

			this->Paint += gcnew PaintEventHandler(PaintBackGround, &PaintImage::RaisePaint);
			this->Paint += gcnew PaintEventHandler(PaintTrees, &PaintImage::RaisePaint);

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






	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::Label^ lbl_choice2;
























	private: System::Windows::Forms::Timer^ timer2;






	private: System::Windows::Forms::Button^ btn_AddHuman;



	private: System::Windows::Forms::TrackBar^ trackBar1;


	private: System::Windows::Forms::Button^ btn_Settings;





	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Button^ btn_Choice1;
	private: System::Windows::Forms::Button^ btn_Choice2;


	private: System::Windows::Forms::Label^ lbl_choice;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ btn_exit;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Button^ btn_AutoAddHuman;
private: System::Windows::Forms::Label^ label6;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::Button^ btn_EventRain;
private: System::Windows::Forms::Button^ btn_EventLamppostBreak;













































































	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->lbl_choice2 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btn_AddHuman = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->btn_Settings = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->btn_Choice1 = (gcnew System::Windows::Forms::Button());
			this->btn_Choice2 = (gcnew System::Windows::Forms::Button());
			this->lbl_choice = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_AutoAddHuman = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->btn_EventRain = (gcnew System::Windows::Forms::Button());
			this->btn_EventLamppostBreak = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
			// 
			// lbl_choice2
			// 
			this->lbl_choice2->AutoSize = true;
			this->lbl_choice2->BackColor = System::Drawing::Color::Silver;
			this->lbl_choice2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_choice2->ForeColor = System::Drawing::Color::Black;
			this->lbl_choice2->Location = System::Drawing::Point(1633, 28);
			this->lbl_choice2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_choice2->Name = L"lbl_choice2";
			this->lbl_choice2->Size = System::Drawing::Size(242, 31);
			this->lbl_choice2->TabIndex = 5;
			this->lbl_choice2->Text = L"Обычный фонарь";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 5000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MainForm::timer2_Tick);
			// 
			// btn_AddHuman
			// 
			this->btn_AddHuman->BackColor = System::Drawing::Color::Gainsboro;
			this->btn_AddHuman->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_AddHuman->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_AddHuman->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_AddHuman->Location = System::Drawing::Point(1596, 274);
			this->btn_AddHuman->Name = L"btn_AddHuman";
			this->btn_AddHuman->Size = System::Drawing::Size(291, 62);
			this->btn_AddHuman->TabIndex = 4;
			this->btn_AddHuman->Text = L"Добавить человека";
			this->btn_AddHuman->UseVisualStyleBackColor = false;
			this->btn_AddHuman->Click += gcnew System::EventHandler(this, &MainForm::btn_AddHuman_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->BackColor = System::Drawing::Color::Silver;
			this->trackBar1->LargeChange = 1;
			this->trackBar1->Location = System::Drawing::Point(1596, 132);
			this->trackBar1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->trackBar1->Maximum = 4;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(292, 69);
			this->trackBar1->TabIndex = 3;
			this->trackBar1->Value = 2;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &MainForm::trackBar1_Scroll);
			// 
			// btn_Settings
			// 
			this->btn_Settings->BackColor = System::Drawing::Color::Transparent;
			this->btn_Settings->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Settings->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_Settings->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Settings->Location = System::Drawing::Point(38, 38);
			this->btn_Settings->Name = L"btn_Settings";
			this->btn_Settings->Size = System::Drawing::Size(256, 62);
			this->btn_Settings->TabIndex = 2;
			this->btn_Settings->Text = L"Открыть настройки";
			this->btn_Settings->UseVisualStyleBackColor = false;
			this->btn_Settings->Click += gcnew System::EventHandler(this, &MainForm::btn_Settings_Click);
			this->btn_Settings->MouseEnter += gcnew System::EventHandler(this, &MainForm::btn_Settings_MouseEnter);
			this->btn_Settings->MouseLeave += gcnew System::EventHandler(this, &MainForm::btn_Settings_MouseLeave);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::Gainsboro;
			this->button7->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(1598, 458);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(291, 62);
			this->button7->TabIndex = 6;
			this->button7->Text = L"Пауза";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MainForm::button7_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Silver;
			this->label10->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Black;
			this->label10->Location = System::Drawing::Point(1569, 206);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(64, 31);
			this->label10->TabIndex = 42;
			this->label10->Text = L"0.25";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->BackColor = System::Drawing::Color::Silver;
			this->label11->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Black;
			this->label11->Location = System::Drawing::Point(1724, 206);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(28, 31);
			this->label11->TabIndex = 43;
			this->label11->Text = L"1";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->BackColor = System::Drawing::Color::Silver;
			this->label12->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Black;
			this->label12->Location = System::Drawing::Point(1653, 206);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(50, 31);
			this->label12->TabIndex = 44;
			this->label12->Text = L"0.5";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->BackColor = System::Drawing::Color::Silver;
			this->label13->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Black;
			this->label13->Location = System::Drawing::Point(1784, 206);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(50, 31);
			this->label13->TabIndex = 45;
			this->label13->Text = L"1.5";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->BackColor = System::Drawing::Color::Silver;
			this->label14->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Black;
			this->label14->Location = System::Drawing::Point(1860, 206);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(28, 31);
			this->label14->TabIndex = 46;
			this->label14->Text = L"2";
			// 
			// btn_Choice1
			// 
			this->btn_Choice1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btn_Choice1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_Choice1.BackgroundImage")));
			this->btn_Choice1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_Choice1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Choice1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Choice1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Choice1->ForeColor = System::Drawing::Color::White;
			this->btn_Choice1->Location = System::Drawing::Point(470, 385);
			this->btn_Choice1->Name = L"btn_Choice1";
			this->btn_Choice1->Size = System::Drawing::Size(285, 451);
			this->btn_Choice1->TabIndex = 0;
			this->btn_Choice1->Text = L"Обычные";
			this->btn_Choice1->UseVisualStyleBackColor = false;
			this->btn_Choice1->Click += gcnew System::EventHandler(this, &MainForm::btn_Choice1_Click);
			// 
			// btn_Choice2
			// 
			this->btn_Choice2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->btn_Choice2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btn_Choice2.BackgroundImage")));
			this->btn_Choice2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->btn_Choice2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_Choice2->FlatAppearance->BorderSize = 0;
			this->btn_Choice2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_Choice2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_Choice2->ForeColor = System::Drawing::Color::White;
			this->btn_Choice2->Location = System::Drawing::Point(1224, 385);
			this->btn_Choice2->Margin = System::Windows::Forms::Padding(0);
			this->btn_Choice2->Name = L"btn_Choice2";
			this->btn_Choice2->Size = System::Drawing::Size(285, 451);
			this->btn_Choice2->TabIndex = 1;
			this->btn_Choice2->Text = L"Умные";
			this->btn_Choice2->UseVisualStyleBackColor = false;
			this->btn_Choice2->Click += gcnew System::EventHandler(this, &MainForm::btn_Choice2_Click);
			// 
			// lbl_choice
			// 
			this->lbl_choice->AutoSize = true;
			this->lbl_choice->BackColor = System::Drawing::Color::Transparent;
			this->lbl_choice->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 36, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_choice->ForeColor = System::Drawing::Color::White;
			this->lbl_choice->Location = System::Drawing::Point(624, 269);
			this->lbl_choice->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->lbl_choice->Name = L"lbl_choice";
			this->lbl_choice->Size = System::Drawing::Size(742, 77);
			this->lbl_choice->TabIndex = 49;
			this->lbl_choice->Text = L"Выберите тип фонаря";
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Silver;
			this->pictureBox2->Location = System::Drawing::Point(1566, 2);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(375, 1108);
			this->pictureBox2->TabIndex = 50;
			this->pictureBox2->TabStop = false;
			// 
			// btn_exit
			// 
			this->btn_exit->BackColor = System::Drawing::Color::Gainsboro;
			this->btn_exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_exit->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_exit->Location = System::Drawing::Point(1596, 1015);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(291, 62);
			this->btn_exit->TabIndex = 10;
			this->btn_exit->Text = L"Выйти";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MainForm::btn_exit_Click);
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Silver;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->ForeColor = System::Drawing::Color::Black;
			this->label7->Location = System::Drawing::Point(1858, 552);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(34, 38);
			this->label7->TabIndex = 32;
			this->label7->Text = L"0";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1980, 1108);
			this->pictureBox1->TabIndex = 38;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Silver;
			this->label2->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::Black;
			this->label2->Location = System::Drawing::Point(1592, 557);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(283, 31);
			this->label2->TabIndex = 52;
			this->label2->Text = L"Количество человек:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Silver;
			this->label3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Black;
			this->label3->Location = System::Drawing::Point(1592, 618);
			this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(112, 31);
			this->label3->TabIndex = 53;
			this->label3->Text = L"Время: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Silver;
			this->label1->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(1710, 618);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(25, 31);
			this->label1->TabIndex = 54;
			this->label1->Text = L"-";
			// 
			// btn_AutoAddHuman
			// 
			this->btn_AutoAddHuman->BackColor = System::Drawing::Color::Gainsboro;
			this->btn_AutoAddHuman->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_AutoAddHuman->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_AutoAddHuman->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_AutoAddHuman->Location = System::Drawing::Point(1596, 363);
			this->btn_AutoAddHuman->Name = L"btn_AutoAddHuman";
			this->btn_AutoAddHuman->Size = System::Drawing::Size(291, 69);
			this->btn_AutoAddHuman->TabIndex = 5;
			this->btn_AutoAddHuman->Text = L"Автоматически добавлять людей";
			this->btn_AutoAddHuman->UseVisualStyleBackColor = false;
			this->btn_AutoAddHuman->Click += gcnew System::EventHandler(this, &MainForm::btn_AutoAddHuman_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Silver;
			this->label6->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Black;
			this->label6->Location = System::Drawing::Point(1724, 711);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(47, 31);
			this->label6->TabIndex = 56;
			this->label6->Text = L"---";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Silver;
			this->label4->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Black;
			this->label4->Location = System::Drawing::Point(1578, 665);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(364, 31);
			this->label4->TabIndex = 57;
			this->label4->Text = L"Время до нового человека:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Silver;
			this->label5->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::Black;
			this->label5->Location = System::Drawing::Point(1677, 763);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(146, 34);
			this->label5->TabIndex = 58;
			this->label5->Text = L"События:";
			// 
			// btn_EventRain
			// 
			this->btn_EventRain->BackColor = System::Drawing::Color::Gainsboro;
			this->btn_EventRain->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_EventRain->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_EventRain->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_EventRain->Location = System::Drawing::Point(1596, 820);
			this->btn_EventRain->Name = L"btn_EventRain";
			this->btn_EventRain->Size = System::Drawing::Size(291, 62);
			this->btn_EventRain->TabIndex = 59;
			this->btn_EventRain->Text = L"Дождь";
			this->btn_EventRain->UseVisualStyleBackColor = false;
			this->btn_EventRain->Click += gcnew System::EventHandler(this, &MainForm::btn_EventRain_Click);
			// 
			// btn_EventLamppostBreak
			// 
			this->btn_EventLamppostBreak->BackColor = System::Drawing::Color::Gainsboro;
			this->btn_EventLamppostBreak->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_EventLamppostBreak->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_EventLamppostBreak->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_EventLamppostBreak->Location = System::Drawing::Point(1596, 908);
			this->btn_EventLamppostBreak->Name = L"btn_EventLamppostBreak";
			this->btn_EventLamppostBreak->Size = System::Drawing::Size(291, 62);
			this->btn_EventLamppostBreak->TabIndex = 60;
			this->btn_EventLamppostBreak->Text = L"Поломка";
			this->btn_EventLamppostBreak->UseVisualStyleBackColor = false;
			this->btn_EventLamppostBreak->Click += gcnew System::EventHandler(this, &MainForm::btn_EventLamppostBreak_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1946, 1106);
			this->Controls->Add(this->btn_EventLamppostBreak);
			this->Controls->Add(this->btn_EventRain);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->btn_AutoAddHuman);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->lbl_choice);
			this->Controls->Add(this->btn_Choice2);
			this->Controls->Add(this->btn_Choice1);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->btn_Settings);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->btn_AddHuman);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->lbl_choice2);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}




	private:
		//Изображения фона
		Image^ MainFormImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\BackGround.png");
		Image^ TreesImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\GeneralTree.png");
		//Отрисовка изображений фона
		PaintImage^ PaintBackGround = gcnew PaintImage(MainFormImage, Point(0, 58), 1320, 720,this);
		PaintImage^ PaintTrees = gcnew PaintImage(TreesImage, Point(0, 385), 1320, 230, this);
		//Экземпляр окружающей среды
		MyEnvironment^ environment = gcnew MyEnvironment();

		int Choice = -1;
		bool OpenSettingDecision = false;

		int humansCounterMainForm = 0;
		int maxHumansCount = 25;
		array<Human^>^ humansMainFormArray = gcnew array<Human^>(maxHumansCount); // Объявляем массив для хранения экземпляров класса Human
		List<Human^>^ humansMainForm = gcnew List<Human^>; // Инициализация списка

		array<SmartLamppost^>^ smartlampposts = gcnew array<SmartLamppost^>(4);

		Random^ random = gcnew Random;

		 bool AutoAddHuman = false;
		 bool SystemStatus = true;
		 bool WeatherStatus = true;


	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		btn_Settings->Parent = pictureBox1;
		lbl_choice2->Visible = false;
		trackBar1->Visible = false;
		label10->Visible = false;
		label12->Visible = false;
		label11->Visible = false;
		label13->Visible = false;
		label14->Visible = false;
		btn_AddHuman->Visible = false;
		button7->Visible = false;
		pictureBox2->Visible = false;
		btn_exit->Visible = false;
		label2->Visible = false;
		label7->Visible = false;
		label1->Visible = false;
		label3->Visible = false;
		btn_AutoAddHuman->Visible = false;
		label4->Visible = false;
		label6->Visible = false;
		label5->Visible = false;
		btn_EventRain->Visible = false;
		btn_EventLamppostBreak->Visible = false;

		OpenSettingDecision = true;
		btn_Settings->Enabled = false;

		timer1->Stop();
		timer2->Stop();
		environment->PauseEnvironment();

	}

protected:
	virtual void OnPaint(PaintEventArgs^ e) override
	{
		__super::OnPaint(e);

		// Вызываем метод Draw для отрисовки человека на форме
		for each (Human ^ human in humansMainForm)
		{
			human->Draw(e);
		}

	}

private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

	int BrokeLamppostIndex = -1;
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (Choice == 1)
	{
		LamppostWork = environment->p_SetLamppostWorkStatus;
		if (LamppostWork)
		{
			Human::CheckHumanCrossLamppost(BrokeLamppostIndex);
		}
		else
		{
			for (int i = 0; i < smartlampposts->Length; i++)
			{
				if (BrokeLamppostIndex == i)
				{
					break;
				}
				smartlampposts[i]->LamppostOff();
			}
		}
			if (LamppostBroke)
			{
				if (smartlampposts[BrokeLamppostIndex]->p_LamppostPosition.X + 355 == electric->p_GetHumanPosition.X)
				{
					smartlampposts[BrokeLamppostIndex]->LampppostNormalMethod();
					LamppostBroke = false;
					btn_EventLamppostBreak->Enabled = true;
					BrokeLamppostIndex = -1;
				}
			}
		

	}

	for (int i = 0; i < humansCounterMainForm; i++)
	{
		humansMainFormArray[i]->HumanMoving();
	}
	label7->Text = Convert::ToString(humansCounterMainForm);

	for (int i = 0; i < humansCounterMainForm; i++)
	{
		if (humansMainFormArray[i]->p_GetHumanSpeed > 0)
		{
			if (humansMainFormArray[i]->p_GetHumanPosition.X > 1520)
			{
				// Удаляем экземпляр, если он вышел за границы формы
				humansMainForm->RemoveAt(i);
				humansMainFormArray[i] = nullptr;
				Human::RemoveFromHumansArray(humansMainFormArray[i]);
				Human::p_GetHumansCounter = humansCounterMainForm;
				// Сдвигаем оставшиеся элементы в массиве и списке
				for (int j = i; j < humansCounterMainForm; j++)
				{
					humansMainFormArray[j] = humansMainFormArray[j + 1];
				}
				// Уменьшаем счетчик, чтобы он указывал на новый последний элемент
				humansCounterMainForm--;
			}
		}
		else
		{
			if (humansMainFormArray[i]->p_GetHumanPosition.X < -220)
			{
				// Удаляем экземпляр, если он вышел за границы формы
				humansMainForm->RemoveAt(i);
				humansMainFormArray[i] = nullptr;
				// Сдвигаем оставшиеся элементы в массиве и списке
				for (int j = i; j < humansCounterMainForm; j++)
				{
					humansMainFormArray[j] = humansMainFormArray[j + 1];
					//humans[j] = humans[j + 1];
				}
				// Уменьшаем счетчик, чтобы он указывал на новый последний элемент
				humansCounterMainForm--;
			}
		}

		//for (int i = 0; i < smartlampposts->Length; i++)
		//{
		//	for (int j = 0; j < humansMainFormArray->Length - (maxHumansCount - humansCounterMainForm); j++)
		//	{
		//		humansMainFormArray[j]->ChecK();
		//	}
		//}


	}

	label1->Text = environment->p_GetPartOfDayName;
	this->BackgroundImage = environment->p_GetBackGroudImage;
	pictureBox1->Image = environment->p_GetPictureBoxImage;

}
	
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	timer2->Interval = random->Next(10000, 15000);
	if (humansCounterMainForm < maxHumansCount)
	{
		Human^ human = gcnew Human();
		humansMainFormArray[humansCounterMainForm++] = human;
		humansMainForm->Add(human);
		label6->Text = Convert::ToString(round(timer2->Interval / 1000)) + " секунд";
	}
}
	  
private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	if (trackBar1->Value == 0)
	{
		timer1->Interval = 500;
		environment->p_SetTimer = 500;
	}
	if (trackBar1->Value == 1)
	{
		timer1->Interval = 250;
		environment->p_SetTimer = 250;

	}
	if (trackBar1->Value == 2)
	{
		timer1->Interval = 100;
		environment->p_SetTimer = 100;

	}
	if (trackBar1->Value == 3)
	{
		timer1->Interval = 50;
		environment->p_SetTimer = 50;

	}
	if (trackBar1->Value == 4)
	{
		timer1->Interval = 1;
		environment->p_SetTimer = 1;
	}

}

private: System::Void btn_Choice1_Click(System::Object^ sender, System::EventArgs^ e) {
	Choice = 0;
	lbl_choice->Visible = false;
	btn_Choice1->Visible = false;
	btn_Choice2->Visible = false;
	lbl_choice2->Text = "Обычный фонарь";

	DefaultLamppost^ FirstLamppost = gcnew DefaultLamppost(Point(-200, 360), 766, 360, false, this);
	DefaultLamppost^ SecondLamppost = gcnew DefaultLamppost(Point(125, 360), 766, 360, false, this);
	DefaultLamppost^ ThirdLamppost = gcnew DefaultLamppost(Point(425, 360), 766, 360, false, this);
	DefaultLamppost^ FourthLamppost = gcnew DefaultLamppost(Point(725, 360), 766, 360, false, this);

	this->Paint += gcnew PaintEventHandler(FirstLamppost, &DefaultLamppost::RaisePaintLamppost);
	this->Paint += gcnew PaintEventHandler(SecondLamppost, &DefaultLamppost::RaisePaintLamppost);
	this->Paint += gcnew PaintEventHandler(ThirdLamppost, &DefaultLamppost::RaisePaintLamppost);
	this->Paint += gcnew PaintEventHandler(FourthLamppost, &DefaultLamppost::RaisePaintLamppost);
	timer1->Start();
	//timer2->Start();
	environment->StartEnvironment();
	btn_Settings->Enabled = true;

	btn_EventLamppostBreak->Enabled = false;
}

private: System::Void btn_Choice2_Click(System::Object^ sender, System::EventArgs^ e) {
	Choice = 1;
	lbl_choice->Visible = false;
	btn_Choice1->Visible = false;
	btn_Choice2->Visible = false;
	lbl_choice2->Text = "Умный фонарь";

	SmartLamppost^ FirstLamppost = gcnew SmartLamppost(Point(-200, 360), 766, 360, false, this);
	SmartLamppost^ SecondLamppost = gcnew SmartLamppost(Point(125, 360), 766, 360, false, this);
	SmartLamppost^ ThirdLamppost = gcnew SmartLamppost(Point(425, 360), 766, 360, false, this);
	SmartLamppost^ FourthLamppost = gcnew SmartLamppost(Point(725, 360), 766, 360, false, this);

	this->Paint += gcnew PaintEventHandler(FirstLamppost, &SmartLamppost::RaisePaintLamppost);
	this->Paint += gcnew PaintEventHandler(SecondLamppost, &SmartLamppost::RaisePaintLamppost);
	this->Paint += gcnew PaintEventHandler(ThirdLamppost, &SmartLamppost::RaisePaintLamppost);
	this->Paint += gcnew PaintEventHandler(FourthLamppost, &SmartLamppost::RaisePaintLamppost);

	smartlampposts[0] = FirstLamppost;
	smartlampposts[1] = SecondLamppost;
	smartlampposts[2] = ThirdLamppost;
	smartlampposts[3] = FourthLamppost;
	timer1->Start();
	//timer2->Start();
	environment->StartEnvironment();
	btn_Settings->Enabled = true;
}

private: System::Void btn_Settings_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!OpenSettingDecision)
	{
		lbl_choice2->Visible = false;
		trackBar1->Visible = false;
		label10->Visible = false;
		label12->Visible = false;
		label11->Visible = false;
		label13->Visible = false;
		label14->Visible = false;
		btn_AddHuman->Visible = false;
		button7->Visible = false;
		pictureBox2->Visible = false;
		btn_exit->Visible = false;
		label2->Visible = false;
		label7->Visible = false;
		label1->Visible = false;
		label3->Visible = false;
		btn_AutoAddHuman->Visible = false;
		label4->Visible = false;
		label6->Visible = false;
		label5->Visible = false;
		btn_EventRain->Visible = false;
		btn_EventLamppostBreak->Visible = false;

		OpenSettingDecision = true;
		btn_Settings->Text = "Открыть настройки";

	}
	else
	{
		lbl_choice2->Visible = true;
		trackBar1->Visible = true;
		label10->Visible = true;
		label12->Visible = true;
		label11->Visible = true;
		label13->Visible = true;
		label14->Visible = true;
		btn_AddHuman->Visible = true;
		button7->Visible = true;
		pictureBox2->Visible = true;
		btn_exit->Visible = true;
		label2->Visible = true;
		label7->Visible = true;
		label1->Visible = true;
		label3->Visible = true;
		btn_AutoAddHuman->Visible = true;
		label5->Visible = true;
		btn_EventRain->Visible = true;
		btn_EventLamppostBreak->Visible = true;

		if (AutoAddHuman)
		{
			label4->Visible = true;
			label6->Visible = true;
		}

		OpenSettingDecision = false;
		btn_Settings->Text = "Скрыть настройки";
	}

}

private: System::Void btn_AddHuman_Click(System::Object^ sender, System::EventArgs^ e) {
	Human^ human = gcnew Human();
	humansMainFormArray[humansCounterMainForm++] = human;
	humansMainForm->Add(human);
}

private: System::Void btn_AutoAddHuman_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!AutoAddHuman)
	{
		label4->Visible = true;
		label6->Visible = true;
		timer2->Start();

		AutoAddHuman = true;

	}
	else
	{
		label4->Visible = false;
		label6->Visible = false;
		timer2->Stop();


		AutoAddHuman = false;
	}
}

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!SystemStatus)
	{
		timer1->Start();
		if (AutoAddHuman)
		{
			timer2->Start();
		}
		environment->StartEnvironment();
		button7->Text = "Пауза";

		SystemStatus = true;
	}
	else
	{
		timer1->Stop();
		if (!AutoAddHuman)
		{
			timer2->Stop();
		}
		environment->PauseEnvironment();
		button7->Text = "Старт";

		SystemStatus = false;
	}
}
private: System::Void btn_Settings_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
	btn_Settings->BackColor = Color::PaleTurquoise;
}
private: System::Void btn_Settings_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	btn_Settings->BackColor = Color::Transparent;

}

	   bool LamppostWork;
private: System::Void btn_EventRain_Click(System::Object^ sender, System::EventArgs^ e) {
	if (WeatherStatus)
	{
		environment->p_SetWeatherRain = WeatherStatus;
		WeatherStatus = false;
	}
	else
	{
		environment->p_SetWeatherRain = WeatherStatus;
		WeatherStatus = true;

	}
}
	
	bool LamppostBroke = false;
	Electrician^ electric;
private: System::Void btn_EventLamppostBreak_Click(System::Object^ sender, System::EventArgs^ e) {
	btn_EventLamppostBreak->Enabled = false;

	Random^ rand = gcnew Random();
	int index = rand->Next(0, smartlampposts->Length);

	BrokeLamppostIndex = index;

	electric = gcnew Electrician(index);
	humansMainForm->Add(electric);
	humansMainFormArray[humansCounterMainForm++] = electric;

	LamppostBroke = true;


	smartlampposts[index]->SmartLamppost::LamppostBrokeEvent += gcnew SmartLamppost::LamppostBrokeHandler(smartlampposts[index], &SmartLamppost::LamppostBroke);
	smartlampposts[index]->SmartLamppost::LamppostNormalEvent += gcnew SmartLamppost::LamppostBrokeHandler(smartlampposts[index], &SmartLamppost::LamppostNormal);

	smartlampposts[index]->LampppostBrokeMethod();
	delete rand;
}
};

}
