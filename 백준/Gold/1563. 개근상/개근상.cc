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
int N;
ll dp[1001][3][4];      // 전체일수, 지각 횟수, 결석 횟수

ll solve(int len, int late, int absent) {
    if(dp[len][late][absent] != -1) return dp[len][late][absent];
    if(late > 1 || absent == 3) {
        return 0;
    }
    if(len > N-1) return 1;

    dp[len][late][absent] = 0;

    dp[len][late][absent] = solve(len+1, late+1, 0) + solve(len+1, late, absent+1)
                                + solve(len+1, late, 0);

    return dp[len][late][absent] % 1000000;
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0, 0);
}