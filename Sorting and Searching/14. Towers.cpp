// n log n complexity 
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n; cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  vector<int>towers;
  towers.push_back(arr[0]);
  for(int k=1; k<n; k++){
    int low = 0, high = towers.size()-1; int ans = high+1;
    while(low<=high){
      int mid = (low+high)/2;
      if(towers[mid]>arr[k]){
        ans = min(ans, mid);
        high = mid-1;
      }
      else{
        low = mid+1;
      }
    }
    if(ans == towers.size()){
      towers.push_back(arr[k]);
    }
    else{
      towers[ans] = arr[k];
    }
  }
  cout<<towers.size()<<endl;
  
}
