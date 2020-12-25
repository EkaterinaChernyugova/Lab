#include  "TestGoods.h"

bool TestChar()
{
	cout << "\nTEST: Template  char*\n" << "--------------------------" << endl;
	try
	{
		Goods a("Juice", "23.06", 75.0, 120);
		ChildGoods b("Barbie", "12.12", 990.0, 14, "03-14", "doll");
		MilkGoods c("Milk", "03.06", 65.0, 100, "15.06");
		Goods d("Powder", "15.07", 33.0, 14);
		Dequeue <char*> x;
		x.push_front(a.ToString());
		x.push_back(b.ToString());
		x.push_back(c.ToString());
		x.add(3, d.ToString());
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
}

bool TestInt()
{
	cout << "\nTEST: Template  int\n" << "--------------------------" << endl;
	try
	{
		Dequeue <int> x;
		x.push_front(52);
		x.push_back(44);
		x.push_back(21);
		x.add(3, 19);
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
}

bool TestGoods()
{
	cout << "\nTEST: Template  Goods\n" << "--------------------------" << endl;
	try
	{
		Goods a("Juice", "23.06", 75.0, 120);
		ChildGoods b("Barbie", "12.12", 990.0, 14, "03-14", "doll");
		MilkGoods c("Milk", "03.06", 65.0, 100, "15.06");
		Goods d("Powder", "15.07", 33.0, 14);
		Dequeue <Goods> x;
		x.push_front(a);
		x.push_back(b);
		x.push_back(c);
		x.add(3, d);
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
}