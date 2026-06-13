#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;

int signum(int a,int b){
        if(a == b){return 0;}
        else if(a >  b){return 1;}
        else{return -1;}
    }

void median(int ele,priority_queue<int> &maxh,priority_queue<int,vector<int>,greater<int>> &minh,int &med){
        switch(signum(maxh.size(),minh.size())){
            case 0: if(ele > med){
                        minh.push(ele); med = minh.top();}
                    else{
                        maxh.push(ele); med = maxh.top();}
                    break;

            case 1: if(ele > med){
                        minh.push(ele); med = (minh.top() + maxh.top())/2;}
                    else{
                        minh.push(maxh.top()); maxh.pop();
                        maxh.push(ele); med = (minh.top() + maxh.top())/2;}
                    break;

            case -1: if(ele > med){
                        maxh.push(minh.top()); minh.pop();
                        minh.push(ele); med = (minh.top() + maxh.top())/2;}
                     else{
                        maxh.push(ele); med = (minh.top() + maxh.top())/2;
                    }
        }
    }

int main(){
    vector<int> v = {5,15,1,3,2,8};
    priority_queue<int> maxh;
    priority_queue<int,vector<int> , greater<int>>minh; 
    int med  = -1;
    vector<int> ans;
    for(int i = 0;i<v.size();i++){
        median(v[i],maxh,minh,med);
        ans.push_back(med);
    }
    for(auto i:ans)cout<<i<<" ";
    cout<<endl;

}