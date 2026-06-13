// question 6 drop, video no. 61 baad mai karna hai;
// question 7 bhi samag nahi aaya hai;
#include<iostream>
#include<queue>

using namespace std;
/*
1. Reverse queue element;
2. Find first -ve in every k element in an array;
3. Reverse first k element of queue;
4. In a circle having n petrol pump then where we start so that cover all distances;
5. Interleave the first half of the queue with second half and only stack can be used as auxiliary space;
6. implement k queues in a single array;
7. Sum of max and min elements of all subarrays of size k;
*/
// 1st ans;
void reversequeue(queue<int> &q){
    if(q.size() == 0){return ;}
    int a = q.front();
    q.pop();
    reversequeue(q);
    q.push(a);
}
void print(queue<int> r){
    while(r.size() != 0){
        int a = r.front();
        cout<<a<<" ";
        r.pop();
    } cout<<endl;
}

// // 3rd ans;
// void reverse_first_k(queue<int> &q,int l,int k){
//     if(k == l){return ;}
//     int a = q.front();
//     q.pop();
//     l++ ;
//     reverse_first_k(q,l,k);
//     q.push(a);
// }

// 6th ans;

int main(){
    // queue<int> q;
    // q.push(5);
    // q.push(4);
    // q.push(3);
    // q.push(2);
    // q.push(1);
    // 1. reverse a queue;
    // reversequeue(q);
    // print(q);
    
    // 2. find first -ve in every k element in an array;
    // int n = 5;
    // int arr[5] = {-8,2,3,-6,10};
    // int k = 4;
    // // cin>>k;
    // for(int i = 0;i<n;i++){
    //     int c = 0,ch = 0;
    //     for(int j = i;j<n && k>c;j++){
    //         if(arr[j] < 0){cout<<arr[j]<<" "; ch = 1; break;}
    //         c++;
    //     }
    //     if(i == n-k){break;}
    //     if(ch == 0){cout<<0<<" ";}
    // }

    // 3rd ans;
    // print(q);
    // int k;
    // cin>>k;
    // if(k>q.size()){k = q.size();}
    // reverse_first_k(q,0,k);
    // int si = q.size() - k ;
    // for(int i = 0;i<si;i++){
    //     int a = q.front();
    //     q.pop();
    //     q.push(a);
    // }
    // print(q);
    
    // 4th ans;
    // int n = 5;
    // int p[n] = {6,1,2,3,4};
    // int d[n] = {4,2,3,4,3};
    // int ps = 0,ds = 0;
    // int arr[n];
    // for(int i = 0;i<n;i++){
    //     int diff = p[i]-d[i];
    //     arr[i] = diff;
    //     ps = ps + p[i];
    //     ds= ds + d[i];
    // }
    // for(int i = 0;i<n;i++){cout<<arr[i]<<" ";}cout<<endl;
    // if(ps>=ds){
    //     int sum = 0,ans = 0;
    //     for(int i = 0;i<n;i++){
    //             sum = sum + arr[i];
    //             if(sum < 0){sum = 0; ans = i+1;}
    //     }
    //     cout<<ans<<endl;
    // }else{cout<<"Nahi hoo payega ji.\n"; }

    // 5th ans;
    // queue<int> q;
    // for(int i = 1;i<9;i++){q.push(i);}
    // int l = q.size();
    // stack<int> fh;
    // stack<int> sh;
    // for(int i = 1;i<=l;i++){
    //     int a = q.front();
    //     q.pop();
    //     if(i<=l/2){fh.push(a);}
    //     else{sh.push(a);}
    // }
    // for(int i = 1;i<=l;i++){
    //     if(i%2 == 1){int a = sh.top(); sh.pop(); q.push(a);}
    //     else{int a = fh.top(); fh.pop(); q.push(a);}
    // }
    // reversequeue(q);
    // print(q);

    // 7th ans;
    int n = 7;
    int arr[7] = {7,6,5,4,3,2,1};
    int k = 4;
    // cin>>k;
    deque<int> maxi;
    deque<int> mini;          
    
    // first k size window k minimum and maximum index store;
    for(int i = 0;i<k;i++){
        while(maxi.size() != 0 && arr[i] >= arr[maxi.back()]){maxi.pop_back();}
        while(mini.size() != 0 && arr[i] <= arr[mini.back()]){mini.pop_back();}
        maxi.push_back(i);
        mini.push_back(i);
    }
    // maxi = 3 and mini = 2,3; ye index hai;
    int ans = 0;
    ans = ans + arr[maxi.front()] + arr[mini.front()];
    
    for(int i = k;i<n;i++){
        // removal
        while(maxi.size() != 0 && i-maxi.front() >= k){
            maxi.pop_front();
        }

        while(mini.size() != 0 && i-mini.front() >= k){
            mini.pop_front();
        }

        // addition
        while(maxi.size() != 0 && arr[i] >= arr[maxi.back()]){maxi.pop_back();}
        while(mini.size() != 0 && arr[i] <= arr[mini.back()]){mini.pop_back();}
        maxi.push_back(i);
        mini.push_back(i);
        
        ans = ans + arr[maxi.front()] + arr[mini.front()];  
    }
    cout<<ans<<endl;
     
}