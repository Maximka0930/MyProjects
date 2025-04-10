using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.IO.Ports;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Documents;
using System.Windows.Ink;
using System.Windows.Input;
using System.Windows.Markup;
using System.Windows.Media;
using System.Windows.Shapes;

namespace GraphicDecisionLP
{
    public class Plotting
    {
        private Canvas _canvas;
        private Grid _GraphicField;
        private double _СoefficientOfApproximation;
        private double XkY;

        private List<List<double>> _equations;
        private List<bool> _isMoreThenLinesList;

        private Polygon MainPolygon;

        public bool isIntersectionExists;

        public Plotting(Grid grid)
        {
            _GraphicField = grid;

            _canvas = new Canvas();
            _canvas.Background = Brushes.Wheat;
            _GraphicField.Children.Add(_canvas);
            //_canvas.ClipToBounds = true;
            _canvas.MouseWheel += Canvas_MouseWheel;                      //Реакция графика на колесико мыши

            _СoefficientOfApproximation = 8;                              //Коэффициенты полей
            XkY = _GraphicField.ActualWidth / _GraphicField.ActualHeight; //Коэффициент отношения полей X и Y

            DrawXAxisDivisions(_СoefficientOfApproximation * XkY);        // Отрисовка вспомогательных вертикальных полей 
            DrawYAxisDivisions(_СoefficientOfApproximation);              // Отрисовка вспомогательных горизонтальных полей
            DrawCoordinateAxes();                                         // Отрисовка осей X и Y

            _equations = new List<List<double>>();
            _isMoreThenLinesList = new List<bool>();
        }

        //Создание из полигона пути для отрисовки геометрической фигуры
        private object CreatePathOfPolygon(Polygon polygon )
        {
            var s1 = polygon.Points.Skip(1).Select(p => new LineSegment { Point = p });
            var FirstGeometry = new PathFigure(polygon.Points.First(), s1, true);
            var path1 = new PathGeometry(new[] { FirstGeometry });
            return path1;
        }

        public void PlotClear()
        {
            _canvas.Children.Clear();
        }

        private void DrawCoordinateAxes()
        {
            Line line = new Line();

            line.Stroke = Brushes.Black;
            line.StrokeThickness = 3;
            line.X1 = 0;
            line.Y1 = 0;
            line.X2 = 0;
            line.Y2 = _GraphicField.ActualHeight;
            line.Width = _GraphicField.ActualWidth;
            _canvas.Children.Add(line);

            Line line2 = new Line();
            line2.Stroke = Brushes.Black;
            line2.StrokeThickness = 3;
            line2.X1 = 0;
            line2.Y1 = _GraphicField.ActualHeight;
            line2.X2 = _GraphicField.ActualWidth;
            line2.Y2 = _GraphicField.ActualHeight;
            _canvas.Children.Add(line2);

            Line line2_1 = new Line();
            line2_1.Stroke = Brushes.Black;
            line2_1.StrokeThickness = 2;
            line2_1.X1 = _GraphicField.ActualWidth - _GraphicField.ActualWidth * 0.04;
            line2_1.Y1 = _GraphicField.ActualHeight - _GraphicField.ActualHeight * 0.03;
            line2_1.X2 = _GraphicField.ActualWidth;
            line2_1.Y2 = _GraphicField.ActualHeight;
            _canvas.Children.Add(line2_1);

            Label labelX = new Label();
            labelX.Content = "X1";
            labelX.Background = Brushes.Transparent;
            labelX.FontSize = 14;
            labelX.Margin = new Thickness(_GraphicField.ActualWidth, _GraphicField.ActualHeight , 0, 0);
            _canvas.Children.Add(labelX);

            Line line2_2 = new Line();
            line2_2.Stroke = Brushes.Black;
            line2_2.StrokeThickness = 2;
            line2_2.X1 = _GraphicField.ActualWidth;
            line2_2.Y1 = _GraphicField.ActualHeight;
            line2_2.X2 = _GraphicField.ActualWidth - _GraphicField.ActualWidth * 0.04;
            line2_2.Y2 = _GraphicField.ActualHeight + _GraphicField.ActualHeight * 0.03;
            _canvas.Children.Add(line2_2);

            Line line1_1 = new Line();
            line1_1.Stroke = Brushes.Black;
            line1_1.StrokeThickness = 2;
            line1_1.X1 = 0;
            line1_1.Y1 = 0;
            line1_1.X2 = _GraphicField.ActualHeight * 0.03;
            line1_1.Y2 = _GraphicField.ActualWidth * 0.04;
            _canvas.Children.Add(line1_1);

            Line line1_2 = new Line();
            line1_2.Stroke = Brushes.Black;
            line1_2.StrokeThickness = 2;
            line1_2.X1 = 0;
            line1_2.Y1 = 0;
            line1_2.X2 = -_GraphicField.ActualHeight * 0.03;
            line1_2.Y2 = _GraphicField.ActualWidth * 0.04;
            _canvas.Children.Add(line1_2);

            Label labelY = new Label();
            labelY.Content = "X2";
            labelY.Background = Brushes.Transparent;
            labelY.FontSize = 14;
            labelY.Margin = new Thickness(-_GraphicField.ActualWidth * 0.03, -_GraphicField.ActualHeight * 0.05, 0, 0);
            _canvas.Children.Add(labelY);

            Label label = new Label();
            label.Content = 0.ToString();
            label.Background = Brushes.Transparent;
            label.FontSize = 12;
            label.Margin = new Thickness(-_GraphicField.ActualWidth * 0.02, _GraphicField.ActualHeight - _GraphicField.ActualHeight * 0.02, 0, 0);
            _canvas.Children.Add(label);

        }//Рисование осей X и Y 

