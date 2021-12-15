#include <iostream>
#include <queue>

using namespace std;

enum
{
    zero = 0,
    first = 1,
    second = 2
};

class PIQ
{
    private:
        string name; //name of person
        int PL; //priority lvl
    public:
        PIQ()
        {
            name = "name";
            PL = zero;
        };

        PIQ(string n, int pl)
        {
            name = n;
            PL = pl;
        };

        void info() const
        {
            cout << name << endl;
        };

        void priority_info() const
        {
            info();
            cout << PL;
        };

        bool operator< (int q) const
        {
            return PL < q;
        };

        bool operator< (PIQ q) const
        {
            return PL < q.PL;
        };
};

int main()
{

    queue<PIQ> QUEUE;
    queue<PIQ> QUEUE1;
    priority_queue<PIQ> FQUEUE;
    priority_queue<PIQ> SQUEUE;

    QUEUE.push(PIQ("first", 0));
    QUEUE.push(PIQ("second", 0));
    QUEUE.push(PIQ("third", 1));
    QUEUE.push(PIQ("fourth", 0));
    QUEUE.push(PIQ("fiveth", 2));

    while (!QUEUE.empty())
    {
        switch (QUEUE.front() < 1)
        {
        case true:
            QUEUE1.push(QUEUE.front());
            QUEUE.pop();
            break;
        case false:
            if (QUEUE.front() < 2) 
            {
                FQUEUE.push(QUEUE.front());
                QUEUE.pop();
            }else 
                {
                    SQUEUE.push(QUEUE.front());
                    QUEUE.pop();
                }
        }
    }

    while (!QUEUE1.empty())
    {
        QUEUE1.front().info();
        QUEUE1.pop();
    }
    
    while (!FQUEUE.empty())
    {
        FQUEUE.top().info();
        FQUEUE.pop();
    }

    while (!SQUEUE.empty())
    {
        SQUEUE.top().info();
        SQUEUE.pop();
    }
    
    return 0;
}