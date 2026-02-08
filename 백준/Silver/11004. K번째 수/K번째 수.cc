#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 201;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;
vector<int> v;

void solve() {
    sort(v.begin(), v.end());

    int cnt = 0;

    for(int i = 0; i < N; i++) {
        cnt++;

        if(cnt == K) {
            cout << v[i];
            break;
        }
    }
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