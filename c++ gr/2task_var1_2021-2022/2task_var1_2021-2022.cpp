#include<iostream>
#include<string>

using namespace std;

enum Operations
{
    e = 'e',
    o = 'o',
    q = 'q',
    out_all = '1',
    out_id = '2',
    initialize = 'i',
    yes = 'y',
    no = 'n'
};

class worker
{
    private:
        string name;
        int worked_time_at_all, payment_in_hour, worked_time, premi, payment, total;
    public:
        void info()
        {
            cout << "\nName of worker:\t" << name << "\nWorked time in years:\t" << worked_time_at_all << "\nPayment in hour:\t" << payment_in_hour << "\nWorked time in hours:\t" << worked_time << endl;
        };

        worker filling(int worker_id)
        {
            worker tmp;
            string name2;
            cout << "Enter the name of " << worker_id << " worker\t";
            cin >> tmp.name;
            cin >> name2;
            tmp.name = tmp.name + " " + name2;
            cout << "Enter the worked time in years of " << worker_id << " worker\t";
            cin >> tmp.worked_time_at_all;
            cout << "Enter the payment in hour of " << worker_id << " worker\t";
            cin >> tmp.payment_in_hour;
            cout << "Enter the worked time in hours of " << worker_id << " worker\t";
            cin >> tmp.worked_time;
            return tmp;
        };
        
        worker(string name, int worked_time_at_all, int payment_in_hour, int worked_time)
        {
            name = name;
            worked_time_at_all = worked_time_at_all;
            payment_in_hour = payment_in_hour;
            worked_time = worked_time;
        };

        worker()
        {
            name = " ";
            worked_time_at_all = 0;
            payment_in_hour = 0;
            worked_time = 0;
        };

        void count()
        {
            payment = payment_in_hour*worked_time;
            if (worked_time > 1)
            {
                if (worked_time >= 5) premi = payment*0.18;
                if (worked_time < 5)
                {
                    if (worked_time > 3) premi = payment*0.08;
                        else premi = worked_time*0.05;
                };
            }else premi = 0;
            total = premi + payment;
        };

        void out_payment_inf()
        {
            cout << "Payment for " << name << " " << payment << " rub\n";
            cout << "Premi for " << name << " " << premi << " rub\n";
            cout << "Total payment for " << name << " " << total << " rub\n\n";
        };
};

void quit()
{
    char any;
    cout << "Enter Q to escape\t";
    cin >> any;
    if(any = 'Q') system("clear");
};

int main()
{   
    string name, name2;
    int worked_time_at_all, payment_in_hour, worked_time;
    int id, tmp;
    Operations i;
    char selector;
    int worker_count;
    worker tmp_worker;
    system("clear");

    cout << "Enter count of workers:\t";
    cin >> worker_count;
    system("clear");
    worker *workers_list = new worker [worker_count];

    while (selector != no)
    {
        cout << "Do you whant to initialize data about all workers?\n(y/n)\t";
        cin >> selector;
        switch (selector)
        {
        case yes:
            system("clear");
            cout << "Enter initializing data\n";
            cout << "Enter name for initializing worker\t";
            cin >> name;
            cin >> name2;
            name = name + " " + name2;
            cout << "Enter worked time in years\t";
            cin >> worked_time_at_all;
            cout << "Enter payment in hour\t";
            cin >> payment_in_hour;
            cout << "Enter worked time in hours\t";
            cin >> worked_time;
            for (tmp = 0; tmp < worker_count; tmp++)
            {
                workers_list[tmp] = worker(name, worked_time_at_all, payment_in_hour, worked_time);
            }
            break;
        case no:
            break;
        }
        if (selector == no) break;
    };
    system("clear");
    
//entering data about workers
    while (selector != 'q')
    {
        cout << "\nChoose what you want to do:\n" << "Enter all workers data - e\n" << "Enter data of 1 of woker - o\n" << "Quit - q\n";
        cin >> selector;
        switch (selector)
        {
        case e:
            system("clear");
            for (tmp = 0; tmp < worker_count; tmp ++)
            {
                workers_list[tmp] = tmp_worker.filling(tmp+1);
                system("clear");
            };
            break;
        case o:
            system("clear");
            cout << "Enter id of the worker:\t";
            cin >> id;
            workers_list[id-1] = tmp_worker.filling(id);
            break;
        case q:
            break;
        }
        system("clear");
    };

    selector = 'p';

//output data about workers
    while (selector != 'q')
    {
        cout << "\nWhat you want to do:\n" << "Out all - 1\n" << "Out single worker - 2\n" << "Quit - q\n";
        cin >> selector;
        switch (selector)
        {
        case out_all:
            system("clear");
            for (tmp = 0; tmp < worker_count; tmp++)
            {
                workers_list[tmp].info();
            };
            quit();
            break;
        case out_id:
            system("clear");
            cout << "Enter id of worker:\t";
            cin >> tmp;
            workers_list[tmp-1].info();
            quit();
            break;
        case q:
            break;
        }
        system("clear");
    };

    for (tmp = 0; tmp < worker_count; tmp++)
    {
        workers_list[tmp].count();
    };

    selector = 'p';

//outing information about payment
    while (selector != 'q')
    {
        cout << "\nWhat you want to do:\n" << "Out all information about payment - 1\n" << "Out information about payment of single worker - 2\n" << "Quit - q\n";
        cin >> selector;
        switch (selector)
        {
        case out_all:
            system("clear");
            for (tmp = 0; tmp < worker_count; tmp++)
            {
                workers_list[tmp].out_payment_inf();
            };
            quit();
            break;
        case out_id:
            system("clear");
            cout << "Enter id of the worker:\t";
            cin >> tmp;
            workers_list[tmp-1].out_payment_inf();
            quit();
            break;
        case q:
            break;
        }
    };
    system("clear");
    delete[] workers_list;
    workers_list = 0;
    return 0;
}