#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, result;
int c[52][52], f[52][52], visited[52];
vector<int> v[52];

void maxFlow(int start, int end) {
    while(1) {
        fill(visited, visited + 52, -1);
        queue<int> q;
        q.push(start);
        while(!q.empty()) {
            int xx = q.front();
            q.pop();

            for(int i = 0; i < v[xx].size(); i++) {
                int nx = v[xx][i];

                if(c[xx][nx] - f[xx][nx] > 0 && visited[nx] == -1) {
                    q.push(nx);
                    visited[nx] = xx;       // 경로 저장
                    if(nx == end) break;
                }
            }
        }
        if(visited[end] == -1) break; // 모든 경로를 찾은 후 탈출
        int flow = MAX;

        for(int i = end; i != start; i = visited[i]) {      // 거꾸로 최소 유량 탐색
            flow = min(flow, c[visited[i]][i] - f[visited[i]][i]);
        }
        // 최소 유량 추가
        for(int i = end; i != start; i = visited[i]) {
            f[visited[i]][i] += flow;
            f[i][visited[i]] -= flow;
        }
        result += flow;
    }
}

void solve() {
    maxFlow(0, 25);

    cout << result;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        char a, b;
        int l, r, f;
        cin >> a >> b >> f;
        if(a <= 90) l = a - 'A';
        else l = a - 'a' + 26;
        if(b <= 90) r = b - 'A';
        else r = b - 'a' + 26;
        v[l].push_back(r);      // 단방향
        v[r].push_back(l);      // 역방향
        c[l][r] += f;            // l -> r로 갈 수 있는 최대 용량
        c[r][l] += f;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}