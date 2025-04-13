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
int dp[1001][1001];

void solve() {
    dp[1][1] = dp[2][1] = dp[3][1] = 1;

    for(int i = 2; i < 1001; i++) {
        for(int j = 1; j < 1001; j++) {
            for(int k = 1; k < 4; k++) {
                if(j - k > 0) dp[j][i] += dp[j-k][i-1];
                dp[j][i] %= 1000000009;
            }
        }
    }
}

void input() {
    cin >> T;

    solve();

    for(int i = 0; i < T; i++) {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}