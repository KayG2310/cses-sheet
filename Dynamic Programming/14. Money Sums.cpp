// recursive 
#include <bits/stdc++.h>
using namespace std;

void f(int index, int n, vector<int>& v, int currentSum, set<int>& ans) {
  if (index == n) {
    if (currentSum != 0) ans.insert(currentSum);
    return;
  }
  f(index + 1, n, v, currentSum + v[index], ans); 
  f(index + 1, n, v, currentSum, ans);
}

int main() {
  int n;
  cin >> n;
  vector<int> coins(n);
  for (int i = 0; i < n; i++) cin >> coins[i];

  set<int> ans;
  f(0, n, coins, 0, ans);

  cout << ans.size() << '\n';
  for (int x : ans) cout << x << " ";
  cout << '\n';
}

// memoized
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> coins;
vector<vector<int>> dp;
set<int> sums;

bool f(int index, int sum) {
 if (index == n) {
  if (sum != 0) sums.insert(sum);
  return false;
 }
 if (dp[index][sum] != -1) return dp[index][sum];
 f(index + 1, sum + coins[index]);
 f(index + 1, sum);
 return dp[index][sum] = true;
}

int main() {
 cin >> n;
 coins.resize(n);
 for (int i = 0; i < n; i++) cin >> coins[i];
 int max_sum = accumulate(coins.begin(), coins.end(), 0);
 dp.assign(n + 1, vector<int>(max_sum + 1, -1));
 f(0, 0);
 cout << sums.size() << '\n';
 for (int x : sums) cout << x << " ";
 cout << '\n';
}
