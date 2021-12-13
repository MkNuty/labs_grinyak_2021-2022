#include <iostream>

using namespace std;

class geometric_object
{
    public:
        string name;
        int s, p;
        virtual int S() = 0;
        virtual int P() = 0;
        virtual string get_name(){return name = "Name";}

        void info()
        {
            cout << "It is a " << name << endl;
            cout << "S = " << s << endl;
            cout << "P = " << p << endl;
        };

        virtual void info_plus(){}
};

class triangle: public geometric_object
{
    public:
    int l1, l2, l3;
        virtual string get_name(){return name = "Triangle";}
        int S(){return s=1;}
        int P(){return p=l1+l2+l3;}
        triangle(){cin >> l1; cin >> l2; cin >> l3;};
        virtual void info_plus(){cout << "Sides lenght is\nFirst side\t" << l1 << "\nSeond side\t" << l2 << "\nThird side\t" << l3 << endl;}
};

class square: public geometric_object
{
    public:
    int l1, l2;
        virtual string get_name(){return name = "Square";}
        int S(){return s=l1*l2;}
        int P(){return p=2*(l1+l2);}
        square(){cout << "Enter lenght of sides:\t"; cin >> l1; cin >> l2;};
        virtual void info_plus(){cout << "Sides lenght is\nFirst side\t" << l1 << "Seond side\t" << l2 << endl;}
};

class circle: public geometric_object
{
    public:
    int r;
        virtual string get_name(){return name = "Circle";}
        int S(){return s=2*3.14*r;}
        int P(){return p=3.14*3.14*r;}
        circle(){cout << "Enter r:\t"; cin >> r;};
        virtual void info_plus(){cout << "Radius = " << r << endl;}
};

int main()
{
    triangle a;
    system("clear");
    a.info_plus();
    a.S();
    a.P();
    a.get_name();
    a.info();

    return 0;
}