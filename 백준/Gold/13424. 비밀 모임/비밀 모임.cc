// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int T, N, M, K;
int graph[101][101];
int arr[101];
int road[101];

void solve() {
    pii result = {0, INF};

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                graph[j][k] = min(graph[j][i] + graph[i][k], graph[j][k]);
            }
        }
    }

    for(int i = 1; i <= K; i++) {
        for(int j = 1; j <= N; j++) {
            road[j] += graph[arr[i]][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        if(result.second > road[i]) {
            result = {i, road[i]};
        }
    }

    cout << result.first << endl;
}

void input() {
    cin >> T;
    while (T--) {
        cin >> N >> M;

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(i == j) graph[i][j] = 0;
                else graph[i][j] = INF;
            }
        }

        for(int j = 0; j < M; j++) {
            int a, b, c;
            cin >> a >> b >> c;
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[b][a], c);
        }

        cin >> K;

        for(int i = 1; i <= K; i++) {
            cin >> arr[i];
        }

        memset(road, 0, sizeof(road));

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
