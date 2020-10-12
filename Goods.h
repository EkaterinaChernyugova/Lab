#pragma once

using namespace std;

class Goods
{
public:
	Goods(const char* valName, const char* valDate, double valPrice, int valNumber);//конструктор с параметрами
	Goods();																		//конструктор по умолчанию
	Goods(const Goods& value);														//конструктор копирования 
	~Goods();																		//деструктор 
	void		SetPrice(double valPrice);											//изменение цены товара
	void		SetNumber(int valNumber);											//изменение количества товара
	void		ExtraCharge();														//наценка товара
	void		Markdown();															//уценка товара 
	char*		ToString();															//строковое преобразование 
	char*		ToStringPrice();													//строковое преобразование цены товара
	char*		ToStringNumber();													//строковое преобразование количества товара
	static int count;
	const char* getName();
	const char* getDate();
	double		getPrice();
	int			getNumber();

private:
	const char* name;					//наименование товара
	const char* date;					//дата получения
	double		price;					//цена товара
	int			number;					//количество единиц
};

