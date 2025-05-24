#include <bits/stdc++.h>
using namespace std;

int main() 
{
  string s;
  cin>>s;
  int n = s.length();
  if(n==0 || n==1){
    cout<<n<<endl;
  }
  else{
    int cnt = 1;
    int maxlen = 1;
    for(int i=1; i<n; i++){
      if(s[i]==s[i-1]){
        cnt++;
        maxlen = max(maxlen, cnt);
      }
      else{
        cnt = 1;
      }
    }
    cout<<maxlen<<endl;
  }
}

/*
1 = 1 
1^2 = 3 
3^3 = 0 
0^4 = 4
4^5 = 1 
*/
