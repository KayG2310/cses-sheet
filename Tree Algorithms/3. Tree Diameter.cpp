// nested dfs 
#include <bits/stdc++.h>
using namespace std;

int f(int n, vector<vector<int>>&adj, int parent){
  int dep = 0;
  for(auto it: adj[n]){
    if(it != parent){
      dep = max(dep, 1+f(it, adj, n));
    }
  }
  return dep;
}
int main() 
{
  int n; cin>>n;
  vector<vector<int>>adj(n+1);
  for(int i=1; i<n; i++){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int diam = 0;
  for(int i=1; i<=n; i++) {
    diam = max(diam, f(i, adj, i));
  }
  cout<<diam<<endl;
}

// better
#include <bits/stdc++.h>
using namespace std;

pair<int, int> f(int n, vector<vector<int>>&adj, int parent){
  int dep = 0, neigh = n;
  for(auto it: adj[n]){
    if(it != parent){
      auto i = f(it, adj, n);
      i.first += 1; 
      if(dep< i.first){
        dep = i.first;
        neigh = i.second;
      }
    }
  }
  return {dep, neigh};
}
int main() 
{
  int n; cin>>n;
  vector<vector<int>>adj(n+1);
  for(int i=1; i<n; i++){
    int a, b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  int diam = f(1, adj, 1).second;
  // cout<<diam<<endl;
  cout<<f(diam, adj, diam).first<<endl;
}
/*
        3 
      1       9.    
                8 
*/
