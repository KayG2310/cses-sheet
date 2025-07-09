#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin>>n;
    set<int>s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    auto it=s.begin();
    it++;
    int i=1;
    while(!s.empty()){
        //cout<<"iteration"<<i<<endl;
        if(it==s.end()) it=s.begin();
        if(s.size()==1){
            int x=*it;
            s.erase(x);
            cout<<x<<" "; 
            break;
        }
        int x=*it;
        auto copy=it;
        copy++; if(copy==s.end()) copy=s.begin();
        if(s.size()>2){
            copy++; if(copy==s.end()) copy=s.begin();
        }
        s.erase(it);
        it=copy;
        cout<<x<<" ";
        i++;
    }
    cout<<endl;
    return 0;
}
