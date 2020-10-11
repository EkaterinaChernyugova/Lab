#pragma once

using namespace std;

class Goods
{
private:
	const char*	name;					//������������ ������
	const char* date;					//���� ���������
	double		price;					//���� ������
	 int			number;					//���������� ������
public:
	Goods(const char* valName, const char* valDate, double valPrice, int valNumber);	//����������� � �����������
	Goods();																		//����������� �� ���������
	Goods(const Goods& value);														//����������� ����������� 
	~Goods();																		//���������� 
	void		SetPrice(double valPrice);											//��������� ���� ������
	void		SetNumber(int valNumber);											//��������� ���������� ������
	void		ExtraCharge();														//������� ������
	void		Markdown();															//������ ������ 
	void		ConvertingToString();												//��������� ��������������
	static int count;
};

