#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N;
int dp[21];

void solve() {
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 4; i <= N; i++) {
        if(i % 2 == 0) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }
        else {
            dp[i] = dp[i-1] * 2;
        }
    }

    cout << dp[N];
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}