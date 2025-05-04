#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;
char graph[7][7];
int tmpgraph[7][7];
vector<coordinate> space;       // 빈 공간
vector<coordinate> student;
vector<coordinate> teacher;
bool visited[37];       // 빈 공간 조합
bool isStudent[37];

/*
 *      선생님: (T,2), 학생: (S,1), 아무것도 없음: (X,0), 장애물: -1
 */

void Init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(graph[i][j] == 'X') {
                tmpgraph[i][j] = 0;
            }
            else if(graph[i][j] == 'S') tmpgraph[i][j] = 1;
            else tmpgraph[i][j] = 2;
        }
    }

    for(int i = 0; i < student.size(); i++) {
        isStudent[i] = false;
    }
}

bool search() {
    Init();

    for(int i = 0; i < space.size(); i++) {
        if(visited[i]) {
            int x = space[i].x;
            int y = space[i].y;

            tmpgraph[x][y] = -1;
        }
    }

    for(int i = 0; i < teacher.size(); i++) {
        for(int j = 0; j < 4; j++) {
            int x = teacher[i].x;
            int y = teacher[i].y;

            while(x >= 0 && x < N && y >= 0 && y < N && tmpgraph[x][y] != -1) {
                x += dx[j];
                y += dy[j];

                if(tmpgraph[x][y] == 1) {
                    for(int k = 0; k < student.size(); k++) {
                        if(student[k].x == x && student[k].y == y) {
                            isStudent[k] = true;
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < student.size(); i++) {
        if(isStudent[i]) {
            return false;
        }
    }

    return true;
}

void bt(int x) {
    if(x == 3) {        // 3개 선택
        if(search()) {
            cout << "YES";
            exit(0);
        }
        return;
    }

    for(int i = x; i < space.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            bt(x+1);
            visited[i] = false;
        }
    }
}

void solve() {
    bt(0);

    cout << "NO";
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 'X') {
                space.push_back({i, j});
            }
            else if(graph[i][j] == 'T') {
                teacher.push_back({i, j});
            }
            else student.push_back({i, j});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}