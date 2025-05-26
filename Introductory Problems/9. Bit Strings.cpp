#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() 
{
  int n;
  cin>>n;
  int result = 1;
  while(n--){
    result *=2;
    result = result%mod;
  }
  cout<<result<<endl;
}
