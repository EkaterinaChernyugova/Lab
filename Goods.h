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
	void		ToString();															//строковое преобразование
	static int count;
	const char* getName() { return name; };
	const char* getDate() { return date; };
	double		getPrice() { return price; };
	int			getNumber() { return number; };

private:
	const char* name;					//наименование товара
	const char* date;					//дата получения
	double		price;					//цена товара
	int			number;					//количество единиц
};

