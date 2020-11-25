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

std::ostream& operator <<(std::ostream& os, Goods& value)
{
	os << value.ToString();
	return os;
}

std::ofstream& operator <<(std::ofstream& os, Goods& value)
{
	char* str = value.ToString();
	int k = strlen(str);
	int i = 0, j;
	int s;

	for (i = 0; i < k; i++)
	{
		s = (int)str[i];
		bitset<7> temp(s);
		os << temp << " ";

	}
	os << ';';
	return os;
}

std::istream& operator >>(std::istream& is, Goods& value)
{
	char* s1 = new char;
	char* s2 = new char;
	char* s3 = new char;
	char* s4 = new char;
	is >> s1 >> s1 >> s2 >> s2 >> s3 >> s3 >> s4 >> s4;
	double pr = atoi(s3);
	int num = atoi(s4);
	value.SetName(s1);
	value.SetDate(s2);
	value.SetPrice(pr);
	value.SetNumber(num);
	return is;
}

std::ifstream& operator >>(std::ifstream& ifs, Goods& value)
{
	int c, k, w, n;
	char* s = new char;
	char str[100];
	s[0] = ' ';
	n = 0;
	while (s[0] != ';')
	{
		k = 0;
		w = 0;
		ifs >> s;
		if (s[0] == ';') { break; }
		c = atoi(s);
		while (c != 0)
		{
			w = w + (c % 10) * pow(2, k);
			k++;
			c = c / 10;
		}
		str[n] = (char)w;
		n++;
	}
	str[n] = '\0';
	char* s1 = new char;
	char* s2 = new char;
	char* s3 = new char;
	char* s4 = new char;
	k = 0;
	w = 6;
	while (str[w + k] != ' ')
	{
		s1[k] = str[w + k];
		k++;

	}
	s1[k] = '\0';
	w = w + k + 7;
	k = 0;
	while (str[w + k] != ' ')
	{
		s2[k] = str[w + k];
		k++;

	}
	s2[k] = '\0';
	w = w + k + 7;
	k = 0;
	while (str[w + k] != ' ')
	{
		s3[k] = str[w + k];
		k++;

	}
	s3[k] = '\0';
	w = w + k + 8;
	k = 0;
	while (str[w + k] != '\0')
	{
		s4[k] = str[w + k];
		k++;

	}
	s4[k] = '\0';
	double pr = atoi(s3);
	int num = atoi(s4);
	value.SetName(s1);
	value.SetDate(s2);
	value.SetPrice(pr);
	value.SetNumber(num);
	return ifs;
}

void Goods::writeText()
{
	string path = "myFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open())
	{
		fs << *this << endl;
	}
	fs.close();
}

void Goods::readText()
{
	string path = "myFile.txt";
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open())
	{
		fs >> *this;
	}
	fs.close();

}

void Goods::writeBinary()
{
	string path = "myFile1.txt";
	ofstream ofs;
	ofs.open(path, ofstream::in | ofstream::out | ofstream::app);
	if (ofs.is_open())
	{
		ofs << *this << endl;
	}
	ofs.close();
}

void Goods::readBinary()
{
	string path = "myFile1.txt";
	ifstream ofs;
	ofs.open(path, ifstream::in | ifstream::out | ifstream::app);
	if (ofs.is_open())
	{
		ofs >> *this;
	}
	ofs.close();
}

Goods::~Goods()
{
	//delete[] name;
	//delete[] date;
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
