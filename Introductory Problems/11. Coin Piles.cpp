#include <bits/stdc++.h>
using namespace std;

long long minn(long long l, long long r){
  if(l<r) return l;
  return r;
}
int main() 
{
  int t;
  cin>>t;
  while(t--){
    long long left, right;
    cin>>left>>right; 
    if(left==right*2 || right == left*2){
      cout<<"YES"<<endl;
    }
    else if((left+right)%3==0){
      if(minn(left, right)>=(left+right)/3){
        cout<<"YES"<<endl;
      }
      else{
        cout<<"NO"<<endl;
      }
    }
    else{
      cout<<"NO"<<endl;
    }
  }
  
}
/*

*/
