#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
vector<vector<int>> v(1001);
int unf[1001];
set<int> st;

int Find(int a) {
    if(a == unf[a]) return a;
    return a = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) {     // 작은게 루트
        unf[a] = b;
    }
    else unf[b] = a;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void init() {
    for(int i = 1; i <= N; i++) {
        unf[i] = i;
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j < v[i].size(); j++) {
            if(v[i].size() >= 2) {
                Union(v[i][j-1], v[i][j]);
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        int tmp = Find(i);
        st.insert(tmp);
    }

    cout << st.size();
}

void input() {
    cin >> N >> M;

    init();

    for(int i = 0; i < M; i++) {
        char a;
        int b, c;
        cin >> a >> b >> c;
        if(a == 'F') {      // 친구
            Union(b, c);
        }
        else {              // 원수
            v[b].push_back(c);
            v[c].push_back(b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}