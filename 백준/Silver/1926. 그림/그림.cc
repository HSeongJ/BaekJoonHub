#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int board[501][501];
bool vis[501][501];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, cnt = 0, area = 0;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 1; i <=n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == 1) {
                cnt++;

                queue<pair<int,int>> queue;
                int tmp_area = 1;

                vis[i][j] = 1;
                queue.push({i, j});

                while(!queue.empty()) {
                    pair<int, int> cur = queue.front();
                    board[cur.X][cur.Y] = 0;
                    queue.pop();

                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                        if(vis[nx][ny] || board[nx][ny] == 0) continue;

                        vis[nx][ny] = 1;
                        queue.push({nx, ny});
                        tmp_area++;
                    }
                }

                if(area < tmp_area) {
                    area = tmp_area;
                }
            }
        }
    }

    cout << cnt << '\n' << area;
    return 0;
}
