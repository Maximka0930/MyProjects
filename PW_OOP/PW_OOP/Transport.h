#pragma once
#include <Windows.h>
#include <iostream>
#include <vcclr.h>
#include <string>
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;


ref class Transport
{
	Image^ FirstCarImage = Image::FromFile("C:\\Users\\nikol\\source\\repos\\PW_OOP\\Images\\TaxiRight.png");
	Image^ MainCarImage = FirstCarImage;
	Point CarPosition;
	int CarSpeed;
public:
	Transport(Point postiton, int speed)
	{
		CarPosition = postiton;
		CarSpeed = speed;
	}

	void CarMoving()
	{
		CarPosition.X += CarSpeed;
	}
	Point GetCarPosition()
	{
		return CarPosition;
	}
	Image^ GetMainCarImage()
	{
		return MainCarImage;
	}
	

	void CarDriveLeft(int value)
	{
		this->CarSpeed = -abs(value);
	}
	void CarDriveRight(int value)
	{
		this->CarSpeed = abs(value);
	}

	virtual void Draw(PaintEventArgs^ e)
	{
		Graphics^ g = e->Graphics;
		if (MainCarImage != nullptr)
		{
			g->DrawImage(MainCarImage, CarPosition);
		}
	}


};

