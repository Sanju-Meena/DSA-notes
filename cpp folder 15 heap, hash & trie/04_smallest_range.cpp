#include<iostream>
#include<stack>
#include<queue>
#include<map>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    int r;
    int c;

    node(int d,int r,int c){
        this->data = d;
        this->r = r;
        this->c = c;
    }
};

class cmp{
    public :
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

int main(){
    vector<vector<int>> nums;
    vector<int> arr1 = {4,10,15,24,26};
    vector<int> arr2 = {0,9,12,20};
    vector<int> arr3 = {5,18,22,30};
    nums.push_back(arr1);
    nums.push_back(arr2);
    nums.push_back(arr3);
    
    priority_queue<node*,vector<node*> ,cmp> pq;
    int mini = INT_MAX ,maxi = INT_MIN;
    for(int i = 0;i<nums.size();i++){
        pq.push(new node(nums[i][0],i,0));
        maxi = max(maxi,nums[i][0]);
    }
    mini = pq.top()->data;
    int start = mini,end = maxi;

   while(pq.size() != 0){
    node* temp = pq.top();
    mini = pq.top()->data;
    pq.pop();

    if(maxi - mini < end - start){
        start = mini,end = maxi;
    }

    if(temp->c + 1 < nums[temp->r].size()){
        pq.push(new node(nums[temp->r][temp->c + 1],temp->r,temp->c + 1));
        maxi = max(maxi,nums[temp->r][temp->c + 1]);
    }
    else{break;}
   }
   cout<<start<<" "<<end<<endl;   

   

}