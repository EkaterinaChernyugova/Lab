#include <iostream>
#include "Goods.h"
#include  "TestGoods.h"
#include "ChildGoods.h"
#include "MilkGoods.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <fstream>
#include <ostream>

using namespace std;

int main()
{
    cout << "List of Goods:\n" << "---------------" << endl;

    Goods a("Juice", "23.06", 75.0, 120);
    ChildGoods b("Barbie", "12.12", 990.0, 14, "03-14", "doll");
    MilkGoods c("Milk", "03.06", 65.0, 100, "15.06");

    cout << a.ToString() << endl;
    cout << b.ToString() << endl;
    cout << c.ToString() << endl;

    cout << TestAge(b, 10) << endl;
    cout << TestAge(b, 18) << endl;
    cout << TestRec(c) << endl;
}

