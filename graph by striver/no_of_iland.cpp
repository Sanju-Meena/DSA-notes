#include<iostream>
#include<vector>

using namespace std;

void print(vector<vector<bool>> &isvisited){
    for(auto l : isvisited){
        for(auto m: l){cout<<m<<" ";}
        cout<<endl;
    }
    cout<<endl;

}

void check(int r , int c ,vector<vector<char>>& vec, vector<vector<bool>> &isvisited){
    int row = r, col = c;
    while(c < vec[row].size()){
        if(vec[r][c] == '0') break;
        while(r < vec.size()){
            if(vec[r][c] == '1') isvisited[r][c] = 1;
            else break;
            r++;
        }
        col++;
        r = row;
        c = col;
    }

}

int main(){
    vector<vector<char>> vec = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    vector<vector<bool>> isvisited(vec.size(), vector<bool> (vec[0].size(),0));
    
    int c = 0;
    for(int i = 0;i<vec.size();i++){
        for(int j = 0;j<vec[i].size();j++){
            if(vec[i][j] == '1' &&  isvisited[i][j] == 0){
                c++;
                check(i,j,vec,isvisited);
                print(isvisited);
            }
        }
    }
    
    cout<<c<<endl;

}