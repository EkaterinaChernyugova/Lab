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
    int start = clock();
    try
    {
        list<Goods> mylist;
        mylist.size();
        mylist.push_front(a);
        mylist.push_back(b);
        mylist.push_front(c);
        mylist.push_back(d);
        mylist.push_back(e);
        mylist.clear();
        mylist.push_front(a);
        mylist.push_back(b);
        mylist.push_front(c);
        mylist.push_back(d);
        mylist.push_back(e);
        mylist.pop_front();
        mylist.pop_back();
        mylist.sort();
        int end = clock();
        cout << end - start / CLOCKS_PER_SEC << " seconds" <<endl;
        return true;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
        return false;
    }  
}

bool TestSet()
{
    cout << "Set testing: \n------------------------" << endl;
    Goods a("Juice", "23.06", 75.0, 120);
    Goods b("Powder", "04.11", 30.0, 273);
    Goods c("Soap", "03.12", 15.0, 448);
    Goods d("Socks", "07.05", 134.0, 22);
    Goods e("Chocolate", "15.07", 61.0, 37);
    int start = clock();
    try
    {
        set <Goods> myset;
        myset.insert(a);
        myset.insert(b);
        myset.insert(c);
        myset.insert(d);
        myset.insert(e);
        myset.clear();
        myset.insert(a);
        myset.insert(b);
        myset.insert(c);
        myset.insert(d);
        myset.insert(e);
        myset.find(a);
        myset.erase(b);
        int end = clock();
        cout << end - start / CLOCKS_PER_SEC << " seconds" << endl;
        return true;
    }
    catch (exception& ex)
    {
        cout << ex.what() << endl;
        return false;
    }
}

int main()
{
    cout << TestList() << endl;
    cout << TestSet() << endl;
    
}