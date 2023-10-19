#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>

struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root; // указатель на корень дерева

struct Node* CreateTree(struct Node* root, struct Node* r, int data); // создание
void print_tree(struct Node* r, int l); // вывод

int main()
{
	// ввод и вывод на русском 
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int d, start = 1;

	root = NULL;
	printf("-1 - окончание построения дерева\n");
	while (start)
	{
		printf("Введите число: ");
		scanf_s("%d", &d);
		if (d == -1)
		{
			printf("Построение дерева окончено\n\n");
			start = 0;
		}
		else
			root = CreateTree(root, root, d);

	}

	print_tree(root, 0);

	return 0;
}

// функция создания дерева
struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	if (r == NULL) // если место для узла найдено
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			printf("Ошибка выделения памяти!");
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r; // создание основного корня

		// прикрепляем узел к родителю
		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	// перемещаемся по дереву с помощью рекурсии для размещения нового узла
	if (data == r->data) // проверка на присутствие элемента в дереве
	{
		printf("\n>> Такой элемент уже есть\n\n");
		return r;
	}
	else if (data > r->data)
		CreateTree(r, r->left, data);
	else
		CreateTree(r, r->right, data);

	return root;
}

// функция вывода дерева
void print_tree(struct Node* r, int l)
{

	if (r == NULL)
	{
		return;
	}

	print_tree(r->right, l + 1);
	for (int i = 0; i < l; i++)
	{
		printf(" ");
	}

	printf("%d\n", r->data);
	print_tree(r->left, l + 1);
}