        private void DrawXAxisDivisions(double n)
        {

            double step = _GraphicField.ActualWidth / n;
            for (int i = 1; i < n; i++)
            {
                Line line = new Line();
                line.Stroke = Brushes.Gray;
                line.StrokeThickness = 1;
                line.X1 = step * i;
                line.Y1 = 0;
                line.X2 = step * i;
                line.Y2 = _GraphicField.ActualHeight;
                _canvas.Children.Add(line);

                Label label = new Label();
                label.Content = i.ToString();
                label.Background = Brushes.Transparent;
                label.FontSize = 12;
                label.Margin = new Thickness(line.X2 - 8, line.Y2, 0, 0);
                _canvas.Children.Add(label);

            }

        }
        private void DrawYAxisDivisions(double n)
        {
            double step = _GraphicField.ActualHeight / n;
            for (int i = 1; i < n; i++)
            {
                Line line = new Line();
                line.Stroke = Brushes.Gray;
                line.StrokeThickness = 1;
                line.X1 = 0;
                line.Y1 = _GraphicField.ActualHeight - step * i;
                line.X2 = _GraphicField.ActualWidth;
                line.Y2 = _GraphicField.ActualHeight - step * i;
                _canvas.Children.Add(line);

                Label label = new Label();
                label.Content = i.ToString();
                label.Background = Brushes.Transparent;
                label.FontSize = 12;
                label.Margin = new Thickness(line.X1 - 20, line.Y1 - 10, 0, 0);
                _canvas.Children.Add(label);

            }
        }

        //Реакция графика на колесико мыши 
        //[Реализовать увеличение\уменьшение масшатаба]
        private void Canvas_MouseWheel(object sender, System.Windows.Input.MouseWheelEventArgs e)
        {
            this.PlotClear();

            if (e.Delta > 0)
            {
                if (_СoefficientOfApproximation > 2)
                { 
                    _СoefficientOfApproximation -= 1;
                }
            }
            else
            {
                _СoefficientOfApproximation += 1;
            }
            XkY = _GraphicField.ActualWidth / _GraphicField.ActualHeight;

            isInfinity = false;
            DrawXAxisDivisions(_СoefficientOfApproximation * XkY);
            DrawYAxisDivisions(_СoefficientOfApproximation);
            DrawCoordinateAxes();
            if (_isGraphicBuild)
            {
                CreateAreaOfIntersection(ref MainPolygon, ref isIntersectionExists);                    // Создание путей к полигонам и закрашивание необходимой области
                GetPointOfIntersection(_isFindMax);
            }

        }

