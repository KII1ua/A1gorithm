#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int T, N, M;
int dp[10001];
int coin[10001];

void Init() {
    memset(dp, 0, sizeof(dp));
}

void solve() {
    dp[0] = 1;

    for(int i = 1; i <= N; i++) {
        for(int j = coin[i]; j <= M; j++) {
            dp[j] = dp[j] + dp[j - coin[i]];
        }
    }

    cout << dp[M] << endl;
}

void input() {
    cin >> T;

    while(T--) {
        Init();
        cin >> N;

        for(int i = 1; i <= N; i++) {
            cin >> coin[i];
        }

        cin >> M;
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}