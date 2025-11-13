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
int T;
ll N;
int dp[101];

int func(int n, int money) {
    if(n == money) return 0;
    if(n > money) return MAX;
    if(dp[n] != -1) return dp[n];
    int &ret = dp[n];
    ret = MAX;
    ret = min({func(n+1, money) + 1, func(n+10, money) + 1, func(n + 25, money) + 1});

    return ret;
}

void solve() {
    ll tmp = 0;
    int answer = 0;
    while(N != 0) {
        memset(dp, -1, sizeof(dp));
        tmp = N % 100;
        answer += func(0, tmp);
        N /= 100;
    }

    cout << answer << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
