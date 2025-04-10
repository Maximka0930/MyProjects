#pragma once
#include "DecisionFirstTask.h"
#include "DecisionSecondTask.h"
//#include "GraphVisualizer.h"
#include "Graph.h"

namespace FourthLabThirdCourse {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//vertices = gcnew System::Collections::Generic::List<System::String^>();

			// Инициализация цветов для каждой вершины (по умолчанию синий)


			vertices = gcnew System::Collections::Generic::List<System::String^>();
			vertices->Add("1");
			vertices->Add("2");
			vertices->Add("3");
			vertices->Add("4");
			vertices->Add("5");
			vertices->Add("6");
			vertices->Add("7");
			vertices->Add("8");
			vertices->Add("9");

			vertexColors = gcnew array<Brush^>(vertices->Count);
			for (int i = 0; i < vertices->Count; i++) {
				vertexColors[i] = gcnew SolidBrush(Color::White); // Все вершины синие по умолчанию
			}

			edges = gcnew System::Collections::Generic::List<System::Tuple<int, int>^>();
			edges->Add(System::Tuple::Create(0, 1));
			edges->Add(System::Tuple::Create(0, 3));
			edges->Add(System::Tuple::Create(0, 4));
			edges->Add(System::Tuple::Create(1, 2));
			edges->Add(System::Tuple::Create(1, 5));
			edges->Add(System::Tuple::Create(2, 5));
			edges->Add(System::Tuple::Create(3, 4));
			edges->Add(System::Tuple::Create(3, 6));
			edges->Add(System::Tuple::Create(4, 1));
			edges->Add(System::Tuple::Create(4, 5));
			edges->Add(System::Tuple::Create(4, 6));
			edges->Add(System::Tuple::Create(5, 7));
			edges->Add(System::Tuple::Create(6, 7));
			edges->Add(System::Tuple::Create(7, 8));


			//InitializeWeights();

			weights = gcnew System::Collections::Generic::List<int>();
			weights->Add(20);
			weights->Add(14);
			weights->Add(13);
			weights->Add(19);
			weights->Add(21);
			weights->Add(15);
			weights->Add(22);
			weights->Add(16);
			weights->Add(20);
			weights->Add(24);
			weights->Add(17);
			weights->Add(18);
			weights->Add(14);
			weights->Add(18);

		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_openFirstTask;
	protected:
	private: System::Windows::Forms::Button^ btn_openSecondTask;
	private: System::Windows::Forms::PictureBox^ pct_Graph;

	private: System::Windows::Forms::Label^ lbl_MaxFlow;
	private: System::Windows::Forms::Label^ lbl_MinCut;
	private: System::Windows::Forms::PictureBox^ pct_table;

	private: System::Windows::Forms::Label^ lbl_MinCost;
	private: System::Windows::Forms::Label^ lbl1;

	private: System::Windows::Forms::Label^ lbl_MaxEffective;
	private: System::Windows::Forms::Label^ lbl2;

























