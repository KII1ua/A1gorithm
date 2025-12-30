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
int N, C, M;
vector<tuple<int, int, int>> v;
int dp[2001];

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<1>(a) == get<1>(b)) {
        if(get<2>(a) == get<2>(b)) {
            return get<1>(a) < get<1>(b);
        }
        return get<2>(a) > get<2>(b);
    }

    return get<1>(a) < get<1>(b);
}

void solve() {
    sort(v.begin(), v.end(), compare);

    int answer = 0;

    for(int i = 0; i < M; i++) {
        int left = get<0>(v[i]);
        int right = get<1>(v[i]);
        int cost = get<2>(v[i]);

        if(dp[left] >= C) continue;
        else {
            int weight = cost;

            for(int j = left; j < right; j++) {
                weight = min(weight, C - dp[j]);
            }

            for(int j = left; j < right; j++) {
                dp[j] += weight;
            }

            answer += weight;
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> C >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}