// recursive 
#include <bits/stdc++.h>
using namespace std;

int f(int i, int n, int x,  vector<int>&prices, vector<int>&pages){
  if(i==n || x==0) return 0;
  int notbuy = f(i+1, n, x, prices, pages);
  int buy = 0;
  if(x-prices[i]>=0) buy = pages[i]+f(i+1, n, x-prices[i], prices, pages);
  return max(buy, notbuy);
}
int main() 
{
  int n, x;
  cin>>n>>x;
  vector<int>pages(n), prices(n);
  for(int i=0; i<n; i++){
    cin>>prices[i];
  }
  for(int i=0; i<n; i++){
    cin>>pages[i];
  }
  cout<<f(0, n, x, prices, pages)<<endl;
  
}

// memoized 
#include <bits/stdc++.h>
using namespace std;

int f(int i, int n, int x,  vector<int>&prices, vector<int>&pages, vector<vector<int>>&dp){
  if(i==n || x==0) return 0;
  if(dp[i][x] != -1) return dp[i][x];
  int notbuy = f(i+1, n, x, prices, pages, dp);
  int buy = 0;
  if(x-prices[i]>=0) buy = pages[i]+f(i+1, n, x-prices[i], prices, pages, dp);
  return dp[i][x] = max(buy, notbuy);
}
int main() 
{
  int n, x;
  cin>>n>>x;
  vector<int>pages(n), prices(n);
  for(int i=0; i<n; i++){
    cin>>prices[i];
  }
  for(int i=0; i<n; i++){
    cin>>pages[i];
  }
  vector<vector<int>>dp(n+1, vector<int>(x+1, -1));
  cout<<f(0, n, x, prices, pages, dp)<<endl;
  
} 

// tabulation
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n, y;
  cin>>n>>y;
  vector<int>pages(n), prices(n);
  for(int i=0; i<n; i++){
    cin>>prices[i];
  }
  for(int i=0; i<n; i++){
    cin>>pages[i];
  }
  vector<vector<int>>dp(n+1, vector<int>(y+1, 0));
  // base case already handled
  for(int i=n-1; i>=0; i--){
    for(int x=1; x<=y; x++){
        int notbuy = dp[i+1][x];
        int buy = 0;
        if(x-prices[i]>=0) buy = pages[i]+dp[i+1][x-prices[i]];
        dp[i][x] = max(buy, notbuy);
    }
  }
  cout<<dp[0][y]<<endl;
  
} 
// space opt 
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n, y;
  cin>>n>>y;
  vector<int>pages(n), prices(n);
  for(int i=0; i<n; i++){
    cin>>prices[i];
  }
  for(int i=0; i<n; i++){
    cin>>pages[i];
  }
  vector<int>cur(y+1, 0), ahead(y+1, 0);
  // base case already handled
  for(int i=n-1; i>=0; i--){
    for(int x=1; x<=y; x++){
        int notbuy = ahead[x];
        int buy = 0;
        if(x-prices[i]>=0) buy = pages[i]+ahead[x-prices[i]];
        cur[x] = max(buy, notbuy);
    }
    ahead = cur;
  }
  cout<<cur[y]<<endl;
  
}
