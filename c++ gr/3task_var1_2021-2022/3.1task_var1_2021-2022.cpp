#include<iostream>

using namespace std;

class integer_array
{
    public:
    int array[100];
    int size;
    void info()
    {
        
        for ( int i = 0; i < size; i++)
        {
            cout << array[i];
            if (i < size-1) cout << ", ";
        }
        cout << ";";
    };
    integer_array(int size_of)
    {
        size = size_of;
    };
    integer_array()
    {

    };
};

integer_array operator+(integer_array array1, integer_array array2)
{
    integer_array array3;
    int i;
    for (i = 0; i < array1.size; i++) 
    {
        array3.array[i] = array1.array[i];
    };
    for (i = 0; i < array2.size; i++)
    {
        array3.array[array1.size+i] = array2.array[i];
    };
    array3.size = array1.size + array2.size;
    return array3;
};

bool operator%(integer_array array, int tmp)
{
    bool t = false;
    int i;
    for (i = 0; i < array.size; i++)
    {
        if (tmp == array.array[i])
        {
            t = true;
            break;
        };
    }
    return t; 
};

int main()
{
    char chooser, tmp_data;
    int size_of1, size_of2, i, tmp;
    cout << "Enter size of 1 array: ";
    cin >> size_of1;
    integer_array first_array(size_of1);
    cout << "Enter size of 2 array: ";
    cin >> size_of2;
    integer_array second_array(size_of2);
    while (chooser != 'q')
    {
        cout << "Enter datas of 1 array - 1\n";
        cout << "Enter datas of 2 array - 2\n";
        cout << "Quit - q\n";
        cout << "Choose option:\t";
        cin >> chooser;
        switch (chooser)
        {
        case 'q': break;
        
        case '1':
            cout << "Enter data - e\n";
            cout << "Remove data - r\n";
            cout << "Choose option:\t";
            cin >> chooser;
            switch (chooser)
            {
            case 'e':
                cout << "Enter q for Quit or enter datas: \t";
                for (i = 0; i < size_of1; i++)
                {
                    cin >> tmp_data;
                    if (tmp_data == 'q') break;
                    first_array.array[i] = tmp_data-'0';
                };
                break;
            case 'r':
                while (tmp_data != 'q')
                {
                    cout << "Enter q for Quit or enter enter index of removing element: \t";
                    cin >> tmp_data;
                    if (tmp_data != 'q')
                    {
                        for (i = tmp_data-1; i < size_of1-1; i++)
                        {
                            first_array.array[i] = first_array.array[i+1];
                        };
                        first_array.size--;
                    };
                };
                break;
            }
            break;
        case '2':
            cout << "Enter data - e\n";
            cout << "Remove data - r\n";
            cout << "Choose option:\t";
            cin >> chooser;
            switch (chooser)
            {
            case 'e':
                cout << "Enter q for Quit or enter datas: \t";
                for (i = 0; i < size_of2; i++)
                {
                    cin >> tmp_data;
                    if (tmp_data == 'q') break;
                    second_array.array[i] = tmp_data-'0';
                };
                break;
            case 'r':
                while (tmp_data != 'q')
                {
                    cout << "Enter q for Quit or enter enter index of removing element: \t";
                    cin >> tmp_data;
                    if (tmp_data != 'q')
                    {
                        for (i = tmp_data-1; i < size_of2-1; i++)
                        {
                            second_array.array[i] = second_array.array[i+1];
                        };
                        second_array.size--;
                    };
                };
                break;
            }
            break;
        }
    };
    integer_array tmp_array(size_of1+size_of2);
    first_array.info();
    cout << endl;
    second_array.info();
    cout << endl;
    tmp_array = first_array + second_array;
    for (i = 0; i < tmp_array.size; i++)
    {
        cout << tmp_array.array[i] << " ";
    };
    cout << endl;
    cout << "Enter number:\t";
    cin >> tmp;
    cout << endl;
    cout << first_array % tmp;
    cout << endl;
    cout << second_array %tmp;
    cout << endl;
    return 0;
}