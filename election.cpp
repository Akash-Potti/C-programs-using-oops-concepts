#include <iostream>
using namespace std;
class election
{
    char name[20];
    int vote;

public:
    void get();
    float vote_percentage();
    static election winner(election e[], int candidate);
    void display();
    static int total_votes;
};

int election::total_votes;
void election::get()
{
    cout << "Enter the name of the candidate: ";
    cin >> name;
    cout << "Enter the number of votes: ";
    cin >> vote;
    total_votes += vote;
}

float election::vote_percentage()
{
    float percent;
    percent = (float)vote / total_votes * 100;
    return percent;
}

election election::winner(election e[], int candidate)
{
    int max = 0;
    int windex = 0;

    for (int i = 0; i < candidate; i++)
    {
        if (e[i].vote > max)
        {
            max = e[i].vote;
            windex = i;
        }
    }
    return e[windex];
}

void election::display()
{
    float percent = vote_percentage();
    cout << "Candidate: " << name << endl;
    cout << "Number of votes: " << vote << endl;
    cout << "Percemtage of vote recieved is " << percent << endl;
}

int main() 
{
    int candidate;
    cout << "Enter the number of candidates: ";
    cin >> candidate;

    election *e = new election[candidate];

    for (int i = 0; i < candidate; i++)
    {
        e[i].get();
    }

    for (int i = 0; i < candidate; i++)
    {
        e[i].display();
    }

    cout << "The winner is ";
    election winner = election::winner(e, candidate);
    winner.display();

    delete[] e;

    return 0;
}