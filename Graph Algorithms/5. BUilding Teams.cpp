#include <bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>>&adj, vector<int>&color, int n, int i){
  queue<pair<int, int>>q;
  q.push({i,1});
  color[i] = 1;
  while(!q.empty()){
    auto it = q.front();
    q.pop();
    for(auto i: adj[it.first]){
      if(color[i]==0){
        int x;
        if(it.second ==1) x= 2;
        else x = 1;
        q.push({i, x});
        color[i] = x;
      }
      else{
        if(it.second == color[i]) return false;
      }
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  for (int i = 0; i < m; i++) {
      int a, b; cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
  }
  // a bipartite 
  vector<int>color(n+1);
  bool x = true;
  for(int i=1; i<=n; i++){
    if(color[i] == 0){
      x = x && f(adj, color, n, i);
    }
  }
  if(x==false) cout<<"IMPOSSIBLE"<<endl;
  else{
    for(int i=1; i<=n; i++){
      cout<<color[i]<<" ";
    }
  }
    
}
