#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool is_safe(vector<vector<int>> arr,int n,int x,int y,string op,
    vector<string> &v,vector<vector<int>> vi){
    
        if((x>=0 && x<n) && (y>=0 && y<n) && vi[x][y] == 0 && arr[x][y] == 1  ){
            return true;
        }
        else{return false;}

    }


void rat(vector<vector<int>> arr,int n,int x,int y,string op,
         vector<string> &v,vector<vector<int>> vi){
    if(x == n-1 && y == n-1){
        v.push_back(op);
        return ;
    }

    vi[x][y] = 1;
    
    // Down 
    int newx = x+1;
    int newy = y;
    if(is_safe(arr,n,newx,newy,op,v,vi)){
      op.push_back('D');
      rat(arr,n,newx,newy,op,v,vi);
      op.pop_back();
    }

    // Left
    newx = x;
    newy = y-1;
    if(is_safe(arr,n,newx,newy,op,v,vi)){
      op.push_back('L');
      rat(arr,n,newx,newy,op,v,vi);
      op.pop_back();
    }

    // Right
    newx = x;
    newy = y+1;
    if(is_safe(arr,n,newx,newy,op,v,vi)){
      op.push_back('R');
      rat(arr,n,newx,newy,op,v,vi);
      op.pop_back();
    }

    // Up
    newx = x-1;
    newy = y;
    if(is_safe(arr,n,newx,newy,op,v,vi)){
      op.push_back('U');
      rat(arr,n,newx,newy,op,v,vi);
      op.pop_back();
    }
    vi[x][y] = 0;
    
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> vi  ;
    vector<vector<int>> arr  ;
    
    for(int i = 0;i<n;i++){
    vector<int> temp ;
    vector<int> cemp ;
    for (int h = 0; h < n; h++){
        int a;
        cin >> a;
        temp.push_back(a);
        cemp.push_back(0);
    }
    arr.push_back(temp) ;
    vi.push_back(cemp) ;
    }

    vector<string> v;
    string op;
    if(arr[0][0] == 0){}
    else{
        rat(arr,n,0,0,op,v,vi);
    }
    sort(v.begin(),v.end()) ;
    for(auto i : v){cout<<i<<" ";}

}
/*
4
1 0 0 0
1 1 0 1
1 1 1 0
0 1 1 1
*/