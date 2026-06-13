#include<iostream>
#include<string>
#include<vector>
using namespace std;
//hame class k ander heap mai memory allot karani hai too constructor k ander karane hoti hai; 
class hero{
    public:
    char rating;
    char *name   ;
    int health;
    // Static keyword : it belong to class and we acces this keyword without creating object also and we inilize outside class like
    // datatype hero::timetocomplete = datatype value;.
    static string timetocomplete ;

    // Static function;
    // it also belong to class we can access this function anywhere;
    // This function can access only static member;
    static int sum(){
        cout<<"The only keyword having value in this file is "<<hero::timetocomplete<<endl;
    }
    
    private:
    int level ;

    public:
    int getlevel(){return level;}
    void setlevel(int l){
        level = l;
    }
    
    void setname(char name[]){
       strcpy(this->name,name);
    }
    // simple constructor; 
    hero(){
        name = new char[100];
        cout<<"Constructor bn gaya.\n";
    }
    
    // print karvane k liye parameter ko;
    void print(){
        cout<<"Name "<<(*this).name<<", ";
        cout<<"Health :"<<(*this).health<<", ";
        cout<<"Rating :"<<(*this).rating<<", ";
        cout<<"Level :"<<(*this).getlevel()<<endl;
        
    }
    
    // copy constructor;
    hero(hero &temp){
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch,temp.name);
        this->name = ch;
        (*this). health = temp.health+1;
        this-> rating = temp.rating+2;
        this-> level = temp.level;
    }

    // Destructor;
    ~hero(){
        cout<<"Destructor called\n";
    }
};
string hero::timetocomplete = "100ms";
// :: ->scope resolution operator;
int main(){
    cout<<hero::timetocomplete<<endl;
    // Deep copy;
    hero h1;
    cout<<h1.timetocomplete<<endl;
    h1.timetocomplete = "111 ms";
    cout<<h1.timetocomplete<<endl;
    cout<<hero::timetocomplete<<endl;
    hero::sum();

    h1.health = 45;
    h1.rating = 'A';
    h1.setlevel(75);
    char nam[15] = "Sanjay";
    h1.setname(nam);
    h1.print();

    hero h2(h1);
    h2.print();
    h1.name[0] = 'M';
    h1.health = 50;
    h1.print();
    h2.print();
    cout<<endl;
   
    // copy assignment operator '=';
    h1 = h2; //h2 k saare datatype h1 mai copy hoo jayenge;
    h1.print();
    h1.health ++;
    h2.print();

    // Destructor;
    // A destructor is a special function that automatically runs(for statically allocated object) when an object is destroyed(when it's scope is over),
    // it is used to free resources like memory, files, or connections.
    /* Destructor have some property like:
       1. Iska name class ka name he hota hai;
       2. Iska koi return type bhi nahi hota hai;
       3. Iske ander koi input parameter bhi nahi hote hai;
       4. iski pahechaan ~(telda) sign se hoti hai;
       5. ye default bna hua hota hai yadi hum na banaye too bhi;
    */

    hero a;
    // when we create an object dynamically then destructor only runs when we call manually;
    hero *b = new hero;
    delete b;
    // hw-> const keyword,how it use for object creation and member datatype, how to create const type function,instilization list kya hai;
    


}