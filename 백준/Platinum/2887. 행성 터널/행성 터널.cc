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
int N;
vector<pii> v1;
vector<pii> v2;
vector<pii> v3;
vector<tuple<int, int, int>> edge;
int unf[100001];

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

    if(a != b) return false;
    else return true;
}

void solve() {
    int answer = 0;

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());

    for(int i = 0; i < N-1; i++) {
        edge.push_back({abs(v1[i].first - v1[i+1].first), v1[i].second, v1[i+1].second});
        edge.push_back({abs(v2[i].first - v2[i+1].first), v2[i].second, v2[i+1].second});
        edge.push_back({abs(v3[i].first - v3[i+1].first), v3[i].second, v3[i+1].second});
    }

    sort(edge.begin(), edge.end());

    for(int i = 0; i < edge.size(); i++) {
        int cost = get<0>(edge[i]);
        int Node1 = get<1>(edge[i]);
        int Node2 = get<2>(edge[i]);

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
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v1.push_back({a, i});
        v2.push_back({b, i});
        v3.push_back({c, i});
    }

    Init();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
