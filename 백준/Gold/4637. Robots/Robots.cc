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
int N, M, cnt;
int graph[25][25];

void dfs(int x, int y) {
    if(x == 24 && y == 24) {
        if(graph[x][y] == 1) {
            cnt--;
        }
        return;
    }

    for(int i = x; i <= 24; i++) {
        for(int j = y; j <= 24; j++) {
            if(graph[i][j] == 1) {
                cnt--;
                graph[i][j] = 0;
                dfs(i, j);
                return;
            }
        }
    }

    return;
}

void solve() {
    int answer = 0;

    while(cnt > 0) {
        dfs(0, 0);
        answer++;
    }

    cout << answer << endl;
}

void input() {
    while(true) {
        int a, b;
        cin >> a >> b;

        if(a == -1 && b == -1) return;

        if(a == 0 && b == 0) {
            solve();
            cnt = 0;
            continue;
        }

        graph[a][b] = 1;
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
