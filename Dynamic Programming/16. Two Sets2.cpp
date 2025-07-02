// recursive code 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int f(vector<int>&arr, int index, int target, int n){
  if(target==0) return 1;
  if(index == n) return 0; 
  int pick = 0;
  if(target-arr[index]>=0) pick = f(arr, index+1, target-arr[index], n)%mod; 
  int notpick = f(arr, index+1, target, n)%mod;
  return (pick+notpick)%mod;
}
int main() 
{
  int n;
  cin>>n; 
  int sum = (n*(n+1))/2;
  if(sum%2) cout<<0<<endl;
  else{
    // it is possible 
    int target = sum/2;
    // now we just have to find number of subsets having sum = target
    vector<int>arr(n);
    for(int i=1; i<=n; i++) arr[i-1] = i;
    cout<<f(arr, 0, target, n)/2<<endl;
  }
}

// memoized code 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int f(vector<int>&arr, int index, int target, int n, vector<vector<int>>&dp){
  if(target==0) return 1;
  if(index == n) return 0; 
  if(dp[index][target] != -1) return dp[index][target];
  int pick = 0;
  if(target-arr[index]>=0) pick = f(arr, index+1, target-arr[index], n, dp)%mod; 
  int notpick = f(arr, index+1, target, n, dp)%mod;
  return dp[index][target] = (pick+notpick)%mod;
}
int main() 
{
  int n;
  cin>>n; 
  int sum = (n*(n+1))/2;
  if(sum%2) cout<<0<<endl;
  else{
    // it is possible 
    int target = sum/2;
    // now we just have to find number of subsets having sum = target
    vector<int>arr(n);
    for(int i=1; i<=n; i++) arr[i-1] = i;
    vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
    int res = f(arr, 0, target, n, dp);
int inv2 = 500000004; // Modular inverse of 2 modulo 1e9+7
cout << (res * 1LL * inv2) % mod << endl;

  }
}
// 1 2 3 4 

// tabulation 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() 
{
  int n;
  cin>>n; 
  int sum = (n*(n+1))/2;
  if(sum%2) cout<<0<<endl;
  else{
    // it is possible 
    int targety = sum/2;
    // now we just have to find number of subsets having sum = target
    vector<int>arr(n);
    for(int i=1; i<=n; i++) arr[i-1] = i;
    vector<vector<int>>dp(n+1, vector<int>(targety+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 1;
    for(int index=n-1; index>=0; index--){
      for(int target = targety; target>=0; target--){
        int pick = 0;
        if(target-arr[index]>=0) pick = dp[index+1][target-arr[index]]%mod; 
        int notpick = dp[index+1][target]%mod;
        dp[index][target] = (pick+notpick)%mod;
      }
    }
    int res = dp[0][targety];
    int inv2 = 500000004; // Modular inverse of 2 modulo 1e9+7
    cout << (res * 1LL * inv2) % mod << endl;
  }
}
// 1 2 3 4 

// tabulation + space optimised 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() 
{
  int n;
  cin>>n; 
  int sum = (n*(n+1))/2;
  if(sum%2) cout<<0<<endl;
  else{
    // it is possible 
    int targety = sum/2;
    // now we just have to find number of subsets having sum = target
    vector<int>arr(n);
    for(int i=1; i<=n; i++) arr[i-1] = i;
    vector<int>cur(targety+1, 0), ahead(targety+1, 0);
    for(int i=0; i<=n; i++) {
      cur[0] = 1;
      ahead[0] = 1;
    }
    for(int index=n-1; index>=0; index--){
      for(int target = targety; target>=0; target--){
        int pick = 0;
        if(target-arr[index]>=0) pick = ahead[target-arr[index]]%mod; 
        int notpick = ahead[target]%mod;
        cur[target] = (pick+notpick)%mod;
      }
      ahead = cur;
    }
    int res = cur[targety];
    int inv2 = 500000004; // Modular inverse of 2 modulo 1e9+7
    cout << (res * 1LL * inv2) % mod << endl;
  }
}
// 1 2 3 4
