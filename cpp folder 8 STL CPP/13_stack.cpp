#include<iostream>
#include<stack> 
using namespace std;
//type of container where element added at top
// and removed from top.
int main()
{
    // stack<int> l = {1,2,3}; ye hum nahi kr sakte.
    stack<int> l ;
    l.push(9);
    l.push(7);
    l.push(5);
    cout<<" top element : "<<l.top()<<endl; ;
    l.pop() ;
    cout<<" top element : "<<l.top()<<endl;
    
    stack<string> st ;
    st.push("sanjay");
    st.push("meena");
    st.push("brave");
    cout<<" top element : "<<st.top()<<endl; ;
    st.pop() ;
    cout<<" top element : "<<st.top()<<endl;   
    cout<<"size : "<<st.size()<<endl;
    cout<<"empty or not : "<<st.empty() ;
    

}