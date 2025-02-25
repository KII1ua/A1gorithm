// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int T, N, M;
int test = 1;
int dist[21];
int result[21];

void dijkstra(vector<vector<pii>> a, int cnt) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < cnt; i++) {
        dist[i] = INF;
        result[i] = 0;
    }

    dist[0] = 0;
    pq.push(make_pair(0, dist[0]));

    while(!pq.empty()) {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if(cost > dist[cur]) continue;

        for(int i = 0; i < a[cur].size(); i++) {
            int current = a[cur][i].first;
            int curcost = cost + a[cur][i].second;

            if(dist[current] > curcost) {
                dist[current] = curcost;
                pq.push(make_pair(current, dist[current]));
                result[current] = cur;
            }
        }
    }
}

void input() {
    cin >> T;

    for(int i = 0; i < T; i++) {
        vector<vector<pii>> v(21);
        cin >> N >> M;

        for(int j = 0; j < N; j++) {
            int x, y, z;
            cin >> x >> y >> z;
            v[x].push_back(make_pair(y, z));
            v[y].push_back(make_pair(x, z));
        }
        dijkstra(v, M);

        if(dist[M-1] == INF) cout << "Case #" << test << ": " << -1 << endl;
        else {
            stack<int> st;

            int tmp = M-1;
            st.push(tmp);

            while(true) {
                tmp = result[tmp];
                st.push(tmp);
                if(tmp == 0) break;
            }

            cout << "Case #" << test << ": ";

            while(!st.empty()) {
                int tp = st.top();
                cout << tp << " ";
                st.pop();
            }

            cout << endl;
        }
        test++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
