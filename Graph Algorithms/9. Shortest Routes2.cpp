#include <bits/stdc++.h>
#define ll long long
#define lm LLONG_MAX
using namespace std;


int main() {
  int n, m, q; cin>>n>>m>>q;
  vector<vector<ll>>roads(n+1, vector<ll>(n+1, lm));
  for(int i=0; i<m; i++){
    ll a, b, c; cin>>a>>b>>c; 
    roads[a][b] = min(roads[a][b], c);
    roads[b][a] = min(roads[b][a], c);
  }
  for(int i=0; i<n; i++) roads[i][i] = 0;
  // precompute all 
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      for(int k=1; k<=n; k++){
        if(roads[j][i] != lm && roads[i][k] != lm)roads[j][k] = min(roads[j][k], roads[j][i]+roads[i][k]);
      }
    }
  }
  for(int i=0; i<q; i++){
    int a, b; cin>>a>>b;
    if(a==b) cout<<0<<endl;
    else if(roads[a][b]==lm)cout<<-1<<endl;
    else cout<<roads[a][b]<<endl;
  }
}
