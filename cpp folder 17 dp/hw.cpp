#include<bits/stdc++.h>
using namespace std;
void nextper(vector<int> &v){
    int  j = v.size() -1;
    while(j > 0 && v[j] < v[j-1]){j--;}

    if(j == 0){reverse(v.begin(),v.end());}
    else{
        int ele = v[j-1];
        for(int i = v.size()-1;i > 0;i--){
            if(ele < v[i]){swap(v[j-1],v[i]); break;}
        }
        reverse(v.begin() + j,v.end());
    }


}

void makepermu(vector<int> &v,int n,int k){    
    int count = 1, i = 1;
    if(count == k)return ;
    while(count*i <= k)count = count*i++;
    i--;
    
    int s = n-i, e = n-1;
    while(s < e)swap(v[s++],v[e--]);
    
    // for(int i = 0;i<n;i++){cout<<v[i]<<" ";}cout<<endl;
    if(count == k)return ;
    
    nextper(v);
    count++;
    k = k - count + 1;
    
    // for(int i = 0;i<n;i++){cout<<v[i]<<" ";}cout<<endl;
    if(k == 0)return ;

    makepermu(v,n,k);
}


int main(){
    int k = 1;
    while(k < 25){
        cout<<k<<"  = ";
        int n = 4;
        vector<int> arr(n);
        for(int i = 0;i<n;i++)arr[i]= i+1;
        makepermu(arr,n,k);
        for(int i = 0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
        k++;
        // cout<<endl;
        
        
        string st;
        for(int i = 0;i<arr.size();i++){
            char n = '0' + arr[i];
            st.push_back(n);
        }
        // return st;
        cout<<"ans = "<<st;
        // cout<<endl<<endl;
    }
}