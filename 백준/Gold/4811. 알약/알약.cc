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
int T;
ll dp[31];

ll solve() {
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= T; i++) {
        for(int j = 1; j <= i; j++) {
            dp[i] += dp[i-j] * dp[j-1];
        }
    }
    return dp[T];
}

void input() {
    while(true) {
        cin >> T;

        if(T == 0) break;

        cout << solve() << endl;
        memset(dp, 0, sizeof(dp));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}