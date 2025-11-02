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
int N, M;
int graph[101][101];
int trash;

void dfs(int x, int y) {
    if(x == N-1 && y == M-1) {
        if(graph[x][y] == 1) {
            trash--;
            graph[x][y] = 0;
        }
        return;
    }

    for(int i = x; i < N; i++) {
        for(int j = y; j < M; j++) {
            if(graph[i][j] == 1) {
                graph[i][j] = 0;
                trash--;
                dfs(i, j);
                return;
            }
        }
    }

    return;
}

void solve() {
    int cnt = 0;

    while(trash > 0) {
        dfs(0, 0);
        cnt++;
    }

    cout << cnt;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 1) trash++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
