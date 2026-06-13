#include<iostream>
using namespace std;
// Reference variable means same memory with different name;

// Pass by reference;
int reference(int& n){//Yaha variable ka address aayega.
    n++;
}

// Pass by value;
void value(int n){ //Yaha num ki copy crete hogi.
    n++;
}

// Ismai reference return karenge;
int &update(int m){
    int a = m;
    a++;
    int  &ans = a;
    return ans ;
} //Isse use nahi karna hai.

// Ismai reference return karenge;
int* fun(int m){
    int *ptr = &m;
    return ptr ;
} //Isse use nahi karna hai.


int main(){
    int i = 5;
    // Crete reference variable;
    int &j = i;
    i++;
    cout<<i<<" "<<j<<endl;
    j++;
    cout<<i<<" "<<j<<endl;
    int *ptr = &i;
    int *ptr1 = &j;
    cout<<&i<<" "<<&j<<endl;
    cout<<ptr<<" "<<ptr1<<endl;
    cout<<endl;

    int num = 100;
    value(num);
    cout<<num<<endl;
    reference(num);
    cout<<num<<endl;
    
    int l = 50;
    update(l); //--> Is case mai warning aaye thi sir k laptop mai.
    cout<<update(l)<<endl;
    fun(l) ; //--> Is case mai warning aaye thi sir k laptop mai.

    return 0;
}