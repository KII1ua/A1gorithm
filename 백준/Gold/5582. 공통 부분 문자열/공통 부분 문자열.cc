#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 4002;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s1, s2;
int dp[MAX][MAX];

void solve() {
    s1.insert(0, "[");
    s2.insert(0, "]");

    int answer = 0;

    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            if(s1[i] == s2[j]) {
                dp[i][j] = max(dp[i-1][j-1] + 1, dp[i][j]);
            }
            answer = max(answer, dp[i][j]);
        }
    }

    cout << answer;
}

void input() {
    cin >> s1 >> s2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}