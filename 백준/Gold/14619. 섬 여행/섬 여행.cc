#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M, T;
int arr[101];
int oddgraph[101][101];
int evengraph[101][101];

void solution(int x, int cnt) {
    int result = MAX;

    if(cnt % 2 == 0) {
        for(int i = 1; i <= N; i++) {
            if(evengraph[x][i] <= cnt) {
                result = min(result, arr[i]);
            }
        }
    }
    else {
        for(int i = 1; i <= N; i++) {
            if(oddgraph[x][i] <= cnt) {
                result = min(result, arr[i]);
            }
        }
    }

    if(result != MAX) {
        cout << result << endl;
    }
    else cout << -1 << endl;
}

void solve() {
    for(int k = 1; k <= N; k++) {
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                oddgraph[i][j] = min(oddgraph[i][j], oddgraph[i][k] + evengraph[k][j]);
                oddgraph[i][j] = min(oddgraph[i][j], evengraph[i][k] + oddgraph[k][j]);

                evengraph[i][j] = min(evengraph[i][j], oddgraph[i][k] + oddgraph[k][j]);
                evengraph[i][j] = min(evengraph[i][j], evengraph[i][k] + evengraph[k][j]);
            }
        }
    }
}

void setting() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            oddgraph[i][j] = MAX;
            evengraph[i][j] = MAX;
        }
    }
}

void input() {
    cin >> N >> M;
    setting();

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        oddgraph[x][y] = 1;
        oddgraph[y][x] = 1;
    }

    solve();

    cin >> T;

    for(int i = 0; i < T; i++) {
        int a, k;
        cin >> a >> k;
        solution(a, k);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