        //Построение области значений
        private Polygon DrawGraphicEquation(double firstVar, double secondVar, double resultVar, bool isBigger)
        {
            Line line_1;
            if (firstVar == 0)
            {
                line_1 = new Line()
                {
                    Stroke = Brushes.Blue,
                    StrokeThickness = 3,
                    X1 = 0,
                    Y1 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(firstVar, secondVar, resultVar, 0),
                    X2 = _GraphicField.ActualWidth,
                    Y2 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(firstVar, secondVar, resultVar, 0),
                };
            }
            else if (secondVar == 0)
            {
                line_1 = new Line()
                {
                    Stroke = Brushes.Blue,
                    StrokeThickness = 3,
                    X1 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(firstVar, secondVar, resultVar, 0),
                    Y1 = 0,
                    X2 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(firstVar, secondVar, resultVar, 0),
                    Y2 = _GraphicField.ActualHeight,
                };
            }
            else
            {
                line_1 = new Line()
                {
                    Stroke = Brushes.Blue,
                    StrokeThickness = 3,
                    X1 = 0,
                    Y1 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(firstVar, secondVar, resultVar, 0),
                    X2 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(firstVar, secondVar, resultVar, 0),
                    Y2 = _GraphicField.ActualHeight,
                };

            }

            _canvas.Children.Add(line_1);
            _lines.Add(line_1);

            if (isBigger)
            {
                Point f1 = new Point(0, 0);
                Point f2 = new Point(line_1.X1, line_1.Y1);
                Point f3 = new Point(line_1.X2, line_1.Y2);
                Point f4 = new Point(_GraphicField.ActualWidth, _GraphicField.ActualHeight);
                Point f5 = new Point(_GraphicField.ActualWidth, 0);
                Polygon polygon = new Polygon()
                {
                    Points = { f1, f2, f3, f4, f5 },
                    Stroke = Brushes.Purple,
                };
                //_canvas.Children.Add(polygon);
                return polygon;
            }
            else
            {
                Point firstPoint = new Point(0, _GraphicField.ActualHeight);
                Point fr = new Point(0,0);
                Point secondPoint = new Point(line_1.X1, line_1.Y1);
                Point thirdPoint = new Point(line_1.X2, line_1.Y2);
                Point fourthPoint = new Point(_GraphicField.ActualWidth,_GraphicField.ActualHeight);
                Polygon polygon = new Polygon()
                {
                    Points = { firstPoint, fr, secondPoint, thirdPoint, fourthPoint },
                    Stroke = Brushes.Purple,
                    Fill = Brushes.Red,
                    Opacity = 0.2
                };
                //_canvas.Children.Add(polygon);
                return polygon;
            }

        }

        private Polygon DrawGraphicXYEquation(double firstVar, double secondVar, double resultVar, bool isBigger)
        {
            Line line_1 = new Line()
            {
                Stroke = Brushes.Blue,
                StrokeThickness = 3,
                X1 = 0,
                Y1 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(firstVar, secondVar, resultVar, 0),
                X2 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(firstVar, secondVar, resultVar, 0),
                Y2 = _GraphicField.ActualHeight,
            };

            Point f1 = new Point(0, -_GraphicField.ActualHeight);
            Point f2 = new Point(line_1.X1, line_1.Y1);
            Point f3 = new Point(line_1.X2, line_1.Y2);
            Point f4 = new Point(_GraphicField.ActualWidth, _GraphicField.ActualHeight);
            Point f5 = new Point(100000, -100000);
            Polygon polygon = new Polygon()
            {
                Points = { f1, f2, f3, f4, f5 },
                Stroke = Brushes.Purple,
            };
            return polygon;
            

        }


        //Вспомогательная функция. Нахождение X координаты линии
        private double DecisionXEq(double firstVar, double secondVar, double resultVar, double secondEq)
        {
            if (secondVar == 0)
            {
                return resultVar / firstVar;
            }
            else
            {
                if ((resultVar - secondVar * secondEq) / firstVar == double.NegativeInfinity || (resultVar - secondVar * secondEq) / firstVar == double.PositiveInfinity)
                {
                    return 0;
                }
                return (resultVar - secondVar * secondEq) / firstVar;

            }

        }
        //Вспомогательная функция. Нахождение Y координаты линии
        private double DecisionYEq(double firstVar, double secondVar, double resultVar, double firstEq)
        {
            if (firstVar == 0)
            {
                return resultVar / secondVar;
            }
            else
            {
                if ((resultVar - firstVar * firstEq) / secondVar == double.NegativeInfinity || (resultVar - firstVar * firstEq) / secondVar == double.PositiveInfinity)
                {
                    return 0;
                }
                return (resultVar - firstVar * firstEq) / secondVar;            

            }
        }