	protected:




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btn_openFirstTask = (gcnew System::Windows::Forms::Button());
			this->btn_openSecondTask = (gcnew System::Windows::Forms::Button());
			this->pct_Graph = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_MaxFlow = (gcnew System::Windows::Forms::Label());
			this->lbl_MinCut = (gcnew System::Windows::Forms::Label());
			this->pct_table = (gcnew System::Windows::Forms::PictureBox());
			this->lbl_MinCost = (gcnew System::Windows::Forms::Label());
			this->lbl1 = (gcnew System::Windows::Forms::Label());
			this->lbl_MaxEffective = (gcnew System::Windows::Forms::Label());
			this->lbl2 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pct_Graph))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pct_table))->BeginInit();
			this->SuspendLayout();
			// 
			// btn_openFirstTask
			// 
			this->btn_openFirstTask->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_openFirstTask->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_openFirstTask->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_openFirstTask->ForeColor = System::Drawing::Color::Black;
			this->btn_openFirstTask->Location = System::Drawing::Point(181, 50);
			this->btn_openFirstTask->Margin = System::Windows::Forms::Padding(2);
			this->btn_openFirstTask->Name = L"btn_openFirstTask";
			this->btn_openFirstTask->Size = System::Drawing::Size(256, 40);
			this->btn_openFirstTask->TabIndex = 0;
			this->btn_openFirstTask->Text = L"Задание №1";
			this->btn_openFirstTask->UseVisualStyleBackColor = true;
			this->btn_openFirstTask->Click += gcnew System::EventHandler(this, &MyForm::btn_openFirstTask_Click);
			// 
			// btn_openSecondTask
			// 
			this->btn_openSecondTask->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_openSecondTask->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_openSecondTask->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_openSecondTask->ForeColor = System::Drawing::Color::Black;
			this->btn_openSecondTask->Location = System::Drawing::Point(619, 50);
			this->btn_openSecondTask->Margin = System::Windows::Forms::Padding(2);
			this->btn_openSecondTask->Name = L"btn_openSecondTask";
			this->btn_openSecondTask->Size = System::Drawing::Size(256, 40);
			this->btn_openSecondTask->TabIndex = 1;
			this->btn_openSecondTask->Text = L"Задание №2";
			this->btn_openSecondTask->UseVisualStyleBackColor = true;
			this->btn_openSecondTask->Click += gcnew System::EventHandler(this, &MyForm::btn_openSecondTask_Click);
			// 
			// pct_Graph
			// 
			this->pct_Graph->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pct_Graph.Image")));
			this->pct_Graph->Location = System::Drawing::Point(246, 135);
			this->pct_Graph->Name = L"pct_Graph";
			this->pct_Graph->Size = System::Drawing::Size(563, 223);
			this->pct_Graph->TabIndex = 2;
			this->pct_Graph->TabStop = false;
			// 
			// lbl_MaxFlow
			// 
			this->lbl_MaxFlow->AutoSize = true;
			this->lbl_MaxFlow->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_MaxFlow->Location = System::Drawing::Point(293, 407);
			this->lbl_MaxFlow->Name = L"lbl_MaxFlow";
			this->lbl_MaxFlow->Size = System::Drawing::Size(217, 25);
			this->lbl_MaxFlow->TabIndex = 3;
			this->lbl_MaxFlow->Text = L"Максимальный поток: ";
			// 
			// lbl_MinCut
			// 
			this->lbl_MinCut->AutoSize = true;
			this->lbl_MinCut->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_MinCut->Location = System::Drawing::Point(560, 407);
			this->lbl_MinCut->Name = L"lbl_MinCut";
			this->lbl_MinCut->Size = System::Drawing::Size(214, 25);
			this->lbl_MinCut->TabIndex = 4;
			this->lbl_MinCut->Text = L"Минимальный разрез:";
			// 
			// pct_table
			// 
			this->pct_table->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pct_table.Image")));
			this->pct_table->Location = System::Drawing::Point(377, 115);
			this->pct_table->Name = L"pct_table";
			this->pct_table->Size = System::Drawing::Size(302, 202);
			this->pct_table->TabIndex = 5;
			this->pct_table->TabStop = false;
			// 
			// lbl_MinCost
			// 
			this->lbl_MinCost->AutoSize = true;
			this->lbl_MinCost->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_MinCost->Location = System::Drawing::Point(240, 330);
			this->lbl_MinCost->Name = L"lbl_MinCost";
			this->lbl_MinCost->Size = System::Drawing::Size(245, 25);
			this->lbl_MinCost->TabIndex = 6;
			this->lbl_MinCost->Text = L"Минимальная стоимость: ";
			// 
			// lbl1
			// 
			this->lbl1->AutoSize = true;
			this->lbl1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl1->Location = System::Drawing::Point(250, 355);
			this->lbl1->Name = L"lbl1";
			this->lbl1->Size = System::Drawing::Size(104, 21);
			this->lbl1->TabIndex = 7;
			this->lbl1->Text = L"Назначения:";
			// 
			// lbl_MaxEffective
			// 
			this->lbl_MaxEffective->AutoSize = true;
			this->lbl_MaxEffective->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl_MaxEffective->Location = System::Drawing::Point(560, 330);
			this->lbl_MaxEffective->Name = L"lbl_MaxEffective";
			this->lbl_MaxEffective->Size = System::Drawing::Size(292, 25);
			this->lbl_MaxEffective->TabIndex = 8;
			this->lbl_MaxEffective->Text = L"Максимальная эффективность:";
			// 
			// lbl2
			// 
			this->lbl2->AutoSize = true;
			this->lbl2->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lbl2->Location = System::Drawing::Point(570, 355);
			this->lbl2->Name = L"lbl2";
			this->lbl2->Size = System::Drawing::Size(104, 21);
			this->lbl2->TabIndex = 9;
			this->lbl2->Text = L"Назначения:";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1040, 537);
			this->Controls->Add(this->pct_Graph);
			this->Controls->Add(this->lbl2);
			this->Controls->Add(this->lbl_MaxEffective);
			this->Controls->Add(this->lbl1);
			this->Controls->Add(this->lbl_MinCost);
			this->Controls->Add(this->pct_table);
			this->Controls->Add(this->lbl_MinCut);
			this->Controls->Add(this->lbl_MaxFlow);
			this->Controls->Add(this->btn_openSecondTask);
			this->Controls->Add(this->btn_openFirstTask);
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximumSize = System::Drawing::Size(1320, 720);
			this->MinimumSize = System::Drawing::Size(857, 454);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Выбор задания";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pct_Graph))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pct_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}


