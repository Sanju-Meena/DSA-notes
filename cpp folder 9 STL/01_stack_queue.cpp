#include<bits/stdc++.h>
using namespace std;
//stack is LIFO datastructure means last in first out.
// stack is type of container where element added at top and removed from top.
// ismai hum dublicate value bhi de sakte hai.

//queue is FIFO datastructure means first in first out.
// it is just like open bucket.
int main(){
    // stack<int> s = {1,2,3,4}; ye allow nahi hai.
    stack<int> s;
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(4);
    s.push(5);
    s.push(6) ;
    cout<<"Top element : "<<s.top()<<endl;   
    cout<<"size : "<<s.size()<<endl;
    cout<<"empty or not : "<<s.empty() <<endl; //empty hai too 1 nahi too zero.

    while(!s.empty()){
            cout<<s.top()<<" ";
            s.pop() ;
    }
    cout<<endl;

    // queue<string> q  = { "acd","af"};ye allow nahi hai.
    queue<string> q;
    q.push("abc");
    q.push("def");
    q.push("def");
    q.push("ghi");
    q.push("jkl");
    cout<<"empty or not : "<<q.empty() <<endl;
    cout<<"size : "<<q.size()<<endl;
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop() ;
    }
    cout<<endl;
}