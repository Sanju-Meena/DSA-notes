#include <iostream>
using namespace std;

int dummy(int a){
 a++;
 cout<<a<<endl;
 return a;
}

int main(){
    int a = 4;
   int b = dummy(a);
   cout<<b<<endl; 
    cout<<a<<endl;
}