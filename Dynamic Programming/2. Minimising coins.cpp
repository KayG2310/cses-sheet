#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n, x;
  cin>>n>>x;
  vector<int>coins(n);
  for(int i=0; i<n; i++){
    cin>>coins[i];
  }
  // inputting done 
  vector<int>prev(x+1, 0), cur(x+1, 0);
  for(int i=0; i<=x; i++){
    if(i%coins[0]==0){
      prev[i] = i/coins[0];
      cur[i] = i/coins[0];
    }
    else{
      prev[i] = 1e9;
      cur[i] = 1e9;
    }
  }
  for(int index=1; index<n; index++){
      for(int amt = 1; amt<=x; amt++){
          int notpick = prev[amt];
          int pick = 1e9;
          if(coins[index]<= amt) pick = 1+ cur[amt-coins[index]];
          cur[amt] = min(pick, notpick);
      }
      prev = cur;
  }
  int y = prev[x];
  if(y==1e9){
    cout<<-1<<endl;
  }
  else{
    cout<<y<<endl;
  }
  
}
