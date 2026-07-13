#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0;i<matrix.size();i++){
            int ch = 0;
            for(int j = 0;j<matrix[i].size();j++){
                if(matrix[i][j] == 0){ch = 1; }
            }
        }
        
    }
};

int main(){
    vector<vector<int>> matrix;
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        vector<int> temp;
        for(int j = 0;j<m;j++){
            int a;
            cin>>a;
            temp.push_back(a);
        }
        matrix[i].push_back(temp);
    }
}