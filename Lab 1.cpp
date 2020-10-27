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

// тест для проверки перегрузки оперетора присваивания
bool Test5(Goods x, Goods y)
{
    cout << "\nTEST 5: Assignment operator\n" << "--------------------------" << endl;
    x = y;
    if ((x.getName()==y.getName())&& (x.getDate() == y.getDate())&& (x.getPrice() == y.getPrice())&& (x.getNumber() == y.getNumber())&&(&x!=&y))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// тест для проверки перегрузки оперетора сложения
bool Test6(Goods x,Goods y)
{
    cout << "\nTEST 6: Addition\n" << "--------------------------" << endl;
    Goods* w = new Goods();
    int n = w->getNumber();
    *w = x + y;
    if (w->getNumber() != n)
    {
        return true;
    }
    else
    {
        return false;
    } 
}

// тест для проверки перегрузки оперетора вычитания
bool Test7(Goods x, Goods y)
{
    cout << "\nTEST 7: Subtraction\n" << "--------------------------" << endl;
    Goods* w = new Goods();
    int n = w->getNumber();
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

// тест для проверки перегрузки оперетора инкремента
bool Test8(Goods x)
{
    cout << "\nTEST 8: Increment\n" << "--------------------------" << endl;
    const char* s = x.getDate();
    ++x;
    if (strncmp(s, x.getDate(), 2) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// тест для проверки перегрузки оперетора декремента
bool Test9(Goods x)
{
    cout << "\nTEST 9: Decrement\n" << "--------------------------" << endl;
    const char* s = x.getDate();
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

// тест для проверки перегрузки операции приведения к типу int
bool Test10(Goods x)
{
    cout << "\nTEST 10: Cast to type int\n" << "--------------------------" << endl;
    int n = (int)x;
    x.ExtraCharge();
    if(n!=x.getPrice())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// тест для проверки дружественного оперетора сложения
bool Test11(Goods x, Goods y)
{
    cout << "\nTEST 11: Friendly addition operator\n" << "--------------------------" << endl;
    int temp = x.getNumber();
    x + y;
    if(x.getNumber()!=temp)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// тест для проверки дружественного оперетора вычитания
bool Test12(Goods x, Goods y)
{
    cout << "\nTEST 12: Friendly subtraction operator\n" << "--------------------------" << endl;
    int temp = x.getNumber();
    x - y;
    if (x.getNumber() != temp)
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
    cout << Test5(a, b) << endl;
    cout << Test6(a, b) << endl;
    cout << Test7(a, b) << endl;
    cout << Test8(c) << endl;
    cout << Test9(c) << endl;
    cout << Test10(d) << endl;
    cout << Test11(a,b) << endl;
    cout << Test12(d,e) << endl;

    Goods* f = new Goods();
    cout << "Number of objects = " << Goods::count << endl;
    delete f;
    cout << "Number of objects = " << Goods::count << endl;
  
}


