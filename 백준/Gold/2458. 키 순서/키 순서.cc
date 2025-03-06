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
bool graph[501][501];
int result[501];
int res;

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = true;
    }
}

void solve() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                if(graph[i][k] && graph[k][j]) graph[i][j] = true;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(graph[i][j] || graph[j][i]) {
                result[i]++;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(result[i] == N-1) res++;
    }

    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
