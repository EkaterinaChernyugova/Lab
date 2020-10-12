#include <iostream>
#include "Goods.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


using namespace std;

//тест для проверки функции изменения цены товара
bool Test1(Goods *x,int z)
{
    cout << "\nTEST 1: Price Change\n" << "--------------------" << endl;
    double val = x->getPrice();
    x->SetPrice(z);
    if (val != x->getPrice())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//тест для проверки функции изменения количества товара
bool Test2(Goods* x,int z)
{
    cout << "\nTEST 2: Number Change\n" << "---------------------" << endl;
    int val = x->getNumber();
    x->SetNumber(z);
    if(val!=x->getNumber())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//тест для проверки функции наценки товара на 10%
bool Test3(Goods* x)
{
    cout << "\nTEST 3: Product markup by 10%\n" << "-----------------------------" << endl;
    double val = x->getPrice();
    x->ExtraCharge();
    if (val != x->getPrice())
    {
        return true;
    }
    else
    {
        return false;
    }
}

//тест для проверки функции уценки товара
bool Test4(Goods* x)
{
    cout << "\nTEST 4: Markdown of goods\n" << "--------------------------" << endl;
    int val = x->getNumber();
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

int main()
{
    cout << "List of Goods:\n"<<"---------------" << endl;

    cout <<"Number of objects = " <<Goods::count << endl;

    Goods a("Juice", "23.06", 75.0, 120);
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);
    Goods d("Socks", "07.05", 134.0, 22);
    Goods e("Chocolate", "15.07", 61.0, 37);

    cout << a.ToString() << endl;
    cout << b.ToString() << endl;
    cout << c.ToString() << endl;
    cout << d.ToString() << endl;
    cout << e.ToString() << endl;

    cout << "Number of objects = " << Goods::count << endl;

    cout << Test1(&a, -57) << endl;
    cout << Test1(&a, 57) << endl;
    cout << Test2(&b,-19) << endl;
    cout << Test2(&b, 19) << endl;
    cout << Test3(&c) << endl;
    cout << Test4(&d) << endl;
    
    Goods* f = new Goods();
    cout << "Number of objects = " << Goods::count << endl;
    delete f;
    cout << "Number of objects = " << Goods::count << endl;
}


