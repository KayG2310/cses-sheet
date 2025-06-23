#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<vector<int>>&adj, vector<int>&size){
  for(auto it: adj[node]){
    size[node] += dfs(it, adj, size);
  }
  return size[node];
}

int main() {
  int n; cin>>n;
  vector<vector<int>>adj(n);
  vector<int>size(n, 0);
  for(int i=0; i<n-1; i++){
    int x; cin>>x;
    adj[x-1].push_back(i+1);
    size[x-1]++;
  }
  /*
  x = 2 
  adj[0] --> 1 size[0] = 1
  adj[1] --> 2 size[1] = 1
  adj[2] --> 3 size[2] = 1
  adj[3] --> 4 size[3] = 1
  adj[4] --> 5 size[4] = 1
  adj[5] --> 6 size[5] = 1
  adj[6] --> 7 size[6] = 1
  adj[7] --> 8 size[7] = 1
  adj[8] --> 9 size[8] = 1
  */
  dfs(0, adj, size); 
  for(int i=0; i<n; i++) cout<<size[i]<<" ";
}
