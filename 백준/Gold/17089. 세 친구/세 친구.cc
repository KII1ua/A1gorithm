// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, M;
int graph[4001][4001];
int friends[4001];

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        graph[x][y] = 1;
        graph[y][x] = 1;
        friends[x]++;
        friends[y]++;
    }
}

void solve() {
    int res = -1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j])
                for (int k = 1; k <= N; k++) {
                    if (graph[i][k] && graph[j][k]) {
                        int result = friends[i] + friends[j] + friends[k] - 6;

                        if (res == -1 || res > result)
                            res = result;
                    }
                }
        }
    }

    cout << res;
}

void solution() {
    input();
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
