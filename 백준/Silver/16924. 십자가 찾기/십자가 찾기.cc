#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define endl "\n"

int N, M;
char graph[101][101];
bool visited[101][101];
vector<tuple<int, int, int>> v;

void solve(int x, int y) {
    int cnt = 1;

    while(true) {
        if(x-cnt > 0 && x+cnt <= N && y-cnt > 0 && y+cnt <= M) {
            if(graph[x][y-cnt] == '*') {
                if(graph[x][y+cnt] == '*') {
                    if(graph[x-cnt][y] == '*') {
                        if(graph[x+cnt][y] == '*') {
//                            v.push_back(make_tuple(x, y, cnt));
                            visited[x][y] = true;
                            visited[x][y-cnt] = true;
                            visited[x][y+cnt] = true;
                            visited[x-cnt][y] = true;
                            visited[x+cnt][y] = true;
                            cnt++;
                        }
                        else break;
                    }
                    else break;
                }
                else break;
            }
            else break;
        }
        else break;
    }

    if(cnt - 1 >= 1) {
        v.push_back(make_tuple(x, y, cnt-1));
    }
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            cin >> graph[i][j];
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(graph[i][j] == '*')
                solve(i, j);
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            if(graph[i][j] == '*' && visited[i][j] != true) {
                cout << -1;
                return;
            }
        }
    }

    cout << v.size() << endl;

    for(int i = 0; i < v.size(); i++) {
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i]) << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
