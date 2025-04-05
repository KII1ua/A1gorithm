#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
string s;
int dp[41];

void solve() {
    dp[0] = 1;

    for(int i = 1; i < s.length(); i++) {
        if(s[i] != '0') dp[i] += dp[i-1];

        int n = stoi(s.substr(i-1, 2));

        if(10 <= n && n <= 34) {
            if(i - 2 >= 0) dp[i] += dp[i-2];
            else dp[i] += 1;
        }
    }

    cout << dp[s.length()-1];
}

void input() {
    cin >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
