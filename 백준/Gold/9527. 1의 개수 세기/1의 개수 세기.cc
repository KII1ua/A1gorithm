#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 100005;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
ll A, B;
ll dp[55];

ll func(ll x) {
    ll cnt = x & 1LL;
    for(int i = 54; i > 0; i--) {
        if(x & (1LL << i)) {
            cnt += dp[i-1] + (x - (1LL << i) + 1);
            x -= (1LL << i);
        }
    }

    return cnt;
}

void solve() {
    dp[0] = 1;
    for(int i = 1; i < 55; i++) {
        dp[i] = (dp[i-1] * 2) + (1LL << i);
    }

    cout << func(B) - func(A-1);
}

void input() {
    cin >> A >> B;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}