#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int left, right;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
int N, M;
int answer = INF;
int graph[8][8];
vector<pii> v;

void check(int x, int y, int dir) {
    dir %= 4;

    while(true) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        x = nx;
        y = ny;

        // 범위 밖으로 나간경우
        if(x < 0 || x >= N || y < 0 || y >= M) return;

        // 벽을 만난 경우
        if(graph[x][y] == 6) return;

        if(graph[x][y] != 0) continue;
        graph[x][y] = -1;
    }
}

void bt(int idx) {
    if(idx == v.size()) {
        int cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(!graph[i][j]) cnt++;
            }
        }

        answer = min(answer, cnt);

        return;
    }
    int tmpgraph[8][8];

    int x = v[idx].first;
    int y = v[idx].second;

    for(int dir = 0; dir < 4; dir++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                tmpgraph[i][j] = graph[i][j];
            }
        }

        // 아래, 오른쪽 위 왼쪽
        if(graph[x][y] == 1) {
            check(x, y, dir);
        }
        else if(graph[x][y] == 2) {
            check(x, y, dir+1);
            check(x, y, dir+3);
        }
        else if(graph[x][y] == 3) {
            check(x, y, dir+1);
            check(x, y, dir+2);
        }
        else if(graph[x][y] == 4) {
            check(x, y, dir+1);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }
        else {
            check(x, y, dir);
            check(x, y, dir+1);
            check(x, y, dir+2);
            check(x, y, dir+3);
        }

        bt(idx+1);

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                graph[i][j] = tmpgraph[i][j];
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] != 0 && graph[i][j] != 6) {
                v.push_back({i, j});
            }
        }
    }

    bt(0);

    cout << answer;
}