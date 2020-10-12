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
	void		ToString();															//��������� ��������������
	static int count;
	const char* getName() { return name; };
	const char* getDate() { return date; };
	double		getPrice() { return price; };
	int			getNumber() { return number; };

private:
	const char* name;					//������������ ������
	const char* date;					//���� ���������
	double		price;					//���� ������
	int			number;					//���������� ������
};

