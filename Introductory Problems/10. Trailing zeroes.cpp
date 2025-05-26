#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main() 
{
  int n;
  cin>>n;
  int result = 0, x=0, i = 1;
  while(true){
    x = (n/pow(5,i));
    if(x==0) break;
    result+=x;
    i++;
  }
  cout<<result<<endl;
}
