// baekjoon 13913
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, K;
stack<int> st;
int dist[100001];
vector<int> path(100001, -1);

void bfs(int a) {
    queue<int> q;

    q.push(a);
    dist[a] = 0;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        if(x == K) {
            cout << dist[x] << endl;
            return;
        }

        int dx[] = {x - 1, x + 1, 2 * x};

        for(int i = 0; i < 3; i++) {
            int nx = dx[i];

            if(nx >= 0 && nx <= 100000 && path[nx]==-1) {
                q.push(nx);
                dist[nx] = dist[x] + 1;
                path[nx] = x;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K;

    bfs(N);
    int idx = K;

    st.push(K);
    path[N] = -1;

    while(true) {
        idx = path[idx];
        if(-1 == idx) {
            break;
        }
        st.push(idx);
    }

    int sz = st.size();

    for(int i = 0; i < sz; i++) {
        int res = st.top();
        st.pop();

        cout << res << " ";
    }
}