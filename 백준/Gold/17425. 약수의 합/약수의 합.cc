#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1000001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, N;
ll dp[MAX];

void solve() {
    cout << dp[N] << endl;
}

void Init() {
    for(int i = 1; i < MAX; i++) {
        for(int j = i; j < MAX; j += i) {
            dp[j] += i;
        }
        dp[i] += dp[i-1];
    }
}

void input() {
    cin >> T;

    Init();

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