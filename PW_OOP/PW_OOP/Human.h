#pragma once
#include <stdlib.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
//Класс Человек
ref class Human
{
public:
	Image^ HumanImage; // Текущее изображение человека
	Point HumanPosition; //Позиция человека
	int HumanImageWidth = 120; //Длина изображения человека
	int HumanImageHeight = 180; //Высота изображения человека
	int HumanSpeed; //Скорость человека
	Image^ HumanImageTwo; //Первое изображение анимации 
	Image^ HumanImageOne; //Второе изображение анимации
	int num = 0; // Переменная анимации
	int animationSpeed = 15; // Скорость анимации
	//Массив изображений человека, идущего направо
	static array<Image^>^ HumanImagesRight = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\1.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\2.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\3.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\4.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\1.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\2.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\3.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\4.Two.png") };
	//Массив изображений человека, идущего налево
	static array<Image^>^ HumanImagesLeft = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\1.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\2.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\3.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\4.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\1.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\2.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\3.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Left\\4.Two.png")	};

	static Random^ raNd = gcnew Random();
	static int humansCounter = 0; //Количество человек

	static int LamppostWidthStatic = 766; //Размеры длины фонаря
	static int LamppostHeightStatic = 360; //Размеры высоты фонаря
	static array<Human^>^ humansArray = gcnew array<Human^>(25); //Массив экземпляров класса

	static array<Point>^ LamppostsPositionStatic = gcnew array<Point>{Point(-200, 360), Point(125, 360), Point(425, 360), Point(725, 360)}; //Массив областей фонаря
	int LamppostId; //Номер фонаря

public:

	delegate void HumanCrossLamppostHandler(int id);
	static event HumanCrossLamppostHandler^ HumanCrossLamppostEvent;
	static event HumanCrossLamppostHandler^ HumanOutOfLamppostEvent;

	//Конструктор
	Human()
	{
		int randomNumber = raNd->Next(0, 2); // Генерируем случайное число 0 или 1
		HumanSpeed = (randomNumber == 0) ? -5 : 5; // Если randomNumber равно 0, то HumanSpeed будет -5, иначе 5
		HumanPosition.X = (HumanSpeed == -5) ? 1320 : -120;
		HumanPosition.Y = raNd->Next(500, 535);
		if (HumanSpeed > 0)
		{
			SetRandomImagesRight(); // Установка случайного изображения при создании экземпляра
		}
		else
		{
			SetRandomImagesLeft();
		}
		Human::AddToHumansArray(this);
		humansCounter++;
		}
	//Деструктор
	~Human()
	{
		Human::RemoveFromHumansArray(this);
		humansCounter--;
	}
	
	//Свойство на чтение текущей позиции
	property Point p_GetHumanPosition {
		Point get()
		{
			return HumanPosition;
		}
	}
	//Свойство на чтение текущего изображения
	property Image^ p_GetHumanImage {
		Image^ get()
		{
			return HumanImage;
		}
	}
	//Свойство на чтение текущей длины
	property int p_GetHumanImageWidth {
		int get()
		{
			return HumanImageWidth;

		}
	}
	//Свойство на чтение текущей высоты
	property int p_GetHumanImageHeight {
		int get()
		{
			return HumanImageHeight;

		}
	}
	//Свойство на чтение текущей скорости
	property int p_GetHumanSpeed {
		int get()
		{
			return HumanSpeed;
		}
	}
	//Свойство текущего счётчика людей
	static property int p_GetHumansCounter
	{
		int get()
		{
			return humansCounter;
		}
		void set(int value)
		{
			humansCounter = value;
		}
	}
	// Метод для удаления экземпляра Human из массива
	static void Human::RemoveFromHumansArray(Human^ human)
	{
		for (int i = 0; i < humansArray->Length; i++)
		{
			if (humansArray[i] == human)
			{
				humansArray[i] = nullptr; // Устанавливаем элемент в массиве как nullptr
				break; // Выходим из цикла после удаления элемента
			}
		}
	}
	// Метод для добавления экземпляра класса в статический массив
	static void Human::AddToHumansArray(Human^ human)
	{
		// Ищем первый пустой слот в массиве и добавляем туда экземпляр класса
		for (int i = 0; i < humansArray->Length; i++)
		{
			if (humansArray[i] == nullptr)
			{
				humansArray[i] = human;
				break;
			}
		}
	}

	// Методы для установки случайных изображений
	void SetRandomImagesRight()
	{
		int index = raNd->Next(0, HumanImagesRight->Length / 2); // Генерация случайного индекса
		HumanImageOne = HumanImagesRight[index]; // Установка первого случайного изображения
		// Выбор следующего индекса для второго изображения
		HumanImageTwo = HumanImagesRight[index + 4]; // Установка второго случайного изображения
		HumanImage = HumanImageOne;
		delete raNd;
		//MessageBox::Show(Convert::ToString((index)));

	}
	void SetRandomImagesLeft()
	{
		int index = raNd->Next(0, HumanImagesLeft->Length / 2); // Генерация случайного индекса
		HumanImageOne = HumanImagesLeft[index]; // Установка первого случайного изображения
		// Выбор следующего индекса для второго изображения
		HumanImageTwo = HumanImagesLeft[index + 4]; // Установка второго случайного изображения
		HumanImage = HumanImageOne;
		delete raNd;
		//MessageBox::Show(Convert::ToString((index)));

	}
	//Методы передвижения человека
	void HumanMoving()
	{
		HumanPosition.X += HumanSpeed;
		if (num % (2 * animationSpeed) < animationSpeed)
		{
			HumanImage = HumanImageOne;
		}
		else
		{
			HumanImage = HumanImageTwo;
		}
		num += abs(HumanSpeed);

	}
	//Метод остановки человека
	void HumanStop()
	{
		HumanSpeed = 0;
	}
	//Метод отслеживающий пересечение человека с областью фонаря
	static bool HumanCrossLamppost(int id, int HumanId)
	{
		System::Drawing::Rectangle intersectRegion = Rectangle::Intersect(
			System::Drawing::Rectangle(LamppostsPositionStatic[id].X + 100, LamppostsPositionStatic[id].Y, LamppostWidthStatic - 200, LamppostHeightStatic),
			System::Drawing::Rectangle(humansArray[HumanId]->HumanPosition.X, humansArray[HumanId]->HumanPosition.Y, humansArray[HumanId]->HumanImageWidth, humansArray[HumanId]->HumanImageHeight)
		);
		return intersectRegion != Rectangle::Empty;
	}
	//Методы отслеживающий пересечение человека с областями фонарей
	static void CheckHumanCrossLamppost(int BrokeLamppostIndex)
	{
		for (int i = 0; i < LamppostsPositionStatic->Length; i++)
		{
			if (BrokeLamppostIndex == i)
			{
				continue;	
			}
			else
			{
				bool anyCrossed = false; // Флаг для отслеживания пересечения для текущего фонаря
				for (int j = 0; j < humansArray->Length; j++) // Проходим по всем людям
				{
					if (humansArray[j] != nullptr && HumanCrossLamppost(i, j))
					{
						HumanCrossLamppostEvent(i);
						anyCrossed = true;
						break;
					}
				}
				if (!anyCrossed) // Если фонарь не активирован для текущего человека, выключаем его
				{
					HumanOutOfLamppostEvent(i);
				}

			}
		}
	}
	//Методы отрисовки
	virtual void Draw(PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		if (HumanImage != nullptr)
		{
			g->DrawImage(HumanImage, HumanPosition);
		}
	}
};
//Класс Электрик
ref class Electrician : public Human
{
	static array<Image^>^ ElectricImagesRight = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianOneRight.png"),
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianTwoRight.png")
	}; 	//Массив изображений электрика, идущего направо

	static array<Image^>^ ElectricImagesLeft = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianOneLeft.png"),
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianTwoLeft.png"),
	}; //Массив изображений электрика, идущего налево
public:

	int lmpstPost; //Номер сломанного фонаря
	//Конструктор класса
	Electrician(int lmpstPost) {
		int randomNumber = raNd->Next(0, 2); 
		HumanSpeed = (randomNumber == 0) ? -5 : 5; 
		HumanPosition.X = (HumanSpeed == -5) ? 1320 : -120;
		HumanPosition.Y = raNd->Next(500, 535);
		if (HumanSpeed > 0)
		{
			SetRandomImagesRight(); 
		}
		else
		{
			SetRandomImagesLeft();
		}
		
		this->lmpstPost = lmpstPost;
	}
	//Установка случайных изображений
	void SetRandomImagesRight()
	{
		int index = raNd->Next(0, ElectricImagesRight->Length/2);
		HumanImageOne = ElectricImagesRight[index];
		HumanImageTwo = ElectricImagesRight[index + 1];
		HumanImage = HumanImageOne;
		delete raNd;

	}
	void SetRandomImagesLeft()
	{
		int index = raNd->Next(0, ElectricImagesLeft->Length/2);
		HumanImageOne = ElectricImagesLeft[index]; 
		HumanImageTwo = ElectricImagesLeft[index + 1];
		HumanImage = HumanImageOne;
		delete raNd;
	}



};