#include<iostream>

using namespace std;


class Animal{
    
};

class Dog:public Animal{
public:
    Dog(){

    }   
    void run(){
        cout << "running!" << endl;
    }
};


int main(){
    Animal* A = new Dog;

    A->run();

    return 0;
}