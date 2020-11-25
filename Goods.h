#pragma once

#include <iostream>
#include <fstream>
#include <ostream>

using namespace std;

class Goods
{
public:
	Goods(const char* valName, const char* valDate, double valPrice, int valNumber);//конструктор с параметрами
	Goods();																		//конструктор по умолчанию
	Goods(const Goods& value);														//конструктор копирования 
	~Goods();																		//деструктор 
	void		SetPrice(double valPrice);											//изменение цены товара
	void		SetNumber(int valNumber);											//изменение количества товара
	void		SetName(const char* valName);										//изменение названия товара
	void		SetDate(const char* valDate);										//изменение даты получения товара
	void		ExtraCharge();														//наценка товара
	void		Markdown();															//уценка товара 
	char*		ToString();															//строковое преобразование 
	char*		ToStringPrice();													//строковое преобразование цены товара
	char*		ToStringNumber();													//строковое преобразование количества товара
	Goods &operator = (const Goods* value);											//перегрузка оператора присваивания
	friend Goods operator + (Goods& value1,Goods& value2);							//перегрузка дружественного оператора сложения
	Goods &operator - (const Goods& value);											//перегрузка оператора вычитания
	Goods &operator ++ ();															//перегрузка префиксного оператора инкремента
	Goods &operator -- ();															//перегрузка префиксного оператора декремента
	Goods& operator ++ (const int);													//перегрузка постфиксного оператора инкремента
	Goods& operator -- (const int);													//перегрузка постфиксного оператора декремента
	operator double();																//перегрузка операции приведения к типу double

	friend ostream& operator << (ostream& os, Goods& value);						//перегрузка оператора вывода
	friend istream& operator >> (istream& is, Goods& value);						//перегрузка оператора ввода
	friend ofstream& operator << (ofstream& os, Goods& value);						//перегрузка оператора вывода
	friend ifstream& operator >> (ifstream& is, Goods& value);						//перегрузка оператора ввода

	void writeText();																//функция записи в тектовый файл 
	void readText();																//функция загрузки объектов из текстового файла
	void writeBinary();																//функция записи в двоичный файл
	void readBinary();																//функция загрузки объектов из двоичного файла

	static int count;
	const char* getName();
	const char* getDate();
	double		getPrice();
	int			getNumber();

private:
	const char* name;					//наименование товара
	const char* date;					//дата получения
	double		price;					//цена товара
	int			number;					//количество единиц
};

