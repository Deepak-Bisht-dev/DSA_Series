#include<bits/stdc++.h>
using namespace std;

/*  IMPT. W.R.T INTERVIEW:
  - In case you make an empty class Then it allocates 1 size of m/m
  - this -> keyword refers to the current object
  - Shallow copy is like creating two objects by using copy constructor and when we do any changes in object 1 then it also reflects to object 2 as we r refrencing to same m/m or array
  - Default copy does shallow copy  
  - But in DEEP COPY make another copy so the changes in object 1 will not be reflected in object 2 as another arrray or m/m is created in DEEP COPY
  - For manually created constructor/ dynamic m/m allocation we'll have to call destructor manually
*/
class Hero{

    int health;
    public:
    char level ;
   
    void print(){
        cout << level << endl;
    }

    // getters and setters r used for putting values into class as members inside class r private by default
    int getHealth(){
        return health;
    }
    
    char getLevel(){
        return level;
    }

    void setHealth(int h){
        health = h;
    }

    void setLevel(char ch){
        level = ch;
    }

};

int main(){


    /*
    //static allocation
    Hero a;
    a.setHealth(70);
    a.setLevel('A');
    cout << "Level is: " << a.level << endl;
    cout << "Health is: "<< a.getHealth() << endl;

    //dynamic allocation
    Hero *b = new Hero;
    b -> setLevel('B');
    b -> setHealth(80);
    cout << "Level is: " << (*b).level << endl;
    cout << "Health is: " << (*b).getHealth() << endl;  
    
    // OR we can use -> 

    cout << "Level is: " << b -> level << endl;
    cout << "Health is: " << b -> getHealth() << endl;  
    */

    // cout << "Size of Ramesh is: " << sizeof(Ramesh) << endl;
    // Ramesh.setHealth(70);
    // Ramesh.setLevel('B');

    // cout << "Health is: " << Ramesh.getHealth() << endl;
    // cout << "Level is: " << Ramesh.getLevel() << endl;

    return 0;
}