#pragma once
#include "Environment.h"
#include "Human.h"
//����� ������� ������
ref class DefaultLamppost
{
protected:
	Image^ LamppostImageOff = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\LamppostOff.png"); //����������� ������������ ������
	Image^ LamppostImageOn = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\LamppostOnFirst.png"); //����������� ����������� ������
	Image^ MainLamppostImage; //������� ����������� ������
	Point LamppostPosition; //������� ������ �� �����
	int LamppostImageWidth; //����� ������� ������
	int LamppostImageHeight; //������ ������� ������
	bool WorkStatus; //������ ������ ������
	Form^ MainForm; //�����
	
public:
	//����������� ������ ������� ������
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
	//����� ��������� �������� ������
	void LamppostOn()
	{
		WorkStatus = true;
		MainLamppostImage = LamppostImageOn;
	}
	//����� ���������� �������� ������
	void LamppostOff()
	{
		WorkStatus = false;
		MainLamppostImage = LamppostImageOff;
	}
	//����� ��������� �������� ������
	void RaisePaintLamppost(Object^ sender, PaintEventArgs^ e)
	{
		if (MainLamppostImage != nullptr)
		{
			Graphics^ g = e->Graphics;
			g->DrawImage(MainLamppostImage, LamppostPosition.X, LamppostPosition.Y, LamppostImageWidth, LamppostImageHeight);
		}
	}

};
//����� ����� ������
ref class SmartLamppost : public DefaultLamppost {
	int LamppostId; // ����� ������
	static int LamppostCounter = 0; //���������� �������
	Image^ LamppostImageFirstDispertion = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\SmartLamppostOn.png"); //����������� ����������� ������
	Image^ LamppostBrokeImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\LamppostBroke.png"); //����������� ���������� ������
public:
	//����������� ������ ����� ������
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
	//����� ����������� ������
	void LamppostBroke()
	{
		MainLamppostImage = LamppostBrokeImage;
		WorkStatus = false;
	}
	//����� ����������� ������
	void LamppostNormal()
	{
		MainLamppostImage = LamppostImageOff;
		WorkStatus = false;
	}
	//����� ������ ������� ������� ������
	void LampppostBrokeMethod()
	{
		LamppostBrokeEvent();
	}
	//����� ������ ������� ������� ������
	void LampppostNormalMethod()
	{
		LamppostNormalEvent();
	}

	//����� ��������� ������ ������
	void SLamppostOff(int id)
	{
		if (LamppostId == id)
		{
			MainLamppostImage = LamppostImageOff;
			WorkStatus = false;
		}
	}
	//����� ���������� ������ ������
	void SLamppostOn(int id)
	{
		if (LamppostId == id)
		{
			MainLamppostImage = LamppostImageFirstDispertion;
			WorkStatus = true;

		}
	}
	//�������� �� ������ �������� �����������
	property Image^ p_MainLamppostImage {
		Image^ get() {
			return MainLamppostImage;
		}
	}
	//�������� �� ������ ������� �������
	property Point p_LamppostPosition
	{
		Point get()
		{
			return LamppostPosition;
		}
	}
	//�������� �� ������ ������� �����
	property int p_LamppostImageWidth {
		int get()
		{
			return LamppostImageWidth;
		}
	}
	//�������� �� ������ ������� ������
	property int p_LamppostImageHeight {
		int get()
		{
			return LamppostImageHeight;
		}
	}
};