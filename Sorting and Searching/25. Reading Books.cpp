#include <bits/stdc++.h>
#define int long long
using namespace std;

int max(int a, int b){
  if(a>=b) return a;
  return b;
}
int32_t main() 
{
  int n; cin>>n;
  vector<int>books(n);
  int ans = 0, maxi = 0;
  for(int i=0; i<n; i++) {
    cin>>books[i];
    ans += books[i];
    maxi = max(maxi, books[i]);
  }
  cout<<max(ans, 2*maxi);
  
}
