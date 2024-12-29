// baekjoon 1012
#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int graph[50][50] = {0};
int T, M, N, K, a, b;
int cnt = 0;

//bool compare(strig a, string b) {
//    if(a.length() == b.length())
//        return a < b;
//    else
//        return a.length() < b.length();
//}

void dfs(int x, int y) {
    graph[x][y] = 0;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        if(graph[nx][ny] == 1) {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    for(int u = 0; u < T; u++) {
        cin >> M >> N >> K;

        for(int i = 0; i < K; i++) {
            cin >> a >> b;
            graph[b][a] = 1;
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if(graph[i][j] == 1) {
                    dfs(i, j);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        cnt = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                graph[i][j] = 0;
            }
        }
    }
}