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

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int N;
vector<tuple<int, int, int>> v;
int dp[100001];

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<1>(a) == get<1>(b)) {
        if(get<2>(a) == get<2>(b)) {
            return get<0>(a) < get<0>(b);
        }
        return get<2>(a) < get<2>(b);
    }
    return get<1>(a) < get<1>(b);
}

void solve() {
    sort(v.begin(), v.end(), compare);

    dp[0] = get<2>(v[0]);
    dp[1] = max(dp[0], get<2>(v[1]));


    for(int i = 2; i < N; i++) {
        dp[i] = max(dp[i-2] + get<2>(v[i]), dp[i-1]);
    }

    cout << dp[N-1];
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
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
