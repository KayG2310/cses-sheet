#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin>>n>>q;
  vector<long long>arr(n), presum(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
    if(i==0){
      presum[i] = arr[i];
    }
    else{
      presum[i] = arr[i]+presum[i-1];
    }
  }
  presum.insert(presum.begin(), 0);
  for(int i=0; i<q; i++){
    int a, b;
    cin>>a>>b;
    cout<<presum[b]-presum[a-1]<<endl;
  }
}
