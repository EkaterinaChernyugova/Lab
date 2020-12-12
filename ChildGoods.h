#pragma once
#include "Goods.h"
#include <iostream>

class ChildGoods : public Goods
{
private:
	const char* age;
	const char* type;
public:
	ChildGoods(const char* valName, const char* valDate, double valPrice, int valNumber,const char* valAge,const char* valtype);
	~ChildGoods();
	const char* getAge();
	const char* getType();
	void setAge(const char* valAge);
	void setType(const char* valType);
	char* ToStringChild();
	int CheckAge(int val);
};
