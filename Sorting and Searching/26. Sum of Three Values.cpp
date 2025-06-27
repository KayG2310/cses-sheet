#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() 
{
  int x, n; cin>>n>>x;
  vector<int>num(n);
  unordered_map<int, set<int>>mpp;
  for(int i=0; i<n; i++) {
    cin>>num[i];
    mpp[num[i]].insert(i+1);
  }
  sort(num.begin(), num.end());
  int i=0, j=1, k = n-1;
  while(i<n){
    j = i+1;
    k = n-1;
    bool flag = false;
    while(j<k){
      int sum = num[i]+num[j]+num[k];
      if(sum>x){
        k--;
      }
      else if(sum<x) j++;
      else{
        flag = true;
        break;
      }
    }
    if(flag) break;
    i++;
  }
  if(i>n-3) cout<<"IMPOSSIBLE"<<endl;
  else{
    int a = *mpp[num[i]].begin();
    mpp[num[i]].erase(a);
    int b = *mpp[num[j]].begin();
    mpp[num[j]].erase(b);
    int c = *mpp[num[k]].begin();
    mpp[num[k]].erase(c);
    vector<int>v = {a,b,c}; sort(v.begin(), v.end());
    cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
  }
}
