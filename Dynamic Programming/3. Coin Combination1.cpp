#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int f(int sum, vector<int>& coins, vector<int>& dp) {
    if (sum == 0) return 1;
    if (dp[sum] != -1) return dp[sum];
    
    int ways = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (coins[i] <= sum) {
            ways = (ways + f(sum - coins[i], coins, dp)) % mod;
        }
    }
    return dp[sum] = ways;
}

int main() {
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    
    vector<int> dp(amount + 1, -1);
    cout << f(amount, coins, dp) << endl;
}
