#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  cin>>n;
  long long xorr = 0;
  if(n%4 == 1){
    xorr = 1;
  }
  else if(n%4==2){
    xorr = n+1;
  }
  else if(n%4 == 3){
    xorr = 0;
  }
  else{
    xorr = n;
  }
  for(int i=0; i<n-1; i++){
    int y;
    cin>>y;
    xorr = xorr ^ y;
  }
  cout<<xorr<<endl;
}
/*
1 = 1 
1^2 = 3 
3^3 = 0 
0^4 = 4
4^5 = 1 
*/
