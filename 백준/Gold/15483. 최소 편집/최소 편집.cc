#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
string a, b;
int dp[1001][1001];

void solve() {
    for(int i = 0; i <= a.size(); i++) {
        dp[i][0] = i;
    }

    for(int i = 0; i <= b.size(); i++) {
        dp[0][i] = i;
    }

    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            int tmp = 1;
            if(a[i] == b[j]) {
                tmp = 0;
            }
            dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + tmp});
        }
    }

    cout << dp[a.size()-1][b.size()-1];
}

void input() {
    cin >> a >> b;

    a.insert(0, " ");
    b.insert(0, " ");
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}