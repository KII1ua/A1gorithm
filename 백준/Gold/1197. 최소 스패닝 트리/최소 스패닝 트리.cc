#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e10

struct coordinate {
    int x;
    int y;
};

//int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
//int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int V, E;
vector<tuple<int, int, int>> v;
int unf[10001];
ll result;

void Init() {
    for(int i = 1; i <= V; i++) {
        unf[i] = i;
    }
}

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

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<0>(a) == get<0>(b)) {
        return get<1>(a) < get<1>(b);
    }
    return get<0>(a) < get<0>(b);
}

void solve() {
    Init();
    sort(v.begin(), v.end());

    for(auto it : v) {
        int cost = get<0>(it);
        int Node1 = get<1>(it);
        int Node2 = get<2>(it);

        if(!isUnion(Node1, Node2)) {
            Union(Node1, Node2);
            result += cost;
        }
    }

    cout << result;
}

void input() {
    cin >> V >> E;

    for(int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({c, a, b});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}