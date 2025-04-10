#pragma once
#include "Environment.h"
#include "Human.h"
//Класс обычный фонарь
ref class DefaultLamppost
{
protected:
	Image^ LamppostImageOff = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\LamppostOff.png"); //Изображение выключенного фонаря
	Image^ LamppostImageOn = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\LamppostOnFirst.png"); //Изображение включенного фонаря
	Image^ MainLamppostImage; //Текущее изображение фонаря
	Point LamppostPosition; //Позиция фонаря на форме
	int LamppostImageWidth; //Длина области фонаря
	int LamppostImageHeight; //Высота области фонаря
	bool WorkStatus; //Статус работы фонаря
	Form^ MainForm; //Форма
	
public:
	//Конструктор класса Обычный фонарь
	DefaultLamppost(Point position, int width, int height, bool workstatus, Form^ form)
	{
		MainLamppostImage = LamppostImageOff;
		LamppostPosition = position;
		LamppostImageWidth = width;
		LamppostImageHeight = height;
		WorkStatus = workstatus;
		MainForm = form;
		MyEnvironment::EveningEvent += gcnew MyEnvironment::DaySwitchHandler(this, &DefaultLamppost::LamppostOn);
		MyEnvironment::MorningEvent += gcnew MyEnvironment::DaySwitchHandler(this, &DefaultLamppost::LamppostOff);
		}
	//Метод включения обычного фонаря
	void LamppostOn()
	{
		WorkStatus = true;
		MainLamppostImage = LamppostImageOn;
	}
	//Метод выключения обычного фонаря
	void LamppostOff()
	{
		WorkStatus = false;
		MainLamppostImage = LamppostImageOff;
	}
	//Метод отрисовки обычного фонаря
	void RaisePaintLamppost(Object^ sender, PaintEventArgs^ e)
	{
		if (MainLamppostImage != nullptr)
		{
			Graphics^ g = e->Graphics;
			g->DrawImage(MainLamppostImage, LamppostPosition.X, LamppostPosition.Y, LamppostImageWidth, LamppostImageHeight);
		}
	}

};
//Класс умный фонарь
ref class SmartLamppost : public DefaultLamppost {
	int LamppostId; // Номер фонаря
	static int LamppostCounter = 0; //Количество фонарей
	Image^ LamppostImageFirstDispertion = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\SmartLamppostOn.png"); //Изображение включенного фонаря
	Image^ LamppostBrokeImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\LamppostBroke.png"); //Изображение сломанного фонаря
public:
	//Конструктор класса Умный фонарь
	SmartLamppost(Point position, int width, int height, bool workstatus, Form^ form)
		: DefaultLamppost(position, width, height, workstatus, form)
	{
		MyEnvironment::EveningEvent -= gcnew MyEnvironment::DaySwitchHandler(this, &DefaultLamppost::LamppostOn);
		MyEnvironment::MorningEvent -= gcnew MyEnvironment::DaySwitchHandler(this, &DefaultLamppost::LamppostOff);

		Human::HumanCrossLamppostEvent += gcnew Human::HumanCrossLamppostHandler(this, &SmartLamppost::SLamppostOn);
		Human::HumanOutOfLamppostEvent += gcnew Human::HumanCrossLamppostHandler(this, &SmartLamppost::SLamppostOff);
		
		LamppostId = LamppostCounter;
		LamppostCounter++;

		WorkStatus = true;
	}

	delegate void LamppostBrokeHandler();
	event LamppostBrokeHandler^ LamppostBrokeEvent;
	event LamppostBrokeHandler^ LamppostNormalEvent;
	//Метод поломанного фонаря
	void LamppostBroke()
	{
		MainLamppostImage = LamppostBrokeImage;
		WorkStatus = false;
	}
	//Метод починенного фонаря
	void LamppostNormal()
	{
		MainLamppostImage = LamppostImageOff;
		WorkStatus = false;
	}
	//Метод вызова события поломки фонаря
	void LampppostBrokeMethod()
	{
		LamppostBrokeEvent();
	}
	//Метод вызова события починки фонаря
	void LampppostNormalMethod()
	{
		LamppostNormalEvent();
	}

	//Метод включения умного фонаря
	void SLamppostOff(int id)
	{
		if (LamppostId == id)
		{
			MainLamppostImage = LamppostImageOff;
			WorkStatus = false;
		}
	}
	//Метод выключения умного фонаря
	void SLamppostOn(int id)
	{
		if (LamppostId == id)
		{
			MainLamppostImage = LamppostImageFirstDispertion;
			WorkStatus = true;

		}
	}
	//Свойство на чтение текущего изображения
	property Image^ p_MainLamppostImage {
		Image^ get() {
			return MainLamppostImage;
		}
	}
	//Свойство на чтение текущей позиции
	property Point p_LamppostPosition
	{
		Point get()
		{
			return LamppostPosition;
		}
	}
	//Свойство на чтение текущей длины
	property int p_LamppostImageWidth {
		int get()
		{
			return LamppostImageWidth;
		}
	}
	//Свойство на чтение текущей высоты
	property int p_LamppostImageHeight {
		int get()
		{
			return LamppostImageHeight;
		}
	}
};