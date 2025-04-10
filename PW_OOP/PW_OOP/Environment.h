#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
//����� ���������� �����
ref class MyEnvironment
{
	Timer^ timer; //������ 
	Image^ BackGroudImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\DayNight.png"); //������� �����������
	Image^ FirstPictureBoxImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\NightBackTest2.png"); //����������� 1-��� ����������
	Image^ SecondPictureBoxImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\NightBackTest.png"); //����������� 2-��� ����������
	Image^ WeatherRainImageFirst = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\RainBack.png"); //����������� �����

	Image^ BackImage; //�������� ������� �����������
	Image^ PictureBoxImage; //�������� ����������� PictureBox'a 
	int PartofDay; //����� ���
	String^ PartOfDayName; //����� ���
	int angleDegrees = 0; //���� ��������
	int angleSpeed = 1; //�������� ��������

	bool WeatherRain = false; //�����
	bool LamppostWorkStatus = false; //������ �������
	bool LamppostBroke = false; //������� ������

	Image^ CurrentPictureBoxImage; //������� ����������� PictureBox'a

public:
	delegate void DaySwitchHandler();
	static event DaySwitchHandler^ EveningEvent;
	static event DaySwitchHandler^ MorningEvent;

	delegate void WeatherHandler();
	static event WeatherHandler^ RainEvent;
	static event WeatherHandler^ NormalEvent;
	//����������� ������
	MyEnvironment()
	{
		timer = gcnew Timer();
		timer->Interval = 100;
		timer->Tick += gcnew EventHandler(this, &MyEnvironment::timer_Tick);
		timer->Start();
		EveningEvent += gcnew MyEnvironment::DaySwitchHandler(this, &MyEnvironment::Evening);
		MorningEvent += gcnew MyEnvironment::DaySwitchHandler(this, &MyEnvironment::Morning);

		PartOfDayName = "����";
		
	}
	//���������� ������
	~MyEnvironment()
	{
		timer->Stop(); // ��������� �������
		delete timer; // ������������ �������� �������
	}
	//�������� �������� �������� �������
	property int p_SetTimer
	{
		void set(int value) {
			timer->Interval = value;
		}
	}
	//�������� �� ������ �������� �������� �����������
	property Image^ p_GetBackGroudImage {
		Image^ get() {
			return BackImage;
		}
	}
	//�������� �� ������ �������� ����������� PictureBox'a
	property Image^ p_GetPictureBoxImage {
		Image^ get()
		{
			return PictureBoxImage;
		}
	}
	//�������� �� ������ ������� ����� ���
	property String^ p_GetPartOfDayName
	{
		String^ get()
		{
			return PartOfDayName;
		}
	}
	//�������� �������� ��������� ������
	property bool p_SetWeatherRain
	{
		void set(bool value)
		{
			WeatherRain = value;
		}
	}
	//�������� �������� ������� ������ �������
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
	//�����, �������� ����� ��� � �������� �������
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
	//����� �����
	void Rain()
	{
		PictureBoxImage = WeatherRainImageFirst;
		WeatherRain = true;
		RainEvent();
	}
	//����� ���������� ������
	void Normal()
	{
		PictureBoxImage = CurrentPictureBoxImage;
		WeatherRain = false;
		NormalEvent();
	}
	//����� ������������ ���������� ����� 
	void PauseEnvironment()
	{
		angleSpeed = 0;
	}
	//������ ������� ���������� �����
	void StartEnvironment()
	{
		angleSpeed = 1;
	}
private:
	//����� ����
	void Morning()
	{
		PartOfDayName = "����";
		PartofDay = 0;
		PictureBoxImage = nullptr;
		CurrentPictureBoxImage = PictureBoxImage;
	}
	//����� ���
	void Day()
	{
		PartOfDayName = "����";
		PartofDay = 1;
		PictureBoxImage = nullptr;
		CurrentPictureBoxImage = PictureBoxImage;

	}
	//����� ������
	void Evening()
	{
		PartOfDayName = "�����";
		PartofDay = 2;
		if (!WeatherRain)
		{
			PictureBoxImage = FirstPictureBoxImage;
		}
		CurrentPictureBoxImage = PictureBoxImage;

	}
	//����� ����
	void Night()
	{
		PartOfDayName = "����";
		PartofDay = 3;
		if (!WeatherRain)
		{
			PictureBoxImage = SecondPictureBoxImage;
		}
		CurrentPictureBoxImage = PictureBoxImage;

	}
	//����� �������� �����������
	Image^ RotateImage(Image^ image, float angleDegrees)
	{
		if (image != nullptr) {     // ���������, ������� �� ��������� �����������
			System::Drawing::Drawing2D::Matrix^ matrix = gcnew System::Drawing::Drawing2D::Matrix();    // ������� ������� ��������
			matrix->Translate(-118, -360);
			matrix->RotateAt(angleDegrees, PointF(image->Width / 2.0f, image->Height / 2.0f));
			Bitmap^ rotatedImage = gcnew Bitmap(image->Width, image->Height); // ������� ����� ������ ����������� � ����������� ���������
			Graphics^ g = Graphics::FromImage(rotatedImage);
			g->Transform = matrix;
			g->DrawImage(image, Point(0, 0));
			// ����������� �������
			delete g;
			delete matrix;
			//rotatedImage->Width = 5000;
			return rotatedImage;
		}
		else {
			MessageBox::Show("�� ������� ��������� �����������.", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	//����� �������� ���� ��� ������ ������� 
	void CheckDegrees()
	{
		if (angleDegrees == 360)
		{
			angleDegrees = 0;
		}

	}
};

