#include <bits/stdc++.h>
#define ll long long
#define lm LLONG_MAX
#define pii pair<ll, ll>
using namespace std;

bool static comp(pii a, pii b){
  if(a.first<b.first) return true; 
  if(a.first==b.first) return a.second<=b.second;
  return false;
}
int main() {
  int n; cin>>n;
  vector<pii>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i].first>>arr[i].second;
  }
  sort(arr.begin(), arr.end(), comp);
  ll t = 0, rew = 0;
  for(auto it: arr){
    t += it.first; 
    rew += it.second-t;
  }
  cout<<rew<<endl;
}
