#include "Goods.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cassert>

using namespace std;

int Goods::count = 0;

void Goods::SetPrice(double valPrice)
{
	char* str;
	char* str1;
	cout << "Entered the number " << valPrice << "\nResult: "<<endl;
	if (valPrice < 0)
	{
		cout << "Error:the price cannot be negative" << endl;
		str=ToStringP();
		str1 = ToStringN();
	}
	else
	{
		price = valPrice;
		str = ToStringP();
		str1 = ToStringN();
	}
	
	cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;

}

void Goods::SetNumber(int valNumber)
{
	char* str;
	char* str1;
	cout << "Entered the number " << valNumber << "\nResult: " << endl;
	if (valNumber < 0)
	{
		cout << "Error:the number cannot be negative" << endl;
		str = ToStringP();
		str1 = ToStringN();
	}
	else
	{
		number = valNumber;
		str = ToStringP();
		str1 = ToStringN();
	}
	cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;
}

Goods::Goods(const char* valName, const char* valDate, double valPrice, int valNumber)
{
	char* str;
	char* str1;
	name	= valName;
	date	= valDate;
	price	= valPrice;
	number	= valNumber;
	str = ToStringP();
	str1 = ToStringN();
	cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;
}

Goods::Goods()
{
	char* str;
	char* str1;
	name	= "Book";
	date	= "21.11";
	price	= 255;
	number	= 11;
	str = ToStringP();
	str1 = ToStringN();
	cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;
}

Goods::Goods(const Goods &value)
{
	char* str;
	char* str1;
	this->name = value.name;
	this->date = value.date;
	this->price = value.price;
	this->number = value.number;
	str = ToStringP();
	str1 = ToStringN();
	cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;
}

Goods::~Goods()
{
	//delete[] name;
	//delete[] date;
}

void Goods::ExtraCharge()
{
	char* str;
	char* str1;
	double z = price;
	cout << "Starting price: " <<z<< endl;
	price = price + ((z / 100) * 10);
	cout << "Total price: " << price<<"\nResult:" << endl;
	str = ToStringP();
	str1 = ToStringN();
	cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;
}

void Goods::Markdown()
{
	char* str;
	char* str1;
	cout << "Starting number of goods:" << number<< "\nResult:"<< endl;
	if (number == 0)
		cout << "Eror: No goods" << endl;
	else
	{
		number--;
		str = ToStringP();
		str1 = ToStringN();
		cout << "Name: " << name << "\tDate: " << date << "\tPrice: " << str << "\tNumber: " << str1 << endl;
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

int		Goods::	getNumber() 
{
	return number;
}

char* Goods::ToStringP() 
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

char* Goods::ToStringN()
{
	int x, k, i, l;
	x = number;
	k = 0;
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