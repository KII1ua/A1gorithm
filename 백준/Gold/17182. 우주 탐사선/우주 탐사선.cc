// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, K;
int result = INF;
int graph[11][11];
bool visited[11];

void bt(int cnt, int idx, int presum) {
    if(cnt == N) {
        result = min(result, presum);
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            bt(cnt+1, i, presum + graph[idx][i]);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    for(int k = 0; k < N; k++) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                graph[i][j] = min(graph[i][k] + graph[k][j], graph[i][j]);
            }
        }
    }

    bt(0, K, 0);

    cout << result;
}
