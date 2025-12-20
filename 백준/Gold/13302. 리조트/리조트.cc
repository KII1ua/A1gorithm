#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
bool day[101];
int dp[101][101];

int func(int d, int coupon) {
    if(d > N) return 0;
    int &ret = dp[d][coupon];
    if(ret != INF) return ret;

    if(day[d]) {
        ret = func(d+1, coupon);
        return ret;
    }

    ret = min({func(d+1, coupon) + 10000, func(d+3, coupon+1) + 25000, func(d+5, coupon+2) + 37000, ret});
    if(coupon >= 3) {
        ret = min(ret, func(d+1, coupon-3));
    }

    return ret;
}

void solve() {
    cout << func(1, 0);
}

void Init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            dp[i][j] = INF;
        }
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        day[a] = true;
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}