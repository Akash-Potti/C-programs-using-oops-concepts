#include <iostream>
#include <string>
using namespace std;

class Student
{
protected:
    string name;
    string rollno;

public:
    void read()
    {
        cout << "enter the name of the student: ";
        cin >> name;

        cout << "enter roll number: ";
        cin >> rollno;
    }

    void display()
    {
        cout << "Student name: " << name << endl;
        cout << "Roll number: " << rollno << endl;
    }
};

class Marks : public Student
{
private:
    int mark1, mark2, mark3;

public:
    void read_marks()
    {
        cout << "enter marks 1";
        cin >> mark1;

        cout << "enter marks 2";
        cin >> mark2;

        cout << "enter marks 3";
        cin >> mark3;
    }
    int calculatemarks()
    {
        return mark1 + mark2 + mark3;
    }

    float calculatepercentage()
    {
        return calculatemarks() / 3.0;
    }
    void dislplay_marks()
    {
        display();
        cout << "Marks in subject 1" << mark1 << endl;
        cout << "Marks in subject 2" << mark2 << endl;
        cout << "Marks in subject 3" << mark3 << endl;
        cout << "Total Marks" << calculatemarks() << endl;
        cout << "Percentage" << calculatepercentage() << endl;
    }
};

int main()
{
    Marks Student_obj;

    Student_obj.read();
    Student_obj.read_marks();

    cout << "Student Details" << endl;
    Student_obj.dislplay_marks();
    return 0;
}