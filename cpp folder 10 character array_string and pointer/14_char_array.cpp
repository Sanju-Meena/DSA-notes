#include<iostream>
using namespace std;
// cout ki char array k liye implementation diffent hoti hai as compare to integer array;

int main(){
    char ch[6]= "abcde";//Size iski 6 leni padegi kyuki ye ek null character bhi store karta hai.
    cout<<ch<<" "<<ch[0]<<endl;
    char *c = &ch[0];
    // c entire string print karega.
    cout<<c<<endl;
    char temp[] = "abhishek";
    char *p = &temp[0];
    cout << temp<<endl;
    cout<<"Vapis start "<<endl;
     
    char la = 'a';
    char *oi = &la;
    cout<<oi<<" "<<la<<" "<<*oi<<endl;

    // Samag te hai ab;
    char sd[5] = {"mahi"}; //ismai temperary memory create hui and content gaya and ch mai content copy hota hai;
    char *j = "Dhoni"; //Ye nahi karna hai kabhi bhi use;
    //ismai temperary memory create hui and content gaya and ismai first character ka address store hua j mai;
    cout<<j<<" "<<*j<<endl;

}