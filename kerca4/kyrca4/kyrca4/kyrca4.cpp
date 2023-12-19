#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h>
#include <time.h>

void titul() {
	printf("\n");
	printf(" Министерство науки и высшего образования Российской Федерации\n");
	printf(" Пензенский государственный университет\n");
	printf(" Кафедра «Вычислительная кафедра»\n");

	printf("\n\n");
	printf("  КУРСОВОЙ ПРОЕКТ\n");
	printf("  по дисциплине:\n  ЛОГИКА И ОСНОВЫ АЛГОРИТМИЗАЦИИ В ИНЖЕНЕРНЫХ ЗАДАЧАХ\n");
	printf("  тема проекта:\n  РЕАЛИЗАЦИЯ АЛГОРИТМА ДЕЙКСТРЫ\n ");



	printf("\n\n\n");
	printf(" Выполнил:\n");
	printf(" студент группы 22ВВП1\n");
	printf(" Шатин Д.Д.\n");
	printf("\n\n");
	printf(" Принял:\n");
	printf(" Акифьев И.В.\n");
	printf("\n\n\n");
	printf(" Пенза 2023\n");

	time_t startTime = time(nullptr);
	while (difftime(time(nullptr), startTime) < 5) {}
}

int repeat_program() {
	int repeat;
	char choice;
	do {
		printf("\nХотите запустить программу заново? (y/n): ");
		scanf(" %c", &choice);
		getchar(); // Очистка буфера ввода

		if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
			printf("!!! Введите 'y' для повторного запуска или 'n' для завершения!\n\n");
		}
	} while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');

	repeat = (choice == 'y' || choice == 'Y') ? 1 : 0;
	system("cls");
	return repeat;
}

void input_distance(int** a, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++) {
			int s = -1;
			while (s <= 0 || s >= 20) {
				printf("Введите расстояние между вершинами %d и %d (1-19): ", i + 1, j + 1);
				scanf("%d", &s);
				getchar(); // Очищаем буфер ввода
				if (s <= 0 || s >= 20) {
					printf("!!! Введите корректное расстояние (1-19)!\n\n");
				}
			}
			a[i][j] = a[j][i] = s;
		}
	}
}

void count_vertex(int* count) {
	int flag = 0;
	char value[6];

	do {
		flag = 0;
		printf("Введите размерность графа ( 1 < размер < 11 ): ");
		scanf("%5s", value);
		getchar(); // Чтобы прочитать символ новой строки из буфера ввода

		for (int i = 0; value[i] != '\0'; i++) {
			if (!isdigit(value[i]) || isspace(value[i])) {
				flag = 1;
				break;
			}
		}

		if (!flag) {
			if (atoi(value) == 1) {
				flag = 1;
			}
			if (atoi(value) > 10) {
				flag = 1;
			}
		}

		if (flag == 1) {
			printf("!!! Введите корректное число вершин!\n\n");
			printf("> Нажмите любую клавишу, чтобы продолжить...");
			getchar();
			system("cls");
		}
		else {
			*count = atoi(value);
			break;
		}
	} while (flag);
}

void createRandomDirectedGraph(int** a, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		a[i][i] = 0;
		for (int j = 0; j < SIZE; j++) {
			if (i != j) {
				int probability = rand() % 100; // Генерируем вероятность от 0 до 99
				if (probability < 50) { // Например, задаем вероятность 50%
					a[i][j] = rand() % 20; // Устанавливаем случайное значение от 0 до 19
				}
				else {
					a[i][j] = 0; // Устанавливаем 0 в противном случае
				}
			}
		}
	}
}

void createRandomUndirectedGraph(int** a, int SIZE) {
	for (int i = 0; i < SIZE; i++) {
		a[i][i] = 0;
		for (int j = i + 1; j < SIZE; j++) {
			int weight = rand() % 20;
			a[i][j] = a[j][i] = weight;
		}
	}
}

