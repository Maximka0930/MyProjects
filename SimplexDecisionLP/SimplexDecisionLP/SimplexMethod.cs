using System;
using System.Collections.Generic;
using System.Data.Common;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using static SimplexDecisionLP.DisplayData;


namespace SimplexDecisionLP
{
    public class SimplexMethod
    {
        private int _count_of_variables;
        private int _count_of_restrations;


        private List<List<double>> _main_list;
        private int _count_of_bases;
        private List<int> _list_of_bases;

        private StackPanel _stackPanel;
        DisplayData display = new DisplayData();

        public bool isFindDecision;

        public SimplexMethod(int count_of_variables,int count_of_restrations, List<List<double>> main_list, StackPanel stackPanel) 
        {
            _main_list = new List<List<double>>();
            _main_list = main_list;

            _count_of_restrations = count_of_restrations;
            _count_of_variables = count_of_variables;

            _stackPanel = stackPanel;
            display = new DisplayData();

            _list_of_bases = new List<int>();

            list_of_answers = new List<double>();
        }


        public void Decision()
        {

            CreateFirstListOfBases();
            display.OutPutInTable(_stackPanel, _main_list, _list_of_bases); // Вывод изначальной таблицы 
            isFindDecision = true;

            if (!CheckOptimaly())
            {
                while (!CheckOptimaly())
                {
                    int indexResolveColumn = FindTheResolvingColumn(); //Нахождение разрешающего столбца
                    (int row, int column) = FindTheResolvingRow(indexResolveColumn); //Нахождение разрешающей ячейки

                    if (row != -1 && column !=-1)
                    {
                        BuildABasis(row, column); // Построение базиса
                    }
                    else
                    {
                        function_result = "Функция не ограничена. Оптимальное решение отсутствует";
                        //MessageBox.Show("Функция не ограничена. Оптимальное решение отсутствует");
                        isFindDecision = false;
                        break;
                    }

                    SettingTheAccuracy(); //Округление рез-ов до сотых
                    display.OutPutInTable(_stackPanel, _main_list, _list_of_bases); // Вывод изначальной таблицы 

                }

            }
            else if(!CheckPositiveResult())
            {

                while (!CheckPositiveResult())
                {
                    int indexNegativeRow = FindRowWithNegativeResult(); //Нахождение строки с отрицательным резултатом(F)

                    //Нахождение индекса столбца базиса
                    int indexMinNegativeColumn = -1;
                    double Min = double.MaxValue;
                    for (int i = 0; i < _main_list[indexNegativeRow].Count-1; i++)
                    {
                        if (_main_list[indexNegativeRow][i] < Min)
                        {
                            Min = _main_list[indexNegativeRow][i];
                            indexMinNegativeColumn = i;
                        }
                    }

                    //MessageBox.Show("row = "+indexNegativeRow + " column = "+indexMinNegativeColumn);


                    if (indexNegativeRow != -1 && indexMinNegativeColumn != -1)
                    {
                        BuildABasis(indexNegativeRow, indexMinNegativeColumn); // Построение базиса
                    }
                    else
                    {
                        function_result = "Решения задачи не существует";
                        //MessageBox.Show("Решения задачи не существует");
                        isFindDecision = false;
                        break;
                    }


                    SettingTheAccuracy(); //Округление рез-ов до сотых
                    display.OutPutInTable(_stackPanel, _main_list, _list_of_bases); // Вывод изначальной таблицы 
                    
                }

                _main_list[_main_list.Count - 1][_main_list[_main_list.Count - 1].Count - 1] *= -1;

            }

            if (isFindDecision)
            {
                CreateListOfAnswers();//Запись результатов для вывода на форму
                function_result = _main_list[_main_list.Count-1] [_main_list[_main_list.Count-1].Count-1].ToString();
            }



        }



