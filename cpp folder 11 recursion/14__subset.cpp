#include<iostream>
#include<vector>
using namespace std;
// if arr[3] = {1,2,3} then powerset of this array is 
// {[],[1],[2],[3],[1,2],[2,3],[1,3],[1,2,3]};
// powerset is the set of possible subset;
// no. of element in powerset is power(2,n) where n is no. of element in given array;

void powerset(int arr[],int n,int st,vector<vector<int>> &v,vector<int> output ){
    if(st >= n){
        v.push_back(output);
        return ;}

    // exclude the index;
    powerset(arr,n,st + 1,v,output);
    
    // include the index;
    int a = arr[st];
    output.push_back(a);
    powerset(arr,n,st + 1,v,output);
}
void printvec(vector<int> v);

int main(){
    
    int n = 5;;
    // cin>>n;
    int arr[5];
    for(int i = 0; i<n;i++){
        cin>>arr[i];
    }
    vector<vector<int>> v;
    vector<int> output;
    powerset(arr,n,0,v,output);

    cout<<"{";
    for(int j = 0; j< v.size();j++){
        printvec(v[j]);
        if(j+1 != v.size()){cout<<",";}
    }
    cout<<"}";
}

void printvec(vector<int> v){
    cout<<"[";
    for(int i = 0 ; i<v.size();i++){
        cout<<v[i];
        if(i+1 != v.size()){cout<<",";}
    }
    cout<<"]";
}
