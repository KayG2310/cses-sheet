#include <bits/stdc++.h>
using namespace std;

int main() 
{
  long long n, x;
  cin>>n>>x;
  vector<pair<long long, int>>v;
  for(int i=0; i<n; i++){
    long long x;
    cin>>x;
    v.push_back({x, i+1});
  }
  sort(v.begin(), v.end());
  int i=0, j=n-1, fl=1;
  while(i<j){
    if(v[i].first+v[j].first==x){
      cout<<v[i].second<<" "<<v[j].second<<endl;
      fl=0;
      break;
    }
    else if(v[i].first+v[j].first>x){
      j--;
    }
    else i++;
  }
  if(fl) cout<<"IMPOSSIBLE"<<endl;
  
}
