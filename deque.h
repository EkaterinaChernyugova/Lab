#pragma once
#include "Goods.h"
#include <iostream>

using namespace std;

const int Max = 100;		// ����������� ���������� ����� ��������� � ����

template <class T> class Dequeue {
	struct node {
		node* prev;
		node* next;
		char** dequeue;
		node(node* Pr, node* Ne)
		{
			prev = Pr;
			next = Ne;
			dequeue = new char* [Max]();
		}
	};
public:
	Dequeue();
	void	add_first();						// ���������� ���������� �������
	void	add_last();							// ��������� ����� ���� � ����� ������
	void	delete_first();						// ������� ������ ���� ������
	void	delete_last();						// ������� ��������� ���� ������
	void	push_front(T n); 				//�������� (��������) � ������ ���� ����� �������
	void	push_back(T n);					//�������� (��������) � ����� ���� ����� �������
	char*	pop_front();						//������� �� ���� ������ �������
	char*	pp(int n);
	int		size();								//������� ���������� ��������� � ����
	void	clear();							//�������� ���
	void	print();							//����� �� �����
	char*	front();							//������ �������� ������� ��������
	char*	back();								//������ �������� ���������� ��������
	void	delet(int n);						//�������� �������� �� ������ 
	void	add(int n, T s);				//���������� �������� �� ������
protected:
	node* first;
	node* last;
	int		f;									// ������ ������� ���������� �������� � ������ ����
	int		l;									// ������ ���������� ���������� �������� � ��������� ����
	int		Size;
	T obj;
};
