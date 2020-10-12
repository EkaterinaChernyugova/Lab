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
	void		ExtraCharge();														//������� ������
	void		Markdown();															//������ ������ 
	char*		ToStringP();														//��������� �������������� ���� ������
	char*		ToStringN();														//��������� �������������� ���������� ������
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

