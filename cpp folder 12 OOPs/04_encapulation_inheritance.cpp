#include<iostream>
#include<string>
#include<vector>
using namespace std;

class student{
    private:
    string name = "Sanjay";
    int age = 23;
    double height = 5.11;
    public:
    int getage(){ return age ;}
    double getheight(){return this->height; }
    string getname(){return this->name = name; }

};

class human{
    public:
    int marryage;
    int voting_age;
    public:
    int age;
    double height = 150 ;
    string name;
    int getage(){return (*this).age = age + 1;}
    void setheight(double w){this->height = w - 0.1;}

    private:
    string gf ;
    protected :
    char *fgn;
    char *fgf;
    char *actress;

};

class male: public human{
    public:
    string colour;
    void attack(){cout<<"sanjay attack is very dangerous"<<endl;}
    male(){fgn = new char[100];}
    string getfgn(){return this->fgn;}
    void setfgn(char *ch){strcpy(this->fgn , ch);}

    ~male() {
    delete[] fgn; // destructor frees memory
    }   
};

class female: protected human{
    public:
    void print(){
        marryage = 60;
        cout<<"marry age of female is "<<marryage<<endl;        
    }
    public:
    int getmarryage(){return this->marryage;}
    void setmarryage(int age){this->marryage = age;}

    female(){fgf = new char[100];}
    string getfgf(){return this->fgf;}
    void setfgf(char *ch){strcpy(this->fgf, ch);}

    ~female() {
    delete[] fgf; 
    }
};

class thirdgender: private human{
    public:
    int getvoting_age(){return this->voting_age;}
    void setvoting_age(int age){this->voting_age = age;}
    
    thirdgender(){actress = new char[100];}
    string getactress(){return this->actress;}
    void setactress(char *ch){strcpy(this->actress , ch);}

    ~thirdgender() {
    delete[] fgn; 
    }
};

int main(){           
    
    
    /* Encapsalation;
    1. Wraping up datamember and function in a class so that security and managibility increases;
    2. security from outside world means class ke andar ke functions (methods) ko toh access milta hi hai — kyunki wo class ke trusted part hain ex. bnak locker access by manager only and the person.
    3. Fully encapusalaed class mai all data member is private;
    // Advantages;
    (i)  Used for data/information hiding so that security increases;
    (ii) if we want, we can make class -> "Read only" means we allocate value by parametrized constructor and we not
          write a code for setter and write only code of getter;
    (iii) Code reusability,unit testing easily;
    */
   student s1;
   // s1.getage();
   cout<<"s1 age is "<<s1.getage() <<"."<<endl;
   cout<<"s1 height is "<<s1.getheight() <<"."<<endl;
   cout<<"s1 name is "<<s1.getname() <<"."<<endl;
   cout<<endl;

   /*Inheritance;
     1. Inheritance is a concept in Object-Oriented Programming (OOP) where one class (called child or subclass) gets the 
     properties and behaviors (methods) of another class (called parent or superclass).
    2. Why is Inheritance Useful?
    ✅  Reusability,increase readeability,simplicity;
    ✅ Extensibility: Add new features to child classes without changing parent code.
    3. Access Level After Inheritance 
    | super class   | public Base | protected Base | private Base |
    |---------------|-------------|----------------|--------------|
    | public        |   public    |   protected     |   private   |
    | protected     | protected   |   protected     |   private   |
    | private       |  Not accessible                             |
    
    // protected is similar to private but only difference is protected can be accessible to child class in public way only but private way in main function;
    // privated datamember of any class can not be accessible/inherited;

    */

  female f1;
  f1.print();
  cout<<"marry age of female is "<<f1.getmarryage() <<"."<<endl;
  f1.setmarryage(18);
  cout<<"marry age of female is "<<f1.getmarryage() <<"."<<endl;
  char cha[20] = "anuska sen";
  f1.setfgf(cha);
  cout<<"Sanjay fgf is "<<f1.getfgf() <<"."<<endl;

  thirdgender td;
  td.setvoting_age(19);
  cout<<"voting age of female is "<<td.getvoting_age() <<"."<<endl;
  char heroine[20] = "purvi";
  td.setactress(heroine);
  cout<<"tv serial hot actress name is "<<td.getactress() <<"."<<endl;

  human h1;
  h1.age = 60;
  // hum yadi main function mai value assign karate hai super class ki or inherite karte hai super class ko child class mai too datamember apne aap define hote hai ;

  male sanjay;
  cout<<"Age of sanjay class is "<<sanjay.age<<"."<<endl;
  cout<<"Height of sanjay class is "<<sanjay.height<<"."<<endl;
  sanjay.age = 23;
  sanjay.name = "sanjay";
  cout<<"Age of sanjay class is "<<sanjay.age<<"."<<endl;
  cout<<"Name of sanjay clas is "<<sanjay.name<<"."<<endl;
  string st = "white";
  // strcpy(sanjay.colour,st); ye work nahi karega bcz strcpy need char pointer to copy that ;
  sanjay.colour = st;
  cout<<"Colour of sanjay is "<<sanjay.colour<<"."<<endl;
  sanjay.attack();
  sanjay.setheight(165.80);
  cout<<"Height of sanjay class is "<<sanjay.height<<" ."<<endl;
  cout<<"age of sanjay class is "<<sanjay.getage()<<" ."<<endl;
  char ch[15] = "Priyanka";
  sanjay.setfgn(ch);
  cout<<"Sanjay fgn is "<<sanjay.getfgn() <<"."<<endl;
  cout<<endl;

  //cout<<"sanjay gf is "<<sanjay.gf<<endl;  //error aayega;
}