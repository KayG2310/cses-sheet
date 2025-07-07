#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n, m;
  cin>>n>>m;
  vector<vector<int>>dir(n+1);
  vector<int>indegree(n+1); 
  for(int i=0; i<m; i++){
    int a, b; cin>>a>>b;
    dir[a].push_back(b); 
    indegree[b]++; 
  }
  vector<int>topo; 
  queue<int>q;
  for(int i=1; i<=n; i++){
    if(indegree[i]==0) q.push(i);
  }
  while(!q.empty()){
    int i = q.front(); q.pop(); 
    topo.push_back(i);
    for(auto it: dir[i]){
      indegree[it]--;
      if(indegree[it]==0) q.push(it);
    }
  }
  if(topo.size() != n) cout<<"IMPOSSIBLE"<<endl;
  else{
    for(int i: topo) cout<<i<<" ";
  }
}
