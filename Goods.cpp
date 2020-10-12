#include "Goods.h"
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cassert>

using namespace std;

int Goods::count = 0;

void Goods::SetPrice(double valPrice)
{
	cout << "Entered the number " << valPrice << "\nResult: "<<endl;
	if (valPrice < 0)
	{
		cout << "Error:the price cannot be negative" << endl;
	}
	else
	{
		price = valPrice;
	}

}

void Goods::SetNumber(int valNumber)
{
	cout << "Entered the number " << valNumber << "\nResult: " << endl;
	if (valNumber < 0)
	{
		cout << "Error:the number cannot be negative" << endl;
	}
	else
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
	cout << "Starting price: " <<z<< endl;
	price = price + ((z / 100) * 10);
	cout << "Total price: " << price<<"\nResult:" << endl;
}

void Goods::Markdown()
{
	cout << "Starting number of goods:" << number<< "\nResult:"<< endl;
	if (number == 0)
		cout << "Eror: No goods" << endl;
	else
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
	char* STR = (char*)malloc(sizeof(int) * l);

	STR[0] = 'N';
	STR[1] = 'a';
	STR[2] = 'm';
	STR[3] = 'e';
	STR[4] = ':';
	STR[5] = ' ';
	k = strlen(name);
	int z = 6;
	for (i = 0; i < k ; i++)
	{
		STR[z + i] = name[i];
	}
	z = z + k;

	STR[z + 0] = ' ';
	STR[z + 1] = 'D';
	STR[z + 2] = 'a';
	STR[z + 3] = 't';
	STR[z + 4] = 'e';
	STR[z + 5] = ':';
	STR[z + 6] = ' ';
	z = z + 7;
	k = strlen(date);
	for (i = 0; i < k; i++)
	{
		STR[z + i] = date[i];
	}
	z = z + k;

	STR[z + 0] = ' ';
	STR[z + 1] = 'P';
	STR[z + 2] = 'r';
	STR[z + 3] = 'i';
	STR[z + 4] = 'c';
	STR[z + 5] = 'e';
	STR[z + 6] = ':';
	STR[z + 7] = ' ';
	z = z + 8;
	k = strlen(strPrice);
	for (i = 0; i < k; i++)
	{
		STR[z + i] = strPrice[i];
	}
	z = z + k;

	STR[z + 0] = ' ';
	STR[z + 1] = 'N';
	STR[z + 2] = 'u';
	STR[z + 3] = 'm';
	STR[z + 4] = 'b';
	STR[z + 5] = 'e';
	STR[z + 6] = 'r';
	STR[z + 7] = ':';
	STR[z + 8] = ' ';
	z = z + 9;
	k = strlen(strNumber);
	for (i = 0; i < k; i++)
	{
		STR[z + i] = strNumber[i];
	}
	z = z + k;
	STR[z] = '\0';
	return STR;
}

