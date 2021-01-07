#include "Goods.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cassert>
#include <fstream>
#include <ostream>
#include <string>
#include <bitset>

using namespace std;

int Goods::count = 0;

void Goods::SetName(const char* valName)
{
	name = new const char[strlen(valName)];
	name = valName;
}

void Goods::SetDate(const char* valDate)
{
	date = new const char[strlen(valDate)];
	date = valDate;
}

void Goods::SetPrice(double valPrice)
{
	if (valPrice > 0)
	{
		price = valPrice;
	}
}

void Goods::SetNumber(int valNumber)
{
	if (valNumber > 0)
	{
		number = valNumber;
	}
}

Goods::Goods(const char* valName, const char* valDate, double valPrice, int valNumber)
{
	name = new const char;
	date = new const char;
	name = valName;
	date = valDate;
	price = valPrice;
	number = valNumber;
	count++;
}

Goods::Goods()
{
	name = new const char;
	date = new const char;
	name = "Book";
	date = "21.11";
	price = 255;
	number = 11;
	count++;
}

Goods::Goods(const Goods& value)
{
	this->name = value.name;
	this->date = value.date;
	this->price = value.price;
	this->number = value.number;
	count++;
}

Goods& Goods::operator = (const Goods* value)
{
	SetName(value->name);
	SetDate(value->date);
	this->price = value->price;
	this->number = value->number;
	return *this;
}

Goods operator + (Goods& value1, Goods& value2)
{
	Goods temp;
	temp.number = value1.number + value2.number;
	return temp;
}

Goods& Goods::operator - (const Goods& value)
{
	Goods temp;
	temp.number = this->number - value.number;
	return temp;
}

Goods& Goods::operator ++()
{
	char str[6];
	strcpy_s(str, this->date);
	str[5] = '\0';
	int value = atoi(&str[1]);
	value++;
	str[1] = (value % 10) + '0';
	char* s = new char;
	s[0] = str[0];
	s[1] = str[1];
	s[2] = str[2];
	s[3] = str[3];
	s[4] = str[4];
	s[5] = '\0';
	this->SetDate(s);
	return *this;
}

Goods& Goods::operator --()
{
	char str[6];
	strcpy_s(str, this->date);
	str[5] = '\0';
	int value = atoi(&str[1]);
	value--;
	str[1] = (value % 10) + '0';
	char* s = new char;
	s[0] = str[0];
	s[1] = str[1];
	s[2] = str[2];
	s[3] = str[3];
	s[4] = str[4];
	s[5] = '\0';
	this->SetDate(s);
	return *this;
}

Goods& Goods::operator ++(const int)
{
	Goods temp(*this);
	char str[6];
	strcpy_s(str, this->date);
	str[5] = '\0';
	int value = atoi(&str[1]);
	value++;
	str[1] = (value % 10) + '0';
	char* s = new char;
	s[0] = str[0];
	s[1] = str[1];
	s[2] = str[2];
	s[3] = str[3];
	s[4] = str[4];
	s[5] = '\0';
	this->SetDate(s);
	return temp;
}

Goods& Goods::operator --(const int)
{
	Goods temp(*this);
	char str[6];
	strcpy_s(str, this->date);
	str[5] = '\0';
	int value = atoi(&str[1]);
	value--;
	str[1] = (value % 10) + '0';
	char* s = new char;
	s[0] = str[0];
	s[1] = str[1];
	s[2] = str[2];
	s[3] = str[3];
	s[4] = str[4];
	s[5] = '\0';
	this->SetDate(s);
	return temp;
}

Goods::operator double()
{
	Goods object;
	double res = (double)object.price;
	return res;
}

ostream& operator << (ostream& os, Goods& value)
{
	os << value.name << " " << value.date << " " << value.price << " " << value.number << endl;
	return os;
}

