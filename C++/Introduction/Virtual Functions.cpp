/*
Create three classes Person, Professor and Student. The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.

The class Professor should have two data members: publications and cur_{id}. There will be two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age and publications of the professor. The function putdata should print the name, age, publications and the cur_{id} of the professor.

The class Student should have two data members: marks, which is an array of size 66 and cur_{id}. It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age, and the marks of the student in 66 subjects. The function putdata should print the name, age, sum of the marks and the cur_{id} of the student.

For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 11.
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

static int total_prof = 0;
static int total_stud = 0;

class Person{
    private:
        string name;
        int age;
    public:
    virtual void getdata(void){
        cin >> name >> age;
        return;
    }
    virtual void putdata(void){
        cout << name << ' ' << age << ' ';
        return;
    }
};

class Professor: public Person{
    private:
        int publications;
        int id;
    public:
        Professor(){++total_prof; id = total_prof;}
        //~Professor(){--total_prof;}
        void getdata(void){
            Person::getdata();
            cin >> publications;
            return;
        }
        void putdata(void){
            Person::putdata();
            cout << publications << ' ' << id << endl;
            return;
        }
};

class Student: public Person{
    private:
        vector<int> marks;
        int id;
    public:
        Student(): marks(6,0){++total_stud; id = total_stud;}
        //~Student(){--total_stud;}
        void getdata(void){
            Person::getdata();
            for(int i = 0; i < 6; ++i)
                cin >> marks[i];
            return;
        }
        void putdata(void){
            Person::putdata();
            int sum = 0;
            for_each(marks.begin(), marks.end(), [&] (int n) {sum += n;});
            cout << sum << ' ' << id << endl;
            return;
        }
};

int main(){
    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){
        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
