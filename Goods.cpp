#include "Goods.h"
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

int Goods::count = 0;

void Goods::SetPrice(double valPrice)
{
	cout << "Entered the number " << valPrice << "\nResult: "<<endl;
	if (valPrice < 0)
	{
		cout << "Error:the price cannot be negative" << endl;
		ConvertingToString();
	}
	else
	{
		price = valPrice;
		ConvertingToString();
	}
	
}

void Goods::SetNumber(int valNumber)
{
	cout << "Entered the number " << valNumber << "\nResult: " << endl;
	if (valNumber < 0)
	{
		cout << "Error:the number cannot be negative" << endl;
		ConvertingToString();
	}
	else
	{
		number = valNumber;
		ConvertingToString();
	}
}

Goods::Goods(const char* valName, const char* valDate, double valPrice, int valNumber)
{
	name	= valName;
	date	= valDate;
	price	= valPrice;
	number	= valNumber;
	ConvertingToString();
}

Goods::Goods()
{
	name	= "Book";
	date	= "21.11";
	price	= 255;
	number	= 11;
	ConvertingToString();
}

Goods::Goods(const Goods &value)
{
	this->name = value.name;
	this->date = value.date;
	this->price = value.price;
	this->number = value.number;
	ConvertingToString();
}

Goods::~Goods()
{

}

void Goods::ExtraCharge()
{
	double z = price;
	cout << "Starting price: " <<z<< endl;
	price = price + ((z / 100) * 10);
	cout << "Total price: " << price<<"\nResult:" << endl;
	ConvertingToString();
}

void Goods::Markdown()
{
	cout << "Starting number of goods:" << number<< "\nResult:"<< endl;
	if (number == 0)
		cout << "Eror: No goods" << endl;
	else
	{
		number--;
		ConvertingToString();
	}
}

void Goods::ConvertingToString() {
	 int x, k, i,l,z;
	 l = 7;
	 char* st = (char*)malloc(sizeof(int) * l);
	 st[0] = 'N';
	 st[1] = 'a';
	 st[2] = 'm';
	 st[3] = 'e';
	 st[4] = ':';
	 st[5] = ' ';
	 st[6] = '\0';
	 z = 6;

	 k = strlen(name);
	 l=l+k;
	 st = (char*)realloc(st, l);
	 k++;
	 for (i = 0; i < k; i++)
	 {
		 st[z + i] = name[i];
	 }
	 st[l - 1] = '\0';
	 z = l - 1;

	 l = l + 7;
	 st = (char*)realloc(st, l);
	 st[z] = ' ';
	 st[z+1] = 'D';
	 st[z+2] = 'a';
	 st[z+3] = 't';
	 st[z+4] = 'e';
	 st[z+5] = ':';
	 st[z+6] = ' ';
	 st[l - 1] = '\0';
	 z = l - 1;

	 k = strlen(date);
	 l = l + k;
	 st = (char*)realloc(st, l);
	 k++;
	 for (i = 0; i < k; i++)
	 {
		 st[z + i] = date[i];
	 }
	 st[l - 1] = '\0';
	 z = l - 1;

	 l = l + 8;
	 st = (char*)realloc(st, l);
	 st[z] = ' ';
	 st[z + 1] = 'P';
	 st[z + 2] = 'r';
	 st[z + 3] = 'i';
	 st[z + 4] = 'c';
	 st[z + 5] = 'e';
	 st[z + 6] = ':';
	 st[z + 7] = ' '; 
	 st[l - 1] = '\0';
	 z = l - 1;

	 x = price;
	 k = 0;
	 while (x > 0)
	 {
		 x = x / 10;
		 k++;
	 }
	 l = l + k;
	 st = (char*)realloc(st, l);
	 i = 0;
	 l++; l++; x = price;
	 while (i != k)
	 {
		 st[z+k-i-1] = (x % 10) + '0';
		 i++;
		 x = x / 10;
	 }
	 st = (char*)realloc(st, l);
	 st[l - 3] = '.';
	 x = price*10;
	 st[l - 2] = (x % 10) + '0';
	 st[l - 1] = '\0';
	 z = l - 1; 
	 
	 l = l + 9;
	 st = (char*)realloc(st, l);
	 st[z] = ' ';
	 st[z + 1] = 'N';
	 st[z + 2] = 'u';
	 st[z + 3] = 'm';
	 st[z + 4] = 'b';
	 st[z + 5] = 'e';
	 st[z + 6] = 'r';
	 st[z + 7] = ':';
	 st[z + 8] = ' ';
	 st[l - 1] = '\0';
	 z = l - 1;
	 
	 x = number;
	 k = 0;
	 while (x > 0)
	 {
		 x = x / 10;
		 k++;
	 }
	 l = l + k;
	 st = (char*)realloc(st, l);
	 i = 0;
	 x = number;
	 while (i != k)
	 {
		 st[z + k - i - 1] = (x % 10) + '0';
		 i++;
		 x = x / 10;
	 }
	 st[l - 1] = '\0';
	 
	 puts(st);
}
