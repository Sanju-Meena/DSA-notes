#include <iostream>
using namespace std;
// string is similar like char array.
/*Major differences is
 1. it doesn't have fixed size .
 2.we can add or delete any character in string while in fixed size array we cannot 
   add or delete randomly.
 3.we can use direct function that are predefined in string.
 4.we can stop string when we add '\0' and use pop_back function.
 */
void rever(std::string& str,int s , int e ){
    for(int i = s;i < e/2;i++){
      swap(str[i],str[e - 1-i]);
    }
    cout<<str;

}
int main(){
    string s; //It also end with null character.
    cin >> s;
    cout<<s[2]<<endl;
    cout << s << endl;
    string str = "sanjay meena\0assume to that it's gf is kajal";
    std::cout << str << endl;
    int length = str.length();
    cout << length << endl;
    str.push_back('.');
    cout << str << endl;
    str.pop_back();
    cout << str << endl;

    //Take string and reverse it's words.
    //ex:- sanjay meena is honest person.
    //o/p :- yajnas aneem si tsenoh .nosrep
    string st;
    cin>>st;
    int l = st.length();
    int p = 0;
    for(int i =0;i<l;i++){
      if(st[i] == ' ' && st[i] == '\0'){
          for(int j = p ;j < i/2;j++){
             swap(st[j],st[i - 1-j]);
          }
          cout<<st<<endl;
      }
    }

}