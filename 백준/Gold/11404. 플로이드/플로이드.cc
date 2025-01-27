// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int visited[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(i == j) visited[i][j] = 0;
            else visited[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(visited[a][b] < c) continue;
        visited[a][b] = c;
    }

    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                visited[i][j] = min(visited[i][j], visited[i][k] + visited[k][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if(visited[i][j] != INF) cout << visited[i][j] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}
