#include<bits/stdc++.h>
using namespace std;
#define ll long long

int f(int n, vector<int>&dp){
  if(n<10){
    return 1;
  }
  if(dp[n] != -1) return dp[n];
  int copy = n;
  int steps = 1e9;
  while(copy){
    int digit = copy%10;
    if(digit != 0) steps = min(steps, 1+f(n-digit, dp));
    copy = copy/10;
  }
  return dp[n] = steps;
}
int main(){
  int n;
  cin>>n;
  vector<int>dp(n+1, -1);
  cout<<f(n, dp)<<endl;
  
}
