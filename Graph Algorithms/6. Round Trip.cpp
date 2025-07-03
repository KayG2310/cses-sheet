#include <bits/stdc++.h>
using namespace std;

bool cycle(int node, int parent, vector<vector<int>>&adj, vector<int>&vis, vector<int>&p, int &start, int &end) {
    vis[node] = 1;
    p[node] = parent;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(cycle(it, node, adj, vis, p, start, end)) return true;
        }
        else if(it != parent) {
            start = it;
            end = node;
            return true;
        }
    }
    return false;
}

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>>adj(n + 1);
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>vis(n + 1, 0), parent(n + 1, -1);
    int start = -1, end = -1;

    for(int i = 1; i <= n; i++) {
        if(!vis[i] && cycle(i, -1, adj, vis, parent, start, end)) break;
    }

    if(start == -1) {
        cout << "IMPOSSIBLE\n";
    } else {
        vector<int>path;
        path.push_back(start);
        for(int v = end; v != start; v = parent[v]) path.push_back(v);
        path.push_back(start); // complete the cycle
        reverse(path.begin(), path.end());

        cout << path.size() << "\n";
        for(int x : path) cout << x << " ";
        cout << "\n";
    }
}
