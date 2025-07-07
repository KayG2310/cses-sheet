#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<ll, int>
const ll INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    // dist[u][0] = without discount, dist[u][1] = with discount
    vector<vector<ll>> dist(n + 1, vector<ll>(2, INF));
    dist[1][0] = 0;
    priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;
    pq.push({0, 1, 0}); // {cost, node, used_discount}

    while (!pq.empty()) {
        auto [d, u, used] = pq.top(); pq.pop();
        if (d > dist[u][used]) continue;

        for (auto [v, w] : adj[u]) {
            // Case 1: No discount used yet
            if (used == 0) {
                // No discount on this edge
                if (dist[v][0] > dist[u][0] + w) {
                    dist[v][0] = dist[u][0] + w;
                    pq.push({dist[v][0], v, 0});
                }
                // Use discount on this edge
                if (dist[v][1] > dist[u][0] + w / 2) {
                    dist[v][1] = dist[u][0] + w / 2;
                    pq.push({dist[v][1], v, 1});
                }
            } else {
                // Discount already used
                if (dist[v][1] > dist[u][1] + w) {
                    dist[v][1] = dist[u][1] + w;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << "\n"; // answer is with discount used
}
