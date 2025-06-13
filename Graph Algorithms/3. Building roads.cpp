#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
  vector<int>parent;
  vector<int>size;
  DisjointSet(int n){
    parent.resize(n+1);
    size.resize(n+1);
    for(int i=1; i<=n; i++){
      parent[i] = i;
      size[i] = 1;
    }
  }
  int ultimate_parent(int u){
    if(parent[u]==u) return u;
    return parent[u] = ultimate_parent(parent[u]);
  }
  void unionn(int u, int v){
    int pu = ultimate_parent(u);
    int pv = ultimate_parent(v);
    if(pu==pv) return;
    if(size[pu]>=size[pv]){
      size[pu] += size[pv];
      parent[pv] = pu;
    }
    else{
      size[pv] += size[pu];
      parent[pu]=pv;
    }
  }
};

int main() 
{
  int nodes, roads;
  cin>>nodes>>roads;
  DisjointSet ds(nodes);
  for(int i=0; i<roads; i++){
    int a, b;
    cin>>a>>b;
    ds.unionn(a, b);
  }
  int cnt = 0;
  vector<int>ups;
  for(int i=1; i<=nodes; i++){
    if(ds.parent[i]==i){
      cnt++;
      ups.push_back(i);
    }
  }
  cout<<cnt-1<<endl;
  for(int i=1; i<ups.size(); i++){
    cout<<ups[0]<<" "<<ups[i]<<endl;
  }
}
