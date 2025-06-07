#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int D, P;
vector<pii> v;
int dp[100001];

void solve() {
    dp[0] = MAX;

    for(int i = 0; i < P; i++) {
        int len = v[i].first;
        int cost = v[i].second;

        // dp[i] = 길이 i를 만들 때 대 수도관 용량
        for(int j = D; j >= len; j--) {
            // 현재 용량과 파이프를 추가했을 경우 생기는 최소 지름을 비교
            dp[j] = max(dp[j], min(dp[j - len], cost));
        }
    }
    
    cout << dp[D];
}

void input() {
    cin >> D >> P;

    for(int i = 0; i < P; i++) {
        int l, c;
        cin >> l >> c;
        v.push_back({l, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}