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
int N, M;       // 방 개수, 워프 개수
vector<tuple<int, int, int>> v;
int unf[200001];

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
    sort(v.begin(), v.end());

    int answer = 0;

    for(auto it : v) {
        int Node1 = get<1>(it);
        int Node2 = get<2>(it);
        int cost = get<0>(it);

        if(!isUnion(Node1, Node2)) {
            Union(Node1, Node2);
            answer += cost;
        }
    }

    cout << answer;
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
        int a, b, c;

        cin >> a >> b >> c;
        v.push_back({c, a, b});
    }

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v.push_back({a, 0, i});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}