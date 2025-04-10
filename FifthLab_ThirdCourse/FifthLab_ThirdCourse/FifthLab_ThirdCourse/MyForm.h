#pragma once
#include "BinaryTree.h"

namespace FifthLabThirdCourse {

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
			//
			//TODO: добавьте код конструктора
			//
			rootX = panel1->Width / 2;  // Центр панели по горизонтали
			rootY = 10;                // Начальная координата Y (высота корня)
			dx = panel1->Width / 4;    // Горизонтальное смещение на первом уровне
			dy = 40;                   // Вертикальное расстояние между уровнями
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{

			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel1;




	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::Button^ btn_second_graph;
	private: System::Windows::Forms::Button^ btn_third_graph;
	private: System::Windows::Forms::Button^ btn_fourth_graph;
	private: System::Windows::Forms::Button^ btn_fifth_graph;
	private: System::Windows::Forms::Button^ btn_first_graph;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btn_sixth_graph;





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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->btn_second_graph = (gcnew System::Windows::Forms::Button());
			this->btn_third_graph = (gcnew System::Windows::Forms::Button());
			this->btn_fourth_graph = (gcnew System::Windows::Forms::Button());
			this->btn_fifth_graph = (gcnew System::Windows::Forms::Button());
			this->btn_first_graph = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btn_sixth_graph = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(868, 394);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(348, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Решить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Location = System::Drawing::Point(15, 15);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1255, 358);
			this->panel1->TabIndex = 1;
			// 
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::Color::White;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(15, 379);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->ScrollBars = System::Windows::Forms::RichTextBoxScrollBars::Vertical;
			this->richTextBox1->Size = System::Drawing::Size(789, 271);
			this->richTextBox1->TabIndex = 5;
			this->richTextBox1->Text = L"";
			// 
			// btn_second_graph
			// 
			this->btn_second_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_second_graph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_second_graph->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_second_graph->Location = System::Drawing::Point(826, 536);
			this->btn_second_graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_second_graph->Name = L"btn_second_graph";
			this->btn_second_graph->Size = System::Drawing::Size(193, 53);
			this->btn_second_graph->TabIndex = 6;
			this->btn_second_graph->Text = L"Идеально сбалансированное дерево из положительных элементов";
			this->btn_second_graph->UseVisualStyleBackColor = true;
			this->btn_second_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_second_graph_Click);
			// 
			// btn_third_graph
			// 
			this->btn_third_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_third_graph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_third_graph->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_third_graph->Location = System::Drawing::Point(1066, 536);
			this->btn_third_graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_third_graph->Name = L"btn_third_graph";
			this->btn_third_graph->Size = System::Drawing::Size(193, 53);
			this->btn_third_graph->TabIndex = 7;
			this->btn_third_graph->Text = L"Идеально сбалансированное дерево из отрицательных элементов\r\n";
			this->btn_third_graph->UseVisualStyleBackColor = true;
			this->btn_third_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_third_graph_Click);
			// 
			// btn_fourth_graph
			// 
			this->btn_fourth_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_fourth_graph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_fourth_graph->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_fourth_graph->Location = System::Drawing::Point(826, 603);
			this->btn_fourth_graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_fourth_graph->Name = L"btn_fourth_graph";
			this->btn_fourth_graph->Size = System::Drawing::Size(193, 32);
			this->btn_fourth_graph->TabIndex = 8;
			this->btn_fourth_graph->Text = L"B+ дерево";
			this->btn_fourth_graph->UseVisualStyleBackColor = true;
			this->btn_fourth_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_fourth_graph_Click);
			// 
			// btn_fifth_graph
			// 
			this->btn_fifth_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_fifth_graph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_fifth_graph->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_fifth_graph->Location = System::Drawing::Point(1066, 603);
			this->btn_fifth_graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_fifth_graph->Name = L"btn_fifth_graph";
			this->btn_fifth_graph->Size = System::Drawing::Size(193, 32);
			this->btn_fifth_graph->TabIndex = 9;
			this->btn_fifth_graph->Text = L"Красно-чёрное дерево";
			this->btn_fifth_graph->UseVisualStyleBackColor = true;
			this->btn_fifth_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_fifth_graph_Click);
			// 
			// btn_first_graph
			// 
			this->btn_first_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_first_graph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_first_graph->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_first_graph->Location = System::Drawing::Point(826, 483);
			this->btn_first_graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_first_graph->Name = L"btn_first_graph";
			this->btn_first_graph->Size = System::Drawing::Size(193, 40);
			this->btn_first_graph->TabIndex = 10;
			this->btn_first_graph->Text = L"Простое бинарное дерево";
			this->btn_first_graph->UseVisualStyleBackColor = true;
			this->btn_first_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_first_graph_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(987, 447);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 25);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Отобразить:";
			// 
			// btn_sixth_graph
			// 
			this->btn_sixth_graph->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_sixth_graph->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_sixth_graph->Font = (gcnew System::Drawing::Font(L"Yu Gothic UI Semibold", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->btn_sixth_graph->Location = System::Drawing::Point(1066, 483);
			this->btn_sixth_graph->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btn_sixth_graph->Name = L"btn_sixth_graph";
			this->btn_sixth_graph->Size = System::Drawing::Size(193, 40);
			this->btn_sixth_graph->TabIndex = 12;
			this->btn_sixth_graph->Text = L"Строго бинарное дерево";
			this->btn_sixth_graph->UseVisualStyleBackColor = true;
			this->btn_sixth_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_sixth_graph_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1284, 681);
			this->Controls->Add(this->btn_sixth_graph);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_first_graph);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->btn_fifth_graph);
			this->Controls->Add(this->btn_fourth_graph);
			this->Controls->Add(this->btn_third_graph);
			this->Controls->Add(this->btn_second_graph);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->MaximumSize = System::Drawing::Size(1320, 720);
			this->MinimumSize = System::Drawing::Size(1278, 678);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Лабораторная №5";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		BinaryTree::Node* strictTree;
		BinaryTree* tree;  // Указатель на объект BinaryTree
		int rootX;  // Центр панели по горизонтали
		int rootY;                // Начальная координата Y (высота корня)
		int dx;    // Горизонтальное смещение на первом уровне
		int dy;                   // Вертикальное расстояние между уровнями

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели

		graphics1->Clear(panel1->BackColor); // Очищаем панель

		tree = new BinaryTree(3);  // Инициализация объекта BinaryTree

		// Создаем дерево и генерируем случайные узлы
		int X = 7;
		//ИЗМЕНИ ОБРАТНО ПОТОМ НА 88
		tree->generateRandomTree(88, -80, 160); // 88 узлов с диапазоном от -80 до 160
		// Вызов метода отрисовки
		drawNode(graphics1, tree->root, rootX-15, rootY, dx, dy);

		// Формируем текст для label1
		System::Text::StringBuilder^ sb = gcnew System::Text::StringBuilder();
		sb->AppendLine("Информация о дереве:");
		sb->AppendLine("2. Сумма всех элементов: " + tree->calculateSum(tree->root).ToString());
		sb->AppendLine("3. Произведение элементов, кратных 3: " + tree->calculateProductOfMultiples(tree->root, 3).ToString());

		std::vector<int> unequalNodes = tree->findNodesWithUnequalSubtreeSizes(tree->root);
		sb->AppendLine("4. Вершины с разным количеством потомков:");
		for (int key : unequalNodes) {
			sb->Append(key.ToString() + " ");
		}
		sb->AppendLine();

		std::vector<int> unequalHeightNodes = tree->findNodesWithUnequalSubtreeHeights(tree->root);
		sb->AppendLine("5. Вершины с разной высотой поддеревьев:");
		for (int key : unequalHeightNodes) {
			sb->Append(key.ToString() + " ");
		}
		sb->AppendLine();

		sb->AppendLine("6. Число вхождений элемента X(" + X.ToString() + ") в дерево: " + tree->countOccurrences(tree->root, X).ToString());

		int count = 1;
		sb->AppendLine("7. Максимальный элемент: " + tree->findMax(tree->root,count).ToString() + " Количество повторений: "+count.ToString());

		bool hasDuplicates = tree->containsDuplicates();
		sb->AppendLine("8. Есть ли в дереве дубликаты: " + (hasDuplicates ? "Да" : "Нет"));

		int maxFreq = tree->maxFrequency();
		sb->AppendLine("9. Максимальное количество одинаковых элементов: " + maxFreq.ToString());

		sb->AppendLine("10. Симметрично ли дерево: " + (tree->isSymmetric(tree->root) ? "Да" : "Нет"));
		sb->AppendLine("11. Является ли деревом поиска: " + (tree->isBST(tree->root) ? "Да" : "Нет"));

		sb->AppendLine("12. Листья дерева: ");
		// Выводим листья дерева
		auto leaves = tree->getLeaves(tree->root);
		for each (int leaf in leaves) {
			sb->Append(leaf.ToString() + " ");
		}
		sb->AppendLine();


		tree->splitAndBalance();

		tree->printPathsWithMinSum(sb); //14 Задание

		int lastLevel = tree->findLastLevelWithPositiveElements(); // Вызов метода для поиска уровня
		sb->AppendLine("15. Последний уровень с положительными элементами: " + lastLevel);

		std::vector<int> maxPerLevel = tree->findMaxElementPerLevel(); // Вызов метода для поиска максимумов

		sb->AppendLine("16. Максимальные элементы на каждом уровне дерева:");
		for (int i = 0; i < maxPerLevel.size(); i++) {
			sb->AppendLine("     Уровень " + i + ": " + maxPerLevel[i]);
		}

		std::vector<std::pair<int, int>> counts = tree->countInternalAndLeafNodesPerLevel(); // Вызов метода

		sb->AppendLine("17. Количество внутренних вершин и листьев на каждом уровне дерева:");
		for (int i = 0; i < counts.size(); i++) {
			sb->AppendLine("     Уровень " + i + ": Внутренние вершины = " + counts[i].first + ", Листья = " + counts[i].second);
		}

		int sum = tree->sumOddLevelElements(); // Вызов метода
		sb->AppendLine("18. Сумма элементов всех нечётных уровней: " + sum);


		// Получаем пути
		std::pair<std::vector<int>, std::vector<int>> result = tree->findMinMaxLeafPaths();
		const std::vector<int>& minPath = result.first;
		const std::vector<int>& maxPath = result.second;

		// Преобразуем пути в строки для вывода
		System::String^ minPathStr = gcnew System::String("");
		for (size_t i = 0; i < minPath.size(); i++) {
			minPathStr += minPath[i].ToString() + (i == minPath.size() - 1 ? "" : " -> ");
		}

		System::String^ maxPathStr = gcnew System::String("");
		for (size_t i = 0; i < maxPath.size(); i++) {
			maxPathStr += maxPath[i].ToString() + (i == maxPath.size() - 1 ? "" : " -> ");
		}

		// Вывод в StringBuilder
		sb->AppendLine("19. Минимальный путь между листьями: " + minPathStr);

		// Преобразуем дерево в строго бинарное
		strictTree = tree->makeStrictBinaryTree(tree->root);

		// Инфиксный обход
		sb->AppendLine("а) Инфиксный обход:");
		tree->inOrder(tree->root, sb);
		sb->AppendLine();  // Пустая строка для разделения результатов

		// Постфиксный обход
		sb->AppendLine("б) Постфиксный обход:");
		tree->postOrder(tree->root, sb);
		sb->AppendLine();  // Пустая строка для разделения результатов

		// Префиксный обход
		sb->AppendLine("в) Префиксный обход:");
		tree->preOrder(tree->root, sb);

		// Преобразование бинарного дерева в B+ дерево //22 задание
		tree->convertToBPlusTree(3);

		// Преобразование B+ дерева в красно-чёрное дерево //23 задание
		tree->convertBPlusToRB();

		// Устанавливаем текст в label1
		richTextBox1->Text = sb->ToString();

	}

	void drawNode(Graphics^ g, BinaryTree::Node* node, int x, int y, int dx, int dy) {
		if (!node) return;
		g->DrawEllipse(Pens::Black, x, y, 25, 25);
		g->DrawString(gcnew String(std::to_string(node->key).c_str()), gcnew System::Drawing::Font("Arial", 9), Brushes::Black, x+4, y+5);
		if (node->left)
			g->DrawLine(Pens::Black, x + 10, y + 25, x - dx + 10, y + dy);
		if (node->right)
			g->DrawLine(Pens::Black, x + 10, y + 25, x + dx + 10, y + dy);
		drawNode(g, node->left, x - dx, y + dy, dx/2, dy);
		drawNode(g, node->right, x + dx, y + dy, dx/2, dy);
	}

	void drawNodeForSmallGraphic(Graphics^ g, BinaryTree::Node* node, int x, int y, int dx, int dy) {
		if (!node) return;
		g->DrawEllipse(Pens::Black, x, y, 20, 20);
		g->DrawString(gcnew String(std::to_string(node->key).c_str()), gcnew System::Drawing::Font("Arial", 8), Brushes::Black, x + 1, y + 4);
		if (node->left)
			g->DrawLine(Pens::Black, x + 10, y + 20, x - dx + 5, y + dy);
		if (node->right)
			g->DrawLine(Pens::Black, x + 10, y + 20, x + dx + 5, y + dy);
		drawNodeForSmallGraphic(g, node->left, x - dx, y + dy, dx / 1.2, dy);
		drawNodeForSmallGraphic(g, node->right, x + dx, y + dy, dx / 1.2, dy);
	}

	void drawNodeForSmallGraphicBPlus(Graphics^ g, BinaryTree::BPlusNode* node, int x, int y, int dx, int dy) {
		if (!node) return;

		// Отображение ключей текущего узла
		String^ keys = "";
		for (size_t i = 0; i < node->keys.size(); ++i) {
			keys += gcnew String(std::to_string(node->keys[i]).c_str());
			if (i != node->keys.size() - 1) {
				keys += " | "; // Разделитель между ключами
			}
		}

		// Рисуем узел (прямоугольник с ключами)
		int nodeWidth = 20 + (node->keys.size() * 20); // Ширина узла зависит от количества ключей
		g->DrawRectangle(Pens::Black, x - nodeWidth / 2, y, nodeWidth, 30);
		g->DrawString(keys, gcnew System::Drawing::Font("Arial", 8), Brushes::Black, x - nodeWidth / 2 + 5, y + 5);

		// Если узел не листовой, рисуем линии и вызываем рекурсивно для дочерних узлов
		if (!node->isLeaf) {
			int childX = x - dx * (node->children.size() - 1) / 2; // Начальная позиция для дочерних узлов
			for (BinaryTree::BPlusNode* child : node->children) {
				g->DrawLine(Pens::Black, x, y + 30, childX, y + dy); // Линия к дочернему узлу
				drawNodeForSmallGraphicBPlus(g, child, childX, y + dy, dx / 2, dy); // Рекурсивный вызов
				childX += dx;
			}
		}

		// Если узел листовой, соединяем его с соседним листом
		if (node->isLeaf && node->next) {
			int nextNodeX = x + dx; // Положение следующего узла (по горизонтали)
			int nodeMidY = y + 15; // Средняя высота узла для рисования связи
			//g->DrawLine(Pens::Blue, x + nodeWidth / 2, nodeMidY, nextNodeX - nodeWidth / 2, nodeMidY); // Линия между листами
		}
	}

	void drawNodeRB(Graphics^ g, BinaryTree::RBNode* node, int x, int y, int dx, int dy) {
		if (!node) return;

		// Устанавливаем цвет в зависимости от типа узла (красный или чёрный)
		Brush^ nodeBrush = (node->color) ? Brushes::Red : Brushes::Black;
		Pen^ linePen = (node->color) ? Pens::Red : Pens::Black;

		// Рисуем круг для узла
		g->DrawEllipse(Pens::Black, x, y, 25, 25);
		g->FillEllipse(nodeBrush, x, y, 25, 25);

		// Рисуем ключ узла
		g->DrawString(gcnew String(std::to_string(node->key).c_str()), gcnew System::Drawing::Font("Arial", 9), Brushes::White, x + 4, y + 5);

		// Рисуем линии, соединяющие узлы
		if (node->left)
			g->DrawLine(linePen, x + 10, y + 25, x - dx + 10, y + dy);
		if (node->right)
			g->DrawLine(linePen, x + 10, y + 25, x + dx + 10, y + dy);

		// Рекурсивно рисуем левое и правое поддерево
		drawNodeRB(g, node->left, x - dx, y + dy, dx / 2, dy);
		drawNodeRB(g, node->right, x + dx, y + dy, dx / 2, dy);
	}

	private: System::Void btn_first_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели
		graphics1->Clear(panel1->BackColor); // Очищаем панель
		drawNode(graphics1, tree->root, rootX-15, rootY, dx, dy);

	}
	private: System::Void btn_second_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели
		graphics1->Clear(panel1->BackColor); // Очищаем панель
		drawNode(graphics1, tree->nonNegativesRoot, rootX-15, rootY, dx, dy);  // Отрицательные элементы

	}
	private: System::Void btn_third_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели
		graphics1->Clear(panel1->BackColor); // Очищаем панель
		drawNode(graphics1, tree->negativesRoot, rootX - 15, rootY, dx, dy);  // Отрицательные элементы

	}
	private: System::Void btn_fourth_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели
		graphics1->Clear(panel1->BackColor); // Очищаем панель
		drawNodeForSmallGraphicBPlus(graphics1, tree->bPlusRoot, rootX, rootY, dx*4, dy);

	}
	private: System::Void btn_fifth_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели
		graphics1->Clear(panel1->BackColor); // Очищаем панель
		drawNodeRB(graphics1, tree->rbRoot, rootX - 15, rootY, dx, dy);

	}
	private: System::Void btn_sixth_graph_Click(System::Object^ sender, System::EventArgs^ e) {
		Graphics^ graphics1 = panel1->CreateGraphics(); // Создаем объект Graphics для панели
		graphics1->Clear(panel1->BackColor); // Очищаем панель
		drawNode(graphics1, strictTree, rootX - 15, rootY, dx, dy);

	}


};




}
