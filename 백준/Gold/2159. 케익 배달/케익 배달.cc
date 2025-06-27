#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e10

struct coordinate {
    int x;
    int y;
};

//int dx[] = {0,0, 1, -1, 0, 1, -1, -1, 1};
//int dy[] = {0,1, 0, 0, -1, -1, 1, -1, 1};
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int N, X, Y;
pii arr[100001];
ll dp[100001][5];

int manhatan(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

bool check(int x, int y) {
    if(x < 1 || x > 100000 || y < 1 || y > 100000) return false;
    return true;
}

void solve() {
    for(int i = 0; i < 5; i++) {
        int nx = arr[0].first + dx[i];
        int ny = arr[0].second + dy[i];

        if(!check(nx, ny)) continue;

        int cost = manhatan(X, Y, nx, ny);

        dp[0][i] = cost;
    }

    for(int i = 1; i < N; i++) {

        for(int j = 0; j < 5; j++) {
            int nx = arr[i].first + dx[j];
            int ny = arr[i].second + dy[j];

            if(!check(nx, ny)) continue;

            for(int k = 0; k < 5; k++) {
                int cx = arr[i-1].first + dx[k];
                int cy = arr[i-1].second + dy[k];

                if(!check(cx, cy)) continue;

                ll cost = manhatan(cx, cy, nx, ny);

                dp[i][j] = min(dp[i][j], dp[i-1][k] + cost);
            }
        }
    }
    ll result = MAX;

    for(int i = 0; i < 5; i++) {
        result = min(result, dp[N-1][i]);
    }
    cout << result;
}

void input() {
    cin >> N >> X >> Y;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        arr[i].first = a;
        arr[i].second = b;
        for(int j = 0; j < 5; j++) {
            dp[i][j] = MAX;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}