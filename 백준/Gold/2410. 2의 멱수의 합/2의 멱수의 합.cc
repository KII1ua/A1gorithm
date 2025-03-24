#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
ll dp[1000001];

void solution() {
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 3; i <= 1000000; i++) {
        if(i % 2 == 0) dp[i] = (dp[i-1] + dp[i/2]) % 1000000000;
        else dp[i] = dp[i-1];
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
    solution();
}
