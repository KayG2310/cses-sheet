#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() 
{
  ll n, x;
  cin>>n>>x;
  vector<int>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int sum = 0, cnt = 0;
  int i=0, j=0;
  while(j<n){
    while(j<n && sum + arr[j]<= x){
      sum += arr[j];
      j++;
    }
    if(sum==x) cnt++;
    sum -= arr[i];
    i++;
  }
  cout<<cnt<<endl;
}
