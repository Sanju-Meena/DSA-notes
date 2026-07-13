#include <bits\stdc++.h>
using namespace std;
void printvecvec(vector<int> v){
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";}
    cout << endl;
}

void printvec_of_array(vector<int> v){
    for(int i = 0 ;i < v.size() ; i++ ){
        cout<<v[i]<<" ";}
    cout<<endl;
}



int main(){
    vector<int> v = {0,1,2,3,4,5,6,7,8,9} ;
    // erase element which are muntiple of three.
    for(int i = 0 ; i<v.size();i++){
      if(v[i] % 3 == 0 && v[i] != 0){
        v.erase(v.begin() + i); }
    }
    for(int i : v){cout<<i<<" ";}
    
    // Array of vector.
    //it's look like 2d array;
    int num;
    cout<<"enter the number of vector\n" ;
    cin>>num;
    vector<int> vect[num] ; //yaha 0 number of vector bn gaye hai.
    for(int i = 0;i<num;i++){
    int size; cout<<"enter size of vector " <<i<<" \n";
    cin>>size;
    for(int h = 0;h<size;h++){
    int a; cout<<"enter the element of vector " <<i <<endl;
    cin>>a ;
    vect[i].push_back(a);
    }
}
    for(int i = 0;i<num;i++){
        printvec_of_array(vect[i]) ;
    }
    cout<<vect[1][2]<<endl ;//firsr vector ka second element;


    // yaha vector of vector bn gaye hai.
    vector<vector<int>> vec; 
    int numb;
    cout << "enter no. of vector of vector\n";
    cin >> numb;

    for (int i = 0; i < numb; i++){
    int size;
    cout << "enter size of vector " << i << " \n";
    cin >> size;
    vector<int> temp ;
    for (int h = 0; h < size; h++){
        int a;
        cout << "enter the element of vector " << i << endl;
        cin >> a;
        temp.push_back(a);
    }
    vec.push_back(temp) ;
    }
    
    vec[0].push_back(7) ;
    vec.push_back(vector<int> ()) ;                    
    for (int i = 0; i < vec.size(); i++){
         printvecvec(vec[i]);
    }
    cout << vec[0][1];
}