// 
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ppi pair<pair<int,int>,int>
 
int main() {
    int n;
    cin>>n;
    set<ppi> pq;
    set<pii> rpq;
    vector<int> allocation(n);
    for(int i=0;i<n;i++){
        int in,out;
        cin>>in>>out;
        pq.insert({{in,out},i});
    }
    int room=0;
    for(auto x:pq){
        int in=x.first.first;
        int out=x.first.second;
        int idx=x.second;
        if(rpq.empty()){
            ++room;
            rpq.insert({out,room});
            allocation[idx]=room;
        }
        else{
            auto it=rpq.begin();
            int dep=it->first;
            int rno=it->second;
            if(dep<in){   //same room
                rpq.erase(it);
                rpq.insert({out,rno});
                allocation[idx]=rno;
            }
            else{
                ++room;
                rpq.insert({out,room});
                allocation[idx]=room;
            }
        }
    }
    cout<<room<<endl;
    for(int i=0;i<n;i++){
        cout<<allocation[i]<<" ";
    }
    cout<<endl;
    return 0;
}
