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
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {0, -1};
int dy[] = {-1, 0};
int N, M;
vector<vector<int>> v(1001);
int arr[1001];
priority_queue<pii, vector<pii>> max_pq;
priority_queue<pii, vector<pii>, greater<pii>> min_pq;
set<int> st;
int answer;

bool compare(int a, int b) {
    return a > b;
}

void Print() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        sort(v[i].begin(), v[i].end());
    }

    int max_val = 0;
    int answer = MAX;

    priority_queue<pii, vector<pii>, greater<pii>> pq;

    for(int i = 0; i < N; i++) {
        pq.push({v[i][0], i});
        max_val = max(v[i][0], max_val);
    }

    while(true) {
        int min_val = pq.top().first;
        int idx = pq.top().second;
        pq.pop();

        answer = min(answer, max_val - min_val);

        if(++arr[idx] < M) {
            pq.push({v[idx][arr[idx]], idx});
            max_val = max(max_val, v[idx][arr[idx]]);
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
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
