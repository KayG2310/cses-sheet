#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool static comp(pair<ll, ll>p1, pair<ll, ll>p2){
  if(p1.second<=p2.second) return true;
  return false;
}
int main() {
  int n;
  cin >> n;
  set<pair<ll, ll>>inn;
  for(int i=0; i<n; i++){
    ll a, b;
    cin>>a>>b;
    inn.insert({a, b});
  }
  vector<pair<ll, ll>>ii;
  for(auto it: inn){
    ii.push_back(it);
  }
  sort(ii.begin(), ii.end(), comp);
  vector<pair<ll, ll>>v;
  v.push_back(ii[0]);
  for(int i=1; i<ii.size(); i++){
    if(ii[i].first >= v.back().second){
      v.push_back(ii[i]);
    }
  }
  cout<<v.size()<<endl;
  
}
