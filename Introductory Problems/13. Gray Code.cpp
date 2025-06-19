#include <bits/stdc++.h>
using namespace std;

string binary(int y, int x){
  string k = "";
  while(y){
    int rem = y%2;
    y = y/2;
    k = to_string(rem)+k;
  }
  while(k.length()<x){
    k = '0'+k;
  }
  return k;
}
int main() 
{
  int n;
  cin>>n;
  int x = 1<<n;
  for(int i=0; i<x; i++){
      int y = (i^(i>>1));
      cout<<binary(y, n)<<endl;
  }
}
