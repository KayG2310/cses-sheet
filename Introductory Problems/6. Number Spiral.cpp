#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() 
{
  int t;
  cin>>t;
  
  while(t--){
    ll y, x;
    // y is row 
    // x is col 
    cin>>y>>x;
    ll n = max(y, x);
    ll diagonal_element = n*n-n+1;
    swap(y,x);
    if(n%2){
      if(y>x){
        cout<<diagonal_element+(y-x)<<endl;
      }
      else if(x>y){
        cout<<diagonal_element-(x-y)<<endl;
      }
      else{
        cout<<diagonal_element<<endl;
      }
    }
    else{
      if(y>x){
        cout<<diagonal_element-(y-x)<<endl;
      }
      else if(x>y){
        cout<<diagonal_element+(x-y)<<endl;
      }
      else{
        cout<<diagonal_element<<endl;
      }
    }
  }
}
