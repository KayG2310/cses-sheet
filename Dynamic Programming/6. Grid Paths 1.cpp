// recursive code
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int f(int i, int j, int n, vector<vector<int>>&board){
  if(i==n-1&&j==n-1) return 1;
  if(i<0 || i>=n || j<0 || j>=n) return 0;
  int right = 0;
  if(j+1<n && !board[i][j+1]) right = f(i, j+1, n, board)%mod;
  int down = 0;
  if(i+1<n && !board[i+1][j]) down = f(i+1, j, n, board)%mod;
  return (right+down)%mod;
}
int main() 
{
  int n;
  cin>>n;
  vector<vector<int>>board(n, vector<int>(n, 0));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char x;
      cin>>x;
      if(x=='*') board[i][j] = 1;
    }
  }
  // board is made 
  if(board[0][0]||board[n-1][n-1]) cout<<0<<endl;
  else cout<<f(0,0, n, board)<<endl;
}

// memoized code 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int f(int i, int j, int n, vector<vector<int>>&board, vector<vector<int>>&dp){
  if(i==n-1&&j==n-1) return 1;
  if(i<0 || i>=n || j<0 || j>=n) return 0;
  if(dp[i][j]!=-1) return dp[i][j];
  int right = 0;
  if(j+1<n && !board[i][j+1]) right = f(i, j+1, n, board, dp)%mod;
  int down = 0;
  if(i+1<n && !board[i+1][j]) down = f(i+1, j, n, board, dp)%mod;
  return dp[i][j]= (right+down)%mod;
}
int main() 
{
  int n;
  cin>>n;
  vector<vector<int>>board(n, vector<int>(n, 0)), dp(n+1, vector<int>(n+1, -1));
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      char x;
      cin>>x;
      if(x=='*') board[i][j] = 1;
    }
  }
  // board is made 
  if(board[0][0]||board[n-1][n-1]) cout<<0<<endl;
  else cout<<f(0,0, n, board, dp)<<endl;
} 

// tabulation
