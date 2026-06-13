#include<iostream>
#include<queue>
using namespace std;

int main(){
queue<string> a;
a.push("sanjay");
a.push("meena");
a.push("brilliant");
a.push("student");

cout<<"front element : "<<a.front()<<"  "<<endl;
cout<<"end element : "<<a.back()<<"  "<<endl;
a.pop() ;
cout<<"front element : "<<a.front()<<"  "<<endl;
cout<<"end element : "<<a.back()<<"  "<<endl;
cout<<"size : "<<a.size()<<endl;
}