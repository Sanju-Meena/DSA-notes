#include<iostream>
#include<string>
#include<vector>
using namespace std;

// class k ander cout use nhi kr sakte directly kisi constructor ya distructor k ander he use kr sakte hai;
class hero{
    public:
    char rating;
    // char name[100]; isse jitne bhi 
    char *name;//declare a pointer of type character or character array(string);
    int health;
    
    private:
    int level ;

    public:
    int getlevel(){return level;}
    void setlevel(int l){
        level = l;
    }

    int gethealth(){return health;}
    void sethealth(int l){
        health = l;
    }

    void setname(char  name[]){ //ye address le raha hai name ka yaha copy create nahi hoo rahi hai;
        strcpy(this->name, name); 
    }
   
    void print(){
        cout<<"Name "<<(*this).name<<", ";
        cout<<"Health :"<<(*this).health<<", ";
        cout<<"Rating :"<<(*this).rating<<", ";
        cout<<"Level :"<<(*this).getlevel()<<endl;
    }
    
    // simple constructor;
    hero(){
        name = new char[100];//Dynamically allocates 100 characters in heap memory and assigns the address of the first character to name.
        cout<<"Constructor bn gaya.\n";
    }

    // Parameterized constructor;
    hero(int health ){
       // This keyword is a pointer and it point on the address of current object(jis object ne call kiya hai constructor koo vo uska current object hai);
       this-> health = health; // current object ki templete health mai input health assign kr doo ye mtlb hota hai 31 line pr likhe code ka; 
       cout<<"Value of this is "<<this<<"."<<endl;
    }

    hero(int health,char rating,int level){
        (*this).health = health;
        this-> rating = rating;
        this-> level = level;
    }
};

int main(){
    // yadi aap object koo create kr rhe hote hai too sabse pahele constructor call hoti hai;
    // A constructor is used to initialize the object’s properties (data members) when the object is created.
    // constructor ki kuch property hoti hai;
    // ye object creation k time pr invoke hota hai mtlb jb object create karte hoo tb bydefault constructor bn jata hai;
    // it does not have any return type;
    
    cout<<"****Start this file****\n\n";
    hero durgesh;
    // humne object banaya too default constructor call ho jayega durgesh.hero;
    // yadi aap khud he constructor banate hoo(simple ya paramerized vala) too bydefault vala constructor ht jayega;
    hero *actoress = new hero; //dynamically object created;

    
    hero ramesh(10); //Yaha parametrized constructor call hoga jo banaya hai default nahi banta ye vala;
    cout<<"health is "<<ramesh.health<<"."<<endl;
    cout<<"Address of ramesh is "<<&ramesh<<"."<<endl;
    
    hero *actor = new hero(12);
    cout<<"health is "<<(*actor).health<<"."<<endl;
    cout<<"Address of actor is "<<&(*actor)<<"."<<endl;
    // // constructor call ismai bhi hoga same tarike se ;
    // // yadi hum ek bhi type(parametrized ya normal) constructor banate hai too default constructor nhi banta hai;
    
     hero mahesh(100,'B',15); //yaha level assign nahi hoga kyuki vo private modifier hai;
    mahesh.setlevel(25);
    cout<<"mahesh health, rating and level are "<<mahesh.health<<", "<<mahesh.rating<<" and "<<mahesh.getlevel()<<"."<<endl;
    
    // Copy constructor;
    // hero suresh(mahesh); //ye bhi likh sakte hai;
    hero suresh = mahesh; 
    // jb hum object send karte hai too copy constructor apne aap define hoo jata hai;
    // yadi hum chahte too copy constructor khud ka bhi define kr sakte hai pr khud kiya too default vala ht jayega;
    cout<<"suresh health, rating and level are "<<suresh.health<<", "<<suresh.rating<<" and "<<suresh.getlevel()<<"."<<endl<<endl;
    //Default copy constructor shallow copy karta hai; 
    
    // Deep and shallow copy;
    hero h2;
    h2.health = 45;
    h2.rating = 'A';
    h2.setlevel(75);
    char nam[15] = "Sanjay";
    h2.setname(nam);
    h2.print();

    hero h1 = h2;
    h1.print();
    h1.name[0] = 'M';
    h2.health = 50;
    h2.print();
    h1.print();
    // shallow copy mai hum same he memory ko access karte hai jaha humne pointer use kiya hoo vaha only;
    
}