        public Polygon BuildListOfPolygons(List<double> list, bool isBigger) //Добавление нового условия ограничения
        {
            Polygon NewPolygon = DrawGraphicEquation(list[0], list[1], list[2], isBigger);
            return NewPolygon;
        }

        private List<Line> _lines;

        private void CreateAreaOfIntersection(ref Polygon polygon, ref bool isIntersectionExists )
        {
            polygon = new Polygon();
            Polygon BiggerXPolygon = DrawGraphicXYEquation(0, 1, 1000, true);
            Polygon BiggerYPolygon = DrawGraphicXYEquation(1, 0, 1000, true);

            var Xpoly = CreatePathOfPolygon(BiggerXPolygon);
            var YPoly = CreatePathOfPolygon(BiggerYPolygon);

            var ResultArea = new Path()
            {
                Data = new CombinedGeometry(GeometryCombineMode.Intersect, (Geometry)Xpoly, (Geometry)YPoly),
            };

            for (int i = 0; i < _equations.Count; i++)
            {
                Polygon NewPolygon = BuildListOfPolygons(_equations[i], _isMoreThenLinesList[i]);
                var NewPoly = CreatePathOfPolygon(NewPolygon);

                var Var = new Path()
                {
                    Data = new CombinedGeometry(GeometryCombineMode.Intersect, (Geometry)ResultArea.Data, (Geometry)NewPoly),
                    Fill = Brushes.LightBlue,
                    Opacity = 0.75
                };
                ResultArea = Var;
            }

            PathGeometry g = ResultArea.Data.GetFlattenedPathGeometry();
            foreach (var f in g.Figures)
                foreach (var s in f.Segments)
                    if (s is PolyLineSegment)
                        foreach (var pt in ((PolyLineSegment)s).Points)
                            polygon.Points.Add(pt);

            if (polygon.Points.Count > 2)
            {
                isIntersectionExists = true;
            }
            else
            {
                isIntersectionExists = false;
            }

            _canvas.Children.Add(ResultArea);
        } // Создание области пересечения

        private double _valueA;
        private double _valueB;
        private bool _isFindMax;

        public double FunctionValue;

        public bool _isGraphicBuild;
        private Point ResultPoint;
        private Point DecisonPoint;

        public void FindDesisionOfTask(double a, double b, bool _isFindMax, List<List<double>> equations, List<bool> bools) //Получение коэффициентов A и B функции
        {
            PlotClear();
            _valueA = a;
            _valueB = b;
            this._isFindMax = _isFindMax;

            _equations = equations;
            _isMoreThenLinesList = bools;
            _lines = null;
            _lines = new List<Line>();


            isInfinity = false;
            DrawXAxisDivisions(_СoefficientOfApproximation * XkY);
            DrawYAxisDivisions(_СoefficientOfApproximation);
            DrawCoordinateAxes();

            CreateAreaOfIntersection(ref MainPolygon, ref isIntersectionExists);                    // Создание путей к полигонам и закрашивание необходимой области
            if (isIntersectionExists)
            {
                GetPointOfIntersection(_isFindMax);
            }
            else
            {
                FunctionValue = 0;
                ResultPoint.X = 0;
                ResultPoint.Y = 0;
            }

            _isGraphicBuild = true;

        }


