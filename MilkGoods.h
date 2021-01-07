#pragma once
#include "Goods.h"
#include <iostream>


class MilkGoods : public Goods
{
public:
	MilkGoods(const char* valName, const char* valDate, double valPrice, int valNumber, const char* valTerm);
	~MilkGoods();
	const char* getTerm();
	void setTerm(const char* valTerm);
	char* ToString() override;
	void recount();
private:
	const char* term;
};
