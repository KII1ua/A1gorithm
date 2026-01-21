#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 5;
const int MOD = 1e9 + 7;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int graph[MAX][MAX];
vector<pii> v;
bool visited[25];
int dp[25];
int cnt;
int answer = INF;

void Print() {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

bool bfs() {
    bool check[25] = {false};
    int count = 0;
    queue<int> q;
    for(int i = 0; i < 25; i++) {
        if(dp[i] != 0) {
            q.push(i);
            check[i] = true;
            count++;
            break;
        }
    }

    while(!q.empty()) {
        int x = q.front() / MAX;
        int y = q.front() % MAX;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            int idx = nx * MAX + ny;

            if(nx >= 0 && nx < MAX && ny >= 0 && ny < MAX) {
                if(!check[idx] && dp[idx] != 0) {
                    q.push(idx);
                    check[idx] = true;
                    count++;
                }
            }
        }
    }

    if(count == cnt) return true;
    else return false;
}

int manhatan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int calcdist() {
    int dist = 0;

    for(int k = 1; k < v.size(); k++) {
        int x = v[k].first;
        int y = v[k].second;

        for(int i = 0; i < 25; i++) {
            if(dp[i] == k) {
                int nx = i / MAX;
                int ny = i % MAX;

                dist += manhatan(x, y, nx, ny);
            }
        }
    }

    return dist;
}

void func(int count) {
    if(count == cnt+1) {
        if(bfs()) {
            answer = min(answer, calcdist());
        }
        return;
    }

    for(int i = 0; i < 25; i++) {
        if(!visited[i]) {
            visited[i] = true;
            dp[i] = count;
            func(count+1);
            visited[i] = false;
            dp[i] = 0;
        }
    }
}

void solve() {
    func(1);

    cout << answer;
}

void input() {
    v.push_back({0, 0});

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            char a;
            cin >> a;
            if(a == '*') {
                graph[i][j] = ++cnt;
                v.push_back({i, j});
            }
            else graph[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}