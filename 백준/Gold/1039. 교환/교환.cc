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
int N, K;
int answer = -1;

void bfs() {
    queue<pair<string, int>> q;
    q.push({to_string(N), 0});
    vector<set<string>> visited(K+1);

    while(!q.empty()) {
        string value = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if(cnt == K) {
            int ans = stoi(value);
            answer = max(ans, answer);
            continue;
        }

        for(int i = 0; i < value.size(); i++) {
            for(int j = i + 1; j < value.size(); j++) {
                string tmp = value;
                char tmpch = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = tmpch;

                if(tmp[0] == '0') continue;

                if(visited[cnt+1].count(tmp)) continue;

                visited[cnt+1].insert(tmp);
                q.push({tmp, cnt+1});
            }
        }
    }
}

void solve() {
    bfs();

    cout << answer;
}

void input() {
    cin >> N >> K;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
