#pragma once

#include <iostream>
#include <fstream>
#include <ostream>

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
	char* ToString();																//��������� �������������� 
	char* ToStringPrice();															//��������� �������������� ���� ������
	char* ToStringNumber();															//��������� �������������� ���������� ������
	Goods& operator = (const Goods* value);											//���������� ��������� ������������
	friend Goods operator + (Goods& value1, Goods& value2);							//���������� �������������� ��������� ��������
	Goods& operator - (const Goods& value);											//���������� ��������� ���������
	Goods& operator ++ ();															//���������� ����������� ��������� ����������
	Goods& operator -- ();															//���������� ����������� ��������� ����������
	Goods& operator ++ (const int);													//���������� ������������ ��������� ����������
	Goods& operator -- (const int);													//���������� ������������ ��������� ����������
	operator double();																//���������� �������� ���������� � ���� double

	friend ostream& operator << (ostream& os, Goods& value);						//���������� ��������� ������
	friend istream& operator >> (istream& is, Goods& value);						//���������� ��������� �����

	void write();
	void read();

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
