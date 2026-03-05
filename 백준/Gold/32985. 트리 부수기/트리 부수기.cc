#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    // 빠른 입출력 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    if (!(cin >> N)) return 0;
    
    vector<vector<int>> adj(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> depth(N, -1);
    queue<int> q;
    
    depth[0] = 0;
    q.push(0);
    
    // BFS 탐색
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for (int nxt : adj[curr]) {
            if (depth[nxt] == -1) {
                depth[nxt] = depth[curr] + 1;
                q.push(nxt);
            }
        }
    }
    
    string ans = "";
    // N-1번 노드부터 1번 노드까지 역순으로 결과 문자열 생성
    for (int v = N - 1; v >= 1; --v) {
        int bit = ((N - 1) - depth[v]) % 2;
        ans += to_string(bit);
    }
    
    cout << ans << "\n";
    
    return 0;
}