#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
  int n;
  cin>>n;
  vector<ll> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }
  sort(v.begin(),v.end());
  ll cnt = 0;
  for(int i=0; i<n; i++){
    if(cnt+1<v[i]) break;
    cnt += v[i];
  }
  cout<<cnt+1<<endl;
}
