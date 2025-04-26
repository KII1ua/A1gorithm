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
ll dp[110];

ll solve(int n) {
    if (n <= 0) return 0;
    ll &ret = dp[n];
    if (ret != -1) return ret;

    // 1. 그냥 A 하나 찍는 경우
    ret = solve(n - 1) + 1;

    // 2. Ctrl-A, Ctrl-C 이후 Ctrl-V 여러 번 하는 경우
    for (int i = 2; i <= n - 2; i++) {
        ret = max(ret, solve(i) * (n - i - 1));
    }

    return ret;
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    memset(dp, -1, sizeof(dp));
    cout << solve(N);
}