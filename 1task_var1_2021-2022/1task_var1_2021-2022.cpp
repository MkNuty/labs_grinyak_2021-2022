#include<iostream>

using namespace std;

enum kvadrant {FIRST = 1, SECOND = 2, THIRD = 3, FOURTH = 4};

struct vector
{
    int x, y;
};

vector math_func(vector first_vector, vector second_vector, char operation)
{
    while ((operation != '+') && (operation != '-'))
        {
            cout << "Please re-enter operation: ";
            cin >> operation;
        }
    vector res;
    if (operation == '+')
    {
        res.x = first_vector.x + second_vector.x;
        res.y = first_vector.y + second_vector.y;
    }

    if (operation == '-')
    {
        res.x = first_vector.x - second_vector.x;
        res.y = first_vector.y - second_vector.y;
    }
    return res;
};

void vector_form_output(vector printing_vector)
{
    cout << "Result vector coordinates: " << "<" << printing_vector.x << "; " << printing_vector.y << ">" << endl;
};

void which_kvad(vector res_vec)
{
    kvadrant kvad;
    if (res_vec.x > 0 and res_vec.y > 0) kvad =FIRST;
    if (res_vec.x < 0 and res_vec.y > 0) kvad =SECOND;
    if (res_vec.x < 0 and res_vec.y < 0) kvad =THIRD;
    if (res_vec.x > 0 and res_vec.y < 0) kvad =FOURTH;
    
    cout << "Resulting vector in " << kvad << " kvadrant" << endl;
};

int main()
{
    char operation, choosen_vector;
    vector a, b, resulting_vector;
    cout << "Enter coordinates of 1 vector: ";
    cin >> a.x >> a.y;
    cout << "Enter coordinates of 2 vector: ";
    cin >> b.x >> b.y;
    cout << "Enter operation please(+/-): ";
    cin >> operation;

    resulting_vector = math_func(a,b,operation);

    vector_form_output(resulting_vector);
    
    which_kvad(resulting_vector);

    return 0;
}