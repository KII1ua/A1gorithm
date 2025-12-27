#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>

using namespace std;

#define MAX 200005
#define INF 1e16 // Java의 Long.MAX_VALUE 대용 (오버플로우 방지 위해 적당히 큰 값)

typedef long long ll;

int n, m;
vector<pair<int, int>> adj[MAX]; // Java: graph
int isIt[MAX];                   // Java: isIt
int totalCount = 0;
ll dist[MAX];                    // Java: dis
int note_counts[MAX];            // Java: count (변수명 충돌 방지)
int path[MAX];                   // Java: path

void solve() {
    // Java: PriorityQueue<Node> ...
    // C++: {비용, 노드} 순서, 오름차순 정렬(greater)
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    // 거리 초기화
    fill(dist, dist + n + 1, INF);

    // 시작점 설정
    dist[1] = 0;
    note_counts[1] = isIt[1];
    pq.push({0, 1});

    while (!pq.empty()) {
        ll cur_cost = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        // Java: if(cur.v == n) continue; (도착점 이후 탐색 불필요)
        if (cur_node == n) continue;

        // Java: if(dis[cur.v] < cur.c) continue;
        if (dist[cur_node] < cur_cost) continue;

        for (auto& edge : adj[cur_node]) {
            int next_node = edge.first;
            int weight = edge.second;
            ll next_cost = cur_cost + weight;

            // 1. 더 짧은 경로 발견 시 (무조건 갱신 + PQ 푸시)
            if (dist[next_node] > next_cost) {
                dist[next_node] = next_cost;
                note_counts[next_node] = note_counts[cur_node] + isIt[next_node];
                path[next_node] = cur_node;
                pq.push({next_cost, next_node});
            }
            // 2. 거리는 같은데 노트 개수가 더 많은 경로 발견 시 (갱신만 함, PQ 푸시 X)
            // Java 코드의 로직: count[next] <= count[cur] + isIt[next]
            else if (dist[next_node] == next_cost) {
                if (note_counts[next_node] < note_counts[cur_node] + isIt[next_node]) {
                    note_counts[next_node] = note_counts[cur_node] + isIt[next_node];
                    path[next_node] = cur_node;
                    // 여기서 pq.push를 안 하는 것이 핵심입니다.
                }
            }
        }
    }

    // 결과 출력
    if (note_counts[n] == totalCount) {
        vector<int> res_path;
        int curr = n;
        
        // 경로 역추적
        while (curr != 0) {
            res_path.push_back(curr);
            curr = path[curr];
        }

        cout << res_path.size() << "\n";
        for (int i = res_path.size() - 1; i >= 0; i--) {
            cout << res_path[i] << " ";
        }
    } else {
        cout << -1;
    }
}

int main() {
    // 입출력 속도 향상 (Java BufferedReader 대응)
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    for (int i = 1; i <= n; i++) {
        cin >> isIt[i];
        if (isIt[i]) totalCount++;
    }

    solve();

    return 0;
}