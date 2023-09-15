#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

//Задание 5
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    char choice1[20], choice2[20];

    struct student
    {
        char famil[20], name[20], facult[20];
        int nomzach;
    } stud[3];

    std::cout << "Поиск в структуре по двум параметрам" << std::endl << std::endl;

    std::cout << "Ввод данных" << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "----------------------------" << std::endl;
        std::cout << "Фамилия " << i + 1 << "-го студента: ";
        std::cin >> stud[i].famil;
        std::cout << "Имя " << i + 1 << "-го студента: ";
        std::cin >> stud[i].name;
        std::cout << "Факультет " << i + 1 << "-го студента: ";
        std::cin >> stud[i].facult;
        std::cout << "Номер зачетной книжки " << i + 1 << "-го студента: ";
        std::cin >> stud[i].nomzach;
    }

    std::cout << "----------------------------" << std::endl;
    std::cout << "Ввод параметров для поиска (фамилия, имя, факультет)" << "\n";
    std::cout << "Параметр 1: ";
    std::cin >> choice1;
    std::cout << "Параметр 2: ";
    std::cin >> choice2;
    std::cout << "----------------------------" << std::endl;

    std::cout << "Результаты поиска" << std::endl;;
    
    for (int i=0; i < 3; i++) 
    {
        if ((strcmp(choice1, stud[i].famil) == 0 and strcmp(choice2, stud[i].facult) == 0)
            or (strcmp(choice1, stud[i].facult) == 0 and strcmp(choice2, stud[i].famil) == 0)
            or (strcmp(choice1, stud[i].famil) == 0 and strcmp(choice2, stud[i].name) == 0)
            or (strcmp(choice1, stud[i].name) == 0 and strcmp(choice2, stud[i].famil) == 0)
            or (strcmp(choice1, stud[i].name) == 0 and strcmp(choice2, stud[i].facult) == 0)
            or (strcmp(choice1, stud[i].facult) == 0 and strcmp(choice2, stud[i].name) == 0))
        {
            std::cout << "----------------------------" << std::endl;
            std::cout << "Фамилия: " << stud[i].famil << std::endl;
            std::cout << "Имя: " << stud[i].name << std::endl;
            std::cout << "Факультет: " << stud[i].facult << std::endl;
            std::cout << "Номер зачетной книжки: " << stud[i].nomzach << std::endl;
        }
    }
}

/*
// Задание 4
int main()
{
    setlocale(LC_ALL, "Rus");

    int arr[3][5];

    srand(time(NULL));

    std::cout << "Матрица имеет вид:" << std::endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            arr[i][j] = rand() % 10;
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Суммы строк" << std::endl;

    for (int i = 0, sum = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            sum += arr[i][j];
        }
        std::cout << i + 1 << "-я: " << sum << std::endl;
        sum = 0;
    }

    std::cout << std::endl << "Суммы столбцов" << std::endl;

    for (int j = 0, sum = 0; j < 5; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            sum += arr[i][j];
        }
        std::cout << j + 1 << "-й: " << sum << std::endl;
        sum = 0;
    }

    return 0;
}
*/

/*
// Задание 3
int main()
{
    setlocale(LC_ALL, "Rus");

    int size = 0;

    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* arr = new int[size];

    std::cout << "Введите значения элементов массива:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << i + 1 << "-й = ";
        std::cin >> arr[i];
    }

    std::cout << "Вывод массиива:" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
*/

/*
// Задание 2
int main()
{
    int arr[15];

    srand(time(NULL));
    
    for (int i = 0; i < 15; i++)
    {
        arr[i] = rand() % 101;
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
*/


//// Задание 1
//int main()
//{
//  int arr[5] = { -1, 5, 3, -77, 9 }, min = arr[0], max = arr[0] ;
//
//  for (int i = 1; i < 5; i++)
//    {
//      if (arr[i] < min)
//    min = arr[i];
//      if (arr[i] > max)
//    max = arr[i];
//    }
//
//  std::cout << "max = " << max << "\n";
//  std::cout << "min = " << min << "\n";
//  std::cout << "MAX + MIN = " << max + min;
//
//  return 0;
//}
