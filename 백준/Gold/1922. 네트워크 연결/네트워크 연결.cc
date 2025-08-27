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
int N, M;
int unf[1001];
vector<tuple<int, int, int>> v;

int Find(int a) {
    if(a == unf[a]) return a;
    return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a < b) unf[a] = b;
    else unf[b] = a;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a != b) return false;
    return true;
}

void solve() {
    sort(v.begin(), v.end());

    int answer = 0;

    for(auto it : v) {
        auto [cost, Node1, Node2] = it;

        if(!isUnion(Node1, Node2)) {
            answer += cost;
            Union(Node1, Node2);
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

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
