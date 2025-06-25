#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin>>n;
  vector<int> v(n);
  vector<int> ind(n+1,0);
  for(int i=0;i<n;i++){
    cin>>v[i];
    ind[v[i]]=i;
  }
  sort(v.begin(),v.end());
  int c=1;
  int prev=v[0], cur=v[0];
  for(int i=1;i<n;i++){
    cur=v[i];
    if(ind[cur]<ind[prev]) c++;
    prev=cur;
  }
  cout<<c<<endl;
  return 0;
}
/*
ind = 0 2 1 4 0 3 
1 2 4 3 5 
prev = 2, cur = 3  cnt = 1 


*/