#pragma endregion


	private: System::Void btn_openFirstTask_Click(System::Object^ sender, System::EventArgs^ e) {
		btn_openSecondTask->ForeColor = System::Drawing::Color::Black;
		btn_openFirstTask->ForeColor = System::Drawing::Color::Gray;
		btn_openFirstTask->Enabled = false;
		btn_openSecondTask->Enabled = true;
		this->Text = "Задание №1";
		pct_table->Visible = false;

		// Чтобы скрыть все лейблы
		for (int i = 0; i < this->Controls->Count; i++) {
			Label^ currentLabel = dynamic_cast<Label^>(this->Controls[i]);
			if (currentLabel != nullptr) {
				currentLabel->Visible = false;
			}
		}

		pct_Graph->Visible = false; //ОТКЛЮЧИЛ картинку ГРАФА
		lbl_MaxFlow->Visible = true;
		lbl_MinCut->Visible = true;

		const int MAX_NODES = 100; // Максимальное количество узлов в графе

		int graph[MAX_NODES][MAX_NODES] = {
		{0, 20, 0, 14, 13, 0, 0, 0, 0},
		{0, 0, 19, 0, 0, 21, 0, 0, 0},
		{0, 0, 0, 0, 0, 15, 0, 0, 0},
		{0, 0, 0, 0, 22, 0, 16, 0, 0},
		{0, 20, 0, 0, 0, 24, 17, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 18, 0},
		{0, 0, 0, 0, 0, 0, 0, 14, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 18},
		{0, 0, 0, 0, 0, 0, 0, 0, 0}
		};

		int n = 9; // Количество узлов
		int source = 0; // Источник (вершина 1)
		int sink = 8;   // Сток (вершина 9)

		DecisionFirstTask* first = new DecisionFirstTask();

		int residualGraph[MAX_NODES][MAX_NODES];
		int maxFlow = first->fordFulkerson(graph, n, source, sink, residualGraph);
		lbl_MaxFlow->Text = "Максимальный поток: " + maxFlow;

		// Найти минимальный разрез
		bool visited[MAX_NODES];
		first->findMinCut(residualGraph, n, source, visited);

		String^ str;

		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				if (visited[u] && !visited[v] && graph[u][v] > 0) {
					int a = u + 1;
					int b = v + 1;
					str += (a + " - " + b);
				}
			}
		}

		lbl_MinCut->Text = "Минимальный разрез: " + str;

		Graphics^ g = this->CreateGraphics(); // Создание объекта Graphics для текущей формы
		for (int u = 0; u < n; ++u) {
			for (int v = 0; v < n; ++v) {
				if (visited[u] && !visited[v] && graph[u][v] > 0) {
					ChangeVertexColor(u, Color::Red); // Изменит цвет вершины
					ChangeVertexColor(v, Color::Red); // Изменит цвет вершины

				}
			}
		}
		//ChangeVertexColor(7, Color::Red); // Изменит цвет вершины
		//ChangeVertexColor(8, Color::Red); // Изменит цвет вершины

		DrawGraph(g); // Вызов метода отрисовки
		g->DrawLine(gcnew Pen(Color::Red, 2), 800, 300, 900, 200);

	}


	private: System::Void btn_openSecondTask_Click(System::Object^ sender, System::EventArgs^ e) {

		Graphics^ g = this->CreateGraphics(); // Создание объекта Graphics для текущей формы
		g->Clear(System::Drawing::Color::White);

		btn_openSecondTask->ForeColor = System::Drawing::Color::Gray;
		btn_openFirstTask->ForeColor = System::Drawing::Color::Black;
		btn_openSecondTask->Enabled = false;
		btn_openFirstTask->Enabled = true;
		this->Text = "Задание №2";

		pct_Graph->Visible = false;
		lbl_MaxFlow->Visible = false;
		lbl_MinCut->Visible = false;

		lbl1->Visible = true;
		lbl2->Visible = true;
		lbl_MaxEffective->Visible = true;
		lbl_MinCost->Visible = true;
		pct_table->Visible = true;


		const int N = 5;

		int Matrix[N][N] = {
		{13, 15, 18, 11, 19},
		{41, 39, 43, 33, 38},
		{37, 31, 29, 33, 35},
		{23, 27, 28, 29, 22},
		{46, 42, 48, 44, 45}
		};

		DecisionSecondTask* second = new DecisionSecondTask();

		// Решение задачи (а): минимизация стоимости
		int assignmentMin[N];
		int minCost = second->hungarianAlgorithmMin(Matrix, assignmentMin);

		lbl_MinCost->Text =  "Минимальная стоимость: " + minCost;


		int XF = 250;
		int YF = 380;

		for (int i = 0; i < N; i++)
		{
			Label^ label = gcnew Label();
			int a = i + 1;
			int b = assignmentMin[i] + 1;
			label->Text = "Работа " + a + " -> Исполнитель " + b;
			label->Location = Point(XF, YF);
			label->Font = gcnew Drawing::Font("Yu Gothic UI", 10, Drawing::FontStyle::Bold);
			label->Width = 200;  // Устанавливает ширину метки в 200 пикселей

			this->Controls->Add(label);

			YF += 25;
			
		}


		// Решение задачи (б): максимизация эффективности
		int assignmentMax[N];
		int maxEfficiencyy = second->hungarianAlgorithmMax(Matrix, assignmentMax);

		int maxEfficiency = 0;

		for (int i = 0; i < N; i++)
		{
			maxEfficiency += Matrix[i][assignmentMax[i]];
		}

		lbl_MaxEffective->Text = "Максимальная эффективность: " + maxEfficiency;

		int XS = 570;
		int YS = 380;

		for (int i = 0; i < N; ++i) {
			Label^ label = gcnew Label();
			int a = i + 1;
			int b = assignmentMax[i] + 1;
			label->Text = "Работа " + a.ToString() + " -> Исполнитель " + b.ToString();
			label->Location = Point(XS, YS);
			label->Font = gcnew Drawing::Font("Yu Gothic UI", 10, Drawing::FontStyle::Bold);
			label->Width = 200; 
			this->Controls->Add(label);

			YS += 25;
		}


	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		pct_table->Visible = false;
		pct_Graph->Visible = false;

		// Чтобы скрыть все лейблы
		for (int i = 0; i < this->Controls->Count; i++) {
			Label^ currentLabel = dynamic_cast<Label^>(this->Controls[i]);
			if (currentLabel != nullptr) {
				currentLabel->Visible = false;
			}
		}

	}

	private:
    System::Collections::Generic::List<System::String^>^ vertices;
    System::Collections::Generic::List<System::Tuple<int, int>^>^ edges;
    System::Collections::Generic::List<int>^ weights;
	array<Brush^>^ vertexColors;



	
