using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Media;
using static SimplexDecisionLP.SimplexMethod;

namespace SimplexDecisionLP
{
    public class DisplayData
    {

        public void OutPutInTable(StackPanel stack, List<List<double>> main_list,List<int> list_of_bases)
        {

            DataGrid dataGrid = new DataGrid()
            {
                HorizontalAlignment = System.Windows.HorizontalAlignment.Center,
                IsReadOnly = true,
                AutoGenerateColumns = false, // Чтобы управлять столбцами вручную
                Margin = new System.Windows.Thickness(0,32,0,0),
                Width = 800,
                ColumnWidth = 800 / (main_list[0].Count+1),
                RowHeight = 36,
                HeadersVisibility = DataGridHeadersVisibility.Column, // Скрыть заголовки строк
                //HeadersVisibility = DataGridHeadersVisibility.Row // Показывать только заголовки строк
                HorizontalScrollBarVisibility = ScrollBarVisibility.Disabled, // Отключение горизонтальной прокрутки
                VerticalScrollBarVisibility = ScrollBarVisibility.Auto // Вертикальная прокрутка остается включенной

            };

            // Настраиваем стиль ячеек
            dataGrid.CellStyle = new Style(typeof(DataGridCell))
            {
                Setters =
                {
                new Setter(DataGridCell.FontWeightProperty, FontWeights.Bold),       // Жирный шрифт
                new Setter(DataGridCell.FontSizeProperty, 16.0),                     // Размер шрифта 16
                new Setter(TextBlock.TextAlignmentProperty, TextAlignment.Center)

                }
            };
            // Настраиваем стиль заголовок столбцов
            dataGrid.ColumnHeaderStyle = new Style(typeof(DataGridColumnHeader))
            {
                Setters =
                {
                    new Setter(DataGridColumnHeader.FontSizeProperty, 16.0),               // Размер шрифта
                    new Setter(DataGridColumnHeader.FontWeightProperty, FontWeights.Bold), // Жирный текст
                    new Setter(DataGridColumnHeader.FontFamilyProperty, new System.Windows.Media.FontFamily("Segoe UI")), // Шрифт
                    new Setter(DataGridColumnHeader.HorizontalContentAlignmentProperty, HorizontalAlignment.Center), // Горизонтальное центрирование
                    new Setter(DataGridColumnHeader.VerticalContentAlignmentProperty, VerticalAlignment.Center)      // Вертикальное центрирование
                }
            };
            // Стиль для заголовков строк (DataGridRowHeader)
            dataGrid.RowHeaderStyle = new Style(typeof(DataGridRowHeader))
            {
                Setters =
        {
            new Setter(DataGridRowHeader.FontSizeProperty, 16.0),
            new Setter(DataGridRowHeader.FontWeightProperty, FontWeights.Bold),
            new Setter(DataGridRowHeader.FontFamilyProperty, new System.Windows.Media.FontFamily("Segoe UI")),
            new Setter(DataGridRowHeader.HorizontalContentAlignmentProperty, HorizontalAlignment.Center),
            new Setter(DataGridRowHeader.VerticalContentAlignmentProperty, VerticalAlignment.Center)
        }
            };

/*            // Добавляем столбец для индексов строк
            dataGrid.Columns.Add(new DataGridTextColumn
            {
                Header = "Row", // Заголовок для первого столбца (индекс строки)
                IsReadOnly = true,
                CanUserSort = false, // Отключение сортировки
            });*/

            // Создаем столбцы на основе количества элементов в первой строке
            for (int i = 0; i < main_list[0].Count+1; i++)
            {
                if (i == main_list[0].Count)
                {
                    dataGrid.Columns.Add(new DataGridTextColumn
                    {
                        Header = $"F", // Текст заголовка
                        Binding = new System.Windows.Data.Binding($"[{i}]"), // Привязка к элементу
                        IsReadOnly = true,
                        CanUserSort = false // Отключение сортировки

                    });
                }
                else if (i == 0)
                {
                    dataGrid.Columns.Add(new DataGridTextColumn
                    {
                        Header = $"Базис", // Текст заголовка
                        Binding = new System.Windows.Data.Binding($"[{i}]"), // Привязка к элементу
                        IsReadOnly = true,
                        CanUserSort = false // Отключение сортировки

                    });
                }
                else
                {
                    dataGrid.Columns.Add(new DataGridTextColumn
                    {
                        Header = $"X{i}", // Текст заголовка
                        Binding = new System.Windows.Data.Binding($"[{i}]"), // Привязка к элементу
                        IsReadOnly = true,
                        CanUserSort = false // Отключение сортировки
                    
                    });

                }
            }


            // Предположим, что у нас есть одномерный список индексов строк:
            //List<int> rowIndexes = new List<int> { 6, 7, 8, 9, 10 }; // Пример значений индексов строк

            // Добавляем строки с индексами
            for (int rowIndex = 0; rowIndex < main_list.Count; rowIndex++)
            {
                var row = main_list[rowIndex];
                var rowWithIndex = new List<object>();

                // Добавляем индекс строки из rowIndexes (если размер списка индексов соответствует количеству строк)
                if (rowIndex == list_of_bases.Count-1)
                {
                    rowWithIndex.Add("△");  // Добавляем индекс строки
                }
                else if (rowIndex < list_of_bases.Count)
                {
                    rowWithIndex.Add("X"+(list_of_bases[rowIndex]+1));  // Добавляем индекс строки
                }
                else
                {
                    rowWithIndex.Add("");  // Если индексов меньше, добавляем пустое значение (или другое по вашему выбору)
                }

                // Добавляем все данные из текущей строки
                rowWithIndex.AddRange(row.Cast<object>());

/*                // Создаем объект строки
                DataGridRow dataGridRow = new DataGridRow();
                dataGridRow.Item = rowWithIndex;

                // Меняем фон ячейки в определенной строке
                if (rowIndex == 0) // Условие для строки
                {
                    dataGridRow.Background = new SolidColorBrush(Colors.LightBlue); // Меняем фон строки
                }*/

                // Добавляем строку в DataGrid
                dataGrid.Items.Add(rowWithIndex);
            }


            stack.Children.Add(dataGrid);

        }

        private void SettingTheAccuracy(List<List<double>> _main_list)
        {
            for (int i = 0; i < _main_list.Count; i++)
            {
                for (int j = 0; j < _main_list[i].Count; j++)
                {
                    _main_list[i][j] = Math.Round(_main_list[i][j], 2);
                }
            }
        }


    }
}
