// baekjoon 2206
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, K, M;
int result;
bool visited[1001];
vector<vector<int>> v1(100001);     // 역 - 하이퍼튜브
vector<vector<int>> v2(1001);       // 하이퍼튜브 - 역

int bfs(int x) {
    queue<pii> q;

    q.push(make_pair(x, 0));

    while(!q.empty()) {
        int xx = q.front().first;       // 현재 있는 역
        int cnt = q.front().second;
        q.pop();

        if(xx == N) {
            return cnt;
        }

        for(int i = 0; i < v1[xx].size(); i++) {
            int tube = v1[xx][i];
            if(!visited[tube]) {
                for(int j = 0; j < v2[tube].size(); j++) {
                    q.push(make_pair(v2[tube][j], cnt+1));
                    visited[tube] = true;
                }
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> K >> M;

    for(int i = 1; i <= M; i++) {
        for(int j = 0; j < K; j++) {
            int a;
            cin >> a;
            v2[i].push_back(a);
            v1[a].push_back(i);
        }
    }

    result = bfs(1);
    
    if(result == -1) {
        cout << result;
        return 0;
    }

    cout << result+1;
}
