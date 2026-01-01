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
int unf[1001];
int graph[1001][1001];
vector<tuple<int, int, int>> v;

int Find(int a) {
    if(a == unf[a]) return a;
    return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) unf[a] = b;
    else unf[b] = a;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void solve() {
    for(int i = 2; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            v.push_back({graph[i][j], i, j});
        }
    }

    sort(v.begin(), v.end());

    vector<pii> answer;

    int ans = 0;

    for(auto &it : v) {
        int cost = get<0>(it);
        int node1 = get<1>(it);
        int node2 = get<2>(it);

        if(!isUnion(node1, node2)) {
            Union(node1, node2);
            ans += cost;
            answer.push_back({node1, node2});
        }
    }

    cout << ans << " " << answer.size() << endl;

    for(auto &it : answer) {
        cout << it.first << " " << it.second << endl;
    }
}

void Init() {
    for(int i = 1; i <= N; i++) {
        unf[i] = i;
    }
}

void input() {
    cin >> N >> M;

    Init();

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}