#include  "TestGoods.h"

bool TestAge(ChildGoods x, int val)
{
	cout << "\nTEST: Age check\n" << "--------------------------" << endl;
	int n;
	n = x.CheckAge(val);
	if (n == 1)
	{
		return true;
	}
	else return false;
}

bool TestRec(MilkGoods x)
{
	cout << "\nTEST: Recalculation of cost\n" << "--------------------------" << endl;
	double n = x.getPrice();
	x.recount();
	n = n / 2;
	if (n == x.getPrice())
	{
		return 1;
	}
	else return 0;
}