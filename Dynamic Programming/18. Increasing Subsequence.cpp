// recursive code 
#include <bits/stdc++.h>
using namespace std;
int f(int index, int n, vector<int>&arr, int prev){
  if(index==n) return 0;
  int len = 0;
  if(arr[index]>arr[prev]){
    // we can choose 
    len = max(len, 1+f(index+1, n, arr, index));
  }
  // in any case, move ahead as well
  len = max(len, f(index+1, n, arr, prev));
  return len;
}
int main() 
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  arr.insert(arr.begin(), 0);
  cout<< f(1, n+1, arr, 0);
} 

// will give tle 
// binary search approach 
#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int n;
  cin>>n;
  vector<int>arr(n);
  for(int i=0; i<n; i++){
    cin>>arr[i];
  }
  vector<int>temp;
  temp.push_back(arr[0]);
  for(int i=1; i<arr.size(); i++){
    if(arr[i]>temp.back()) temp.push_back(arr[i]);
    else{
      int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
      temp[ind] = arr[i];
    }
  }
  for(int i=0; i<temp.size(); i++) cout<<temp[i]<<" ";
  cout<<endl;
  cout<<temp.size();
}
// 2 5 6 9 8    
