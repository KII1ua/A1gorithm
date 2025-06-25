#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M;
vector<tuple<int, int, int>> v;
int unf[100001];

void Init() {
    for(int i = 1; i <= N; i++) {
        unf[i] = i;
    }
}

int Find(int a) {
    if(a == unf[a]) return unf[a];
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

    if(a != b) {
        return false;
    }
    return true;
}

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if(get<2>(a) == get<2>(b)) {
        return get<0>(a) < get<0>(b);
    }
    return get<2>(a) < get<2>(b);
}

void solve() {
    sort(v.begin(), v.end(), compare);

    int result = 0;
    int maxresult = 0;
    for(auto it : v) {
        int Node1 = Find(get<0>(it));
        int Node2 = Find(get<1>(it));
        int cost = get<2>(it);

        if(!isUnion(Node1, Node2)) {
            Union(Node1, Node2);
            result += cost;
            maxresult = max(cost, maxresult);
        }
    }

    cout << result - maxresult;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}