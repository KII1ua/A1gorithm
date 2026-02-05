#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 10001;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, N, a, b;
int par[MAX];
int depth[21];

void func(int node, int dep, vector<vector<int>> &v) {
    depth[node] = dep;

    for(auto &iter : v[node]) {
        func(iter, dep+1, v);
    }
}

void solve(vector<vector<int>> &v) {
    int rt = 0;

    for(int i = 1; i <= N; i++) {
        if(par[i] == 0) {
            rt = i;
            break;
        }
    }

    int node1 = a;
    int node2 = b;
    int dep1 = 0;
    int dep2 = 0;

    while(node1 != rt) {
        node1 = par[node1];
        dep1++;
    }

    while(node2 != rt) {
        node2 = par[node2];
        dep2++;
    }

    if(dep1 > dep2) {
        while(dep1 != dep2) {
            a = par[a];
            dep1--;
        }
    }
    else if(dep1 < dep2) {
        while(dep1 != dep2) {
            b = par[b];
            dep2--;
        }
    }

    while(a != b) {
        a = par[a];
        b = par[b];
    }

    cout << a << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        vector<vector<int>> v(N+1, vector<int>(0));

        memset(par, 0, sizeof(par));

        for(int i = 0; i < N-1; i++) {
            int a, b;
            cin >> a >> b;
            par[b] = a;
            v[a].push_back(b);
        }

        cin >> a >> b;

        solve(v);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}