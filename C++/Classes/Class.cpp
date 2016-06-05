/*
create a class, named Student, representing the student's details, as mentioned above, and store the data of a student. Create setter and getter functions for each element; that is, the class should at least have following functions:

    get_age, set_age
    get_first_name, set_first_name
    get_last_name, set_last_name
    get_standard, set_standard

Also, you have to create another method to_string() which returns the string consisting of the above elements, separated by a comma(,). You can refer to stringstream for this.
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Student{
    private:
        int age, standard;
        string first_name, last_name;
    public:
        void set_age(int& a){this->age = a;}
        void set_standard(int& a){this->standard = a;}
        void set_first_name(string& s){this->first_name = s;}
        void set_last_name(string& s){this->last_name = s;}
        int get_age(void)const {return this->age;} 
        int get_standard(void)const {return this->standard;}
        string get_first_name(void) const{return this->first_name;}
        string get_last_name(void){return this->last_name;}
        string to_string(void) {
            stringstream ss;
            ss << this->age << ','<< this->first_name << ','<< this->last_name<<','<< this->standard;
            return ss.str();
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
