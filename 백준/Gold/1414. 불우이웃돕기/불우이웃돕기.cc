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
int N;
char graph[51][51];
vector<tuple<int, int, int>> v;
int unf[51];
int cable;

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
        int cost = get<0>(it);
        int idx1 = get<1>(it);
        int idx2 = get<2>(it);

        if(!isUnion(idx1, idx2)) {
            answer += cost;
            Union(idx1, idx2);
        }
    }

    set<int> st;

    for(int i = 1; i <= N; i++) {
        st.insert(Find(i));
    }

    if(st.size() == 1) {
        cout << cable - answer;
    }
    else cout << -1;
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
        for(int j = 1; j <= N; j++) {
            cin >> graph[i][j];

            int value;

            if(graph[i][j] == '0') {
                continue;
            }
            else if(graph[i][j] >= 'A' && graph[i][j] <= 'Z') {
                value = graph[i][j] - 'A' + 27;
            }
            else {
                value = graph[i][j] - 'a' + 1;
            }

            if(value > 0) cable += value;
            v.push_back({value, i, j});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}