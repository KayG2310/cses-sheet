#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> board;
vector<vector<int>> dist;
vector<vector<pair<int, char>>> parent;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char dir[4] = {'U', 'D', 'L', 'R'};

bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && board[x][y] != '#';
}

int main() {
    cin >> n >> m;
    board.resize(n);
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, char>>(m, {-1, '?'}));

    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'A') sx = i, sy = j;
            if (board[i][j] == 'B') ex = i, ey = j;
        }
    }

    queue<pair<int, int>> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (isValid(nx, ny) && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x * m + y, dir[d]};
                q.push({nx, ny});
            }
        }
    }

    if (dist[ex][ey] == -1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << dist[ex][ey] << '\n';
        string path;
        int x = ex, y = ey;
        while (x != sx || y != sy) {
            auto [p, ch] = parent[x][y];
            path += ch;
            int px = p / m, py = p % m;
            x = px, y = py;
        }
        reverse(path.begin(), path.end());
        cout << path << '\n';
    }

    return 0;
}
