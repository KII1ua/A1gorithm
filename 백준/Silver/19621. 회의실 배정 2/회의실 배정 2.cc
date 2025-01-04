// baekjoon 28706
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<tuple<int, int, int>> v;
int dp[26];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N;

    cin >> N;

    for(int i = 0; i < N; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }

    dp[0] = get<2>(v[0]);
    dp[1] = max(get<2>(v[0]), get<2>(v[1]));

    for(int i = 2; i < N; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + get<2>(v[i]));
    }

    cout << dp[N-1];
}