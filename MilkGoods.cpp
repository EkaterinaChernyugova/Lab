#include "MilkGoods.h"
#include "Goods.h"

const char* MilkGoods::getTerm()
{
	return term;
}

void MilkGoods::setTerm(const char* valTerm)
{
	term = new const char[strlen(valTerm)];
	term = valTerm;
}

MilkGoods::MilkGoods(const char* valName, const char* valDate, double valPrice, int valNumber, const char* valTerm)
{
	SetName(valName);
	SetDate(valDate);
	SetPrice(valPrice);
	SetNumber(valNumber);
	setTerm(valTerm);
}

MilkGoods::~MilkGoods()
{
	delete[] term;
}

char* MilkGoods::ToString()
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
	strcat_s(STR, " Term ");
	strcat_s(STR, getTerm());
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

void MilkGoods::recount()
{
	double n = getPrice();
	n = n / 2;
	SetPrice(n);
}