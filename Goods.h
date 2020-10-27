#pragma once

using namespace std;

class Goods
{
public:
	Goods(const char* valName, const char* valDate, double valPrice, int valNumber);//����������� � �����������
	Goods();																		//����������� �� ���������
	Goods(const Goods& value);														//����������� ����������� 
	~Goods();																		//���������� 
	void		SetPrice(double valPrice);											//��������� ���� ������
	void		SetNumber(int valNumber);											//��������� ���������� ������
	void		SetName(const char* valName);										//��������� �������� ������
	void		SetDate(const char* valDate);										//��������� ���� ��������� ������
	void		ExtraCharge();														//������� ������
	void		Markdown();															//������ ������ 
	char*		ToString();															//��������� �������������� 
	char*		ToStringPrice();													//��������� �������������� ���� ������
	char*		ToStringNumber();													//��������� �������������� ���������� ������
	Goods &operator = (const Goods* value);											//���������� ��������� ������������
	Goods &operator + (const Goods& value);											//���������� ��������� ��������
	Goods &operator - (const Goods& value);											//���������� ��������� ���������
	Goods &operator ++ ();															//���������� ��������� ����������
	Goods &operator -- ();															//���������� ��������� ����������
	operator int();																	//���������� �������� ���������� � ���� int
	friend Goods operator +(Goods& a,Goods& b);										//������������� �������� ��������
	friend Goods operator -(Goods& a, Goods& b);									//������������� �������� ���������
	static int count;
	const char* getName();
	const char* getDate();
	double		getPrice();
	int			getNumber();

private:
	const char* name;					//������������ ������
	const char* date;					//���� ���������
	double		price;					//���� ������
	int			number;					//���������� ������
};

