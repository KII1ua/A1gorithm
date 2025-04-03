#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Endl "\n"
#define MAX 1e9

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int graph[11][11];
int Bridge[8];
vector<tuple<int, int, int>> v;     // cost, from, to
int cost, edgeCount;

int Find(int x) {
    if(x == Bridge[x]) {
        return x;
    }
    return Bridge[x] = Find(Bridge[x]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a < b) Bridge[a] = b;
    else Bridge[b] = a;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void makeBridge(int x, int y, int fromLabel) {
    for(int dir = 0; dir < 4; dir++) {
        int nx = x;
        int ny = y;
        int length = 0;

        while(true) {
            nx += dx[dir];
            ny += dy[dir];

            if(nx < 0 || ny < 0 || nx >= N || ny >= M) break;

            if(graph[nx][ny] == fromLabel) break;

            if(graph[nx][ny] == 0) {
                length++;
            }
            else {
                if(length >= 2) {
                    int toLabel = graph[nx][ny];
                    v.push_back(make_tuple(length, fromLabel, toLabel));
                }
                break;
            }
        }
    }
}

void bfs(int x, int y, int label) {
    queue<pii> q;
    q.push(make_pair(x, y));
    graph[x][y] = label;

    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];

            if(nx >= 0 && ny >= 0 && nx < N && ny < M) {
                if(graph[nx][ny] == 1) {
                    q.push(make_pair(nx, ny));
                    graph[nx][ny] = label;
                }
            }
        }
    }
}

void solve() {
    int number = 2;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == 1) {
                bfs(i,j, number);
                number++;
            }
        }
    }

    for(int i = 2; i < 7; i++) {
        Bridge[i] = i;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] != 0) {
                makeBridge(i, j, graph[i][j]);
            }
        }
    }

    sort(v.begin(), v.end());

    for(auto it : v) {
        int cnt = get<0>(it);
        int from = get<1>(it);
        int to = get<2>(it);
        if(!isUnion(from, to)) {
            Union(from, to);
            cost += cnt;
            edgeCount++;
        }
    }

    if(number - 3 == edgeCount) {
        cout << cost;
    }
    else {
        cout << -1;
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
