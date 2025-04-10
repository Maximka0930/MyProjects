#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
//Класс Окружающая среда
ref class MyEnvironment
{
	Timer^ timer; //Таймер 
	Image^ BackGroudImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\DayNight.png"); //Фоновое изображение
	Image^ FirstPictureBoxImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\NightBackTest2.png"); //Изображение 1-ого затемнения
	Image^ SecondPictureBoxImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\NightBackTest.png"); //Изображение 2-ого затемнения
	Image^ WeatherRainImageFirst = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\RainBack.png"); //Изображение дождя

	Image^ BackImage; //Основное фоновое изображение
	Image^ PictureBoxImage; //Основное изображение PictureBox'a 
	int PartofDay; //Часть дня
	String^ PartOfDayName; //Часть дня
	int angleDegrees = 0; //Угол поворота
	int angleSpeed = 1; //Скорость поворота

	bool WeatherRain = false; //Дождь
	bool LamppostWorkStatus = false; //Работа фонарей
	bool LamppostBroke = false; //Поломка фонаря

	Image^ CurrentPictureBoxImage; //Текущее изображение PictureBox'a

public:
	delegate void DaySwitchHandler();
	static event DaySwitchHandler^ EveningEvent;
	static event DaySwitchHandler^ MorningEvent;

	delegate void WeatherHandler();
	static event WeatherHandler^ RainEvent;
	static event WeatherHandler^ NormalEvent;
	//Конструктор класса
	MyEnvironment()
	{
		timer = gcnew Timer();
		timer->Interval = 100;
		timer->Tick += gcnew EventHandler(this, &MyEnvironment::timer_Tick);
		timer->Start();
		EveningEvent += gcnew MyEnvironment::DaySwitchHandler(this, &MyEnvironment::Evening);
		MorningEvent += gcnew MyEnvironment::DaySwitchHandler(this, &MyEnvironment::Morning);

		PartOfDayName = "Утро";
		
	}
	//Деструктор класса
	~MyEnvironment()
	{
		timer->Stop(); // Остановка таймера
		delete timer; // Освобождение ресурсов таймера
	}
	//Свойство текущего значения таймера
	property int p_SetTimer
	{
		void set(int value) {
			timer->Interval = value;
		}
	}
	//Свойство на чтение текущего фонового изображения
	property Image^ p_GetBackGroudImage {
		Image^ get() {
			return BackImage;
		}
	}
	//Свойство на чтение текущего изображения PictureBox'a
	property Image^ p_GetPictureBoxImage {
		Image^ get()
		{
			return PictureBoxImage;
		}
	}
	//Свойство на чтение текущей части дня
	property String^ p_GetPartOfDayName
	{
		String^ get()
		{
			return PartOfDayName;
		}
	}
	//Свойство текущего состояния погоды
	property bool p_SetWeatherRain
	{
		void set(bool value)
		{
			WeatherRain = value;
		}
	}
	//Свойство текущего статуса работы фонарей
	property bool p_SetLamppostWorkStatus
	{
		void set(bool value)
		{
			LamppostWorkStatus = value;
		}
		bool get()
		{
			return LamppostWorkStatus;
		}
	}
	//Метод, меняющий части дня и погодные условия
	void timer_Tick(System::Object^ sender, System::EventArgs^ e)
	{
		BackImage = RotateImage(BackGroudImage, angleDegrees);
		CheckDegrees();
		if (angleDegrees >= 260 && angleDegrees < 290)
		{
			MorningEvent();
			LamppostWorkStatus = false;
			if (WeatherRain)
			{
				LamppostWorkStatus = true;
			}

		}
		if ((angleDegrees >= 0 && angleDegrees < 70) || (angleDegrees >= 290 && angleDegrees < 360))
		{
			Day();
			LamppostWorkStatus = false;
			if (WeatherRain)
			{
				LamppostWorkStatus = true;	
			}
		}
		if (angleDegrees >= 70 && angleDegrees < 110)
		{
			EveningEvent();
			LamppostWorkStatus = true;
		}
		if (angleDegrees >= 110 && angleDegrees < 260)
		{
			Night();
			LamppostWorkStatus = true;
		}
		if (WeatherRain)
		{
			Rain();
		}
		else
		{
			Normal();
		}
		

		angleDegrees += angleSpeed;
	}
	//Метод дождя
	void Rain()
	{
		PictureBoxImage = WeatherRainImageFirst;
		WeatherRain = true;
		RainEvent();
	}
	//Метод нормальной погоды
	void Normal()
	{
		PictureBoxImage = CurrentPictureBoxImage;
		WeatherRain = false;
		NormalEvent();
	}
	//Метод приостановки окружающей среды 
	void PauseEnvironment()
	{
		angleSpeed = 0;
	}
	//Методы запуска окружающей среды
	void StartEnvironment()
	{
		angleSpeed = 1;
	}
private:
	//Метод утра
	void Morning()
	{
		PartOfDayName = "Утро";
		PartofDay = 0;
		PictureBoxImage = nullptr;
		CurrentPictureBoxImage = PictureBoxImage;
	}
	//Метод дня
	void Day()
	{
		PartOfDayName = "День";
		PartofDay = 1;
		PictureBoxImage = nullptr;
		CurrentPictureBoxImage = PictureBoxImage;

	}
	//Метод вечера
	void Evening()
	{
		PartOfDayName = "Вечер";
		PartofDay = 2;
		if (!WeatherRain)
		{
			PictureBoxImage = FirstPictureBoxImage;
		}
		CurrentPictureBoxImage = PictureBoxImage;

	}
	//Метод ночи
	void Night()
	{
		PartOfDayName = "Ночь";
		PartofDay = 3;
		if (!WeatherRain)
		{
			PictureBoxImage = SecondPictureBoxImage;
		}
		CurrentPictureBoxImage = PictureBoxImage;

	}
	//Метод поворота изображения
	Image^ RotateImage(Image^ image, float angleDegrees)
	{
		if (image != nullptr) {     // Проверяем, удалось ли загрузить изображение
			System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();    // Создаем матрицу поворота
			matrix->Translate(-118, -360);
			matrix->RotateAt(angleDegrees, PointF(image->Width / 2.0f, image->Height / 2.0f));
			Bitmap^ rotatedImage = gcnew Bitmap(image->Width, image->Height); // Создаем новый объект изображения с примененным поворотом
			Graphics^ g = Graphics::FromImage(rotatedImage);
			g->Transform = matrix;
			g->DrawImage(image, Point(0, 0));
			// Освобождаем ресурсы
			delete g;
			delete matrix;
			//rotatedImage->Width = 5000;
			return rotatedImage;
		}
		else {
			MessageBox::Show("Не удалось загрузить изображение.", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	//Метод проверки угла при полном обороте 
	void CheckDegrees()
	{
		if (angleDegrees == 360)
		{
			angleDegrees = 0;
		}

	}
};

