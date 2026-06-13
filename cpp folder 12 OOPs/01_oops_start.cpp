// Hw is study about padding and greedy alignment;
#include<iostream>
#include<string>
#include<vector>

#include"00_actor.cpp" 
using namespace std;

class Hero{
    // it's properties;
    public:
    char name[100];
    string film;
    int health = 10;
    double level;
    
    private:
    char rating;
    int money = 50;
    string popularity;
    // if we use private modifier than we can use this modifier in any function with the help of set and get function;
    // getter/setter concept;
    public :
    int gethealth(){return health;}
    char getrating(){return rating; }
    int getmoney(){return money ;}
    string getpopularity(){return popularity;}
    
    void setrating(char r){rating = r;}
    void sethealth(int r){health = r;}
    void setmoney(int m){money = m;}
    void setpopularity(string popu,string famous){
        if(famous == "amitab"){popularity = "low";}
        else{popularity = "high"; }
    }
};

int main(){
    // OOPs is a type of programming in which we can write the code with the help of object and class so that it is more connected with real world entity;
    // by the help of opps, we can increase the readiability, managebility of our program and is more relatable/close to real world.
    //  class is a user defined datatype, it is just like a blueprint that help to create object;  
    /*
     1. object is a instance of class(means object is created with the help of class).
     and object has it's own behaiviour(attack for hero) and some property(like health etc) having example hero;
    */
    Actor a1;//hum issi file mai duseri file k class ki templete bana kr use kr sakte hai by adding #include"file name";
    
    //How to make object of hero type by static allocation.
    Hero srk; //isse likhne se srk ko memory allot kr di jitni property hai hero ka naam;
    cout<<"size of class: "<<sizeof(srk)<<endl; 
    //padding tb hoti hai jb hamne class mai more than one type of datatype banaye hoo;
    //padding mai kuch space jayada lagti hai isliye actual size se thodi jayada size he aati hai object ki.
    // empty class k case mai object ko 1 byte memory allot hoti hai;
    
    // srk.name = {"sharuk khan"}; ye work nahi karta hai ismai;
    strcpy(srk.name , "sharuk khan");
    srk.film = "chennai express";
    // srk.health = 50; //ab is line se koi change nhi aayega bcz niche vali line mai hamne health ko set kr diya hai;
    srk.sethealth(70);
    srk.level = 45.45;
    // data member koo hum access kr sakte hai using dot operator;
    cout<<"srk name is "<<srk.name<<endl;
    cout<<"srk famous film is "<<srk.film<<endl;
    cout<<"health is :"<<srk.health<<endl;
    cout<<"health is :"<<srk.gethealth()<<endl;
    cout<<"level is :"<<srk.level<<endl;
    cout<<"level is :"<<srk.getmoney()<<endl;

    /*  ACCESS MODIFIERS
        1. It means hum class k behaiviour or property define karte hai or unhai kaha kaha use karte hai that depend on access modefier;
        2. It is of 3 type:
        (i)   Public : datamember ko class k ander or bahar dono gajah access kr sakte hoo;
        (ii)  Private : datamember ko class k ander he only access kr sakte hoo;
        (iii) Protected : baad mai samjenge;

        2. Bydefault access modefier private vala mana jata hai or unhe hum class k ander he access kr sakte hai directly;
    */ 

   cout<<"srk rating is = "<<srk.getrating()<<endl;
   srk.setrating('A');
   cout<<"srk rating is = "<<srk.getrating()<<endl;
   
    srk.setmoney(100000);
    cout<<"srk have money = "<<srk.getmoney()<<endl;

    srk.setpopularity("high","amitab");
    cout<<"srk popularity is "<<srk.getpopularity() <<endl;

    srk.setpopularity("high","akshay");
    cout<<"srk popularity is "<<srk.getpopularity() <<endl;

    // /*
    // Create a variable dynamically;
    int *n = new int ;
    
    // Now create an object dynamically;
    Hero *b = new Hero; //Ye hamne dynamically object create kr liya, iska name hamne rakha hai *b;
    // b is a pointer and *b is a object, of type hero.
    cout<<"size of "<<sizeof(*b)<<endl;
    (*b).health = 34;
    cout<<"health is "<<(*b).health<<endl;
    (*b).level = 100.08;
    cout<<"level is "<<(*b).level<<endl;
    (*b).setrating('C');
    cout<<"rating is "<<b->getrating()<<endl;
    // */
    
}