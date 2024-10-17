//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <locale.h>

using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root;

int find(struct Node* r, int find_data) {
	int f = 0;
	if (r->data == find_data) {
		f = 1;
	}
	else if (r->data < find_data && r->left != NULL) {
		f = find(r->left, find_data);
	}
	else if (r->data > find_data && r->right != NULL)
	{
		f = find(r->right, find_data);
	}
	else {
		f = 0;
	}

	return f;
}

struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	int m = 0;
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			cout << "Ошибка выделения памяти";
			exit(0);
		}

		r->left = NULL;
		r->right = NULL;
		r->data = data;
		if (root == NULL) return r;

		if (data > root->data)	root->left = r;
		else root->right = r;
		return r;
	}

	m = find(r, data);
	if (m == 0) {
		if (data > r->data)
			CreateTree(r, r->left, data);
		else
			CreateTree(r, r->right, data);
	}
	else {
		cout << "Элемент уже есть\n";
	}
	return root;
}



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

	cout << r->data << endl;
	print_tree(r->left, l + 1);
}




int main()
{
	setlocale(LC_ALL, "");
	int D, start = 1;

	root = NULL;
	while (start)
	{
		cin >> D;
		if (D == -1)
		{
			cout << "Построение дерева окончено" << endl << endl;
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);

	cout << "\nконец";
	cin >> D;
	return 0;
}