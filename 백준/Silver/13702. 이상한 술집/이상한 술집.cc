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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
ll N, K, answer;
vector<int> v;

void solve() {
    ll start = 1;
    ll end = 1e18;

    while(start <= end) {
        ll mid = (start + end) / 2;

        int cnt = 0;
        for(int i = 0; i < N; i++) {
            int div = v[i] / mid;
            cnt += div;
        }

        if(cnt >= K) {      // 더 늘려야함
            start = mid + 1;
            answer = mid;
        }
        else {
            end = mid - 1;
        }
    }

    cout << answer;
}

void input() {
    cin >> N >> K;

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
