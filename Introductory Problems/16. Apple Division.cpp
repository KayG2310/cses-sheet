#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll f(int index, vector<ll>&arr, ll sum, ll s, int n){
  if(s==sum) return LLONG_MAX;
  if(index==n) return abs(sum-s-s);
  ll pick = f(index+1, arr, sum, s+arr[index], n);
  ll notpick = f(index+1, arr, sum, s, n);
  return min(pick, notpick);
}

int main() {
  int n;
  cin>>n;
  ll sum = 0;
  vector<ll>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
    sum += arr[i];
  }
  cout<<f(0, arr, sum, 0, n)<<endl;
}
