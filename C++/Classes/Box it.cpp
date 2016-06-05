#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int BoxesCreated,BoxesDestroyed;

/*
Design a class named Box whose dimensions are integers and private to the class. The dimensions are labeled: length l, breadth b, and height h.

The default constructor of the class should initialize l, b, and h to 0.

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's l,b and h to length, breadth and height.

The copy constructor Box((Box BB) should set l,b and h to B's l,b and h, respectively.

Every constructor should increment the global variable BoxesCreated.
The destructor should increment the global variable BoxesDestroyed.

Apart from the constructor and destructor, the class should have 4 functions:
    int getLength() - Return box's length
    int getBreadth() - Return box's breadth
    int getHeight() - Return box's height
    long long CalculateVolume() - Return the volume of the box

Overload the operator << for the class Box. 
Box A << Box B if:
    A.l < B.l
    A.b < B.b and A.l==B.l
    A.h < B.h and A.b==B.b and A.l==B.l

Overload operator << for the class Box().
If B is an object of class Box:
cout<<B should print B.l, B.b and B.h on a single line separated by spaces.
*/

class Box{
    private:
        int l, b, h;
    public:
        Box():l(0),b(0),h(0){++BoxesCreated;}
        Box(int length, int breadth, int height):l(length),b(breadth),h(height){++BoxesCreated;}
        Box(Box& B){this->l = B.getLength(); this->b = B.getBreadth(); this->h = B.getHeight(); ++BoxesCreated;}
        ~Box(){++BoxesDestroyed;}
    
        int getLength() const {return this->l;} // Return box's length
        int getBreadth() const {return this->b;} // Return box's breadth
        int getHeight() const {return this->h;}  //Return box's height
        // Return the volume of the box
        long long CalculateVolume() const {
			return static_cast<long long>(this->l) * this->b * this->h;
		} 
        //Overload operator < as specified
        bool operator<(const Box &b) const{
            if (this->l < b.l)
                return true;
            else if (this->l == b.l){
                 if (this->b < b.b)
                     return true;
                else if (this->b == b.b){
                    if (this->h < b.h)
                        return true;
                }
            }
            return false;
        }    
};

//Overload operator << as specified
ostream& operator<<(ostream& out, const Box B){
    out << B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
}

void check2()
{
int n;
cin>>n;
Box temp;
for(int i=0;i<n;i++)
    {
    int type;
    cin>>type;
    if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
        }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }

    }
}

int main(){
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
	return 0;
}
