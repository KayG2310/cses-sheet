#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  cin>>n;
  if(n==1) cout<<1<<endl;
  else if(n<=3) cout<<"NO SOLUTION"<<endl;
  else{
    int i=2;
    while(i<=n){
      cout<<i<<" ";
      i+=2;
    }
    i=1;
    while(i<=n){
      cout<<i<<" ";
      i+=2;
    }
  }
}
/*
7
6 2 4 7 3 5 1
*/
