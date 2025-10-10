#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
int N, K;
int graph[14][14];
vector<int> lst[14][14];
horse ware[14];

void Print() {
    for(int i = 0; i <= N+1; i++) {
        for(int j = 0; j <= N+1; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int changeDir(int dir) {
    if(dir == 1) return 2;
    if(dir == 2) return 1;
    if(dir == 3) return 4;
    if(dir == 4) return 3;

    return 0;
}


void solve() {
    int cnt = 0;

    while(true) {
        cnt++;

        if(cnt > 1000) {
            cout << -1;
            return;
        }
        for(int k = 1; k <= K; k++) {
            int x = ware[k].x;
            int y = ware[k].y;
            int dirs = ware[k].dir;

            if(lst[x][y].front() != k) continue;

            int nx = x + dx[dirs];
            int ny = y + dy[dirs];

            if(graph[nx][ny] == 2) {
                dirs = changeDir(dirs);

                nx += dx[dirs] * 2;
                ny += dy[dirs] * 2;
                ware[k].dir = dirs;

                if(graph[nx][ny] == 2) continue;
            }

            if(graph[nx][ny] == 0) {            // 다음 이동할 칸이 흰색인 경우
                for(int l = 0; l < lst[x][y].size(); l++) {
                    ware[lst[x][y][l]].x = nx;
                    ware[lst[x][y][l]].y = ny;

                    lst[nx][ny].push_back(lst[x][y][l]);
                }

                lst[x][y].clear();
            }
            else if(graph[nx][ny] == 1) {
                reverse(lst[x][y].begin(), lst[x][y].end());

                for(int l = 0; l < lst[x][y].size(); l++) {
                    ware[lst[x][y][l]].x = nx;
                    ware[lst[x][y][l]].y = ny;

                    lst[nx][ny].push_back(lst[x][y][l]);
                }

                lst[x][y].clear();
            }
            if(lst[nx][ny].size() >= 4) {
                cout << cnt;
                return;
            }
        }
    }
}

void Init() {
    for(int i = 0; i <= N+1; i++) {
        for(int j = 0; j <= N+1; j++) {
            graph[i][j] = 2;
        }
    }
}

void input() {
    cin >> N >> K;

    Init();

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 1; i <= K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ware[i].x = a;
        ware[i].y = b;
        ware[i].dir = c;

        lst[a][b].push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
