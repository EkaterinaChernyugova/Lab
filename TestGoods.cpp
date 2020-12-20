#include  "TestGoods.h"

bool TestVirt()
{
	cout << "\nTEST: Virtual functions\n" << "--------------------------" << endl;
	Goods a("Juice", "23.06", 75.0, 120);
	ChildGoods b("Barbie", "12.12", 990.0, 14, "03-14", "doll");
	MilkGoods c("Milk", "03.06", 65.0, 100, "15.06");
	char* s1 = new char;
	char* s2 = new char;
	char* s3 = new char;
	Goods* p;
	p = &a;
	s1 = p->ToString();
	p = &b;
	s2 = p->ToString();
	p = &c;
	s3 = p->ToString();
	if (s1 != s2 && s2 != s3)
	{
		return true;
	}
	else return false;
}

bool TestAdd()
{
	cout << "\nTEST: Adding an item by number to deque\n" << "--------------------------" << endl;
	try
	{
		Goods a("Juice", "23.06", 75.0, 120);
		ChildGoods b("Barbie", "12.12", 990.0, 14, "03-14", "doll");
		MilkGoods c("Milk", "03.06", 65.0, 100, "15.06");
		Goods d("Powder", "15.07", 33.0, 14);
		Dequeue x;
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

bool TestDel()
{
	cout << "\nTEST: Removing an item by numberdeque\n" << "--------------------------" << endl;
	try
	{
		Goods a("Juice", "23.06", 75.0, 120);
		ChildGoods b("Barbie", "12.12", 990.0, 14, "03-14", "doll");
		MilkGoods c("Milk", "03.06", 65.0, 100, "15.06");
		Goods d("Powder", "15.07", 33.0, 14);
		Dequeue x;
		x.push_front(a.ToString());
		x.push_back(b.ToString());
		x.push_back(c.ToString());
		x.push_back(d.ToString());
		x.delet(3);
		return true;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
		return false;
	}
}