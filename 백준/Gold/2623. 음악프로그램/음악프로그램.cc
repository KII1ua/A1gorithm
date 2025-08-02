#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    string s;
    vector<int> v;
};

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N, M;
int inDegree[1001];
vector<vector<int>> v(1001);
vector<int> result;

bool topologysort() {
    queue<int> q;

    for(int i = 1; i <= N; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    for(int i = 1; i <= N; i++) {
        if(q.empty()) {
            return false;
        }

        int x = q.front();
        result.push_back(x);
        q.pop();

        for(auto it : v[x]) {
            if(--inDegree[it] == 0) {
                q.push(it);
            }
        }
    }
    return true;
}

void solve() {
    if(topologysort()) {
        for(auto it : result) {
            cout << it << endl;
        }
    }
    else cout << 0;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        vector<int> tmp;
        for(int j = 0; j < a; j++) {
            int a;
            cin >> a;
            if(j != 0) inDegree[a]++;
            tmp.push_back(a);
        }

        for(int j = 1; j < a; j++) {
            v[tmp[j-1]].push_back(tmp[j]);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}