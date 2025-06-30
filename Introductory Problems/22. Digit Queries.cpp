#include <bits/stdc++.h>
#define ll long long
using namespace std;
void dig(ll n){
  ll digit = 1, base = 9, total = 0;
  while (total + base * digit < n) {
    total += digit * base;
    base *= 10;
    digit++;
  }
  n -= total;
  ll num = pow(10, digit - 1);
  num += (n - 1) / digit;
  ll index = (n - 1) % digit;
  string s = to_string(num);
  cout<<s[index] - '0'<<endl;
}

int main() {
  int q;
  cin>>q;
  for(int i=0; i<q; i++){
    ll k; cin>>k;
    dig(k);
  }
}
