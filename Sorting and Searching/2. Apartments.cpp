#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
  int n, m, k;
  cin>>n>>m>>k;
  vector<int>applicants(n);
  for(int i=0; i<n; i++){
    cin>>applicants[i];
  }
  vector<int>size(m);
  for(int i=0; i<m; i++){
    cin>>size[i];
  }
  sort(applicants.begin(), applicants.end());
  sort(size.begin(), size.end());
  
  int i=0, j=0, cnt=0;
  while(i<n && j<m){
    if(applicants[i]-k<=size[j] && applicants[i]+k>=size[j]){
      cnt++;
      i++;
      j++;
    }
    else if(applicants[i]-k>size[j]){
      j++;
    }
    else if(applicants[i]+k<size[j]){
      i++;
    }
  }
  cout<<cnt<<endl;
}
