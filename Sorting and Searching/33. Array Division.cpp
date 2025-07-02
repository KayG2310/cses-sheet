#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll max(ll a, ll b){
  if(a>=b) return a;
  return b;
}

bool f(ll mid, vector<ll>&arr, int k, int n){
  ll cnt = 1, sum = 0;
  for(int i=0; i<n; i++){
    if(sum + arr[i]<=mid){
      sum += arr[i];
    }
    else{
      sum = arr[i];
      cnt++;
    }
    if(cnt>k) return false;
  }
  if(cnt>k) return false;
  return true;
}
int main() {
  int n, k; 
  cin>>n>>k;
  vector<ll>arr(n); ll high = 0, low = 0;
  for(int i=0; i<n; i++){
    cin>>arr[i];
    high += arr[i];
    low = max(low, arr[i]);
  }
  // do BS on answers 
  ll ans = high;
  while(low<=high){
    ll mid = (low+high)/2;
    if(f(mid, arr, k, n)){
      ans = min(ans, mid);
      high = mid-1;
    }
    else{
      low = mid+1;
    }
  }
  cout<<ans<<endl;
}
// 1 2 3 4
