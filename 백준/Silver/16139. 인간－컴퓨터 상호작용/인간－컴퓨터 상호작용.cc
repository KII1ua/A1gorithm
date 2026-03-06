#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e18;
const int MAX = 200000;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
string s;
map<char, vector<int>> m;
int N;

void solve() {
    for(int i = 0; i < s.length(); i++) {
        m[s[i]].push_back(i);
    }

    for(int i = 0; i < N; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;

        if(m[a].size() == 0) {
            cout << 0 << endl;
        }
        else {
            auto lo = lower_bound(m[a].begin(), m[a].end(), b);
            auto ri = upper_bound(m[a].begin(), m[a].end(), c);

            cout << distance(lo , ri) << endl;
        }
    }
}

void input() {
    cin >> s >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}