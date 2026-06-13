#include<iostream>
#include<vector>
#include<stack>
using namespace std;
// next greater element;
// void print(stack<int> s){
//     int l = s.size();
//      for(int i = 0;i<l;i++){
//         cout<<s.top()<<" ";
//         s.pop();
//     } 
//     cout<<endl;
// }
// Sir next smaller element and previous smaller;
// ye function or pahele vala function mai  bus itna farak tha ki usmai hum value daal rahe the -1 k saath or 
// ismai hum index daal rahe hai -1 k saath;
void nextsmaller(vector<int> v,stack<int> s,int n,vector<int> &ns){
    for(int i = n-1;i>=0;i--){
        int curr = v[i];
        while(s.top() != -1 && v[s.top()] >= curr){s.pop();}
        ns.push_back(s.top());
        s.push(i);
    }
}

void prevsmaller(vector<int> v,stack<int> s,int st,vector<int> &ps){
    for(int i = 0;i<v.size();i++){
        int curr = v[i];  
        while(s.top() != -1 && v[s.top()] >= curr){s.pop();}
        ps.push_back(s.top());
        s.push(i);
    }
}
int main(){
    
    /*By Me -> ans 1;*/
    // ismai TLE aayegi when arr size = 10^5, this is not a optimal solution;
    // int si;
    // cin>>si;
    // vector<int> arr;
    // for(int i = 0;i<si;i++){
    //     int a;
    //     cin>>a;
    //     arr.push_back(a);
    // }
    // int n = arr.size();    
    // int sum = 0;
    // int ans = 0;

    // for(int i = 0;i<n;i++){
    //     int k = -1 ;
    //     sum = 0;
    //     int min = 0;
    //     // vector<int> v;
    //     for(int j = 0;j<n-i;j++){
    //         int l = j;
    //         min = arr[l];
    //         while(k < i && l<n){
    //             if(min > arr[l]){min = arr[l];}
    //             l++;
    //             k++;
    //         }
    //         sum = min*(i+1);
    //         cout<<sum<<" ";
    //         if(ans < sum){ans = sum;}
    //         sum = 0;
    //         k = -1;
    //         min = 0;
    //     }
    //     cout<<endl;

    // }
    // cout<<ans<<endl;

    /*By sir -> question 1; method 1;*/
    // int si;
    // cin>>si;
    // vector<int> arr;
    // for(int i = 0;i<si;i++){
    //     int a;
    //     cin>>a;
    //     arr.push_back(a);
    // }
    // int n = arr.size();  
    // int ans = 0;

    // for(int i = 0;i<n;i++){
    //     int bs = arr[i];
    //     int sum = bs;
    //     int c = 2;
    //     for(int j = i+1;j<n;j++){
    //         if(bs <= arr[j]){sum = sum + bs; }
    //         else{break;}
    //     }
    //     for(int k = i-1;k>= 0;k--){
    //         if(bs <= arr[k]){sum = sum + bs; }
    //         else{break;}
    //     }
    //     // cout<<sum<<" ";
    //     if(ans < sum){ans = sum;}
    // }
    // cout<<ans<<endl;
    
    /*By sir -> question 1; method 2;*/
    int si;
    cin>>si;
    vector<int> arr;
    for(int i = 0;i<si;i++){
        int a;
        cin>>a;
        arr.push_back(a);
    }
    int n = arr.size();  
    vector<int> ns;
    stack<int> s;
    s.push(-1);
    nextsmaller(arr,s,n,ns);
    for(auto i: ns){cout<<i<<" ";}cout<<endl;
    
    stack<int> p;
    p.push(-1);
    vector<int> ps;
    prevsmaller(arr,p,0,ps);
    for(auto i: ps){cout<<i<<" ";}cout<<endl;
    int answ = 0;

    for(int i = 0;i<n;i++){
        int nsi = ns[n-i-1];
        if(nsi == -1){nsi = arr.size();}
        int width = nsi - ps[i] - 1;
        int area = arr[i]*width ;
        cout<<area<<" ";
        answ = max(area,answ);
    }
    cout<<endl;
    cout<<answ<<endl;


}
// 6
// 3 5 1 7 5  9 