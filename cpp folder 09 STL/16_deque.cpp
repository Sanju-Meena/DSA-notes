#include<iostream>
#include<deque>
using namespace std;
//special array in which we can insert and delete element from both end.
void printvec(deque<int> v){
    for(int i = 0 ; i < v.size();i++){
        cout<<v[i]<<" ";}
        cout<<endl;
    }

int main(){
  deque<int> asd ;
  asd.push_back(4) ; //front se only first element he le sakte hai.
  asd.push_front(3) ;
  asd.push_back(9) ;
  asd.push_front(2) ;
  printvec(asd) ;

  asd.pop_back() ;
  printvec(asd) ;

  asd.pop_front() ;
  printvec(asd) ;

  cout<<asd[0]<<endl;
  asd.push_back(5) ;
  asd.push_back(6) ;
  asd.push_back(7) ;
  printvec(asd) ;

  asd.erase(asd.begin() + 1 , asd.begin() + 3 ) ;//begin + 1 delete nahi hoyega only 2nd or 3rd element he delete hoyange.
  cout<<"size " <<asd.size( )<<endl;
  printvec(asd) ;

  cout<<"First  element is "<<asd.front()<<endl;  
  cout<<"Second element is "<<asd.at(1)<<endl;  
  cout<<"Last   element is "<<asd.back()<<endl;  
  // "0" means not empty .
  cout<<"empty or not : "<<asd.empty()<<endl;  
}