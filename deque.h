#pragma once
#include "Goods.h"
#include <iostream>

using namespace std;

const int Max = 100;		// максимально допустимое число элементов в деке
struct node {
	node* prev;
	node* next;
	char** dequeue;
	node(node* Pr, node* Ne)
	{
		prev = Pr;
		next = Ne;
		dequeue = new char*[Max]();
	}
};

class Dequeue {
public:
	Dequeue();
	void	add_first();						// Управление двусвязным списком
	void	add_last();							// добавляет новый узел в конец списка
	void	delete_first();						// удаляет первый узел списка
	void	delete_last();						// удаляет последний узел списка
	void	push_front(char* n); 				//Добавить (положить) в начало дека новый элемент
	void	push_back(char* n);					//Добавить (положить) в конец дека новый элемент
	char*	pop_front();						//Извлечь из дека первый элемент
	char*	pp(int n);
	int		size();								//Вывести количество элементов в деке
	void	clear();							//Очистить дек
	void	print();							//вывод на экран
	char*	front();							//Узнать значение первого элемента
	char*	back();								//Узнать значение последнего элемента
	void	delet(int n);						//удаление элемента по номеру 
	void	add(int n, char* s);				//добавление элемента по номеру
protected:
	node* first;
	node* last;
	int		f;									// индекс первого свободного элемента в первой деке
	int		l;									// индекс последнего свободного элемента в последней деке
	int		Size;
};
