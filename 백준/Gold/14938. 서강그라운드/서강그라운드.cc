// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int n, m, r, result;
int sector[101];
int graph[101][101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) {
        cin >> sector[i];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }

    for(int i = 1; i <= r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a][b] = l;
        graph[b][a] = l;
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        int res = 0;
        for(int j = 1; j <= n; j++) {
            if(graph[i][j] <= m) {
                res += sector[j];
            }
        }
        result = max(res, result);
    }

    cout << result;
}
