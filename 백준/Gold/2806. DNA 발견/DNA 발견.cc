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
int N;
int dp[1000001][2];     // 0 -> A, 1 -> B
string s;

void solve() {
    for(int i = 0; i < N; i++) {
        dp[i][0] = dp[i][1] = MAX;
    }

    if(s[0] == 'A') {
        dp[0][0] = 0, dp[0][1] = 1;
    }
    else {
        dp[0][0] = 1, dp[0][1] = 0;
    }

    for(int i = 1; i < N; i++) {
        if(s[i] == 'A') {       // 현재 문자가 A인 경우 현재까지 A인 상태를 가져옴,
                                // 지금까지 B인 상태에서 전부 뒤집고 나서 가져옴
            dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1);     // A로 만드는데 최소 비용 (이전에 A문자일때 최소비용을 그냥 가져옴, 이전에 B문자일때 최소비용을 가져와서 1을 더함)
            dp[i][1] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);     // B로 만드는데 최소 비용 (이전에 A문자일때의 최소비용을 가져오고 + 1, 이전에 B문자일때의 최소비용을 가져오고 + 1)
        }
        else {                  // 현재 문자가 B인 경우 현재까지 B인 상태를 가져옴,
                                // 지금까지 A인 상태에서 전부 뒤집고 나서 가져옴
            dp[i][0] = min(dp[i-1][1] + 1, dp[i-1][0] + 1);     // A로 만드는데 최소 비용
            dp[i][1] = min(dp[i-1][1], dp[i-1][0] + 1);     // B로 만드는데 최소 비용
        }
    }

    cout << dp[N-1][0];
}

void input() {
        cin >> N >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
