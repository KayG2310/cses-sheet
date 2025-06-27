#include <bits/stdc++.h>
#define int long long
using namespace std;

bool f(int mid, vector<int>&machines, int t, int n){
  int m = 0;
  for(int i=0; i<n; i++){
    int x = mid/machines[i];
    if(x==0) return m>=t;
    m += x;
    if(m>=t) return true;
  }
  return false;
}
int32_t main() 
{
  int n, t; cin>>n>>t;
  vector<int>machines(n);
  for(int i=0; i<n; i++){
    cin>>machines[i];
  }
  sort(machines.begin(), machines.end());
  int low = 1, high = machines[n-1]*t, ans = high;
  while(low<=high){
    int mid = (high+low)/2;
    if(f(mid, machines, t, n)){
      ans = min(ans, mid);
      high = mid-1;
    }
    else low = mid+1;
  }
  cout<<ans<<endl;
}
/*
7 machines to be made 
*/
