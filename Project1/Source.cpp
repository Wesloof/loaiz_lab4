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

int find_input(struct Node* r, int find_data, int count_fun, int m) {
	if (r->data == find_data) {
		count_fun += 1;
	}
	if (m < count_fun) {
		m = count_fun;
	}
	if (r->left != NULL) {
		m = find_input(r->left, find_data, count_fun, m);
	}
	if (r->right != NULL)
	{
		m = find_input(r->right, find_data, count_fun, m);
	}

	return m;
}


struct Node* CreateTree(struct Node* root, struct Node* r, int data)
{
	int m = 0;
	if (r == NULL)
	{
		r = (struct Node*)malloc(sizeof(struct Node));
		if (r == NULL)
		{
			cout << "ќшибка выделени€ пам€ти";
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
		cout << "Ёлемент уже есть\n";
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
	int count;
	root = NULL;
	while (start)
	{
		cin >> D;
		if (D == -1)
		{
			cout << "ѕостроение дерева окончено" << endl << endl;
			start = 0;
		}
		else
			root = CreateTree(root, root, D);

	}

	print_tree(root, 0);
	cout << "¬ведите число: ";
	cin >> D;
	count = find_input(root, D, count, 0);
	cout << "Ёлементов в дереве:" << count;

	return 0;
}