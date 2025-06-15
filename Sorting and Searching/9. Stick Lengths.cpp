#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  cin>>n;
  vector<long long>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  sort(arr.begin(), arr.end());
  vector<long long>presum(n);
  presum[0] = arr[0];
  for(int i=1; i<n; i++){
    presum[i] = presum[i-1] + arr[i];
  }
  int i=0, j = 0;
  long long cost = LLONG_MAX;
  while(i<n && j<n){
    while(j<n && arr[j]==arr[i]){
      j++;
    }
    long long left = (i > 0) ? arr[i] * i - presum[i-1] : 0;
    long long right = (j < n) ? (presum[n-1] - presum[j-1]) - arr[i] * (n - j) : 0;
    cost = min(cost, left + right);
    i=j;
  }
  cout<<cost<<endl;
}
