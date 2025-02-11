// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
ll dp[1000001];
int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> T;

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= 1000000; i++) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % (1000000009);
    }

    for(int i = 0; i < T; i++) {
        int a;
        cin >> a;
        cout << dp[a] << endl;
    }
}
