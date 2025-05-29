#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n, x;
  cin>>n>>x;
  vector<int>weights(n);
  for(int i=0; i<n; i++){
    cin>>weights[i];
  }
  sort(weights.begin(), weights.end());
  int i=0, j= n-1, cnt=0;
  while(i<=j){
    if(weights[i]+weights[j]<=x){
      i++; 
      j--;
    }
    else{
      j--;
    }
    cnt++;
  }
  cout<<cnt<<endl;
  
}
