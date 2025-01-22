// baekjoon 2206
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<int> v;
int dp[100001];
int N, result;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a;
        v.push_back(a);
    }

    dp[0] = v[0];
    result = dp[0];

    for(int i = 1; i < N; i++) {
        dp[i] = max(v[i], dp[i-1] + v[i]);
        result = max(dp[i], result);
    }

    cout << result;
}
