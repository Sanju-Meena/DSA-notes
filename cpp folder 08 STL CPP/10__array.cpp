#include<bits/stdc++.h>
using namespace std;

int main()
{
  array<int,3> a = {1,2,3};
  int size = a.size() ;
  for(int i = 0; i<size;i++){
    cout<<a[i]<<" ";
  }
  cout<<endl;
  cout<<"First  element is "<<a.front()<<endl;  
  cout<<"Second element is "<<a.at(1)<<endl;  
  cout<<"Last   element is "<<a.back()<<endl;  
  // "0" means not empty .
  cout<<"empty or not : "<<a.empty()<<endl;  //written boolean.
}