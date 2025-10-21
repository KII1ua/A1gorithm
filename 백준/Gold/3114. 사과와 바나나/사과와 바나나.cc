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
int apple[1501][1501];
int banana[1501][1501];
int dp[1501][1501];

void Print() {
    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= M; j++) {
    //         cout << apple[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for(int i = 1; i <= N; i++) {
    //     for(int j = 1; j <= M; j++) {
    //         cout << banana[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // cout << endl;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            apple[i][j] += apple[i-1][j];
            banana[i][j] += banana[i-1][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(j == 1) {        // 아래로만 올 수 있음
                dp[i][j] = apple[N][1] - apple[i][j];
            }
            else {
                int fruits = (apple[N][j] - apple[i][j]) + banana[i-1][j];
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + fruits);        // 대각선
                dp[i][j] = max(dp[i][j], dp[i][j-1] + fruits);          // 오른쪽
                dp[i][j] = max(dp[i][j], dp[i-1][j] - (apple[i][j] - apple[i-1][j]));       // 아래
            }
        }
    }

    cout << dp[N][M];
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            char a;
            int b;
            cin >> a >> b;

            if(a == 'A') {
                apple[i][j] = b;
            }
            else banana[i][j] = b;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
