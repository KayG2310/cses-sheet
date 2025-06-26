#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() 
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m; cin>>n>>m;
  vector<vector<pair<ll, ll>>>adj(n+1);
  for(int i=0; i<m; i++){
    ll a, b, c;
    cin>>a>>b>>c;
    adj[a].push_back({b, c});
  }
  vector<ll>dist(n+1, LLONG_MAX); 
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
  dist[1]=0;
  pq.push({0, 1});
  while(!pq.empty()){
    auto it = pq.top();
    pq.pop(); 
    if(it.first > dist[it.second]) continue;
    for(auto i: adj[it.second]){
      if(dist[i.first]>it.first +i.second){
        dist[i.first] = it.first +i.second;
        pq.push({dist[i.first], i.first});
      }
    }
  }
  
  for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
}
