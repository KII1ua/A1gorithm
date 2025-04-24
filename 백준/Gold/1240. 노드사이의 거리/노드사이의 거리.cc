#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<vector<pii>> v(1001);
bool visited[1001];
int c,d;

void dfs(int start, int cnt) {
    if(start == d) {
        cout << cnt << endl;
        return;
    }

    visited[start] = true;
    for(int i = 0; i < v[start].size(); i++) {
        int nextNode = v[start][i].first;
        int count = cnt + v[start][i].second;
        if(!visited[nextNode]) {
            dfs(nextNode, count);
        }
    }
}

void solve() {

}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N-1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }

    for(int i = 0; i < M; i++) {
        cin >> c >> d;
        dfs(c, 0);
        memset(visited, 0, sizeof(visited));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}