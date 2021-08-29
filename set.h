#ifndef _SET_H
#define _SET_H
#include <iostream>
using namespace std;

template <class T>
class cTNode
{
public:
	T data;
	cTNode* parent;
	cTNode* left;
	cTNode* right;
};

template <class T>
class cSet
{
	int counter;
	cTNode<T>* head;
public:
	cSet();
	void input(const T& d);
	void erase(const T& d);
};
	

template <class T> cSet<T>::cSet()
{
	counter = 0;
	head = NULL;
}
template <class T> void cSet<T>::input(const T& d)
{
	bool flag = false;
	if (head == NULL)
	{
		counter = 1;
		head = new cTNode<T>();
		head->data = d;
		head->left = NULL;
		head->right = NULL;
		head->parent = NULL;
		return;
	}
	cTNode<T>* tmp = head;
	cTNode<T>* tmp2 = head;
	while (tmp != NULL)
	{
		if (tmp->data == d)
			return;
		if (tmp->data > d)
		{
			tmp2 = tmp;
			tmp = tmp->left;
			flag = false;
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->right;
			flag = true;
		}
	}
	if (flag == false)
	{
		tmp2->left = new cTNode<T>;
		tmp2->left->data = d;
		tmp2->left->left = NULL;
		tmp2->left->right = NULL;
		tmp2->left->parent = tmp2;
	}
	else
	{
		tmp2->right = new cTNode<T>;
		tmp2->right->data = d;
		tmp2->right->left = NULL;
		tmp2->right->right = NULL;
		tmp2->right->parent = tmp2;
	}
	counter++;
}

template <class T> void cSet<T>::erase(const T& d)
{
	if (head == NULL)
		return;
	cTNode<T>* tmp = head;
	cTNode<T>* tmp2 = head;
	int flag = 2;
	while (tmp != NULL)
	{
		if (tmp->data == d)
			break;
		if (tmp->data > d)
		{
			tmp2 = tmp;
			tmp = tmp->left;
			flag = 0;
		}
		else
		{
			tmp2 = tmp;
			tmp = tmp->right;
			flag = 1;
		}
	}
	if (tmp == NULL) // ���� �� ������
		return;
	if (tmp->left != NULL && tmp->right != NULL) // ���� � ���������� �������� 2 �������
	{
		cTNode<T>* tmp3 = tmp->right;
		while (tmp3->left != NULL)
		{
			tmp3 = tmp3->left;
		}
		// � tmp3 (������ ������ �������� ������� ��������� ���������� tmp) ����� ���� ������� ������			
		if (tmp3->right == NULL) // ���� ��� ���, ������ ���������� tmp3 �� ����� ���������� tmp
		{
			tmp->data = tmp3->data;
			tmp->right = NULL;
			delete tmp3;
		}
		else // ���� ����, ������������� ������� ������ ��������� ������������� tmp3 �����
		{
			tmp->data = tmp3->data;
			tmp3->parent->left = tmp3->right;
			tmp3->right->parent = tmp3->parent;
			delete tmp3;
		}
	}
	// ���� 1 ��� 0 �����
	else if (flag == 2) // ������� �������� �������
	{
		if (tmp->left == NULL && tmp->right == NULL) // ���� � ���������� �������� ��� �����
		{
			delete tmp;
			head = NULL;
		}
		else if (tmp->left != NULL && tmp->right == NULL) // ���� � ���������� �������� ������ ����� �������
		{
			head = tmp->left;
			head->parent = NULL;
			delete tmp;
		}
		else if (tmp->left == NULL && tmp->right != NULL) // ���� � ���������� �������� ������ ������ �������
		{
			head = tmp->right;
			head->parent = NULL;
			delete tmp;
		}
	}
	else if (flag == 0) // ������� ����� ������� ��� ������� ��������
	{
		if (tmp->left == NULL && tmp->right == NULL) // ���� � ���������� �������� ��� �����
		{
			delete tmp;
			tmp2->left = NULL;
		}
		else if (tmp->left != NULL && tmp->right == NULL) // ���� � ���������� �������� ������ ����� �������
		{
			tmp2->left = tmp->left;
			tmp->left->parent = tmp2;
			delete tmp;
		}
		else if (tmp->left == NULL && tmp->right != NULL) // ���� � ���������� �������� ������ ������ �������
		{
			tmp2->left = tmp->right;
			tmp->right->parent = tmp2;
			delete tmp;
		}
	}
	else if (flag == 1) // ������� ������ ������� ��� ������� ��������
	{
		if (tmp->left == NULL && tmp->right == NULL) // ���� � ���������� �������� ��� �����
		{
			delete tmp;
			tmp2->right = NULL;
		}
		else if (tmp->left != NULL && tmp->right == NULL) // ���� � ���������� �������� ������ ����� �������
		{
			tmp2->right = tmp->left;
			tmp->left->parent = tmp2;
			delete tmp;
		}
		else if (tmp->left == NULL && tmp->right != NULL) // ���� � ���������� �������� ������ ������ �������
		{
			tmp2->right = tmp->right;
			tmp->right->parent = tmp2;
			delete tmp;
		}
	}
	counter--;
}

#endif