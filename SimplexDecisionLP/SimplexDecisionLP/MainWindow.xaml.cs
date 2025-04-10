using System;
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

namespace SimplexDecisionLP
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            CountOfVariables.Text = "3";
            CountOfRestrictions.Text = "4";

        }

        private int _count_of_variables;
        private int _count_of_restrictions;

        private void CountOfVariables_TextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                _count_of_variables = Convert.ToInt32(CountOfVariables.Text);
                if (CountOfVariables.Text.Length != 0)
                {
                    if (_count_of_variables > 0)
                    {
                        CreateMainFunction(_count_of_variables);
                        CreateRestrictions(_count_of_variables, _count_of_restrictions);
                        CreateResult(_count_of_variables);
                    }
                }
            }
            catch (Exception)
            {
                CountOfVariables.Text = string.Empty;
            }
        }
        private void CountOfRestrictions_TextChanged(object sender, TextChangedEventArgs e)
        {
            try
            {
                _count_of_restrictions = Convert.ToInt32(CountOfRestrictions.Text);
                if (CountOfRestrictions.Text.Length != 0)
                {
                    if (_count_of_restrictions > 0)
                    {
                        CreateRestrictions(_count_of_variables, _count_of_restrictions);
                    }
                }
            }
            catch (Exception)
            {
                CountOfRestrictions.Text = string.Empty;
            }
        }

        //Создание формы для ввода целевой функции ЗЛП
        private void CreateMainFunction(int countOfVariables)
        {
            TargetFunction.Children.Clear();
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                Margin = new Thickness(8, 0, 0, 0),
            };
            TextBlock txtBlock1 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "F ="
            };
            stackPanel.Children.Add(txtBlock1);

            for (int i = 0; i < countOfVariables; i++)
            {
                TextBox txt = new TextBox()
                {
                    Height = 32,
                    Width = 32,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    TextAlignment = TextAlignment.Center,
                    HorizontalAlignment = HorizontalAlignment.Center,

                };
                stackPanel.Children.Add(txt);
                if (i + 1 == countOfVariables)
                {
                    TextBlock txtBlock2 = new TextBlock()
                    {
                        VerticalAlignment = VerticalAlignment.Center,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        Text = "X" + (i + 1),
                    };
                    stackPanel.Children.Add(txtBlock2);
                }
                else
                {
                    TextBlock txtBlock2 = new TextBlock()
                    {
                        VerticalAlignment = VerticalAlignment.Center,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        Text = "X"+(i+1)+"+ "
                    };
                    stackPanel.Children.Add(txtBlock2);

                }

                };

            TextBlock txtBlock3 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 24,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "→"
            };
            stackPanel.Children.Add(txtBlock3);

            ComboBox comboBox = new ComboBox()
            {
                Height = 32,
                Width = 70,
                FontSize = 24,
                Margin = new Thickness(0, 0, 5, 0),
                HorizontalContentAlignment = HorizontalAlignment.Center,
                VerticalContentAlignment = VerticalAlignment.Center,
            };
            comboBox.ItemsSource = new TextBlock[]
            {
                new TextBlock() { FontSize = 18, Text = " max "},
                new TextBlock() { FontSize = 18, Text = " min "},
            };
            stackPanel.Children.Add(comboBox);
            TargetFunction.Children.Add(stackPanel);
        }//Создание целевой функции с заданным количеством перменных
        private void CreateMainFunction(int countOfVariables,int[] targetFunction)
        {
            TargetFunction.Children.Clear();
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                Margin = new Thickness(8, 0, 0, 0),
            };
            TextBlock txtBlock1 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 28,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "F ="
            };
            stackPanel.Children.Add(txtBlock1);

            for (int i = 0; i < countOfVariables; i++)
            {
                TextBox txt = new TextBox()
                {
                    Height = 32,
                    Width = 32,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    TextAlignment = TextAlignment.Center,
                    HorizontalAlignment = HorizontalAlignment.Center,
                    Text = targetFunction[i].ToString(),

                };
                stackPanel.Children.Add(txt);
                if (i + 1 == countOfVariables)
                {
                    TextBlock txtBlock2 = new TextBlock()
                    {
                        VerticalAlignment = VerticalAlignment.Center,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        Text = "X" + (i + 1),
                    };
                    stackPanel.Children.Add(txtBlock2);
                }
                else
                {
                    TextBlock txtBlock2 = new TextBlock()
                    {
                        VerticalAlignment = VerticalAlignment.Center,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        Text = "X" + (i + 1) + "+ "
                    };
                    stackPanel.Children.Add(txtBlock2);

                }

            };

            TextBlock txtBlock3 = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 24,
                Margin = new Thickness(0, 0, 5, 0),
                Text = "→"
            };
            stackPanel.Children.Add(txtBlock3);

            ComboBox comboBox = new ComboBox()
            {
                Height = 32,
                Width = 70,
                FontSize = 24,
                Margin = new Thickness(0, 0, 5, 0),
                HorizontalContentAlignment = HorizontalAlignment.Center,
                VerticalContentAlignment = VerticalAlignment.Center,
            };
            comboBox.ItemsSource = new TextBlock[]
            {
                new TextBlock() { FontSize = 18, Text = " max "},
                new TextBlock() { FontSize = 18, Text = " min "},
            };
            if (targetFunction[targetFunction.Length-1] == 1)
            {
                comboBox.SelectedIndex = 0;
            }
            else
            {
                comboBox.SelectedIndex = 1;
            }
            stackPanel.Children.Add(comboBox);
            TargetFunction.Children.Add(stackPanel);
        }//Создание целевой функции с зараннее определёнными перменными 

        //Создание формы для ввода ограничений ЗЛП
        private void CreateRestrictions(int countOfVariables, int countofRestrictions)
        {
            MainField.Children.Clear();
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Vertical,
                HorizontalAlignment = HorizontalAlignment.Center,
            };

            TextBlock textBlock = new TextBlock()
            {
                Text = "Ограничения",
                FontSize = 24,
                FontWeight = FontWeights.DemiBold,
                HorizontalAlignment = HorizontalAlignment.Center,

            };
            stackPanel.Children.Add(textBlock);

            for (int i = 0; i < countofRestrictions; i++)
            {
                StackPanel stack = new StackPanel()
                {
                    Orientation = Orientation.Horizontal,
                    Margin = new Thickness(0,8,0,0),
                };

                for (int j = 0; j < countOfVariables; j++)
                {
                    TextBox txtBox1 = new TextBox()
                    {
                        Height = 32,
                        Width = 32,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        TextAlignment = TextAlignment.Center,
                        HorizontalAlignment = HorizontalAlignment.Center,

                    };
                    stack.Children.Add(txtBox1);

                    if (j+1 == countOfVariables)
                    {
                        TextBlock txtBlock2 = new TextBlock()
                        {
                            VerticalAlignment = VerticalAlignment.Center,
                            FontSize = 24,
                            Margin = new Thickness(0, 0, 5, 0),
                            Text = "X" + (j + 1),
                        };
                        stack.Children.Add(txtBlock2);
                    }
                    else
                    {
                        TextBlock txtBlock2 = new TextBlock()
                        {
                            VerticalAlignment = VerticalAlignment.Center,
                            FontSize = 24,
                            Margin = new Thickness(0, 0, 5, 0),
                            Text = "X"+(j+1)+" + "
                        };
                        stack.Children.Add(txtBlock2);

                    }

                }

                ComboBox comboBox = new ComboBox()
                {
                    Height = 32,
                    Width = 48,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    HorizontalContentAlignment = HorizontalAlignment.Center,
                    VerticalContentAlignment = VerticalAlignment.Center,
                };
                comboBox.ItemsSource = new TextBlock[]
                {
                    new TextBlock() { FontSize = 18, Text = " ≥ "},
                    new TextBlock() { FontSize = 18, Text = " ≤ "},
                };
                stack.Children.Add(comboBox);
                TextBox txtBox3 = new TextBox()
                {
                    Height = 32,
                    Width = 32,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    TextAlignment = TextAlignment.Center,
                };
                stack.Children.Add(txtBox3);


                stackPanel.Children.Add(stack);
            }
            MainField.Children.Add(stackPanel);
        }
        private void CreateRestrictions(int countOfVariables, int countofRestrictions, int[][] restrictions)
        {
            MainField.Children.Clear();
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Vertical,
                HorizontalAlignment = HorizontalAlignment.Center,
            };
            TextBlock textBlock = new TextBlock()
            {
                Text = "Ограничения",
                FontSize = 24,
                FontWeight = FontWeights.DemiBold,
                HorizontalAlignment = HorizontalAlignment.Center,

            };
            stackPanel.Children.Add(textBlock);


            for (int i = 0; i < countofRestrictions; i++)
            {
                StackPanel stack = new StackPanel()
                {
                    Orientation = Orientation.Horizontal,
                    Margin = new Thickness(0, 8, 0, 0),
                };

                for (int j = 0; j < countOfVariables; j++)
                {
                    TextBox txtBox1 = new TextBox()
                    {
                        Height = 32,
                        Width = 32,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        TextAlignment = TextAlignment.Center,
                        HorizontalAlignment = HorizontalAlignment.Center,
                        Text = restrictions[i][j].ToString(),
                    };
                    stack.Children.Add(txtBox1);

                    if (j + 1 == countOfVariables)
                    {
                        TextBlock txtBlock2 = new TextBlock()
                        {
                            VerticalAlignment = VerticalAlignment.Center,
                            FontSize = 24,
                            Margin = new Thickness(0, 0, 5, 0),
                            Text = "X" + (j + 1),
                        };
                        stack.Children.Add(txtBlock2);
                    }
                    else
                    {
                        TextBlock txtBlock2 = new TextBlock()
                        {
                            VerticalAlignment = VerticalAlignment.Center,
                            FontSize = 24,
                            Margin = new Thickness(0, 0, 5, 0),
                            Text = "X" + (j + 1) + " + "
                        };
                        stack.Children.Add(txtBlock2);

                    }

                }

                ComboBox comboBox = new ComboBox()
                {
                    Height = 32,
                    Width = 48,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    HorizontalContentAlignment = HorizontalAlignment.Center,
                    VerticalContentAlignment = VerticalAlignment.Center,
                };
                comboBox.ItemsSource = new TextBlock[]
                {
                    new TextBlock() { FontSize = 18, Text = " ≥ "},
                    new TextBlock() { FontSize = 18, Text = " ≤ "},
                };
                stack.Children.Add(comboBox);
                if (restrictions[i][restrictions[i].Length - 1] == 1)
                {
                    comboBox.SelectedIndex = 0;
                }
                else
                {
                    comboBox.SelectedIndex = 1;
                }
                TextBox txtBox3 = new TextBox()
                {
                    Height = 32,
                    Width = 48,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    TextAlignment = TextAlignment.Center,
                    Text = restrictions[i][2].ToString(),
                };
                stack.Children.Add(txtBox3);


                stackPanel.Children.Add(stack);
            }
            MainField.Children.Add(stackPanel);
        }

        private void CreateRestrictions(int countOfVariables, int countofRestrictions, List<List<double>> restrictions)
        {
            //MainField.Children.Clear();
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Vertical,
                HorizontalAlignment = HorizontalAlignment.Center,
                Margin = new Thickness(0,16,0,0),
            };
            TextBlock textBlock = new TextBlock()
            {
                Text = "Каноничный вид",
                FontSize = 24,
                FontWeight = FontWeights.DemiBold,
                HorizontalAlignment = HorizontalAlignment.Center,

            };
            stackPanel.Children.Add(textBlock);


            for (int i = 0; i < countofRestrictions; i++)
            {
                StackPanel stack = new StackPanel()
                {
                    Orientation = Orientation.Horizontal,
                    Margin = new Thickness(0, 8, 0, 0),
                };

                for (int j = 0; j < countOfVariables; j++)
                {
                    TextBox txtBox1 = new TextBox()
                    {
                        Height = 32,
                        Width = 32,
                        FontSize = 24,
                        Margin = new Thickness(0, 0, 5, 0),
                        TextAlignment = TextAlignment.Center,
                        HorizontalAlignment = HorizontalAlignment.Center,
                        Text = restrictions[i][j].ToString(),
                        //IsEnabled = false,
                    };
                    stack.Children.Add(txtBox1);

                    if (j + 1 == countOfVariables)
                    {
                        TextBlock txtBlock2 = new TextBlock()
                        {
                            VerticalAlignment = VerticalAlignment.Center,
                            FontSize = 24,
                            Margin = new Thickness(0, 0, 5, 0),
                            Text = "X" + (j + 1),
                        };
                        stack.Children.Add(txtBlock2);
                    }
                    else
                    {
                        TextBlock txtBlock2 = new TextBlock()
                        {
                            VerticalAlignment = VerticalAlignment.Center,
                            FontSize = 24,
                            Margin = new Thickness(0, 0, 5, 0),
                            Text = "X" + (j + 1) + " + "
                        };
                        stack.Children.Add(txtBlock2);

                    }

                }

                ComboBox comboBox = new ComboBox()
                {
                    Height = 32,
                    Width = 48,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    HorizontalContentAlignment = HorizontalAlignment.Center,
                    VerticalContentAlignment = VerticalAlignment.Center,
                    IsEnabled = false,
                };
                comboBox.ItemsSource = new TextBlock[]
                {
                    new TextBlock() { FontSize = 18, Text = " ≥ "},
                    new TextBlock() { FontSize = 18, Text = " ≤ "},
                };
                stack.Children.Add(comboBox);
                if (restrictions[i][restrictions[i].Count - 1] == 1)
                {
                    comboBox.SelectedIndex = 0;
                }
                else
                {
                    comboBox.SelectedIndex = 1;
                }
                TextBox txtBox3 = new TextBox()
                {
                    Height = 32,
                    Width = 48,
                    FontSize = 24,
                    Margin = new Thickness(0, 0, 5, 0),
                    TextAlignment = TextAlignment.Center,
                    Text = restrictions[i][restrictions[0].Count-1].ToString(),
                };
                stack.Children.Add(txtBox3);


                stackPanel.Children.Add(stack);
            }
            MainField.Children.Add(stackPanel);
        }


        //Создание формы вывода результатов
        private void CreateResult(int countOfVariables)
        {
            Result.Children.Clear();
            StackPanel stackPanel = new StackPanel()
            {
                Orientation = Orientation.Horizontal,
                HorizontalAlignment = HorizontalAlignment.Center,
                Margin = new Thickness(8),
            };

            for (int i = 0; i < countOfVariables; i++)
            {
                TextBlock textBlock = new TextBlock()
                {
                    VerticalAlignment = VerticalAlignment.Center,
                    FontSize = 24,
                    Text = "X" + (i + 1) + " = ",
                    FontWeight = FontWeights.DemiBold,
                    Margin = new Thickness(16,0,0,0),
                };
                stackPanel.Children.Add(textBlock);
            }
            TextBlock text = new TextBlock()
            {
                VerticalAlignment = VerticalAlignment.Center,
                FontSize = 24,
                Text = "F = ",
                FontWeight = FontWeights.DemiBold,
                Margin = new Thickness(16, 0, 0, 0),
            };
            stackPanel.Children.Add(text);
            Result.Children.Add(stackPanel);
        }

        private List<List<double>> list_of_restractions = new List<List<double>>();
        private List<double> list_of_targetFunction = new List<double>();

        //Чтение данных из ограничений
        private void ReadDataFromRestrictions()
        {

            foreach (StackPanel stackPanel in MainField.Children)
            {
                foreach (var child in stackPanel.Children)
                {
                    List<double> list = new List<double>();
                    if (child is StackPanel stack)
                    {
                        foreach (var item in stack.Children)
                        {
                            if (item is TextBox textbox)
                            {
                                list.Add(Convert.ToDouble(textbox.Text));
                            }
                            if (item is ComboBox comboBox)
                            {
                                if (comboBox.SelectedIndex == 0)
                                {
                                    list.Add(1);

                                }
                                else if (comboBox.SelectedIndex == 1)
                                {
                                    list.Add(-1);
                                }
                                else
                                {
                                    list.Add(0);
                                }

                            }

                        }
                        list_of_restractions.Add(list);
                    }
/*                    for (int k = 0; k < list.Count; k++)
                    {
                        MessageBox.Show(list[k].ToString());
                    }*/
                }                
            }

        }

        private void ReadDatafromMainFunction()
        {
            foreach (StackPanel stackPanel in TargetFunction.Children)
            {
                foreach (var child in stackPanel.Children)
                {
                    if (child is TextBox textbox)
                    {
                        list_of_targetFunction.Add(Convert.ToInt32(textbox.Text));
                    }
                    if (child is ComboBox comboBox)
                    {
                        if (comboBox.SelectedIndex == 0)
                        {
                            list_of_targetFunction.Add(1);
                        }
                        else if (comboBox.SelectedIndex == 1)
                        {
                            list_of_targetFunction.Add(-1);
                        }
                    }
                }
            }
        }

        private List<List<double>> CreateListForSolveLPB()
        {
            //Далее реализовать метод, преобразующий массив в канонический вид
            //и тд.

            //Приведение целевой функции к каноническому виду
            if (list_of_targetFunction[list_of_targetFunction.Count - 1] == 1)
            {
                for (int i = 0; i < list_of_targetFunction.Count; i++)
                {
                    list_of_targetFunction[i] *= -1;
                }
                list_of_targetFunction.Remove(list_of_targetFunction[list_of_targetFunction.Count - 1]);
                list_of_targetFunction.Add(0);
            }
            else if (list_of_targetFunction[list_of_targetFunction.Count - 1] == -1)
            {
                list_of_targetFunction.Remove(list_of_targetFunction[list_of_targetFunction.Count - 1]);
                list_of_targetFunction.Add(0);
            }

            //Приведение ограничений к каноническому виду
            for (int i = 0; i < list_of_restractions.Count; i++)
            {
                if (list_of_restractions[i][list_of_restractions[i].Count - 2] == 1)
                {
                    for (int j = 0; j < list_of_restractions[i].Count; j++)
                    {
                        list_of_restractions[i][j] *= -1;
                    }
                    //list_of_restractions[i].Remove(list_of_restractions[i][list_of_restractions[i].Count - 2]);
                }
                else if (list_of_restractions[i][list_of_restractions[i].Count - 2] == -1)
                {
                    //list_of_restractions[i].Remove(list_of_restractions[i][list_of_restractions[i].Count - 2]);
                }
                //НА ПОДУМАТЬ
                //СИТУАЦИЯ, КОГДА У НАС ЗНАК = НЕ ОБРАБАТЫВАЕТСЯ. МОГУТ БЫТЬ ОШИБКИ С РАЗМЕРНОСТЬЮ МАССИВОВ ИЗ-ЗА этого
            }

            //Создание вспомогающего массива ограничений
            List<List<double>> helplist = new List<List<double>>();

            for (int i = 0; i < list_of_restractions.Count; i++)
            {
                helplist.Add(list_of_restractions[i]);
            }


            int CountOfVariables = 0;
            //Добавление дополнительных переменных к ограничениям
            for (int j = 0; j < helplist.Count; j++)
            {
                for (int i = 0; i < helplist.Count; i++)
                {
                    if (helplist[i][helplist[i].Count - 2] == -1)
                    {
                        if (j == i)
                        {
                            list_of_restractions[i].Insert(list_of_restractions[i].Count - 2, 1);
                            CountOfVariables++;
                        }
                        else
                        {
                            list_of_restractions[i].Insert(list_of_restractions[i].Count - 2, 0);
                        }
                    }
                }
            }

            //ПРОБЛЕМА ПРИ ВЫЧИТАНИИ ТУТ -2, НАДО - 1
            //НАВЕРНОЕ СТОИТ ПРИВЯЗАТЬ К КАКОЙ-НИБУДТ ПЕРЕМЕННОЙ

            //Удаление лишних единиц из списков ограчничений
            for (int i = 0; i < list_of_restractions.Count; i++)
            {
                list_of_restractions[i].RemoveAt(list_of_restractions[i].Count - 2);
            }


            //Добавление дополнительных переменных к целевой функции
            for (int i = 0; i < CountOfVariables; i++)
            {
                list_of_targetFunction.Insert(list_of_targetFunction.Count - 1, 0);
            }

            List<List<double>> list_main = new List<List<double>>();
            //Создание общего массива уравнений. Канонический вид задачи
            for (int i = 0; i < list_of_restractions.Count; i++)
            {
                list_main.Add(list_of_restractions[i]);
            }
            list_main.Add(list_of_targetFunction);



            return list_main;
        }



        private int[] FirstTF = { 2, 1, 1 };
        private int[][] FirstRestrictions = { new[] { 4,6,20,1 }, new[] { 2,-5,-27,1}, new[] { 7,5,63,0}, new[] { 3,-2,23,0} };

        private int[] SecondTF = { 2,1, 0 };
        private int[][] SecondRestrictions = { new[] { 4, 6, 20,1 }, new[] { 2, -5, -27,1 }, new[] { 7, 5, 63,0 }, new[] { 3, -2, 23,0 } };

        private int[] ThirdTF = { 2, 3, 1};
        private int[][] ThirdRestrictions = { new[] { 1, 2, 8, 0  }, new[] { 1, 1, 6, 0  }, new[] { 2, 3, 3, 1  } };

        private int[] FourthTF = { 2, 4, 0 };
        private int[][] FourthRestrictions = { new[] { 1, 1, 8, 0 }, new[] { 1, 3, 6, 0 }, new[] { 1, 2, 3, 1 } };

        private int[] FifthTF = { 2, 1,1 };
        private int[][] FifthRestrictions = { new[] { 1, 2, 8, 1 }, new[] { 1, 3, 6, 1 }, new[] { 2, 3, 3, 1 } };

        private int[] SixthTF = { 2, 1, 0 };
        private int[][] SixthRestrictions = { new[] { 1, 2, 4, 0 }, new[] { 2, 1, 6, 0 }, new[] { 1, 1, 8, 1 } };

        private void FirstTask_Click(object sender, RoutedEventArgs e)
        {
            ClearResultField();
            CreateResult(_count_of_variables);
            CountOfVariables.Text = "2";
            CountOfRestrictions.Text = "4";
            CreateMainFunction(2, FirstTF);
            CreateRestrictions(2, 4, FirstRestrictions);
        }
        private void SecondTask_Click(object sender, RoutedEventArgs e)
        {
            ClearResultField();
            CreateResult(_count_of_variables);
            CountOfVariables.Text = "2";
            CountOfRestrictions.Text = "4";
            CreateMainFunction(2, SecondTF);
            CreateRestrictions(2, 4, SecondRestrictions);
        }
        private void ThirdTask_Click(object sender, RoutedEventArgs e)
        {
            ClearResultField();
            CreateResult(_count_of_variables);
            CountOfVariables.Text = "2";
            CountOfRestrictions.Text = "3";
            CreateMainFunction(2, ThirdTF);
            CreateRestrictions(2, 3, ThirdRestrictions);
        }
        private void FourthTask_Click(object sender, RoutedEventArgs e)
        {
            ClearResultField();
            CreateResult(_count_of_variables);
            CountOfVariables.Text = "2";
            CountOfRestrictions.Text = "3";
            CreateMainFunction(2, FourthTF);
            CreateRestrictions(2, 3, FourthRestrictions);
        }
        private void FifthTask_Click(object sender, RoutedEventArgs e)
        {
            ClearResultField();
            CreateResult(_count_of_variables);
            CountOfVariables.Text = "2";
            CountOfRestrictions.Text = "3";
            CreateMainFunction(2, FifthTF);
            CreateRestrictions(2, 3, FifthRestrictions);
        }
        private void SixthTask_Click(object sender, RoutedEventArgs e)
        {
            ClearResultField();
            CreateResult(_count_of_variables);
            CountOfVariables.Text = "2";
            CountOfRestrictions.Text = "3";
            CreateMainFunction(2, SixthTF);
            CreateRestrictions(2, 3, SixthRestrictions);
        }

        private void btn_Decision_Click(object sender, RoutedEventArgs e)
        {
            list_of_targetFunction.Clear(); // Очищение массива перед новым использованием
            list_of_restractions.Clear(); // Очищение массива перед новым использованием
            ReadDatafromMainFunction(); //Значения целевой функции
            ReadDataFromRestrictions(); //Значения ограничений


            List<List<double>> list_main = CreateListForSolveLPB();

            CreateRestrictions(Convert.ToInt32(CountOfVariables.Text), Convert.ToInt32(CountOfRestrictions.Text), list_main);

            SimplexMethod simplex = new SimplexMethod(Convert.ToInt32(CountOfVariables.Text),Convert.ToInt32(CountOfRestrictions.Text), list_main, MainField);
            simplex.Decision();

            ResultOutPut(simplex);
        }

        private void ResultOutPut(SimplexMethod simplex)
        {

            if (!simplex.isFindDecision)
            {
                Result.Children.Clear();
                StackPanel stackPanel = new StackPanel()
                {
                    Orientation = Orientation.Horizontal,
                    HorizontalAlignment = HorizontalAlignment.Center,
                    Margin = new Thickness(8),
                };

                TextBlock textBlock = new TextBlock()
                {
                    VerticalAlignment = VerticalAlignment.Center,
                    FontSize = 24,
                    Text = simplex.function_result,
                    FontWeight = FontWeights.DemiBold,
                    Margin = new Thickness(0, 0, 0, 0),
                };
                stackPanel.Children.Add(textBlock);
                Result.Children.Add(stackPanel);

            }
            else
            {
                int k = 0;
                foreach (StackPanel stackPanel in Result.Children)
                {
                    for (int i = 0; i < stackPanel.Children.Count; i++)
                    {
                        TextBlock textBlock = stackPanel.Children[i] as TextBlock;

                        if (i == stackPanel.Children.Count - 1)
                        {
                            textBlock.Text = "F = " + simplex.function_result;
                        }
                        else
                        {
                            textBlock.Text = "X" + (k + 1) + " = ";
                            k++;
                        }
                    }

                }

                k = 0;
                foreach (StackPanel stackPanel in Result.Children)
                {
                    for (int i = 0; i < stackPanel.Children.Count; i++)
                    {
                        TextBlock textBlock = stackPanel.Children[i] as TextBlock;
                    
                        if (i == stackPanel.Children.Count - 1)
                        {
                            textBlock.Text = "F = " + simplex.function_result;

                        }
                        else
                        {
                            if (simplex.list_of_answers.Count > 0)
                            {
                                textBlock.Text = "X" + (k + 1) + " = " + simplex.list_of_answers[k].ToString();
                                k++;
                            }
                        }
                    }


                }
            }


        }

        private void ClearResultField()
        {
            int k = 0;
            foreach (StackPanel stackPanel in Result.Children)
            {
                for (int i = 0; i < stackPanel.Children.Count; i++)
                {
                    TextBlock textBlock = stackPanel.Children[i] as TextBlock;

                    if (i == stackPanel.Children.Count - 1)
                    {
                        textBlock.Text = "F = ";
                    }
                    else
                    {
                        textBlock.Text = "X" + (k + 1) + " = ";
                        k++;
                    }
                }

            }
        }

    }
}
