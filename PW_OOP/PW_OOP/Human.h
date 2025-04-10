#pragma once
#include <stdlib.h>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
//����� �������
ref class Human
{
public:
	Image^ HumanImage; // ������� ����������� ��������
	Point HumanPosition; //������� ��������
	int HumanImageWidth = 120; //����� ����������� ��������
	int HumanImageHeight = 180; //������ ����������� ��������
	int HumanSpeed; //�������� ��������
	Image^ HumanImageTwo; //������ ����������� �������� 
	Image^ HumanImageOne; //������ ����������� ��������
	int num = 0; // ���������� ��������
	int animationSpeed = 15; // �������� ��������
	//������ ����������� ��������, ������� �������
	static array<Image^>^ HumanImagesRight = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\1.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\2.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\3.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\4.One.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\1.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\2.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\3.Two.png"),
			Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Right\\4.Two.png") };
	//������ ����������� ��������, ������� ������
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
	static int humansCounter = 0; //���������� �������

	static int LamppostWidthStatic = 766; //������� ����� ������
	static int LamppostHeightStatic = 360; //������� ������ ������
	static array<Human^>^ humansArray = gcnew array<Human^>(25); //������ ����������� ������

	static array<Point>^ LamppostsPositionStatic = gcnew array<Point>{Point(-200, 360), Point(125, 360), Point(425, 360), Point(725, 360)}; //������ �������� ������
	int LamppostId; //����� ������

public:

	delegate void HumanCrossLamppostHandler(int id);
	static event HumanCrossLamppostHandler^ HumanCrossLamppostEvent;
	static event HumanCrossLamppostHandler^ HumanOutOfLamppostEvent;

	//�����������
	Human()
	{
		int randomNumber = raNd->Next(0, 2); // ���������� ��������� ����� 0 ��� 1
		HumanSpeed = (randomNumber == 0) ? -5 : 5; // ���� randomNumber ����� 0, �� HumanSpeed ����� -5, ����� 5
		HumanPosition.X = (HumanSpeed == -5) ? 1320 : -120;
		HumanPosition.Y = raNd->Next(500, 535);
		if (HumanSpeed > 0)
		{
			SetRandomImagesRight(); // ��������� ���������� ����������� ��� �������� ����������
		}
		else
		{
			SetRandomImagesLeft();
		}
		Human::AddToHumansArray(this);
		humansCounter++;
		}
	//����������
	~Human()
	{
		Human::RemoveFromHumansArray(this);
		humansCounter--;
	}
	
	//�������� �� ������ ������� �������
	property Point p_GetHumanPosition {
		Point get()
		{
			return HumanPosition;
		}
	}
	//�������� �� ������ �������� �����������
	property Image^ p_GetHumanImage {
		Image^ get()
		{
			return HumanImage;
		}
	}
	//�������� �� ������ ������� �����
	property int p_GetHumanImageWidth {
		int get()
		{
			return HumanImageWidth;

		}
	}
	//�������� �� ������ ������� ������
	property int p_GetHumanImageHeight {
		int get()
		{
			return HumanImageHeight;

		}
	}
	//�������� �� ������ ������� ��������
	property int p_GetHumanSpeed {
		int get()
		{
			return HumanSpeed;
		}
	}
	//�������� �������� �������� �����
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
	// ����� ��� �������� ���������� Human �� �������
	static void Human::RemoveFromHumansArray(Human^ human)
	{
		for (int i = 0; i < humansArray->Length; i++)
		{
			if (humansArray[i] == human)
			{
				humansArray[i] = nullptr; // ������������� ������� � ������� ��� nullptr
				break; // ������� �� ����� ����� �������� ��������
			}
		}
	}
	// ����� ��� ���������� ���������� ������ � ����������� ������
	static void Human::AddToHumansArray(Human^ human)
	{
		// ���� ������ ������ ���� � ������� � ��������� ���� ��������� ������
		for (int i = 0; i < humansArray->Length; i++)
		{
			if (humansArray[i] == nullptr)
			{
				humansArray[i] = human;
				break;
			}
		}
	}

	// ������ ��� ��������� ��������� �����������
	void SetRandomImagesRight()
	{
		int index = raNd->Next(0, HumanImagesRight->Length / 2); // ��������� ���������� �������
		HumanImageOne = HumanImagesRight[index]; // ��������� ������� ���������� �����������
		// ����� ���������� ������� ��� ������� �����������
		HumanImageTwo = HumanImagesRight[index + 4]; // ��������� ������� ���������� �����������
		HumanImage = HumanImageOne;
		delete raNd;
		//MessageBox::Show(Convert::ToString((index)));

	}
	void SetRandomImagesLeft()
	{
		int index = raNd->Next(0, HumanImagesLeft->Length / 2); // ��������� ���������� �������
		HumanImageOne = HumanImagesLeft[index]; // ��������� ������� ���������� �����������
		// ����� ���������� ������� ��� ������� �����������
		HumanImageTwo = HumanImagesLeft[index + 4]; // ��������� ������� ���������� �����������
		HumanImage = HumanImageOne;
		delete raNd;
		//MessageBox::Show(Convert::ToString((index)));

	}
	//������ ������������ ��������
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
	//����� ��������� ��������
	void HumanStop()
	{
		HumanSpeed = 0;
	}
	//����� ������������� ����������� �������� � �������� ������
	static bool HumanCrossLamppost(int id, int HumanId)
	{
		System::Drawing::Rectangle intersectRegion = Rectangle::Intersect(
			System::Drawing::Rectangle(LamppostsPositionStatic[id].X + 100, LamppostsPositionStatic[id].Y, LamppostWidthStatic - 200, LamppostHeightStatic),
			System::Drawing::Rectangle(humansArray[HumanId]->HumanPosition.X, humansArray[HumanId]->HumanPosition.Y, humansArray[HumanId]->HumanImageWidth, humansArray[HumanId]->HumanImageHeight)
		);
		return intersectRegion != Rectangle::Empty;
	}
	//������ ������������� ����������� �������� � ��������� �������
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
				bool anyCrossed = false; // ���� ��� ������������ ����������� ��� �������� ������
				for (int j = 0; j < humansArray->Length; j++) // �������� �� ���� �����
				{
					if (humansArray[j] != nullptr && HumanCrossLamppost(i, j))
					{
						HumanCrossLamppostEvent(i);
						anyCrossed = true;
						break;
					}
				}
				if (!anyCrossed) // ���� ������ �� ����������� ��� �������� ��������, ��������� ���
				{
					HumanOutOfLamppostEvent(i);
				}

			}
		}
	}
	//������ ���������
	virtual void Draw(PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		if (HumanImage != nullptr)
		{
			g->DrawImage(HumanImage, HumanPosition);
		}
	}
};
//����� ��������
ref class Electrician : public Human
{
	static array<Image^>^ ElectricImagesRight = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianOneRight.png"),
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianTwoRight.png")
	}; 	//������ ����������� ���������, ������� �������

	static array<Image^>^ ElectricImagesLeft = gcnew array<Image^>{
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianOneLeft.png"),
		Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\People\\Electrician\\ElectricianTwoLeft.png"),
	}; //������ ����������� ���������, ������� ������
public:

	int lmpstPost; //����� ���������� ������
	//����������� ������
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
	//��������� ��������� �����������
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