#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int arr[9];
vector<tuple<int, int, int>> v;
map<vector<int>, int> m;

bool check(vector<int> &vec) {
    for(int i = 1; i < N; i++) {
        if(vec[i] < vec[i-1]) {
            return false;
        }
    }
    return true;
}

void dijkstra() {
    priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>, greater<pair<int, vector<int>>>> pq;
    vector<int> tmp;
    for(int i = 0; i < N; i++) {
        tmp.push_back(arr[i]);
    }
    pq.push({0, tmp});

    while(!pq.empty()) {
        vector<int> Node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(check(Node)) {
            cout << cost;
            exit(0);
        }

        for(int i = 0; i < M; i++) {
            vector<int> nextNode = Node;
            int le = get<0>(v[i]);
            int ri = get<1>(v[i]);
            int nextCost = cost + get<2>(v[i]);

            swap(nextNode[le-1], nextNode[ri-1]);

            if(m.find(nextNode) != m.end()) {
                if(m[nextNode] > nextCost) {
                    m[nextNode] = nextCost;
                    pq.push({nextCost, nextNode});
                }
            }
            else {
                m[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }
}

void solve() {
    dijkstra();

    cout << -1;
//
//    int answer = MAX;
//    for(auto it : m) {
//        vector<int> key = it.first;
//        int cost = it.second;
//
//        if(check(key)) {
//            answer = min(answer, cost);
//        }
//    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
