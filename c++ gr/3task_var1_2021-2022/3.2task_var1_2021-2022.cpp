#include<iostream>

using namespace std;

class drob
{
private:
    int chisl, znam;
public:
    drob()
    {
        chisl = 0;
        znam = 1;
    };
    drob(int chislit, int znamen)
    {
        if (znamen != 0) 
        {
            chisl =chislit;
            znam = znamen;
        };
    };
    drob(int integer)
    {
        chisl = integer;
        znam = 1;
    };
    operator string()
    {
        string tmp;
        tmp = chisl + '/' + znam;
        return tmp;
    };

    operator double()
    {
        return (double)chisl/znam;
    };
    void info()
    {
        cout << (string)*this;
    };
};



int main()
{
    drob d1;
    drob d2(1, 2);
    drob d3 = 5;
    double x = d2;
    cout << d1;
    cout << endl;
    d2.info();
    cout << endl;
    d3.info();
    cout << endl;
    cout << x;
    cout << endl;
    return 0;
}