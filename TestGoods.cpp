#include  "TestGoods.h"

bool TestMark(Goods* x)
{
    cout << "\nTEST: Markdown of goods\n" << "--------------------------" << endl;
    x->SetNumber(1);
    int val = x->getNumber();
    x->Markdown();
    x->Markdown();
    if (val != x->getNumber())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TestAss(Goods x, Goods y)
{
    cout << "\nTEST: Assignment operator\n" << "--------------------------" << endl;
    x = y;
    if ((x.getName() == y.getName()) && (x.getDate() == y.getDate()) && (x.getPrice() == y.getPrice()) && (x.getNumber() == y.getNumber()) && (&x != &y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TestSub(Goods x, Goods y)
{
    cout << "\nTEST: Subtraction\n" << "--------------------------" << endl;
    Goods* w = new Goods();
    int n = w->getNumber();
    x.SetNumber(10);
    y.SetNumber(20);
    *w = x - y;
    if (w->getNumber() != n)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TestDecPr(Goods x)
{
    cout << "\nTEST: Prefix decrement\n" << "--------------------------" << endl;
    const char* s = x.getDate();
    x.SetDate("00.00");
    --x;
    if (strncmp(s, x.getDate(), 2) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TestDecPost(Goods x)
{
    cout << "\nTEST: Postfix decrement\n" << "--------------------------" << endl;
    const char* s = x.getDate();
    x.SetDate("00.00");
    x--;
    if (strncmp(s, x.getDate(), 2) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}