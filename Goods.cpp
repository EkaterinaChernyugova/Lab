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
		ToString();
	}
	else
	{
		price = valPrice;
		ToString();
	}
	
}

void Goods::SetNumber(int valNumber)
{
	cout << "Entered the number " << valNumber << "\nResult: " << endl;
	if (valNumber < 0)
	{
		cout << "Error:the number cannot be negative" << endl;
		ToString();
	}
	else
	{
		number = valNumber;
		ToString();
	}
}

Goods::Goods(const char* valName, const char* valDate, double valPrice, int valNumber)
{
	name	= valName;
	date	= valDate;
	price	= valPrice;
	number	= valNumber;
	ToString();
}

Goods::Goods()
{
	name	= "Book";
	date	= "21.11";
	price	= 255;
	number	= 11;
	ToString();
}

Goods::Goods(const Goods &value)
{
	this->name = value.name;
	this->date = value.date;
	this->price = value.price;
	this->number = value.number;
	ToString();
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
	ToString();
}

void Goods::Markdown()
{
	cout << "Starting number of goods:" << number<< "\nResult:"<< endl;
	if (number == 0)
		cout << "Eror: No goods" << endl;
	else
	{
		number--;
		ToString();
	}
}

void Goods::ToString() {
	 int x, k, i,l;

	const char* to_string(name);
	const char* to_string1(date);

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
		 strPrice[k-1-i] = (x % 10) + '0';
		 i++;
		 x = x / 10;
	 }
	 strPrice[l - 3] = '.';
	 x = price * 10;
	 strPrice[l - 2] = (x % 10) + '0';
	 strPrice[l - 1] = '\0';
	 const char* to_string2(strPrice);

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
	 strNumber[l-1] = '\0';
	 const char* to_string3(strNumber);

	 cout << "Name: " << to_string << "\tDate: " << to_string1 << "\tPrice: " << to_string2 << "\tNumber: " << to_string3 << endl;
}
