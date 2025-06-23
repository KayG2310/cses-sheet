// recursive code
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n, m;
vector<int> a;
vector<vector<int>> dp;
long long f(int i, int prev) {
  if(i == n) return 1;
  if(dp[i][prev] != -1) return dp[i][prev];
  long long ans = 0;
  if(a[i] != 0) {
      if(prev == 0 || abs(a[i] - prev) <= 1) {
          ans = f(i + 1, a[i]);
      } else {
          ans = 0;
      }
  } else {
      for(int val = 1; val <= m; val++) {
          if(prev == 0 || abs(val - prev) <= 1) {
              ans = (ans + f(i + 1, val)) % mod;
          }
      }
  }
  return dp[i][prev] = ans;
}
int main() {
  cin >> n >> m;
  a.resize(n);
  for(int i = 0; i < n; i++) cin >> a[i];

  dp.assign(n + 1, vector<int>(m + 2, -1)); // m+2 for safety

  cout << f(0, 0) << "\n";
}
