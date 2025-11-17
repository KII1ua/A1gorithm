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
int N;
vector<vector<int>> v(100001);
int order[100001];
bool visited[100001];
vector<int> answer;
int arr[100001];

bool compare(int a, int b) {
    return order[a] < order[b];
}

void dfs(int x) {
    visited[x] = true;
    answer.push_back(x);

    for(auto it : v[x]) {
        if(!visited[it]) {
            dfs(it);
        }
    }
}

void solve() {
    for(int i = 1; i <= N; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }

    dfs(1);

    for(int i = 0; i < N; i++) {
        if(answer[i] != arr[i+1]) {
            cout << 0;
            return;
        }
    }

    cout << 1;
}

void input() {
    cin >> N;

    for(int i = 0; i < N-1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        order[a] = i;
        arr[i] = a;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
