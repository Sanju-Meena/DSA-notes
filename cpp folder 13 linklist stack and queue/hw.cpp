#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
// Question 1: reversr a linklist ; 
// ip = 1 2 3 4 5 0;
// op = 5 4 3 2 1 ;

class node{
    public:
    int data ;
    node* next;

    node(int d){
        this->data = d;
        this->next = NULL;
    }
    
};

void insert(node* &head,node* &tail ,int a){
    node* temp = new node(a);
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

void print(node* head){
    while(head == NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void search(vector<vector<int>> &vec,int sum,vector<int> v,int si){
    vector<int> ans;
    ans.push_back(v[si]);
    int s = si+1,e = v.size()-1;
    while(s<e){
        if(v[s] + v[e] == sum){
            ans.push_back(v[s]);
            ans.push_back(v[e]);
            vec.push_back(ans);
            ans.pop_back();
            ans.pop_back();
            while(v[s] == v[s+1]){s++; cout<<s<<" ";if(s==e)return ;}cout<<endl;
            while(v[e] == v[e-1]){e--; cout<<e<<" "; if(e==s )return; }cout<<endl;
            s++;     
        }
        else if(v[s]+v[e] < sum)s++;
        else e--;
    }
}

int main(){
    // node* head = NULL;
    // node* tail = NULL;
    // int n ;
    // cin>>n;
    // while(n--){
    //     int a;
    //     cin>>a;
    //     insert(head,tail,a);
    // }

    // print(head);

    vector<int> v = {-1,0,1,2,-1,-4};
    sort(v.begin(),v.end());
    vector<vector<int>> vec;
    
    for(int i = 0;i<v.size()-3;i++){
       if(i != 0) while(v[i] == v[i-1]){i++; if(i>=v.size()-3){break;} }
       
       if(i<=v.size()-3){
           int sum = -1*v[i];
           search(vec,sum,v,i);
        }
    }


    for(int i = 0;i<vec.size();i++){
        for(int j = 0;j<3;j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }

    
}