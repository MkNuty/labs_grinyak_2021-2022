#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class thing
{
    public:
    thing(){};
        int data;
        thing(int a){data = a;}
        int get(){return data;}
        thing operator=(int dd)
            {
                data = dd;
            };
        void operator>> (int p)
        {
            data = p;
        };

        thing operator=(thing c)
        {
            data = c.data;
        }
};

thing operator+ (thing first, thing second)
{
    thing result;
    result.data = first.data + second.data;
    return result;
};

ostream& operator << (ostream& stream, thing& object)
{
    stream << object.data;
};

istream& operator >> (istream& stream, thing& object)
{
    stream >> object.data;
};

bool operator != (thing fd, int smth)
{
    if (fd.data == smth) return 0; else return 1;
};

bool operator == (thing fd, int smth)
{
    if (fd.data == smth) return 1; else return 0;
};

bool operator> (thing x, thing y)
{   
    if(x.get() > y.get()) return 1; else return 0;
};

template <class T>

class test
{
    private:
        int lenght;
        T *datas;
    public:
        test(){cout << "Enter count of array elements: "; cin >> lenght;}
        
        void info()
        {
            cout << "Elements of array: ";
            for (int i = 0; i < lenght; i++)
            {
                cout << datas[i] << " ";
            };
            cout << endl;
        };

        void rand_fill_in()
        {
            int var;
            cout << "Enter the limit of random value: ";
            cin >> var;
            var++;
            for (int i = 0; i < lenght; i++)
            {
                datas[i] = random()%var;
            };
        };

        test add(test array)
        {
            int index;
            cout << "Enter element index to start: ";
            cin >> index;
            if ((index >= 0) && (index < lenght))
            {
                for (int i = index; i < lenght; i++)
                {
                    if (datas[i] != 0)
                    {
                        cout << "You must delete " << i << " element first\n";
                    };

                    if (datas[i] == 0)
                    {
                        cout << "Enter element " << i << ": ";
                        cin >> datas[i];
                    };  
                };
            };
            return array;
        };

        void remove_with_select(int t)
        {
            T summ;
            for (size_t i = 0; i < lenght; i++)
            {
                summ = summ + datas[i];
            }
            if (summ > 0) datas[t] = NULL;else cout << "\n\tError - array is empty\n";
        };

        void remove()
        {
            for (int i = 0; i < lenght; i++)
            {
                datas[i] = NULL;
            };
        }

        void array_maker()
        {
            datas = new T[lenght];
        };

        void array_del()
        {
            delete[] datas;
        };

        void sorting()
        {
            bool checker;
            T tmp;
            while(!checker)
            {
                if (lenght > 1)
                {    
                    for (size_t j = 0; j < lenght-2; j++)
                    {
                        for(int i = 0; i < lenght-1; i++)
                        {
                            if(datas[i] > datas[i+1])
                            {
                                tmp = datas[i];
                                datas[i] = datas[i+1];
                                datas[i+1] = tmp;
                            }
                        };
                    }
                    checker = true;
                }else checker = true;
            };
        };
};

int main()
{
    test<thing> test_int;
    test_int.array_maker();
    test_int.rand_fill_in();
    test_int.info();
    test_int.add(test_int);
    test_int.sorting();
    test_int.info();
    test_int.remove();
    test_int.info();
    test_int.array_del();
    return 0;
}