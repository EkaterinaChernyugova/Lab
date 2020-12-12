#include "ChildGoods.h"
#include "Goods.h"

const char* ChildGoods:: getAge()
{
	return age;
}

const char* ChildGoods::getType()
{
	return type;
}

void ChildGoods::setAge(const char* valAge)
{
	age = new const char[strlen(valAge)];
	age = valAge;
}

void ChildGoods::setType(const char* valType)
{
	type = new const char[strlen(valType)];
	type = valType;
}

ChildGoods::ChildGoods(const char* valName, const char* valDate, double valPrice, int valNumber, const char* valAge, const char* valtype)
{
	SetName(valName);
	SetDate(valDate);
	SetPrice(valPrice);
	SetNumber(valNumber);
	setAge(valAge);
	setType(valtype);
}

ChildGoods::~ChildGoods()
{
	delete[] age;
	delete[] type;
}

char* ChildGoods::ToStringChild()
{
	int  k, l, i;
	char* strPrice;
	char* strNumber;
	strPrice = ToStringPrice();
	strNumber = ToStringNumber();
	char STR[150];
	strcpy_s(STR, "Name: ");
	strcat_s(STR, getName());
	strcat_s(STR, " Date: ");
	strcat_s(STR, getDate());
	strcat_s(STR, " Age: ");
	strcat_s(STR, getAge());
	strcat_s(STR, " Type: ");
	strcat_s(STR, getType());
	strcat_s(STR, " Price: ");
	strcat_s(STR, strPrice);
	strcat_s(STR, " Number: ");
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

int ChildGoods::CheckAge(int val)
{
	int n, m;
	n = age[0] - '0';
	n = n * 10;
	n = n + (age[1] - '0');
	m = age[3] - '0';
	m = m * 10;
	m = m + (age[4] - '0');
	if (val <= m && val >= 3)
	{
		return 1;
	}
	else return 0;
}