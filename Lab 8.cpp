#include <iostream>
#include "Goods.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <ctime>
#include <list>
#include <set>

using namespace std;

bool TestList()
{
    cout << "List testing: \n------------------------" << endl;
    Goods a("Juice", "23.06", 75.0, 120);
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);
    Goods d("Socks", "07.05", 134.0, 22);
    Goods e("Chocolate", "15.07", 61.0, 37);
    int k, i, n = 100;
    int start = clock();
    list<int> mylist;
    for (i = 0; i < n; i++)
    {
        k = rand() % 100 + 1;
        mylist.push_front(k);
        mylist.push_back(k);
    }
    n = mylist.size();
    int end = clock();
    cout << "Adding: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    mylist.sort();
    end = clock();
    cout << "Sorting: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    mylist.clear();
    end = clock();
    cout << "Deleting: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    list<Goods> mylist1;
    for (i = 0; i < n; i++)
    {
        mylist1.push_front(a);
        mylist1.push_back(b);
        mylist1.push_front(c);
        mylist1.push_back(d);
        mylist1.push_back(e);
    }
    n = mylist1.size();
    end = clock();
    cout << "Adding: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    mylist.sort();
    end = clock();
    cout << "Sorting: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    mylist.clear();
    end = clock();
    cout << "Deleting: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    return true;
}

bool TestSet()
{
    cout << "\nSet testing: \n------------------------" << endl;
    Goods a("Juice", "23.06", 75.0, 120);
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);
    Goods d("Socks", "07.05", 134.0, 22);
    Goods e("Chocolate", "15.07", 61.0, 37);
    int k, i, n = 200;
    int start = clock();
    set <int> myset;
    for (i = 0; i < n; i++)
    {
        k = rand() % 1000 + 1;
        myset.insert(k);
    }
    n = myset.size();
    int end = clock();
    cout << "Adding: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    myset.find(220);
    end = clock();
    cout << "Search: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    myset.clear();
    end = clock();
    cout << "Deleting: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    set <Goods> myset1;
    myset1.insert(a);
    for (i = 0; i < n; i++)
    {
        myset1.insert(a);
        myset1.insert(b);
        myset1.insert(c);
        myset1.insert(d);
        myset1.insert(e);
    }
    n = myset1.size();
    end = clock();
    cout << "Adding: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;*/

    start = clock();
    myset1.find(a);
    end = clock();
    cout << "Search: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    start = clock();
    myset1.clear();
    end = clock();
    cout << "Deleting: n = " << n << ", " << end - start / CLOCKS_PER_SEC << " seconds" << endl;

    return true;
}

int main()
{
    TestList();
    TestSet();
}