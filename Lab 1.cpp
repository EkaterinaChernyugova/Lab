#include <iostream>
#include "Goods.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 


using namespace std;

//тест для проверки функции изменения цены товара
void Test1(Goods *x)
{
    cout << "\nTEST 1: Price Change\n" << "--------------------" << endl;
    x->SetPrice(-57);
    x->SetPrice(57);
}

//тест для проверки функции изменения количества товара
void Test2(Goods* x)
{
    cout << "\nTEST 2: Number Change\n" << "---------------------" << endl;
    x->SetNumber(-19);
    x->SetNumber(19);
}

//тест для проверки функции наценки товара на 10%
void Test3(Goods* x)
{
    cout << "\nTEST 3: Product markup by 10%\n" << "-----------------------------" << endl;
    x->ExtraCharge();
}

//тест для проверки функции уценки товара
void Test4(Goods* x)
{
    cout << "\nTEST 4: Markdown of goods\n" << "--------------------------" << endl;
    x->Markdown();
    cout << "Number of goods - 0" << endl;
    x->SetNumber(0);
    x->Markdown();
}

int main()
{
    cout << "List of Goods:\n"<<"---------------" << endl;

    Goods a("Juice", "23.06", 75.0, 120);
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);
    Goods d("Socks", "07.05", 134.0, 22);
    Goods e("Chocolate", "15.07", 61.0, 37);
    
    Test1(&a);
    Test2(&b);
    Test3(&c);
    Test4(&d); 
 
}
