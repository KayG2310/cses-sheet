#include <bits/stdc++.h>
using namespace std;

long long count(vector<int>& nums, int n) {
    long long ans = 0;
    long long sum = 0;
    unordered_map<long long, long long> mpp;
    mpp[0] = 1;  // To count subarrays starting from index 0

    for (int i = 0; i < n; i++) {
        sum += nums[i];
        long long mod = (sum % n + n) % n;  // handle negative mods
        ans += mpp[mod];  // add all previously seen mod-matches
        mpp[mod]++;       // increment current mod frequency
    }
    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long x = count(nums, n);
    cout << x << endl;
}
