#include <bits/stdc++.h>
using namespace std;

void f(string &s, vector<bool> &vis, string &seq, set<string> &st) {
  if (seq.length() == s.length()) {
    st.insert(seq);
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    if (!vis[i]) {
      vis[i] = true;
      seq += s[i];
      f(s, vis, seq, st);
      seq.pop_back();
      vis[i] = false;
    }
  }
}

int main() {
  string s;
  cin >> s;
  int n = s.length();
  set<string> st;
  vector<bool> vis(n, false);
  string seq = "";
  f(s, vis, seq, st);
  cout << st.size() << endl;
  for (auto it : st) {
      cout << it << endl;
  }
}
