#include<iostream>
#include<string>
#include<vector>

using namespace std;
class A{
    public:
    void sayhello(){
        cout<<"Hello\n";
    }
    int sayhello(char no){
        int nm = 7;
        cout<<"Hello\n";
        return nm;  
    }

    int sayhello(char no,int n = 9){
        int nm = 7;
        cout<<"Hello\n";
        return nm;  
    }
    // Not valid bcz function having same name but different return type cannot be overloaded;
    // It is valid only when we have different no. of input parameter ;
    void sayhello(int number){
        cout<<"Hello love babbar\n";
    } 
};

class sum {
    public :
    int a,b;
    // int add(){
    //     return a+b ;
    // }

    // Syntex: return_type operator 'sign' (input argument) and b is input argument;
    // If input argument is a+b then 'a' assign by this pointer(called current object)
    void operator + (sum &obj){  //obj = ob2 hai bcz ob1 + ob2 hai input;
        // '+' operator ko overload kiya gaya hai;
        // obj wo doosra object hai jiske saath aap operation perform kar rahe ho;
        int s1 = this-> a;
        int s2 = obj.a;
        cout<<"Output is "<<s1-s2<<endl;
    }

    void operator () (){  
        int s1 = this-> b;
        cout<<"Output is "<<s1<<endl;
    }
};

class animal{
    public:
    void speak(){
        cout<<"speaking\n";             
    }
};
class dog:public animal{
    public:
    void speak(){
        cout<<"barking\n";
    }
};

int main(){
    /*Polymorphism--------
    difination: Existing in multiple forms then we call it polymorphism happen;
    Types are: 
    1. Compile time polymorphism/static polymorphism: we know at the time of compile that kon kon se chij kitne form mai exist kr rhi hoti hai;
       (i) Function overloading: when there are multiple functions in a class with the same name but different parameters, these functions are overloaded;
       (ii)Operator overloading/dynamic polymorphism;: it allows you to redefine the way operators work for user-defined types (classes and objects).
    2. Run time polymorphism: 
    // it depend on inheritance polymorphism;
 
    */
    A obj;
    obj.sayhello();
    obj.sayhello();

    sum ob1,ob2;
    ob1.a = 10;
    ob1.b = 5;
    ob2.b = 8;
    ob2.a = 7;

    ob1 + ob2; //ob1 is current object and ob2 is input argument; // a+b has two operand a, b ; 
    /*
    Jab ob1 + ob2; call hota hai:
    ob1 → this ban jata hai
    ob2 → obj ke roop mein function mein jata hai
    */
   ob2();

//    function overriding;
   animal a1;
   dog d1;
   d1.speak();
// It is used when we have 10 function that we inherited from parent class and we can change 2 work that we inherited then
// function overriding concept is workig;

/*Abstraction---------
difination: 
// it is used we try to do implementation hiding; 

*/
}