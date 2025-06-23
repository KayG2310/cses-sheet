#include <bits/stdc++.h>
using namespace std;


int main() {
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  int i=0, j=0, ans = 0;
  set<int>s;
  while(j<n){
    if(s.find(arr[j]) == s.end()){
      s.insert(arr[j]);
      ans = max(ans, j-i+1);
      j++;
    }
    while(i<j && s.find(arr[j]) != s.end()){
      s.erase(arr[i]);
      i++;
    }
  }
  cout<<ans<<endl;
}
/*
1 2 1 3 2 7 4 2
i 
j 
*/
