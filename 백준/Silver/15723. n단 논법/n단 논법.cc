#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<vector<int>> v(30);

bool bfs(int x, int y) {
    queue<int> q;
    bool visited[30];

    memset(visited, 0, sizeof(visited));
    q.push(x);

    while(!q.empty()) {
        int xx = q.front();
        q.pop();

        if(xx == y) {
            return true;
        }

        for(int i = 0; i < v[xx].size(); i++) {
            int nx = v[xx][i];

            if(!visited[nx]) {
                q.push(nx);
                visited[nx];
            }
        }
    }

    return false;
}

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        char a, b;
        cin >> a >> s >> b;
        int x = a - 'a';
        int y = b - 'a';
        v[x].push_back(y);
    }
}

void solution() {
    input();

    cin >> M;

    for(int i = 0; i < M; i++) {
        char a, b;
        string s;
        cin >> a >> s >> b;
        int x = a - 'a';
        int y = b - 'a';

        if(bfs(x, y)) {
            cout << "T" << endl;
        }
        else {
            cout << "F" << endl;
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
