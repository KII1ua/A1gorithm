#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
vector<tuple<int, int, int>> v; // 무게, 가치, 개수
int dp[10001];

void Print() {
    for(auto &it : v) {
        cout << get<0>(it) << " " << get<1>(it) << " " << get<2>(it) << endl;
    }
}

void solve() {
    for(int i = 0; i < v.size(); i++) {
        int weight = get<0>(v[i]);
        int cost = get<1>(v[i]);
        int cnt = get<2>(v[i]);

        for(int j = M; j >= 0; j--) {
            if(j - weight < 0) continue;
            dp[j] = max(dp[j], dp[j - weight] + cost);
        }
    }

    cout << dp[M];
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int cnt = 1;

        int tmp = c;

        while(tmp > 0) {
            int value = min(cnt, tmp);

            v.push_back({a * value, b * value, value});
            tmp -= cnt;
            cnt = cnt << 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}