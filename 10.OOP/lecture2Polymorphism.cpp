#include<iostream>
using namespace std;

// Compile Time PolyMorphism(Static)==>>2 Type==> (i) , (ii)
// ii)Function Overloading
class A {

    public:
    void sayHello() {
        cout << "Hello Love Babbar" << endl;
    }
    
    int sayHello(char name) {
        cout << "Hello Love Babbar" << endl;
        return 1;
    }

    void sayHello(string name) {
        cout << "Hello " << name  << endl;
    }

};

// i) Operator Overloading
class B {
    public:
    int a;
    int b;

    public: 
    int add() {
        return a+b;
    }

    void operator+ (B &obj) {
/*        int value1 = this -> a;
        int value2 = obj.a;
        cout << "output " << value2 - value1 << endl; 
        */
       cout << "Hello Babbar" << endl;
    }

    void operator() () {
        cout << "main Bracket hu " << this->a << endl;
    }

};

// Run Time Polymorphism ( Dynamic )
// Function Overriding
class Animal {
    public:
    void speak() {
        cout << "Speaking "<< endl;
    }
};

class Dog: public Animal {

    public:
    void speak() {
        cout << "Barking " << endl;
    }


};



int main() {

// Run Time Polymorphism ( Dynamic )
// Function Overriding
    Dog obj;
    obj.speak();


// Compile Time PolyMorphism(Static)
// i) Operator Overloading
/*
    B obj1, obj2;

    obj1.a = 4;
    obj2.a = 7;

    obj1 + obj2;
    obj1();
*/

/*
// ii)Function Overloading
    A obj;
    obj.sayHello();
*/
    return 0;
}