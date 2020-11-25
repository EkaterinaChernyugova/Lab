﻿#include <iostream>
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
    cout << "List of Goods:\n"<<"---------------" << endl;

    Goods a("Juice", "23.06", 75.0, 120);
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);
    
    cout << a.ToString() << endl;
    cout << b.ToString() << endl;
    cout << c.ToString() << endl;

    cout << TestSet("abc", "def", 23.05, 145) << endl;
    cout << TestMark(&a) << endl;
    cout << TestAss(a, b) << endl;
    cout << TestSub(a, b) << endl;
    cout << TestDecPr(c) << endl;
    cout << TestDecPost(a) << endl;
}


