#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e18

struct coordinate {
    int x;
    int y;
    int r;
};

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int graph[1001][1001];

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            graph[i][j] += max({graph[i-1][j], graph[i][j-1], graph[i-1][j-1]});
        }
    }

    cout << graph[N][M];
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
