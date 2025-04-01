#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Endl "\n"
#define MAX 1e9

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, End;
vector<vector<int>> v(11);
map<int, vector<int>> m;
int result = MAX;

void bfs(int x, int y) {
    vector<vector<bool>> visited(11, vector<bool>(11, false));
    queue<tuple<int, int, int>> q;      // 호선, 역, 환승 수
    q.push(make_tuple(x, 0, 0));
    visited[x][y] = true;

//    for(int i = 1; i <= N; i++) {
//        for(int j = 0; j < v[i].size(); j++) {
//            if(v[i][j] == 0) {
//                q.push(make_tuple(i, 0, 0));
//                visited[i][j] = true;
//                break;
//            }
//        }
//    }

    while(!q.empty()) {
        int lines = get<0>(q.front());
        int stations = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if(stations == End) {
            result = min(cnt, result);
        }

        for(int i = 0; i < v[lines].size(); i++) {  // 인접 역
            int nextstation = v[lines][i];
            if(!visited[lines][i]) {
                q.push(make_tuple(lines, nextstation, cnt));
                visited[lines][i] = true;
            }
            else if(nextstation == End) {
                result = min(cnt, result);
                return;
            }
        }

        for(auto it : m[stations]) {
            int nextlines = it;
            for(int i = 0; i < v[nextlines].size(); i++) {
                if(!visited[nextlines][i]) {
                    q.push(make_tuple(nextlines, v[nextlines][i], cnt+1));
                    visited[nextlines][i] = true;
                }
            }
        }
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < v[i].size(); j++) {
            if(v[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    if(result != MAX) {
        cout << result;
    }
    else cout << -1;
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        for(int j = 0; j < a; j++) {
            int b;
            cin >> b;
            v[i].push_back(b);
            m[b].push_back(i);
        }
    }

    cin >> End;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
