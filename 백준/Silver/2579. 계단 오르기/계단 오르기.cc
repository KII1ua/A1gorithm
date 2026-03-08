#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200000;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;

    cin >> N;

    vector<int> v(N, 0);
    vector<vector<int>> dp(N, vector<int>(3, 0));

    for(auto &it : v) {
        cin >> it;
    }

    dp[0][1] = v[0];

    if(N > 1) {
        dp[1][1] = v[1], dp[1][2] = v[0] + v[1];
    }


    for(int i = 2; i < N; i++) {
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + v[i];
        dp[i][2] = max(dp[i-1][1], dp[i][2]) + v[i];
    }

    int answer = 0;

    for(int i = 0; i < 3; i++) {
        answer = max(answer, dp[N-1][i]);
    }

    cout << answer;
}