void readMatrixFromFile(int** a, int SIZE, const char* filename) {
	FILE* file;
	int success = 0;

	do {
		file = fopen(filename, "r");
		if (file == NULL) {
			printf("Ошибка при открытии файла. Пожалуйста, введите верное имя файла: ");
			scanf("%s", filename);
		}
		else {
			success = 1;
		}
	} while (!success);

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			fscanf(file, "%d", &a[i][j]);
		}
	}

	fclose(file);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	titul();
	FILE* fp;
	int s = -1, minchislo, min, menu = 0;
	int** a; // матрица связей
	int* d; // минимальное расстояние
	int* v; // посещенные вершины
	int begin_index = 0;
	char namefile[20];
	char keyboard;
	int choice = 0;
	int num = 1;
	int isDirected = -1;
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));

	int SIZE = 0;
	count_vertex(&SIZE);

	fp = fopen("Результат.txt", "w");
	if (fp == NULL) {
		printf("Ошибка при открытии файла.\n");
		return 1; // Или обработайте ошибку соответствующим образом
	}

	int readFromFile = -1;
	while (readFromFile == -1) {
		printf("\nВыберите источник данных для графа:\n1. Ввод с клавиатуры\n2. Чтение из файла\n");
		char keyboard = _getch();
		if (keyboard == 49 || keyboard == 50) {
			readFromFile = (keyboard == 49) ? 0 : 1;
		}
	}



	// меню
	system("clear || cls");
	a = (int**)malloc(SIZE * sizeof(int*));
	for (int i = 0; i < SIZE; i++) a[i] = (int*)malloc(SIZE * sizeof(int));

	if (readFromFile) {
		char filename[50];
		printf("Введите имя файла для чтения данных: ");
		scanf("%s", filename);
		readMatrixFromFile(a, SIZE, filename);
	}
	else {
		while (isDirected == -1) {
			printf("\nВыберите тип графа:\n1. Ориентированный\n2. Неориентированный\n");
			char keyboard = _getch();
			if (keyboard == 49 || keyboard == 50) {
				isDirected = (keyboard == 49) ? 1 : 0;
			}
		}
		while (menu == 0) {
			printf("\nНажмите клавишу для выбора действия\n1.Случайное заполнение\n2.Заполнение вручную\n3.Выход\n");
			keyboard = _getch();
			if (keyboard == 49) {
				if (isDirected) {
					createRandomDirectedGraph(a, SIZE);
				}
				else {
					createRandomUndirectedGraph(a, SIZE);
				}
				menu = 1;
			}
			if (keyboard == 50) {
				input_distance(a, SIZE); // Вызов функции для ручного ввода расстояний
				menu = 1;
			}
			if (keyboard == 51) exit(0);
		}
	}

	// Вывод матрицы связей
	printf("Ваша матрица:\n");
	fprintf(fp, "Ваша матрица:\n");
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++) {
			printf("%5d ", a[i][j]);
			fprintf(fp, "%5d ", a[i][j]);
		}
		printf("\n");
		fprintf(fp, "\n");
	}
	//Инициализация вершин и расстояний
	v = (int*)malloc(SIZE * sizeof(int));
	d = (int*)malloc(SIZE * sizeof(int));
	for (int i = 0; i < SIZE; i++)
	{
		d[i] = 100000;
		v[i] = 1;
	}
	d[begin_index] = 0;
	// Шаг алгоритма
	do {
		minchislo = 100000;
		min = 100000;
		for (int i = 0; i < SIZE; i++)
		{ // Если вершину ещё не обошли и вес меньше min
			if ((v[i] == 1) && (d[i] < min))
			{ // Переприсваиваем значения
				min = d[i];
				minchislo = i;
			}
		}
		// Добавляем найденный минимальный вес
		// к текущему весу вершины
		// и сравниваем с текущим минимальным весом вершины
		if (minchislo != 100000)
		{
			for (int i = 0; i < SIZE; i++)
			{
				if (a[minchislo][i] > 0)
				{
					s = min + a[minchislo][i];
					if (s < d[i])
					{
						d[i] = s;
					}
				}
			}
			v[minchislo] = 0;
		}
	} while (minchislo < 100000);
	// Вывод кратчайших расстояний до вершин
	printf("\nКратчайшие расстояния до вершин: \n");
	fprintf(fp, "\nКратчайшие расстояния до вершин: \n");
	for (int i = 0; i < SIZE; i++) {
		printf("%5d ", d[i]);
		fprintf(fp, "%5d ", d[i]);
	}
	// Восстановление пути
	int* ver; // массив посещенных вершин
	int end = SIZE - 1; // индекс конечной вершины
	ver = (int*)malloc(SIZE * sizeof(int));
	ver[0] = end + 1; // начальный элемент - конечная вершина
	int k = 1; // индекс предыдущей вершины
	int weight = d[end]; // вес конечной вершины
	while (end != begin_index) // пока не дошли до начальной вершины
	{
		for (int i = 0; i < SIZE; i++) // просматриваем все вершины
			if (a[i][end] != 0) // если связь есть
			{
				int s = weight - a[i][end]; // определяем вес пути из предыдущей вершины
				if (s == d[i]) // если вес совпал с рассчитанным
				{ // значит из этой вершины и был переход
					weight = s; // сохраняем новый вес
					end = i; // сохраняем предыдущую вершину
					ver[k] = i + 1; // и записываем ее в массив
					k++;
				}
			}
	}
	// Вывод пути (начальная вершина оказалась в конце массива из k элементов)
	printf("\nВывод кратчайшего пути\n");
	fprintf(fp, "\nВывод кратчайшего пути\n");
	for (int i = k - 1; i >= 0; i--) {
		printf("%3d ", ver[i]);
		fprintf(fp, "%3d ", ver[i]);
	}
	fclose(fp);
	free(a);
	free(v);
	free(d);
	free(ver);
	int repeat = repeat_program();
	if (repeat) {
		main();
	}
	else {
		system("cls");
	}
	return 0;
}