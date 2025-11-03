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

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, answer;
int dp[2001][2001];
vector<int> v;

int dfs(int le, int ri) {
    if(le > ri) return 0;
    else if(le == ri) return 1;
    int &ret = dp[le][ri];

    if(ret != -1) return ret;
    ret = 2;

    int diff = v[ri] - v[le];
    int idx = lower_bound(v.begin(), v.end(), v[ri] + diff) - v.begin();

    if(v[idx] == v[ri] + diff) return dfs(ri, idx) + 1;
    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));
    sort(v.begin(), v.end());

    int cnt = 1;

    answer = 1;
    for(int i = 1; i < N; i++) {
        if(v[i] == v[i-1]) {
            cnt++;
        }
        else cnt = 1;
        answer = max(answer, cnt);
    }

    v.erase(unique(v.begin(), v.end()), v.end());

    N = v.size();
    for(int i = 0; i < N-1; i++) {
        for(int j = i+1; j < N; j++) {
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