        private void GetPointOfIntersection(bool _FindMax) //Поиск точки макс/мин. значения функции. Отрисовка точки
        {
            if (MainPolygon.Points.Count > 0)
            {
                int k = 0;
                double Max = 0;
                double Min = 1000000;
                for (int i = 0; i < Convert.ToInt32(MainPolygon.Points.Count); i++)
                {
                    double x = Math.Round(MainPolygon.Points[i].X,2);
                    double y = Math.Round(_GraphicField.ActualHeight -  MainPolygon.Points[i].Y, 2);

                    Point point = new Point();

                    point.X = Math.Round(x/(_GraphicField.ActualWidth/(_СoefficientOfApproximation*XkY)),2);
                    point.Y = Math.Round(y/(_GraphicField.ActualHeight/_СoefficientOfApproximation),2);

                    if (_FindMax)
                    {
                        if (_valueA * point.X + _valueB * point.Y > Max)
                        {
                            Max = _valueA * point.X + _valueB * point.Y;
                            FunctionValue = Math.Round(Max, 2);
                            ResultPoint = point;
                            DecisonPoint.X = Math.Round(MainPolygon.Points[i].X, 2);
                            DecisonPoint.Y = Math.Round(MainPolygon.Points[i].Y, 2);
                        }
                    }
                    else
                    {
                        if (_valueA * point.X + _valueB * point.Y < Min)
                        {
                            Min = _valueA * point.X + _valueB * point.Y;
                            FunctionValue = Math.Round(Min, 2);
                            ResultPoint = point;
                            DecisonPoint.X = Math.Round(MainPolygon.Points[i].X, 2);
                            DecisonPoint.Y = Math.Round(MainPolygon.Points[i].Y, 2);
                        }
                    }
                
                }


                double X = Math.Round(_GraphicField.ActualWidth / (_GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY)), 3);
                double Y = Math.Round(_GraphicField.ActualHeight / (_GraphicField.ActualHeight / _СoefficientOfApproximation), 3);


                double G = _valueA * X + _valueB * Y;
                if (Math.Round(FunctionValue,1) == Math.Round(G,1))
                {
                    isInfinity = true;
                }

                ChangeFunctionPosition(FunctionValue);
            }

        }

        private bool test;
        private void DrawDecisionPoint()
        {
            Ellipse ellipse = new Ellipse()
            {
                Fill = Brushes.Red,
                StrokeThickness = 3,
                Margin = new Thickness(DecisonPoint.X - 4, DecisonPoint.Y - 4, 0, 0),
                Width = 8,
                Height = 8,
            };
            _canvas.Children.Add(ellipse);
        }

        public bool isInfinity;

        public void ChangeFunctionPosition(double value) //Построение прямой функции в макс/мин. точке
        {
       
            if (!isInfinity)
            {
                Line line;

                if (_valueA == 0)
                {
                    line = new Line()
                    {
                        Stroke = Brushes.LightGreen,
                        StrokeThickness = 3,
                        X1 = 0,
                        Y1 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(_valueA, _valueB, value, 0),
                        X2 = _GraphicField.ActualWidth,
                        Y2 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(_valueA, _valueB, value, 0),
                    };
                }
                else if (_valueB == 0)
                {
                    line = new Line()
                    {
                        Stroke = Brushes.LightGreen,
                        StrokeThickness = 3,
                        X1 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(_valueA, _valueB, value, 0),
                        Y1 = 0,
                        X2 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(_valueA, _valueB, value, 0),
                        Y2 = _GraphicField.ActualHeight,
                    };
                }
                else
                {
                    line = new Line()
                    {
                        Stroke = Brushes.LightGreen,
                        StrokeThickness = 3,
                        X1 = 0,
                        Y1 = _GraphicField.ActualHeight - _GraphicField.ActualHeight / _СoefficientOfApproximation * DecisionYEq(_valueA, _valueB, value, 0),
                        X2 = _GraphicField.ActualWidth / (_СoefficientOfApproximation * XkY) * DecisionXEq(_valueA, _valueB, value, 0),
                        Y2 = _GraphicField.ActualHeight,
                    };

                }
                _canvas.Children.Add(line);

                bool isDrawPoint = true;

                for (int i = 0; i < _equations.Count; i++)
                {
                    if (_lines[i].X1 == line.X1 && _lines[i].Y1 == line.Y1 && _lines[i].X2 == line.X2 && _lines[i].Y2 == line.Y2)
                    {
                        isDrawPoint = false;
                        break;
                    }
                }
                if (isDrawPoint)
                {
                    DrawDecisionPoint();

                }
                
            }            
        }

        public void CheckAnotherDecisons(double value) //Построение прямой функции в макс/мин. точке
        {
            PlotClear();
            DrawXAxisDivisions(_СoefficientOfApproximation * XkY);
            DrawYAxisDivisions(_СoefficientOfApproximation);
            DrawCoordinateAxes();
            CreateAreaOfIntersection(ref MainPolygon, ref isIntersectionExists);
            ChangeFunctionPosition(value);
        }

        public String OutPutPoint()
        {
            return "[ " + ResultPoint.X + " ; " + ResultPoint.Y + " ]";
        }

    }

}