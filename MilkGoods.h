#pragma once
#include "Goods.h"
#include <iostream>


class MilkGoods : public Goods
{
private:
	const char* term;
public:
	MilkGoods(const char* valName, const char* valDate, double valPrice, int valNumber, const char* valTerm);
	~MilkGoods();
	const char* getTerm();
	void setTerm(const char* valTerm);
	char* ToStringMilk();
	void recount();
};
