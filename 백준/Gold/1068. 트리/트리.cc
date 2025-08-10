#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int N, M;
vector<vector<int>> v(51);
bool visited[51];
int start;
int cnt;

void dfs(int Node, int parent) {
    visited[Node] = true;
    int children = 0;

    for(auto it : v[Node]) {
        if(it == M || it == parent) continue;
        children++;
        dfs(it, Node);
    }
    if(children == 0) cnt++;
}

void solve() {
    if(start != M) {
        dfs(start, -1);
    }

    cout << cnt;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(a != -1) {
            v[i].push_back(a);
            v[a].push_back(i);
        }
        else start = i;
    }

    cin >> M;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}