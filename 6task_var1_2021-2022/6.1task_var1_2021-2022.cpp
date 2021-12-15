#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Human
{
    public:
        string name;
        string surname;
        int birth_date[3];

        Human(string name0, string surname0, int f, int s, int t)
        {
            name = name0;
            surname = surname0;
            birth_date[0] = f;
            birth_date[1] = s;
            birth_date[2] = t;
        }

        Human()
        {
            name = "f";
            surname = "k";
            birth_date[0] = 1;
            birth_date[1] = 2;
            birth_date[2] = 4;
        }

        int get_birth_year()
        {
            return birth_date[2];
        }

        void info() const
        {
            cout << name << " " << surname << " " << birth_date[0] << "." << birth_date[1] << "." << birth_date[2] << endl;
        }

        bool operator < (int b) const
        {
            if (birth_date[2] > b) return true; else return false;
        }
};

list<Human> getHuman(vector<Human> vector_of_Human, int year)
{
    list<Human> Humanlist;
    for (vector<Human>::iterator it = vector_of_Human.begin(); it != vector_of_Human.end(); it++)
    {
        if (it->birth_date[2] > year) Humanlist.push_back(*it);
    }
    
    return Humanlist;
};

int main()
{
    Human h1("ni", "gga", 1, 2, 3);
    Human h2("ni", "gger", 1, 2, 5);
    Human h3("ni", "ggas", 1, 2, 3);
    Human h4("nii", "gga", 1, 2, 3);
    Human h5("n", "word", 1, 2, 3);

    vector<Human> HumanVector;
    list<Human> Humanlist;

    HumanVector.push_back(h1);
    HumanVector.push_back(h2);
    HumanVector.push_back(h3);
    HumanVector.push_back(h4);
    HumanVector.push_back(h5);
    for (vector<Human>::iterator it = HumanVector.begin(); it != HumanVector.end(); it++)
    {
        it->info();
    };

    cout << "----------------" << "\n";

    Humanlist = getHuman(HumanVector, 3);

    for (list<Human>::iterator it = Humanlist.begin(); it != Humanlist.end(); it++)
    {
        it->info();
    }

    return 0;
}