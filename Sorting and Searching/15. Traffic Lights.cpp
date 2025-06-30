// idk why it gave TLE 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int x, n;
  cin >>x>> n;
  set<int>lights;
  multiset<int>segments;
  lights.insert(0);
  lights.insert(x);
  segments.insert(x);
  for (int i=0; i<n; i++) {
    int pos;
    cin>>pos;
    auto upper = lights.upper_bound(pos); 
    auto lower = prev(upper); 
    int right = *upper;
    int left = *lower;
    segments.erase(segments.find(right - left));
    segments.insert(pos - left);
    segments.insert(right - pos);
    lights.insert(pos);
    cout << *segments.rbegin() << " ";
  }
}

// optimised code ---> map access is easier 
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  int x, n;
  cin >>x>> n;
  set<int>lights;
  map<int, int>segments;
  lights.insert(0);
  lights.insert(x);
  segments[x]++;
  for (int i=0; i<n; i++) {
    int pos;
    cin>>pos;
    auto upper = lights.upper_bound(pos); 
    auto lower = prev(upper); 
    int right = *upper;
    int left = *lower;
    segments[right-left]--;
    if(segments[right-left]==0) segments.erase(right-left);
    segments[pos - left]++;;
    segments[right - pos]++;
    lights.insert(pos);
    cout << (*segments.rbegin()).first << " ";
  }
}
