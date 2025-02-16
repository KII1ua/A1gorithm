// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int R, C, K;
int cnt;
int graph[6][6];
bool visited[6][6];

void bt(int x, int y, int z) {
    if(x == 0 && y == C-1 && z == K) {
        cnt++;
        return;
    }

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(x >= 0 && y >= 0 && x < R && y < C) {
            if(!visited[nx][ny] && graph[x][y] != 1) {
                visited[nx][ny] = true;
                bt(nx, ny, z+1);
                visited[nx][ny] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C >> K;

    cin.ignore();

    for(int i = 0; i < R; i++) {
        string s;
        getline(cin, s);
        for(int j = 0; j < C; j++) {
            if(s[j] == '.') {
                graph[i][j] = 0;
            }
            else {
                graph[i][j] = 1;
            }
        }
    }

    visited[R-1][0] = true;
    bt(R-1, 0, 1);

    cout << cnt;
}

