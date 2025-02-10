// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int D, K;
int dp[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> D >> K;

    for(int i = 1; i <= 100000; i++) {
        for(int j = 1; j <= 100000; j++) {
            dp[1] = i;
            dp[2] = j;

            for(int k = 3; k <= D; k++) {
                dp[k] = dp[k-1] + dp[k-2];
            }

            if(dp[D] == K) {
                cout << dp[1] << endl << dp[2];
                return 0;
            }
        }
    }
}
