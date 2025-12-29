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
set<int> st;
int dp[10001][1001];

int func(int locate, int jump) {
    if(locate > N) return INF;

    if(locate == N) return 0;

    if(jump == 0) return INF;

    int &ret = dp[locate][jump];

    if(st.find(locate) != st.end()) {
        return INF;
    }

    if(ret != INF) return ret;

    ret = min({func(locate + jump + 1, jump+1), func(locate + jump, jump), func(locate + jump - 1, jump-1)}) + 1;

    return ret;
}

void solve() {
    if(N == 2) {
        cout << 1;
    }
    else {
        int answer = func(2, 1) + 1;

        if(answer >= INF) {
            cout << -1;
        }
        else cout << answer;
    }
}

void input() {
    cin >> N >> M;

    for(int i = 2; i <= N; i++) {
        for(int j = 0; j <= 1000; j++) {
            dp[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        st.insert(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}