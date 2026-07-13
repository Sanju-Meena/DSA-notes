#include<iostream>
using namespace std;

int main(){
    int a = 3;
    cout<<a<<endl;
    if(true){
        int a = 5 ;
        cout<<a<<endl;
        int b = 7;
        // b cannot be excess outside if block;
    }
    cout<<a<<endl;
    int i = 5;
    for(int i= 1;i<6;i++){
        cout<<"HI"<<endl;
    }

}