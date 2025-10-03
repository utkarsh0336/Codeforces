/*Utkarsh Sahay*/
#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

void dfs(int i,int j,vector<vector<char>> &grid){
    if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '#') return;

    grid[i][j] = '#';
    for(auto dir : dirs){
        int i_ = i + dir[0];
        int j_ = j + dir[1];

         if(i_ >= 0 && i_ < grid.size() && j_ >= 0 && j_ < grid[0].size() && grid[i_][j_] != '#'){
            dfs(i_,j_,grid);
         }
    }
    // grid[i][j] = '.';
}
void Solve(){
    int n , m;
    cin >> n >> m;
    vector<vector<char>> grid(n,vector<char>(m,' '));
    int cnt = 0;

    for(int i = 0;i < n; i++){
        for(int j = 0;j < m; j++){
            cin >> grid[i][j];
        }
    }

    for(int i = 0;i < n; i++){
        for(int j = 0;j < m; j++){
            if(grid[i][j] == '.'){
                dfs(i,j,grid);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

    
}
 
int main(){

    int t = 1;
    // cin >> t;
    while(t--){
        Solve();
    }
 
    return 0;
}