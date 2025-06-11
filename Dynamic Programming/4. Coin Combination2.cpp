// recursive + memoized 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int f(int index, int n, vector<int>&coins, int x, vector<vector<int>>&dp){
  if(x==0) return 1;
  if(index == n) return 0;
  if(dp[index][x] != -1) return dp[index][x];
  int notpick = f(index+1, n, coins, x, dp)%mod;
  int pick = 0;
  if(x-coins[index]>=0) pick = f(index, n, coins, x-coins[index], dp)%mod;
  return dp[index][x] = (pick+notpick)%mod;
}
int main() 
{
  int n, x;
  cin>>n>>x;
  vector<int>coins(n);
  for(int i=0; i<n; i++) cin>>coins[i];
  vector<vector<int>>dp(n+1, vector<int>(x+1, -1));
  cout<< f(0, n, coins, x, dp);
} 

// tabilation
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() 
{
  int n, x;
  cin>>n>>x;
  vector<int>coins(n);
  for(int i=0; i<n; i++) cin>>coins[i];
  vector<vector<int>>dp(n+1, vector<int>(x+1, 0));
  for(int i=0; i<n; i++){
    dp[i][0] = 1;
  }
  for(int index=n-1; index>=0; index--){
    for(int sum=1; sum<=x; sum++){
      int notpick = dp[index+1][sum]%mod;
      int pick = 0;
      if(sum-coins[index]>=0) pick = dp[index][sum-coins[index]]%mod;
      dp[index][sum] = (pick+notpick)%mod;
    }
  }
  cout<< dp[0][x];
} 
// space optimisation
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() 
{
  int n, x;
  cin>>n>>x;
  vector<int>coins(n);
  for(int i=0; i<n; i++) cin>>coins[i];
  vector<int>cur(x+1, 0), ahead(x+1, 0);
  for(int i=0; i<n; i++){
    cur[0] = 1;
    ahead[0] = 1;
  }
  for(int index=n-1; index>=0; index--){
    for(int sum=1; sum<=x; sum++){
      int notpick = ahead[sum]%mod;
      int pick = 0;
      if(sum-coins[index]>=0) pick = cur[sum-coins[index]]%mod;
      cur[sum] = (pick+notpick)%mod;
    }
    ahead = cur;
  }
  cout<< cur[x];
}
