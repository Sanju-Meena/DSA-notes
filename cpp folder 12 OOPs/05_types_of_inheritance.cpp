#include<iostream>
#include<string>
#include<vector>

using namespace std;

    // 1. Single Inheritance: A single child class inherits from one parent class.
    class Animal{
         public:
         void eat() { cout << "Eating..." << endl; }
        };
    class Dog : public Animal { };  
        
    // 2. Multilevel Inheritance: A class is derived from a class, which is also derived from another class.
    class A {
        public:
        void display() { cout << "Class A" << endl; }
    };
    class B : public A { };
    class C : public B { };
    
    // 3. Multiple Inheritance: One single child class inherits from more than one base/super class.
    class a {
        public:
        void show() { cout << "Class a" << endl; }
    };
    
    class b {
        public:
        void show() { cout << "Class b" << endl; }
    };
    
    class c : public b, public a {
    };
    
    // 4. Hierarchical Inheritance: Multiple classes inherit from a single base class.
    class animal {
        public:
        void eat() { cout << "Fighting..." << endl; }
    };
    class dog : public animal { };
    class cat : public animal { };
    
    // 5. Hybrid Inheritance: Combination of two or more than two types of inheritance.
    class Alpha { };
    class Beta : public Alpha { };
    class gamma : public Alpha { };
    class Delta : public Beta, public gamma { }; 
    /*
         A
         | 
      --------    
      |       |
      B       G
              |
              De
    1. B, G dono A se inherit kar rahe hain (Hierarchical):
    2. A->G->De multilevel inheritance;
    */

      int main(){
        //  ------Types of Inheritance in OOP:------
        // 1.Single Inheritance.
        cout<<endl;
        dog d;
        d.eat();
        cout<<endl;

        // 2. Multilevel Inheritance.
        // A-> B -> C -> D.. asie inheriate hoo rahi hai class;
        C ml;
        ml.display();
        cout<<endl;
        
        // 3. Multiple Inheritance.  
        // yadi super class mai same function hai too aise call kaise kr sakte hai;
        c mp;
        // inheritance ambiguity;
        mp.a::show();
        mp.b::show();
        cout<<endl;
        
        //   4.Hierarchical Inheritance.
        dog d1;
        d1.eat();
        cat c1;
        c1.eat();
        cout<<endl;

        // 5. Hybrid Inheritance.
        // hum main function k ander bhi class bana sakte hai but some restriction like you do not inherited that class and not accessible outside main class
        //  and static member not allowed; 

      }