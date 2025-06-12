#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n;
  cin>>n;
  vector<pair<ll, int>>t;
  for(int i=0; i<n; i++){
    ll a, b;
    cin>>a>>b;
    t.push_back({a, 0});
    t.push_back({b, 1});
  }
  sort(t.begin(), t.end());
  int cnt = 0, ans=0;
  for(int i=0; i<2*n; i++){
    if(t[i].second==0){
      cnt++;
      ans = max(ans, cnt);
    }
    else{
      cnt--;
    }
  }
  cout<<ans<<endl;
}
