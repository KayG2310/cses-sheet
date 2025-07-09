#include <bits/stdc++.h>
using namespace std;

int ans = 0;
bool col[8], diag1[15], diag2[15];
vector<vector<char>> board(8, vector<char>(8));

void dfs(int row) {
    if (row == 8) {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++) {
        if (board[row][c] == '*' || col[c] || diag1[row + c] || diag2[row - c + 7])
            continue;
        col[c] = diag1[row + c] = diag2[row - c + 7] = true;
        dfs(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + 7] = false;
    }
}

int main() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> board[i][j];
    dfs(0);
    cout << ans << endl;
}