        //Проверка оптимальности плана/Проверка на положительности последней строки
        private bool CheckOptimaly() 
        {
            for (int i = 0; i < _main_list[_main_list.Count - 1].Count; i++)
            {
                if (_main_list[_main_list.Count - 1][i] < 0 )
                {
                    return false;
                }
            }
            return true;
        }
        private bool CheckPositiveResult()
        {
            for (int i = 0; i < _main_list.Count-1; i++)
            {
                if (_main_list[i][_main_list[i].Count - 1] < 0)
                {
                    return false;
                }
            }
            return true;
        }
        //Поиск индекса разрешающего столбца
        private int FindTheResolvingColumn()
        {
            double Min = double.MaxValue;
            int index = -1;

            for (int i = 0; i < _main_list[_main_list.Count - 1].Count; i++)
            {
                if (_main_list[_main_list.Count - 1][i] < Min)
                {
                    Min = _main_list[_main_list.Count - 1][i];
                    index = i;
                }
            }

            return index;

        }
        //Поиск индекса строки с отрицательным F
        private int FindRowWithNegativeResult()
        {
            double Min = double.MaxValue;
            int row_index = -1;
            for (int i = 0; i < _main_list.Count-1; i++)
            {
                if (_main_list[i][_main_list[i].Count-1] < 0 && _main_list[i][_main_list[i].Count - 1] < Min)
                {
                    Min = _main_list[i][_main_list[i].Count - 1];
                    row_index = i;
                    //break;
                }
            }
            return row_index;
        }
        //Поиск индекса разрешающией строки
        private (int,int) FindTheResolvingRow(int indexResolveColumn)
        {
            double MinResult = int.MaxValue;
            int column = -1,row = -1;
            for (int i = 0; i < _main_list.Count-1; i++)
            {
                for (int j = 0; j < _main_list[i].Count; j++)
                {
                    if (j == indexResolveColumn)
                    {
                        if (_main_list[i][j] != 0 )
                        {
                            double res = _main_list[i][_main_list[i].Count - 1] / _main_list[i][j];
                            if (res < MinResult && res > 0)
                            {
                                MinResult = res;
                                row = i;
                                column = j;
                            }
                        }
                    }
                }
            }
            return (row,column);
        }
        //Создание начального списка базисов
        private void CreateFirstListOfBases()
        {

            for (int i = _count_of_variables; i <= _count_of_variables + _count_of_restrations; i++)
            {
                _list_of_bases.Add(i);
            }

        }

        //Округление полученных данных, перед передачей из в таблицу
        private void SettingTheAccuracy()
        {
            for (int i = 0; i < _main_list.Count; i++)
            {
                for (int j = 0; j < _main_list[i].Count; j++)
                {
                    _main_list[i][j] = Math.Round(_main_list[i][j], 2);
                }
            }
        }

        public List<double> list_of_answers;
        public string function_result;

        //Создание списка ответов
        private void CreateListOfAnswers()
        {
            for (int i = 0; i < (_count_of_restrations+_count_of_variables); i++)
            {
                list_of_answers.Add(0);
            }

            for (int i = 0; i < _list_of_bases.Count-1; i++)
            {
                list_of_answers[_list_of_bases[i]] =  _main_list[i][_main_list[i].Count-1];
            }


        }
        //Построение базиса
        private void BuildABasis(int row, int column)
        {
            double k = 1 / Convert.ToDouble(_main_list[row][column]);

            for (int i = 0; i < _main_list[0].Count; i++)
            {
                _main_list[row][i] *= k;
            }

            for (int i = 0; i < _main_list.Count; i++)
            {
                List<double> timely = new List<double>();
                for (int d = 0; d < _main_list[0].Count; d++)
                {
                    timely.Add(_main_list[row][d]);
                }

                if (i != row)
                {
                    double num = _main_list[i][column];
                    for (int j = 0; j < timely.Count; j++)
                    {
                        timely[j] *= num;
                    }

                    for (int l = 0; l < _main_list[i].Count; l++)
                    {
                        _main_list[i][l] -= timely[l];
                    }
                    timely.Clear();
                }
            }

            _list_of_bases[row] = column;
            
        }



    }
}
