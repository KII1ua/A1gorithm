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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, answer;
int graph[52][52];
vector<vector<int>> v(52);

char idxToChar(int x) {
    if(x < 26) return 'A' + x;
    else return 'a' + (x - 26);
}

vector<int> bfs(int a) {
    queue<int> q;
    bool visited[52] = {false};
    vector<int> arr;
    q.push(a);

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < 52; i++) {
            if(a == i) continue;

            if(graph[x][i] && !visited[i]) {
                q.push(i);
                visited[i] = true;
                arr.push_back(i);
            }
        }
    }
    answer += arr.size();
    sort(arr.begin(), arr.end());
    return arr;
}

void solve() {
    for(int i = 0; i < 52; i++) {
        vector<int> tmp = bfs(i);

        for(auto it : tmp) {
            v[i].push_back(it);
        }
    }

    cout << answer << endl;

    for(int i = 0; i < 52; i++) {
        if(v[i].size() == 0) continue;
        else {
            for(auto it : v[i]) {
                cout << idxToChar(i)  << " => " << idxToChar(it) << endl;
            }
        }
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        char a, b;
        string s;
        int tmp1, tmp2;

        cin >> a >> s >> b;

        if(a >= 97) tmp1 = a - 'a' + 26;
        else tmp1 = a - 'A';

        if(b >= 97) tmp2 = b - 'a' + 26;
        else tmp2 = b - 'A';

        graph[tmp1][tmp2] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
