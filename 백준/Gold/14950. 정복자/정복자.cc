#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
vector<tuple<int, int, int>> v;
int N, M, t;
int Node[10001];
int result;

int Find(int a) {
    if(a == Node[a]) return a;
    return Node[a] = Find(Node[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a < b) Node[b] = a;
    else Node[a] = b;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void solve() {
    for(int i = 1; i <= N; i++) {
        Node[i] = i;
    }
    sort(v.begin(), v.end());
    int cnt = 0;

    for(auto it : v) {
        int cost = get<0>(it);
        int from = get<1>(it);
        int to = get<2>(it);

        if(!isUnion(from, to)) {
            int maxcost = cost + cnt * t;
            result += maxcost;
            Union(from, to);
            cnt++;
        }
    }

    cout << result;
}

void input() {
    cin >> N >> M >> t;

    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        v.push_back(make_tuple(C, A, B));
        v.push_back(make_tuple(C, B, A));
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}