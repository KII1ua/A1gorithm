#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
char graph[5][9];
int minCnt, minMv;

void copyMap(char a[][9], char b[][9]) {        // a 그래프에 복사
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            a[i][j] = b[i][j];
        }
    }
}

void Init() {
    minCnt = MAX;
    minMv = MAX;
}

void bt(int cnt, char tmp_graph[][9]) {
    char Map[5][9];
    bool visited = false;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            if(tmp_graph[i][j] == 'o') {
                for(int k = 0; k < 4; k++) {
                    int xx = i + dx[k];
                    int yy = j + dy[k];
                    int nx = i + dx[k] + dx[k];     // 다다음 칸
                    int ny = j + dy[k] + dy[k];

                    if(xx >= 0 && yy >= 0 && xx < 5 && yy < 9 && nx >= 0 && ny >= 0 && nx < 5 && ny < 9) {
                        if(tmp_graph[xx][yy] == 'o' && tmp_graph[nx][ny] == '.') {
                            visited = true;
                            copyMap(Map, tmp_graph);
                            Map[i][j] = '.';
                            Map[xx][yy] = '.';
                            Map[nx][ny] = 'o';
                            bt(cnt+1, Map);
                        }
                    }
                }
            }
        }
    }
    if(!visited) {
        int pin = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 9; j++) {
                if(tmp_graph[i][j] == 'o') {
                    pin++;
                }
            }
        }

        if(minCnt > pin) {
            minCnt = pin;
            minMv = cnt;
        }
        return;
    }
}

void input() {
    cin >> N;

    while(N--) {
        Init();
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> graph[i][j];
            }
        }
        bt(0, graph);

        cout << minCnt << " " << minMv << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}