istream& operator >> (istream& is, Goods& value)
{
	char* s1 = new char;
	char* s2 = new char;
	double pr;
	int num;
	is >> s1 >> s2 >> pr >> num;
	value.SetName(s1);
	value.SetDate(s2);
	value.SetPrice(pr);
	value.SetNumber(num);
	return is;
}

void Goods::write()
{
	const char* file = "MyFile1.dat";
	fstream out;
	out.open(file, fstream::app | fstream::binary);
	if (!out.is_open())
	{
		cout << "File open error" << endl;
	}
	else
	{
		out.write(name, sizeof(name));
		out.write(" ", sizeof(1));
		out.write(date, sizeof(date));
		out.write(" ", sizeof(1));
		out.write(ToStringPrice(), sizeof(ToStringPrice()));
		out.write(" ", sizeof(1));
		out.write(ToStringNumber(), sizeof(ToStringNumber()));
		out.write(" ", sizeof(1));
		out.write("\n", sizeof(2));
	}
	out.close();
}

void Goods::read()
{
	const char* file = "MyFile1.dat";
	fstream in;
	in.open(file, fstream::in | fstream::binary);
	if (!in.is_open())
	{
		cout << "File open error" << endl;
	}
	else
	{
		char* s1 = new char;
		char* s2 = new char;
		char* s3 = new char;
		char* s4 = new char;
		in.read((char*)&s1, sizeof(s1));
		in.read((char*)&s2, sizeof(s2));
		in.read((char*)&s3, sizeof(s3));
		in.read((char*)&s4, sizeof(s4));
		double pr = atoi(s3);
		int num = atoi(s4);
	}
	in.close();
}

Goods::~Goods()
{
	delete[] name;
	delete[] date;
	count--;
}

void Goods::ExtraCharge()
{
	double z = price;
	price = price + ((z / 100) * 10);
}

void Goods::Markdown()
{
	if (number != 0)
	{
		number--;
	}
}

const char* Goods::getName()
{
	return name;
}

const char* Goods::getDate()
{
	return date;
}

double	Goods::getPrice()
{
	return price;
}

int		Goods::getNumber()
{
	return number;
}

char* Goods::ToStringPrice()
{
	int x, k, l, i;
	x = price;
	k = 0;
	while (x > 0)
	{
		x = x / 10;
		k++;
	}
	l = k + 3;
	char* strPrice = (char*)malloc(sizeof(int) * l);
	i = 0;
	x = price;
	while (i != k)
	{
		strPrice[k - 1 - i] = (x % 10) + '0';
		i++;
		x = x / 10;
	}
	strPrice[l - 3] = '.';
	x = price * 10;
	strPrice[l - 2] = (x % 10) + '0';
	strPrice[l - 1] = '\0';
	return strPrice;
}

char* Goods::ToStringNumber()
{
	int x, k, l, i;
	x = number;
	k = 0; l = 0;
	while (x > 0)
	{
		x = x / 10;
		k++;
	}
	l = k + 1;
	char* strNumber = (char*)malloc(sizeof(int) * l);
	i = 0;
	x = number;
	while (i != k)
	{
		strNumber[k - 1 - i] = (x % 10) + '0';
		i++;
		x = x / 10;
	}
	strNumber[l - 1] = '\0';
	return strNumber;
}

char* Goods::ToString()
{
	int  k, l, i;
	char* strPrice;
	char* strNumber;
	strPrice = ToStringPrice();
	strNumber = ToStringNumber();
	l = 31;
	k = strlen(strPrice);
	l = l + k;
	k = strlen(strNumber);
	l = l + k;
	char STR[100];
	strcpy_s(STR, "Name: ");
	strcat_s(STR, name);
	strcat_s(STR, " Date: ");
	strcat_s(STR, date);
	strcat_s(STR, " Price ");
	strcat_s(STR, strPrice);
	strcat_s(STR, " Number ");
	strcat_s(STR, strNumber);
	l = strlen(STR);
	char* ST = new char[l];
	for (i = 0; i < l; i++)
	{
		ST[i] = STR[i];
	}
	ST[l] = '\0';
	return ST;
}