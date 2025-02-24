// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int dp[250001];
int N;

int solution() {
    int result = -10001;

    for(int i = 1; i < N; i++) {
        dp[i] = max(dp[i] + dp[i-1], dp[i]);
    }

    for(int i = 0; i < N; i++) {
        result = max(result, dp[i]);
    }

    return result;
}

void input() {
    while(true) {
        cin >> N;
        if(!N) return;

        for(int i = 0; i < N; i++) {
            cin >> dp[i];
        }

        cout << solution() << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
