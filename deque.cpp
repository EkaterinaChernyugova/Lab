#include "deque.h"

Dequeue::Dequeue() {
	node* N = new node(nullptr, nullptr);
	first = N;
	last = N;
	f = Max / 2 - 1;
	l = Max / 2;
	Size = 0;
}

void Dequeue::add_first() {			// добавляет новый узел в начало списка
	node* N = new node(nullptr, first);
	first->prev = N;
	first = N;
	f = Max - 1;
}

void Dequeue::add_last() {		// добавляет новый узел в конец списка
	node* N = new node(last, nullptr);
	last->next = N;
	last = N;
	l = 0;
}

void Dequeue::delete_first() {		// удаляет первый узел списка
	node* N = first->next;
	delete first;
	first = N;
	first->prev = nullptr;
	f = 0;
}

void Dequeue::delete_last() {		// удаляет последний узел списка
	node* N = last->prev;
	delete last;
	last = N;
	last->next = nullptr;
	l = Max - 1;
}

void Dequeue::push_front(char* n) {		//Добавить (положить) в начало дека новый элемент
	
	(first->dequeue)[f] = n;
	f--;
	Size++;
	if (f == -1)		// если первый дек переполнен
		add_first();	// добавляем в начало списка новый дек
}

void Dequeue::push_back(char* n) {				//Добавить (положить) в конец дека новый элемент
	(last->dequeue)[l] = n;
	l++;
	Size++;
	if (l == Max)		// если последний дек переполнен
		add_last();		// добавляем в конец списка новый дек
}

char* Dequeue::pop_front() {			//Извлечь из дека первый элемент
	Size--;
	if (f == Max - 1)
		delete_first();
	else
		f++;
	return (first->dequeue)[f];
}

int Dequeue::size() {			//Вывести количество элементов в деке
	return Size;
}

void Dequeue::clear() {				//Очистить дек
	node* N = first;
	while (N) {
		node* M = N->next;
		delete N->prev;
		delete N;
		N = M;
	}
	N = new node(nullptr, nullptr);
	first = N;
	last = N;
	Size = 0;
	f = Max / 2 - 1;
	l = Max / 2;
}

void Dequeue::print() { //вывод на экран
	int k, i = 0;
	k = f + 1;
	while(k < l)
	{
		i++;
		cout << i << ") ";
		cout << pp(k) << endl;
		k++;
	}
}

char* Dequeue::pp(int n)
{
	return (first->dequeue)[n];
}

char* Dequeue::front() {				//Узнать значение первого элемента
	if (f == Max - 1)
		return ((first->next)->dequeue)[0];
	else
		return (first->dequeue)[f + 1];
}

char* Dequeue::back() {			//Узнать значение последнего элемента
	if (l == 0)
		return ((last->prev)->dequeue)[Max - 1];
	else
		return (last->dequeue)[l - 1];
}

void Dequeue::delet(int n)		//удаление элемента по номеру
{
	if (n <= l - f)
	{
		int m = n, i = 0;
		char* str = new char;
		if (n == 1)pop_front();
		else
		{
			while (m != 1)
			{
				str = front();
				pop_front();
				push_back(str);
				m--;
				i++;
			}
			pop_front();
			while (i != 1)
			{
				str = front();
				pop_front();
				push_back(str);
				i--;
			}
		}
	}
	else throw std::exception("Error: No such number exists");
}

void Dequeue::add(int n,char* s)			//добавление элемента по номеру
{
	if (n <= l - f)
	{
		int m = n, i = 0;
		char* str = new char;
		if (n == 1)push_front(s);
		else
		{
			while (m != 1)
			{
				str = front();
				pop_front();
				push_back(str);
				m--;
				i++;
			}
			push_front(s);
			while (i != 0)
			{
				str = front();
				pop_front();
				push_back(str);
				i--;
			}
		}
	}
	else throw std::exception("Error: No such number exists");
}