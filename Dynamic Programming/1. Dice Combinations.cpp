#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int f(int sum, int target, vector<int>&dp){
  if(sum==target) return 1;
  if(dp[sum] != -1) return dp[sum];
  int x = 0;
  for(int i=1; i<=6; i++){
    if(sum+i<=target){
      x = (x+f(sum+i, target, dp))%mod;
    }
  }
  return dp[sum] = x%mod;
}
int main() 
{
  int n;
  cin>>n;
  vector<int>dp(n+1, -1);
  cout<<f(0, n, dp)<<endl;
}



