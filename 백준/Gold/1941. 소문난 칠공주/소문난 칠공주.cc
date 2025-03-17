#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int graph[5][5];
bool Select[25];
int answer = 0;

bool checkfour() {
    int count = 0;

    for(int i = 0; i < 25; i++) {
        if(Select[i]) {
            int x = i / 5;
            int y = i % 5;

            if(graph[x][y] == 2) {
                count++;
            }
        }
    }

    if(count >= 4) {
        return true;
    }
    else return false;
}

bool adjacent() {
    queue<pii> q;
    bool check_select[5][5];
    bool queue_select[5][5];
    bool check_answer = false;

    memset(check_select, 0, sizeof(check_select));
    memset(queue_select, 0, sizeof(queue_select));

    int tmp = 0;
    for(int i = 0; i < 25; i++) {
        if(Select[i]) {
            int x = i / 5;
            int y = i % 5;

            check_select[x][y] = true;

            if(tmp == 0) {
                tmp++;
                q.push(make_pair(x, y));
                queue_select[x][y] = true;
            }
        }
    }

    int cnt = 1;
    while(!q.empty()) {
        int xx = q.front().first;
        int yy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = xx + dx[i];
            int ny = yy + dy[i];
            
            if(cnt == 7) {
                check_answer = true;
            }

            if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
                if(check_select[nx][ny] && !queue_select[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    queue_select[nx][ny] = true;
                    cnt++;
                }
            }
        }
    }
    
    if(check_answer) {
        return true;
    } else return false;
}

void dfs(int idx, int cnt) {
    if(cnt == 7) {
        if(checkfour()) {
            if(adjacent()) {
                answer++;
            }
        }
        return;
    }

    for(int i = idx; i < 25; i++) {
        if(Select[i]) continue;
        Select[i] = true;
        dfs(i, cnt+1);
        Select[i] = false;
    }
}

void solve() {
    dfs(0, 0);
    cout << answer;
}

void input() {
    for(int i = 0; i < 5; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < s.size(); j++) {
            if(s[j] == 'Y') graph[i][j] = 1;
            else graph[i][j] = 2;
        }
    }

    solve();
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
