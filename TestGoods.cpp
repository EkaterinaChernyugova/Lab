#include  "TestGoods.h"

bool TestMark(Goods* x)
{
    cout << "\nTEST: Markdown of goods\n" << "--------------------------" << endl;
    try
    {
        x->Markdown();
        return true;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
        return false;
    }
}

bool TestAss(Goods x, Goods y)
{
    cout << "\nTEST: Assignment operator\n" << "--------------------------" << endl;

    try
    {
        x = y;
        if ((x.getName() == y.getName()) && (x.getDate() == y.getDate()) && (x.getPrice() == y.getPrice()) && (x.getNumber() == y.getNumber()) && (&x != &y))
        {
            return true;
        }
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
        return false;
    }
}

bool TestSub(Goods x, Goods y)
{
    cout << "\nTEST: Subtraction\n" << "--------------------------" << endl;
    try
    {
        Goods* w = new Goods();
        *w = x - y;
        return true;

    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
        return false;
    }
}

bool TestWR(Goods x, Goods y)
{
    cout << "\nTEST: Write\n" << "--------------------------" << endl;
    try
    {
        x.write();
        y.read();
        if (strcmp(x.getName(), y.getName()) == 0 && strcmp(x.getDate(), y.getDate()) == 0 && x.getPrice() == y.getPrice() && x.getNumber() == y.getNumber())
        {
            return true;
        }

    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
        return false;
    }
}


