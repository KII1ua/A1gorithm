#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e10

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M, P;
char graph[1001][1001];
int turncnt[10];            // 사용자 턴 횟수
int castlecnt[10];          // 사용자 섬 개수
vector<pii> v[10];

void solve() {
    bool flag = false;
    while(!flag) {
        int totalmove = 0;
        for(int i = 1; i <= P; i++) {       // 어떤 플레이어의 턴인지
            for(int j = 0; j < turncnt[i]; j++) {       // 플레이어 턴 횟수
                int step = 0;
                vector<pii> tmp;
                for(auto it : v[i]) {
                    for(int k = 0; k < 4; k++) {
                        int nx = it.first + dx[k];
                        int ny = it.second + dy[k];

                        if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;

                        if(graph[nx][ny] == '#' || graph[nx][ny] >= 49) continue;

                        tmp.push_back({nx, ny});
                        graph[nx][ny] = graph[it.first][it.second];
                        step++;
                        totalmove++;
                        castlecnt[i]++;
                    }
                }
                if(step == 0) break;
                v[i] = tmp;
            }
        }
        if(totalmove == 0) flag = true;
    }

    for(int i = 1; i <= P; i++) {
        cout << castlecnt[i] << " ";
    }
}

void input() {
    cin >> N >> M >> P;

    for(int i = 1; i <= P; i++) {
        cin >> turncnt[i];
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] >= 49 && graph[i][j] <= 57) {
                v[graph[i][j] - '0'].push_back({i, j});
                castlecnt[graph[i][j] - '0']++;
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