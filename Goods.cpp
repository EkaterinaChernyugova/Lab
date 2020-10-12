#include "Goods.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cassert>

using namespace std;

int Goods::count = 0;
double Goods::count1 = 0;

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
	name	= valName;
	date	= valDate;
	price	= valPrice;
	number	= valNumber;
}

Goods::Goods()
{
	name	= "Book";
	date	= "21.11";
	price	= 255;
	number	= 11;
}

Goods::Goods(const Goods &value)
{
	this->name = value.name;
	this->date = value.date;
	this->price = value.price;
	this->number = value.number;
}

Goods::~Goods()
{
	delete[] name;
	delete[] date;
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

int		Goods::	getNumber() 
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
	strcpy_s(STR, "Name:");
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
	ST[l - 1] = '\0';
	return ST;
}



