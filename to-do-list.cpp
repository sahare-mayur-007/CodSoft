#include<Iostream>
#include<vector>
#include<string.h>

using namespace std;

struct Tsk 
{
    string name;
    bool completed;
};


void addTsk(vector<Tsk> & tsks) 
{
    Tsk tsk;
    cout << "Enter tsk name: ";
    cin >> tsk.name;
    tsk.completed = false;
    tsks.push_back(tsk);
    cout << "Tsk add successfully!" << endl;
}


void removeTsk(vector<Tsk> & tsks) 
{
    int tskNu;
    cout << "Enter tsk nu to remove: ";
    cin >> tskNu;

    if (tskNu > 0 && tskNu <= tsks.size()) 
    {
        tsks.erase(tsks.begin() + tskNu - 1);
        cout << "Tsk del successfuly!!" << endl;
    } 
    else 
    {
        cout << "Invald tsk nu!!" << endl;
    }
}


void mrkTskComp(vector<Tsk>& tsks) 
{
    int tskNu;
    cout << "Enter tsk nu to mrk as completed: ";
    cin >> tskNu;

    if (tskNu > 0 && tskNu <= tsks.size())
    {
        tsks[tskNu - 1].completed = true;
        cout << "Tsk mrked as comp!!" << endl;
    } 
    else 
    {
        cout << "Invald tsk nu!" << endl;
    }
}

void viewTsks(const vector<Tsk>& tsks) 
{
    for (size_t i = 0; i < tsks.size(); ++i) 
    {
        cout << i + 1 << ". Tsk: " << tsks[i].name << ", Status: " << (tsks[i].completed ? "Completed" : "Pend..") << endl;
    }
}

int main() 
{
    vector<Tsk> tsks;

    while (true) 
    {
        cout << "\n1. Add Tsk" << endl;
        cout << "2. View Tsks" << endl;
        cout << "3. Mrk Tsk as Completed" << endl;
        cout << "4. Remove Tsk" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) 
        {
            case 1:
                addTsk(tsks);
                break;
            case 2:
                viewTsks(tsks);
                break;
            case 3:
                mrkTskComp(tsks);
                break;
            case 4:
                removeTsk(tsks);
                break;
            case 5:
                return 0;
            default:
                cout << "Invald choice, try again" << endl;
        }
    }

    return 0;
}
