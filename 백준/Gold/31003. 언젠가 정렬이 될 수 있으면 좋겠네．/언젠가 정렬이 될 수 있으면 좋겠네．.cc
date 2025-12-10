#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

const int INF = 1e9;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<int> arr, answer;
vector<vector<int>> edge(3001);
int Indegree[3001];

void Print() {
    for(int i = 0; i < N; i++) {
        cout << Indegree[i] << " ";
    }
}

void topologysort() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < N; i++) {
        if(Indegree[i] == 0) {
            pq.push({arr[i], i});
        }
    }

    while(!pq.empty()) {
        int x = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        answer.push_back(x);

        for(auto iter : edge[idx]) {
            Indegree[iter]--;

            if(Indegree[iter] == 0) {
                pq.push({arr[iter], iter});
            }
        }
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            if(gcd(arr[i], arr[j]) != 1) {
                edge[i].push_back(j);
                Indegree[j]++;
            }
        }
    }

    topologysort();

    for(auto iter : answer) {
        cout << iter << " ";
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}