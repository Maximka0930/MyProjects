#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class PaintImage
{
protected:
	Image^ globalImage;
	Point globalImagePosition;
	int width;
	int height;
	Windows::Forms::Form^ form;
public:
	PaintImage(Image^ image, Point position, int width, int height, Form^ form)
	{
		this->globalImage = image;
		this->globalImagePosition = position;
		this->width = width;
		this->height = height;
		this->form = form;
	}
	void DrawImageOnTop(Control^ parentControl)
	{
		// Запрашиваем перерисовку элемента управления
		parentControl->Invalidate();
		parentControl->Update();
		// Вызываем событие Paint
		RaisePaint(parentControl, gcnew PaintEventArgs(parentControl->CreateGraphics(), parentControl->DisplayRectangle));

	}
	void RaisePaint(Object^ sender, PaintEventArgs^ e)
	{
		// Проверяем, существует ли изображение
		if (globalImage != nullptr)
		{
			// Создаем объект Graphics для рисования на форме
			Graphics^ g = e->Graphics;
			// Рисуем изображение с использованием объекта Graphics
			//g->FillRectangle(Brushes::Red, globalImagePosition.X, globalImagePosition.Y, width, height);
			g->DrawImage(globalImage, globalImagePosition.X, globalImagePosition.Y, width, height);
		}
	}
	void DrawMovingImageOnTop(Image^ image, Point position, Control^ parentControl, int width, int height)
	{
		// Запрашиваем перерисовку элемента управления
		parentControl->Invalidate();
		parentControl->Update();
		// Вызываем событие Paint
		RaisePaint(parentControl, gcnew PaintEventArgs(parentControl->CreateGraphics(), parentControl->DisplayRectangle));

	}
	
	Image^ GetglobalImage()
	{
		return globalImage;
	}
	Point GetglobalImagePosition()
	{
		return globalImagePosition;
	}
	int Getwidth()
	{
		return width;
	}
	int Getheight()
	{
		return height;
	}
};