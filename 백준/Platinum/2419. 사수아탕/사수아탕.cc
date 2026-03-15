#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
vector<int> v;
int dp[301][301][2];

int func(int left, int right, int dir, int cnt) {       // 왼, 오, 방향, 개수
    if(cnt == 0) return 0;
    if(left > right) return INF;

    int &ret = dp[left][right][dir];

    if(ret != -1) return ret;

    int locate = (dir)? v[right] : v[left];

    ret = INF;

    if(left > 0) {
        ret = min(ret, func(left-1, right, 0, cnt-1) + (cnt * abs(locate - v[left-1])));
    }

    if(right < N) {
        ret = min(ret, func(left, right+1, 1, cnt-1) + (cnt * abs(locate - v[right+1])));
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    v.push_back(0);

    sort(v.begin(), v.end());

    int idx = lower_bound(v.begin(), v.end(), 0) - v.begin();

    int answer = 0;

    for(int i = 1; i <= N; i++) {
        memset(dp, -1, sizeof(dp));
        answer = max(answer, (i * M) - func(idx, idx, 0, i));
    }

    cout << answer;
}