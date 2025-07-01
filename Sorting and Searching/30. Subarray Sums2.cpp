#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
  ll n, x;
  cin >> n >> x;
  vector<ll> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  ll sum = 0, cnt = 0;
  unordered_map<ll, int> mpp;
  mpp[0] = 1;

  for (int i = 0; i < n; i++) {
    sum += arr[i];
    cnt += mpp[sum - x];
    mpp[sum]++;
  }

  cout << cnt << endl;
}
