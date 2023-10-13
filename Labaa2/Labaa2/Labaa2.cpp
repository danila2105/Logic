#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

void shell(int* items, int count)
{

	int i, j, gap, k;
	int x;

	if (count == 0) printf("Time shell: %d", 0);

	for (k = 0; k < count; k++) {
		gap = items[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;

	i = left; j = right;
	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}

int compare(const void* x1, const void* x2)
{
	return(*(int*)x1 - *(int*)x2);
}


void printB(int* items, int count)
{
	for (int i = 0; i < count; i++) printf("%d ", items[i]);
	printf("\n\n");
}



void mass1(int* items, int count)
{
	int i = 0;
	for (i; i < count; i++) items[i] = rand() % 100 + 1;

	//printf("Rand chicla: ");

	clock_t start = clock();
	shell(items, count);
	clock_t end = clock();
	double time_spent1 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time shell : % f s.\n", time_spent1);

	i = 0;
	for (i; i < count; i++) items[i] = rand() % 100 + 1;
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	double time_spent2 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time qs: %f s.\n", time_spent2);


	i = 0;
	for (i; i < count; i++) items[i] = rand() % 100 + 1;
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	double time_spent3 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time standart: %f s.\n", time_spent3);

	std::cout << std::left << std::setw(15) << " " << "| Shell sort |" << std::setw(10) << " Quick sort " << std::setw(15) << "| Standart sort" << std::endl;
	//printf("               | Shell sort | Quick sort | Standart sort\n");
	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Rand chicla    |  " << std::setw(10) << time_spent1 << "| " << std::setw(10) << time_spent2 << " | " << time_spent3 << std::endl;
}

void mass2(int* items, int count) {
	for (int i = 0; i < count; i++) items[i] = i;

	//printf("\nVozr chicla: \n");

	clock_t start = clock();
	shell(items, count);
	clock_t end = clock();
	double time_spent4 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time shell: %f s.\n", time_spent4);

	for (int i = 0; i < count; i++) items[i] = i;
	start = clock();
	qs(items, 0, count - 1);
	end = clock();
	double time_spent5 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time qs: %f s.\n", time_spent5);

	for (int i = 0; i < count; i++) items[i] = i;
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	double time_spent6 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time standart: %f s.\n", time_spent6);

	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Vozr chicla    |  " << std::setw(10) << time_spent4 << "| " << std::setw(10) << time_spent5 << " | " << time_spent6 << std::endl;
}

void mass3(int* items, int count) {
	for (int i = count, j = 0; i > 0; i--, j++) items[i - 1] = j;

	//printf("\nybiv chicla: \n");

	clock_t start = clock();
	shell(items, count);
	clock_t end = clock();
	double time_spent7 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time shell: %f s.\n", time_spent7);

	for (int i = count, j = 0; i > 0; i--, j++) items[i - 1] = j;
	start = clock();
	//for (int i = 0; i < count; i++) std::cout << items[i] << std::endl;
	qs(items, 0, count - 1);
	//for (int i = 0; i < count; i++) std::cout << items[i] << std::endl;
	end = clock();
	double time_spent8 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time qs: %f s.\n", time_spent8);

	for (int i = count, j = 0; i > 0; i--, j++) items[i - 1] = j;
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	double time_spent9 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time standart: %f s.\n", time_spent9);

	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Ybiv chicla    |  " << std::setw(10) << time_spent7 << "| " << std::setw(10) << time_spent8 << " | " << time_spent9 << std::endl;
}

void mass4(int* items, int count)
{
	int i = 0, j = 0;
	for (i; i < count / 2; i++) items[i] = i;
	for (i = count, j; i >= count / 2; i--, j++) items[i - 1] = j;

	//printf("\nCmew chicla: \n");

	clock_t start = clock();
	shell(items, count);
	clock_t end = clock();
	double time_spent10 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time shell: %f s.\n", time_spent10);

	i = 0, j = 0;
	for (i; i < count / 2; i++) items[i] = i;
	for (i = count, j; i >= count / 2; i--, j++) items[i - 1] = j;
	start = clock();
	//for (int i = 0; i < count; i++) std::cout << items[i] << std::endl;
	qs(items, 0, count - 1);
	//for (int i = 0; i < count; i++) std::cout << items[i] << std::endl;
	end = clock();
	double time_spent11 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time qs: %f s.\n", time_spent11);

	i = 0, j = 0;
	for (i; i < count / 2; i++) items[i] = i;
	for (i = count, j; i >= count / 2; i--, j++) items[i - 1] = j;
	start = clock();
	qsort(items, count, sizeof(int), compare);
	end = clock();
	double time_spent12 = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("time standart: %f s.\n", time_spent12);

	std::cout << "---------------------------------------------------------" << std::endl;
	std::cout << std::left << std::setw(15) << "Cmew chicla    |  " << std::setw(10) << time_spent10 << "| " << std::setw(10) << time_spent11 << " | " << time_spent12 << std::endl;
}



int main(void)
{
	setlocale(LC_ALL, "Russian");

	int n, i = 0, j = 0;


	printf("Size array: ");
	std::cin >> n;
	printf("\n");


	int* arr = new int[n];


	mass1(arr, n);

	mass2(arr, n);

	mass3(arr, n);

	mass4(arr, n);

}