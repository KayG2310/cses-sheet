#include <bits/stdc++.h>
using namespace std;

int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp) {
    if (i == 0) return j;
    if (j == 0) return i;
    if (dp[i][j] != -1) return dp[i][j];
    if (S1[i - 1] == S2[j - 1])
        return dp[i][j] = editDistanceUtil(S1, S2, i - 1, j - 1, dp);
    return dp[i][j] = 1 + min({editDistanceUtil(S1, S2, i - 1, j - 1, dp),
                               editDistanceUtil(S1, S2, i - 1, j, dp),
                               editDistanceUtil(S1, S2, i, j - 1, dp)});
}

int main() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << editDistanceUtil(s, t, n, m, dp) << endl;
}
