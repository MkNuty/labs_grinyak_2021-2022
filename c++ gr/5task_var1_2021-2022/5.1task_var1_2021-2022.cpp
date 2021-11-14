#include <iostream>

using namespace std;
template <typename T>

bool search(T constant, T *array_of_smth)
{
    bool tmp = 0;
    for (int i = 0; i < 8; i++)
    {
        if (constant == array_of_smth[i])
        {
            tmp = 1;
            break;
        };
    };
    return tmp;
};

class integer
{
    public:
        int test;
        integer(){}

        void randmize()
        {
            test = random()%8;
        };

        void enter()
        {
            cin >> test;
        };

        void info()
        {
            cout << test << endl;
        };
};

bool operator==(integer y, integer int1)
    {
        if (int1.test == y.test) return 1;
        else return 0;
    };

int main()
{
    bool tmp;
    integer array[8];
    for (int i = 0; i < 8; i++)
    {
        array[i].randmize();
        array[i].info();
    };
    integer constant_value;
    cout << "Enter the value for the compare: ";
    constant_value.enter();
    tmp = search(constant_value, array);
    cout << tmp << endl;

    return 0;
}