using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace GraphicDecisionLP
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {

        //private List<double> equations;
        private List<bool> isMoreThenLineList;
        private StackPanel stackPanels;
        private double ValueA;
        private double ValueB;
        private bool isFindMax;

        private List<double> MainValues;

        public MainWindow()
        {
            InitializeComponent();    
            Loaded += MyWindow_Loaded;
            SizeChanged += MainWindow_SizeChanged;

            stackPanels = new StackPanel();

            equations = new List<List<double>>();
            isMoreThenLineList = new List<bool>();
            MainValues = new List<double>(2);
        }

        private Plotting _plot;
        private bool _isPlotInitialize;

        private void MainWindow_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            if (_isPlotInitialize)
            {
                _plot.PlotClear();
                _plot = new Plotting(GraphicField);
            }
        }

        private void MyWindow_Loaded(object sender, RoutedEventArgs e)
        {
            _plot = new Plotting(GraphicField);
            _isPlotInitialize = true;
            slider.Value = 50;

        }

        private void AddEquation_Click(object sender, RoutedEventArgs e)
        {
            CreateEquatonInputInterface();
        }

        private void BuildGraphic_Click(object sender, RoutedEventArgs e)
        {
            TakeFromMainTextBox();
            TakeFromMainComboBox();

            TakeFromTextBox();
            TakeFromComboBox();

            _plot.FindDesisionOfTask(MainValues[0], MainValues[1], isFindMax, equations, isMoreThenLineList);
            //slider.Value = _plot.FunctionValue;
            slider.Maximum = _plot.FunctionValue;
            FunctionResultPoint.Text =  "Точка: " + _plot.OutPutPoint();

            if (isFindMax)
            {
                if (_plot.isInfinity)
                {
                    FunctionResult.Text = "F(max) = ∞";
                    //slider.Value = 10;
                    slider.Maximum = 50;
                    FunctionResultPoint.Text = "Точка: [ ; ]";

                }
                else
                {
                    FunctionResult.Text = "F(max) = " + _plot.FunctionValue.ToString();
                }
                if (_plot.FunctionValue == 0)
                {
                    FunctionResult.Text = "Решений нет";
                }
            }
            else
            {
                FunctionResult.Text = "F(min) = " + _plot.FunctionValue.ToString();
            }

            slider.IsEnabled = true;
            isValueInstall = true;
        }

        private bool isValueInstall;
        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            if (isValueInstall)
            {
                ChangeFunctionResultPoint.Text = "Текущее значение: " + slider.Value.ToString();
                _plot.CheckAnotherDecisons(slider.Value);
            }
        }

        private int CountOfEq;
        private void CreateEquatonInputInterface(double valueA, double valueB, double result, bool isMore)
        {
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                Margin = new Thickness(0,0,0,12),
            };
            TextBlock txtBlock1 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0,0,5,0),
                Text = "f"+ CountOfEq.ToString()+"=",
            };
            CountOfEq++;
            stackPanel.Children.Add(txtBlock1);
            TextBox txtBox1 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
                Text = valueA.ToString() 
            };
            stackPanel.Children.Add(txtBox1);
            TextBlock txtBlock2 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "X1+ "
            };
            stackPanel.Children.Add (txtBlock2);
            TextBox txtBox2 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
                Text = valueB.ToString()
            };
            stackPanel.Children.Add(txtBox2);
            TextBlock txtBlock3 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "X2"
            };
            stackPanel.Children.Add(txtBlock3);
            ComboBox comboBox = new ComboBox()
            {
                MaxWidth = 50,
                MaxHeight = 40,
                Height = 40,
                Width = 50,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                HorizontalContentAlignment = HorizontalAlignment.Center,
                VerticalContentAlignment = VerticalAlignment.Center,
            };
            comboBox.ItemsSource = new TextBlock[]
            {
                new TextBlock() { FontSize = 20, Text = " ≥ "},
                new TextBlock() { FontSize = 20, Text = " ≤ "},
            };
            if (isMore)
            {
                comboBox.SelectedIndex = 0;
            }
            else
            {
                comboBox.SelectedIndex = 1;
            }
            stackPanel.Children.Add(comboBox);
            TextBox txtBox3 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
                Text = result.ToString()
            };
            stackPanel.Children.Add (txtBox3);
            LimitEquationPanel.Children.Add(stackPanel);
        }
        private void CreateEquatonInputInterface()
        {
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                Margin = new Thickness(0, 0, 0, 12),
            };
            TextBlock txtBlock1 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "f" + CountOfEq.ToString() + "=",
            };
            CountOfEq++;
            stackPanel.Children.Add(txtBlock1);
            TextBox txtBox1 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
            };
            stackPanel.Children.Add(txtBox1);
            TextBlock txtBlock2 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "X1+ "
            };
            stackPanel.Children.Add(txtBlock2);
            TextBox txtBox2 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
            };
            stackPanel.Children.Add(txtBox2);
            TextBlock txtBlock3 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "X2"
            };
            stackPanel.Children.Add(txtBlock3);
            ComboBox comboBox = new ComboBox()
            {
                MaxWidth = 50,
                MaxHeight = 40,
                Height = 40,
                Width = 50,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                HorizontalContentAlignment = HorizontalAlignment.Center,
                VerticalContentAlignment = VerticalAlignment.Center,
            };
            comboBox.ItemsSource = new TextBlock[]
            {
                new TextBlock() { FontSize = 20, Text = " ≥ "},
                new TextBlock() { FontSize = 20, Text = " ≤ "},
            };
            stackPanel.Children.Add(comboBox);
            TextBox txtBox3 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
            };
            stackPanel.Children.Add(txtBox3);
            LimitEquationPanel.Children.Add(stackPanel);

        }

        private List<List<double>> equations;

        private void TakeFromTextBox()
        {
            equations.Clear();
            // Убедитесь, что в списке equations достаточно вложенных списков
            if (equations.Count < LimitEquationPanel.Children.Count)
            {
                // Инициализируем вложенные списки при необходимости
                for (int i = equations.Count; i < LimitEquationPanel.Children.Count; i++)
                {
                    equations.Add(new List<double>());
                }
            }

            int k = 0;
            foreach (StackPanel stack in LimitEquationPanel.Children)
            {
                foreach (var child in stack.Children)
                {
                    if (child is TextBox textBox)
                    {
                        // Теперь добавляем данные в правильный вложенный список
                        equations[k].Add(Convert.ToDouble(textBox.Text));
                    }
                }
                k++;
            }
        }


        private void TakeFromComboBox()
        {
            // Убедитесь, что в списке equations достаточно вложенных списков
            if (isMoreThenLineList.Count < LimitEquationPanel.Children.Count)
            {
                // Инициализируем вложенные списки при необходимости
                for (int i = isMoreThenLineList.Count; i < LimitEquationPanel.Children.Count; i++)
                {
                    isMoreThenLineList.Add(new bool());
                }
            }

            int k = 0;
            foreach (StackPanel stack in LimitEquationPanel.Children)
            {
                foreach (var child in stack.Children)
                {
                    if (child is ComboBox comboBox)
                    {
                        if (comboBox.Text == " ≥ ")
                        {
                            isMoreThenLineList[k] = true;
                        }
                        else if (comboBox.Text == " ≤ ")
                        {
                            isMoreThenLineList[k] = false;
                        }
                        k++;
                    }
                }
            }
        }

        private void CreateMainFunction(double valueA, double valueB, bool isMore)
        {
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
            };
            TextBlock txtBlock1 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "F ="
            };
            stackPanel.Children.Add(txtBlock1);
            TextBox txtBox1 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
                Text = valueA.ToString(),
            };
            stackPanel.Children.Add(txtBox1);
            TextBlock txtBlock2 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "X1+ "
            };
            stackPanel.Children.Add(txtBlock2);
            TextBox txtBox2 = new TextBox()
            {
                MaxHeight = 40,
                MaxWidth = 40,
                Width = 40,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                TextAlignment = TextAlignment.Center,
                Text = valueB.ToString(),

            };
            stackPanel.Children.Add(txtBox2);
            TextBlock txtBlock3 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "X2→"
            };
            stackPanel.Children.Add(txtBlock3);
            ComboBox comboBox = new ComboBox()
            {
                MaxWidth = 70,
                MaxHeight = 40,
                Height = 40,
                Width = 70,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                HorizontalContentAlignment = HorizontalAlignment.Center,
                VerticalContentAlignment = VerticalAlignment.Center,
            };
            comboBox.ItemsSource = new TextBlock[]
            {
                new TextBlock() { FontSize = 20, Text = " max "},
                new TextBlock() { FontSize = 20, Text = " min "},
            };
            if (isMore)
            {
                comboBox.SelectedIndex = 0;
            }
            else
            {
                comboBox.SelectedIndex = 1;
            }
            stackPanel.Children.Add(comboBox);
            MainEquationGrid.Children.Add(stackPanel);
        }

        private void TakeFromMainTextBox()
        {
            MainValues.Clear();
            foreach (StackPanel stack in MainEquationGrid.Children)
            {
                foreach (var child in stack.Children)
                {
                    if (child is TextBox textBox)
                    {
                        // Теперь добавляем данные в правильный вложенный список
                        MainValues.Add(Convert.ToDouble(textBox.Text));
                    }
                }
            }
        }

        private void TakeFromMainComboBox()
        {
            foreach (StackPanel stack in MainEquationGrid.Children)
            {
                foreach (var child in stack.Children)
                {
                    if (child is ComboBox comboBox)
                    {
                        if (comboBox.Text == " max ")
                        {
                            isFindMax = true;
                        }
                        else if (comboBox.Text == " min ")
                        {
                            isFindMax = false;
                        }
                    }
                }
            }
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            CountOfEq = 1;
            equations.Clear();
            isMoreThenLineList.Clear();   
            MainValues.Clear();
            MainEquationGrid.Children.Clear();
            LimitEquationPanel.Children.Clear();
            CreateMainFunction(2, 6, true); //Создание ОБОЛОЧКИ уравнения функции
            CreateEquatonInputInterface(1, 2, 10, false);
            CreateEquatonInputInterface(3, 1, 6, false);
            CreateEquatonInputInterface(1, 3, 7, true);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            CountOfEq = 1;
            equations.Clear();
            isMoreThenLineList.Clear();
            MainValues.Clear();
            MainEquationGrid.Children.Clear();
            LimitEquationPanel.Children.Clear();
            CreateMainFunction(8, 6, false); //Создание ОБОЛОЧКИ уравнения функции
            CreateEquatonInputInterface(4, 2, 8, false);
            CreateEquatonInputInterface(1, 3, 6, false);
            CreateEquatonInputInterface(4, 3, 3, true);
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            CountOfEq = 1;
            equations.Clear();
            isMoreThenLineList.Clear();
            MainValues.Clear();
            MainEquationGrid.Children.Clear();
            LimitEquationPanel.Children.Clear();    
            CreateMainFunction(2, 2, true); //Создание ОБОЛОЧКИ уравнения функции
            CreateEquatonInputInterface(1, 2, 8, true);
            CreateEquatonInputInterface(1, 3, 6, true);
            CreateEquatonInputInterface(2, 3, 3, true);
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            CountOfEq = 1;
            equations.Clear();
            isMoreThenLineList.Clear();
            MainValues.Clear();
            MainEquationGrid.Children.Clear();
            LimitEquationPanel.Children.Clear();
            CreateMainFunction(4, 3, false); //Создание ОБОЛОЧКИ уравнения функции
            CreateEquatonInputInterface(4, 2, 8, false);
            CreateEquatonInputInterface(1, 3, 6, false);
            CreateEquatonInputInterface(1, 1, 7, true);
        }
    }
}
