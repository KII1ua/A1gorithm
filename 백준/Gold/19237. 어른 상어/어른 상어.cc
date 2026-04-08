#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Shark {
    int x, y, dir;
    bool live;
    vector<int> priority[5];
};

struct Board {
    vector<int> arr;
    int smell_time;
    int smell_host;
};

const int INF = 1e9;
const int MAX = 100001;
const int D = 2000000;
const int MOD = 10007;
//int dx[] = {0, 0, 1, -1};
//int dy[] = {1, -1, 0, 0};
//int dx[] = {1, 0, -1, 0};
//int dy[] = {0, 1, 0, -1};
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int N, M, K;
int graph[21][21];
Shark shark[401];
Board board[21][21];

bool check() {
    for(int i = 2; i <= M; i++) {
        if(shark[i].live) return false;
    }
    return true;
}

void move_shark(int time) {
    for(int i = 1; i <= M; i++) {
        if(!shark[i].live) continue;

        int x = shark[i].x;
        int y = shark[i].y;
        board[x][y].arr.clear();
        int selfx, selfy, selfdir;
        selfx = selfy = selfdir = -1;

        int ndir = shark[i].dir;
        bool flag = false;

        for(int j = 0; j < shark[i].priority[ndir].size(); j++) {       // 방향 탐색
            int nx = x + dx[shark[i].priority[ndir][j]];
            int ny = y + dy[shark[i].priority[ndir][j]];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

            if(board[nx][ny].smell_time <= time) {      // 다른 빈곳의 냄새를 찾는 경우
                flag = true;
                board[nx][ny].arr.push_back(i);
                shark[i].x = nx;
                shark[i].y = ny;
                shark[i].dir = shark[i].priority[ndir][j];
                break;
            }
            else {
                if(board[nx][ny].smell_host == i) {
                    if(selfx == -1) {
                        selfx = nx;
                        selfy = ny;
                        selfdir = shark[i].priority[ndir][j];
                    }
                }
            }
        }

        if(!flag) {     // 빈곳의 냄새를 찾지 못한 경우
            shark[i].x = selfx;
            shark[i].y = selfy;
            shark[i].dir = selfdir;
            board[selfx][selfy].arr.push_back(i);
        }
    }
}

void killing_shark() {
    for(int i = 1; i <= M; i++) {
        int x = shark[i].x;
        int y = shark[i].y;
        if(!shark[i].live) continue;

        if(board[x][y].arr.size() >= 2) {
            sort(board[x][y].arr.begin(), board[x][y].arr.end());
            vector<int> live;
            vector<int> die;

            live.push_back(board[x][y].arr[0]);

            for(int j = 1; j < board[x][y].arr.size(); j++) {
                die.push_back(board[x][y].arr[j]);
            }

            board[x][y].arr.clear();
            board[x][y].arr.push_back(live[0]);

            for(auto &iter : die) {
                shark[iter].live = false;
            }
        }
    }
}

void smell_spread(int time) {
    for(int i = 1; i <= M; i++) {
        if(!shark[i].live) continue;
        int x = shark[i].x;
        int y = shark[i].y;

        board[x][y].smell_time = time + K;
        board[x][y].smell_host = i;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];

            if(graph[i][j] != 0) {
                shark[graph[i][j]].x = i;
                shark[graph[i][j]].y = j;
                board[i][j].arr.push_back(graph[i][j]);
                board[i][j].smell_host = graph[i][j];
                board[i][j].smell_time = K;
            }
        }
    }

    for(int k = 1; k <= M; k++) {
        cin >> shark[k].dir;
        shark[k].live = true;
    }

    for(int i = 1; i <= M; i++) {
        for(int j = 1; j <= 4; j++) {
            for(int k = 1; k <= 4; k++) {
                int a;
                cin >> a;
                shark[i].priority[j].push_back(a);
            }
        }
    }

    for(int t = 0; t < 1001; t++) {
        if(check()) {
            cout << t;
            return 0;
        }
        smell_spread(t);
        move_shark(t);
        killing_shark();
    }

    cout << -1;
}