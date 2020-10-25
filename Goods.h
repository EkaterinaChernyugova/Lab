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
	void		SetName(const char* valName);										//изменение названия товара
	void		SetDate(const char* valDate);										//изменение даты получения товара
	void		ExtraCharge();														//наценка товара
	void		Markdown();															//уценка товара 
	char*		ToString();															//строковое преобразование 
	char*		ToStringPrice();													//строковое преобразование цены товара
	char*		ToStringNumber();													//строковое преобразование количества товара
	Goods &operator = (const Goods* value);											//перегрузка оперетора присваивания
	Goods &operator + (const Goods& value);											//перегрузка оперетора сложения
	Goods &operator - (const Goods& value);											//перегрузка оперетора вычитания
	Goods &operator ++ ();															//перегрузка оперетора инкремента
	Goods &operator -- ();															//перегрузка оперетора декремента
	operator int();																	//перегрузка операции приведения к типу int
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

