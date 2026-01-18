#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e14 + 1;
const int MAX = 502;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int X;
int cnt[4];
int dp[10001][5];       // dp[i][j] = i원을 만들었을때 j센트의 개수 dp[i][4] = 총 개수

void solve() {
    int arr[4] = {1, 5, 10, 25};

    for(int i = 0; i < 5; i++) {
        dp[0][i] = 0;
    }

    for(int i = 0; i <= X; i++) {
        if(dp[i][4] == -1) continue;

        for(int j = 0; j < 4; j++) {
            int money = i + arr[j];

            if(money > X) continue;

            if(dp[i][j] < cnt[j]) {

                if(dp[money][4] < dp[i][4] + 1) {
                    for(int k = 0; k < 5; k++) {
                        dp[money][k] = dp[i][k];
                    }
                    dp[money][j]++;
                    dp[money][4]++;
                }
            }
        }
    }

    if(dp[X][4] == -1) {
        for(int i = 0; i < 4; i++) {
            cout << 0 << " ";
        }
    }
    else {
        for(int i = 0; i < 4; i++) {
            cout << dp[X][i] << " ";
        }
    }
}

void input() {
    cin >> X;

    for(int i = 0; i < 4; i++) {
        cin >> cnt[i];
    }

    memset(dp, -1, sizeof(dp));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}