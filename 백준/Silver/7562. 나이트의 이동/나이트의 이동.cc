// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

//int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
//int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {-2, -1, -2, -1, 1, 2, 2, 1};
int dy[] = {-1, -2, 1, 2, -2, -1, 1, 2};
int T, l;
int startx, starty, endx, endy;

int bfs(int x, int y) {
    bool visited[l][l];

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < l; j++) {
            visited[i][j] = false;
        }
    }
    queue<tuple<int, int, int>> q;
    q.push({x, y, 0});
    visited[x][y] = true;

    while (!q.empty()) {
        int xx = get<0>(q.front());
        int yy = get<1>(q.front());
        int dist = get<2>(q.front());
        q.pop();

        if (xx == endx && yy == endy) {
            return dist;
        }

        for (int i = 0; i < 8; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if (nx >= 0 && ny >= 0 && nx < l && ny < l)
                if (!visited[nx][ny]) {
                    q.push({nx, ny, dist + 1});
                    visited[nx][ny] = true;
                }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    for(int i = 0; i < T; i++) {
        cin >> l;
        cin >> startx >> starty >> endx >> endy;
        int result = bfs(startx, starty);
        cout << result << endl;
    }
}
