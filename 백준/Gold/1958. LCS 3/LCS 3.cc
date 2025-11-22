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
int dp[101][101][101];
string a, b, c;

void solve() {
    int answer = 0;

    a.insert(0, "1");
    b.insert(0, "2");
    c.insert(0, "3");

    for(int i = 1; i < a.size(); i++) {
        for(int j = 1; j < b.size(); j++) {
            for(int k = 1; k < c.size(); k++) {
                if(a[i] == b[j] && b[j] == c[k]) {
                    dp[i][j][k] = max(dp[i-1][j-1][k-1] + 1, dp[i][j][k]);
                    answer = max(answer, dp[i][j][k]);
                }
                else {
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                }
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> a >> b >> c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
