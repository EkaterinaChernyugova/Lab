#include <iostream>
#include "Goods.h"
#include  "TestGoods.h"
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
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);

    cout << a.ToString() << endl;
    cout << b.ToString() << endl;
    cout << c.ToString() << endl;

    cout << TestText(a, b) << endl;
    cout << TestBinary(b, c) << endl;
}

