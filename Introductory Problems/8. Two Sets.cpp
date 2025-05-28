// dp approach 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

bool f(int n, int sum, int index, vector<int>&seq, vector<int>&ans, vector<int>&np,  vector<int>&ans2) {
    if (sum == 0){
      ans = seq;
      ans2 = np;
      return true;
    }
    if(index>n) return false;
    np.push_back(index);
    bool notpick = f(n, sum, index+1, seq, ans, np, ans2);
    np.pop_back();
    bool pick = false; 
    if(index<=sum){
      seq.push_back(index);
      pick = f(n, sum-index, index+1, seq, ans, np, ans2); 
      seq.pop_back();
    }
    return pick || notpick; 
}

int main() {
    int n;
    cin >> n;
    vector<int>seq, ans;
    vector<int>notpick, ans2;
    long long total = (n*(n+1))/2;
    if(total%2){
      cout<<"NO"<<endl;
    }
    else{
      bool x = f(n, total/2, 1, seq, ans, notpick, ans2);
      if(x==false){
        cout<<"NO"<<endl;
      }
      else{
        cout<<"YES"<<endl;
        cout<<ans.size()<<endl;
        for(int i: ans){
          cout<<i<<" ";
        }
        cout<<endl;
        cout<<n-ans.size()<<endl;
        for(int i: ans2){
          cout<<i<<" ";
        }
        cout<<endl;
      }
    }
    
}

// mathematical approach 
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main() {
  long long n;
  cin >> n;
  set<long long>pick;
  set<long long>np;
  long long total = (long long)(n*(n+1));
  total = total/2;
  cout<<total<<endl;
  if(total%2){
    cout<<"NO"<<endl;
  }
  else{
    long long target = total/2; 
    long long largest = n; 
    while(target >=0 && target>=largest){
      pick.insert(largest); 
      target -= largest; 
      largest--;
    }
    if(target != 0) pick.insert(target); 
    cout<<"YES"<<endl;
    cout<<pick.size()<<endl;
    for(auto it: pick){
      cout<<it<<" ";
    }
    cout<<endl;
    cout<<n-pick.size()<<endl;
    for(int i=1; i<=n; i++){
      if(pick.find(i)==pick.end()){
        cout<<i<<" ";
      }
    }
    cout<<endl;
  }
}
