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

// tabulation 
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); // dp[i][val]

    // Base case
    if (a[n - 1] == 0) {
        for (int val = 1; val <= m; val++) dp[n - 1][val] = 1;
    } else {
        dp[n - 1][a[n - 1]] = 1;
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int val = 1; val <= m; val++) {
            if (a[i] != 0 && a[i] != val) continue; // only consider matching or 0
            int ways = 0;
            for (int d = -1; d <= 1; d++) {
                int next_val = val + d;
                if (next_val >= 1 && next_val <= m) {
                    ways = (ways + dp[i + 1][next_val]) % mod;
                }
            }
            dp[i][val] = ways;
        }
    }

    int result = 0;
    if (a[0] == 0) {
        for (int val = 1; val <= m; val++) {
            result = (result + dp[0][val]) % mod;
        }
    } else {
        result = dp[0][a[0]];
    }
    cout << result << "\n";
    return 0;
}
