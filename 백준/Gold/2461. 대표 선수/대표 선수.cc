#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int graph[1001][1001];
int arr[1001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        sort(graph[i], graph[i]+M);
    }

    int max_val = 0;

    for(int i = 0; i < N; i++) {
        pq.push({graph[i][0], i});
        max_val = max(max_val, graph[i][0]);
    }

    int answer = max_val - pq.top().first;

    while(true) {
        int val = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        answer = min(answer, max_val - val);

        if(++arr[idx] < M) {
            pq.push({graph[idx][arr[idx]], idx});
            max_val = max(max_val, graph[idx][arr[idx]]);
        }
        else {
            break;
        }
    }

    cout << answer;
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