#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll maxx(ll n1, ll n2){
  if(n1>n2) return n1;
  return n2;
}
int main() 
{
  ll n;
  cin>>n;
  vector<ll>v(n);
  ll sum = LLONG_MIN, s2 = 0; 
  for(int i=0; i<n; i++){
    ll x;
    cin>>x;
    s2 += x;
    sum = maxx(sum, s2);
    if(s2<0) s2 = 0;
  }
  cout<<sum<<endl;
}
