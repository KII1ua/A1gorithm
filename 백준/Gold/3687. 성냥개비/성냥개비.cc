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
int T, N;
int min_match[10] = {0, 0, 1, 7, 4, 2, 0, 8, 10};
ll dp[101] = {0, 0, 1, 7, 4, 2, 6, 8, 10};

void solve() {
    for(int i = 9; i <= 100; i++) {
        dp[i] = dp[i-2] * 10 + min_match[2];
        for(int j = 3; j < 8; j++) {
            dp[i] = min(dp[i], dp[i-j] * 10 + min_match[j]);
        }
    }
}

void input() {
    cin >> T;

    solve();

    while(T--) {
        cin >> N;

        cout << dp[N] << " ";

        if(N % 2 == 0) {
            for(int i = 0; i < N / 2; i++) {
                cout << 1;
            }
        }
        else {
            cout << 7;
            for(int i = 0; i < N / 2 - 1; i++) {
                cout << 1;
            }
        }
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
