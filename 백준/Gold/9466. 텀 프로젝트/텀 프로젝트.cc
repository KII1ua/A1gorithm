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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, answer, T;
int arr[100001];
bool visited[100001];
bool cycle[100001];

void dfs(int Node) {
    visited[Node] = true;
    int nextNode = arr[Node];

    if(!visited[nextNode]) {
        dfs(nextNode);
    }
    else if(!cycle[nextNode]) {
        for(int i = nextNode; i != Node; i = arr[i]) {
            answer++;
        }
        answer++;
    }
    cycle[Node] = true;
}

void solve() {
    for(int i = 1; i <= N; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }

    cout << N - answer << endl;
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        solve();
        memset(visited, 0, sizeof(visited));
        memset(cycle, 0, sizeof(cycle));
        answer = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
