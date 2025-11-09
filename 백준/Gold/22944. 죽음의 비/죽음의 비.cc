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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, H, D;        // 크기, 체력, 내구도
char graph[501][501];
queue<tuple<int, int, int, int, int>> q;        // 좌표, 체력, 우산 내구도, 횟수
int dist[501][501];

int bfs() {
    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int hp = get<2>(q.front());
        int umbrella = get<3>(q.front());
        int depth = get<4>(q.front());
        q.pop();

        if(graph[x][y] == 'E') {
            return depth;
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int n_hp = hp;
            int n_umbrella = umbrella;
            int n_depth = depth+1;

            if(nx >= 0 && nx < N && ny >= 0 && ny < N) {
                if(graph[nx][ny] == '.') {
                    if(n_umbrella <= 0) {
                        n_hp--;
                    }
                    else {
                        n_umbrella--;
                    }
                }
                else if(graph[nx][ny] == 'U') {
                    n_umbrella = D;

                    if(n_umbrella <= 0) {
                        n_hp--;
                    }
                    else n_umbrella--;
                }

                if(n_hp > 0 && dist[nx][ny] < n_hp + n_umbrella) {
                    q.push({nx, ny, n_hp, n_umbrella, n_depth});
                    dist[nx][ny] = n_hp + n_umbrella;
                }
            }
        }
    }

    return -1;
}

void solve() {
    int answer = bfs();

    cout << answer;
}

void input() {
    cin >> N >> H >> D;

    for(int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < N; j++) {
            graph[i][j] = s[j];

            if(s[j] == 'S') {
                q.push({i, j, H, 0, 0});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