private: // Измененная версия метода DrawGraph с использованием массива цветов для вершин
	System::Void DrawGraph(Graphics^ g) {
		Pen^ edgePen = gcnew Pen(Color::Black, 2);
		Brush^ textBrush = gcnew SolidBrush(Color::Black);
		Brush^ weightBrush = gcnew SolidBrush(Color::Black);
		System::Drawing::Font^ font = gcnew System::Drawing::Font("Arial", 14);
		System::Drawing::Font^ weightFont = gcnew System::Drawing::Font("Arial", 10);

		// Массив координат вершин
		array<Point>^ vertexCoordinates = gcnew array<Point> {
			Point(200, 250),   // Вершина 1
			Point(350, 150),   // Вершина 2
			Point(475, 200),   // Вершина 3
			Point(350, 350),   // Вершина 4
			Point(355, 250),   // Вершина 5
			Point(700, 200),   // Вершина 6
			Point(700, 300),   // Вершина 7
			Point(800, 250),   // Вершина 8
			Point(900, 250)    // Вершина 9
		};

		// Отрисовка рёбер
		for (int i = 0; i < edges->Count; i++) {
			int startIdx = edges[i]->Item1;
			int endIdx = edges[i]->Item2;

			// Получаем координаты для начала и конца ребра
			Point start = vertexCoordinates[startIdx];
			Point end = vertexCoordinates[endIdx];

			// Рисуем линию (ребро)
			g->DrawLine(edgePen, start.X, start.Y, end.X, end.Y);

			// Координаты для текста (вес ребра)
			int midX = (start.X + end.X) / 2;
			int midY = (start.Y + end.Y) / 2;

			// Смещаем вес немного вверх относительно линии
			int weightX = midX;
			int weightY = midY - 10;
			g->DrawString(weights[i].ToString(), weightFont, weightBrush, weightX, weightY);
		}

		// Отрисовка вершин
		for (int i = 0; i < vertices->Count; i++) {
			Point vertexPos = vertexCoordinates[i];

			// Радиус вершины
			int vertexX = vertexPos.X - 20;
			int vertexY = vertexPos.Y - 20;

			// Рисуем вершину с цветом из массива vertexColors
			g->FillEllipse(vertexColors[i], vertexX, vertexY, 40, 40);
			g->DrawEllipse(Pens::Black, vertexX, vertexY, 40, 40);

			// Добавляем текст (номер вершины)
			System::String^ vertexText = vertices[i];
			int textX = vertexPos.X - 10;
			int textY = vertexPos.Y - 10;
			g->DrawString(vertexText, font, textBrush, textX, textY);
		}
	}



public:
	// Метод для изменения цвета вершины по индексу
	void ChangeVertexColor(int vertexIndex, Color newColor) {
		if (vertexIndex >= 0 && vertexIndex < vertices->Count) {
			vertexColors[vertexIndex] = gcnew SolidBrush(newColor);
		}
	}
	  






};







}
