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
int paddy[301];
int arr[301][301];
int unf[301];
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
    sort(v.begin(),v.end());

    int answer = 0;
    for(auto &it : v) {
        int cost = get<0>(it);
        int Node1 = get<1>(it);
        int Node2 = get<2>(it);

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

    Init();

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        v.push_back({a, 0, i});
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int a;
            cin >> a;
            if(i == j) continue;
            else v.push_back({a, i, j});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
