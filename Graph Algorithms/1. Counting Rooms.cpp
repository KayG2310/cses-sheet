#include <bits/stdc++.h>
using namespace std;
void dfs(int n, int m, int i, int j, vector<vector<char>>&board, vector<vector<int>>&vis, vector<int>&r, vector<int>&c){
  vis[i][j] = 1;
  for(int k=0; k<4; k++){
    int nr = i+r[k];
    int nc = j+c[k];
    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && board[nr][nc]=='.'){
      dfs(n, m,nr, nc, board, vis, r, c);
    }
  }
}


int main() 
{
  int n, m;
  cin>>n>>m;
  vector<vector<char>>board(n, vector<char>(m, '.'));
  vector<vector<int>>vis(n, vector<int>(m, 0));
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      cin>>board[i][j];
    }
  }
  vector<int>r = {-1, 0, 1, 0};
  vector<int>c = {0, 1, 0, -1};
  int cnt = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(!vis[i][j] && board[i][j]=='.'){
        dfs(n, m, i, j, board, vis, r, c);
        cnt++;
      }
    }
  }
  cout<<cnt<<endl;
}

