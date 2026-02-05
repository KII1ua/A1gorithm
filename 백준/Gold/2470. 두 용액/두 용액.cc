#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 2e9;
const int MAX = 51;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<int> v;

void Print() {
    for(auto &it : v) {
        cout << it << " ";
    }
}

void solve() {
    sort(v.begin(), v.end());

    int lo = 0;
    int hi = N-1;
    int ans = INF;
    int ans1 = 0, ans2 = 0;

    while(lo < hi) {
        int value = v[lo] + v[hi];

        if(ans > abs(value)) {
            ans = abs(value);
            ans1 = v[lo];
            ans2 = v[hi];
        }

        if(value > 0) {
            hi--;
        }
        else lo++;
    }

    cout << ans1 << " " << ans2;
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