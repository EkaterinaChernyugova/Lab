#include  "TestGoods.h"

//���� ��� �������� ������ � �������� �� ���������� �����
bool TestText(Goods x, Goods y)
{
    cout << "\nTEST: Operators << and >> (Text)\n" << "--------------------------" << endl;
    fstream fs;
    fs.open("myFile.txt", fstream::in | fstream::out | fstream::app);
    if (!fs.is_open())
    {
        cout << "File open error" << endl;
        return false;
    }
    else
    {
        fs >> y;
        fs << x;
    }
    fs.close();
    if (strcmp(x.getName(), y.getName()) == 0 && strcmp(x.getDate(), y.getDate()) == 0 && x.getPrice() == y.getPrice() && x.getNumber() == y.getNumber())
    {
        return true;
    }
    else return false;
}

//���� ��� �������� ������ � �������� �� ��������� �����
bool TestBinary(Goods x, Goods y)
{
    cout << "\nTEST: Operators << and >> (Binary)\n" << "--------------------------" << endl;
    
    x.write();
    y.read();
    return true;
}
