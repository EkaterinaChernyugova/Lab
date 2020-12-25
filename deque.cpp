#include "deque.h"

template <class T> Dequeue<T>::Dequeue() {
	node* N = new node(nullptr, nullptr);
	first = N;
	last = N;
	f = Max / 2 - 1;
	l = Max / 2;
	Size = 0;
}

template <class T> void Dequeue<T>::add_first() {			// ��������� ����� ���� � ������ ������
	node* N = new node(nullptr, first);
	first->prev = N;
	first = N;
	f = Max - 1;
}

template <class T> void Dequeue<T>::add_last() {		// ��������� ����� ���� � ����� ������
	node* N = new node(last, nullptr);
	last->next = N;
	last = N;
	l = 0;
}

template <class T> void Dequeue<T>::delete_first() {		// ������� ������ ���� ������
	node* N = first->next;
	delete first;
	first = N;
	first->prev = nullptr;
	f = 0;
}

template <class T> void Dequeue<T>::delete_last() {		// ������� ��������� ���� ������
	node* N = last->prev;
	delete last;
	last = N;
	last->next = nullptr;
	l = Max - 1;
}

template <class T> void Dequeue<T>::push_front(T n) {		//�������� (��������) � ������ ���� ����� �������
	
	(first->dequeue)[f] = n;
	f--;
	Size++;
	if (f == -1)		// ���� ������ ��� ����������
		add_first();	// ��������� � ������ ������ ����� ���
}

template <class T> void Dequeue<T>::push_back(T n) {				//�������� (��������) � ����� ���� ����� �������
	(last->dequeue)[l] = n;
	l++;
	Size++;
	if (l == Max)		// ���� ��������� ��� ����������
		add_last();		// ��������� � ����� ������ ����� ���
}

template <class T> char* Dequeue<T>::pop_front() {			//������� �� ���� ������ �������
	Size--;
	if (f == Max - 1)
		delete_first();
	else
		f++;
	return (first->dequeue)[f];
}

template <class T> int Dequeue<T>::size() {			//������� ���������� ��������� � ����
	return Size;
}

template <class T> void Dequeue<T>::clear() {				//�������� ���
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

template <class T> void Dequeue<T>::print() { //����� �� �����
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

template <class T> char* Dequeue<T>::pp(int n)
{
	return (first->dequeue)[n];
}

template <class T> char* Dequeue<T>::front() {				//������ �������� ������� ��������
	if (f == Max - 1)
		return ((first->next)->dequeue)[0];
	else
		return (first->dequeue)[f + 1];
}

template <class T> char* Dequeue<T>::back() {			//������ �������� ���������� ��������
	if (l == 0)
		return ((last->prev)->dequeue)[Max - 1];
	else
		return (last->dequeue)[l - 1];
}

template <class T> void Dequeue<T>::delet(int n)		//�������� �������� �� ������
{
	if (n <= l - f)
	{
		int m = n, i = 0;
		T str = new char;
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

template <class T> void Dequeue<T>::add(int n,T s)			//���������� �������� �� ������
{
	if (n <= l - f)
	{
		int m = n, i = 0;
		T str = new char;
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