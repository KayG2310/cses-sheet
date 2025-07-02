#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int n; 
  cin>>n;
  vector<ll>arr(n+1); 
  for(int i=1; i<=n; i++){
    cin>>arr[i];
  }
  stack<int>st;
  st.push(1);
  cout<<0<<" ";
  for(int i=2; i<=n; i++){
    while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
    if(st.empty()) cout<<0<<" ";
    else cout<<st.top()<<" ";
    st.push(i);
  }
}
// 1 2 3 4
