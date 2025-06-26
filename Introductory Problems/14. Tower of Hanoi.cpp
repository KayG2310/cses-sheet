#include<bits/stdc++.h>
using namespace std;

void t(int n, int from_rod, int to_rod, int aux_rod, int& cnt)
{
  if (n == 0) {
    return;
  }
  t(n - 1, from_rod, aux_rod, to_rod, cnt);
  cnt++;
  t(n - 1, aux_rod, to_rod, from_rod, cnt);
}

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod)
{
  if (n == 0) {
    return;
  }
  towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
  cout <<from_rod<<" " <<to_rod<< endl;
  
  towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
  int n; cin>>n; int cnt = 0;
  t(n, 1, 3, 2, cnt);
  cout<<cnt<<endl;
  towerOfHanoi(n, 1, 3, 2);
}
