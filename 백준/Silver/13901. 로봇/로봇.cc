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

//int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
//int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, -1, 1};
int R, C, k, startx, starty;
int graph[1001][1001];          // 0 : 빈칸, -1 : 장애물
vector<int> dir;

bool check(int x, int y) {
    if(x >= 0 && x < R && y >= 0 && y < C) return true;
    return false;
}

void solve() {
    graph[startx][starty] = 1;

    while(true) {
        bool move = false;

        for (auto &it: dir) {
            int nx = startx + dx[it];
            int ny = starty + dy[it];

            while (true) {
                if (nx >= 0 && nx < R && ny >= 0 && ny < C) {
                    if (graph[nx][ny] == 0) {
                        graph[nx][ny] = 1;
                        nx += dx[it];
                        ny += dy[it];
                        move = true;
                    } else {
                        startx = nx - dx[it];
                        starty = ny - dy[it];
                        break;
                    }
                } else {
                    startx = nx - dx[it];
                    starty = ny - dy[it];
                    break;
                }
            }
        }

        if(!move) {
            break;
        }
    }

    cout << startx << " " << starty;
}

void input() {
    cin >> R >> C >> k;

    for(int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        graph[r][c] = -1;
    }

    cin >> startx >> starty;

    for(int i = 0; i < 4; i++) {
        int a;
        cin >> a;
        dir.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();

//    int row = 3;
//    int column = 4;
//
//    int **arr = (int**)malloc(row * sizeof(int*));
//
//    for(int i = 0; i < row; i++) {
//        arr[i] = (int*)malloc(column * sizeof(int));
//    }
//
//    cout << arr[0][0];


//    int **arr = (int **)malloc(row * sizeof(int*));
//
//    for(int i = 0; i < row; i++) {
//        arr[i] = (int*)malloc(column * sizeof(int));
//    }
//
//    for(int i = 0; i < row; i++) {
//        for(int j = 0; j < column; j++) {
//            arr[i][j] = j;
//        }
//    }
//
//    for(int i = 0; i < row; i++) {
//        for(int j = 0; j < column; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for(int i = 0; i < row; i++) {
//        free(arr[i]);
//    }
//    free(arr);
//
//    cout << sizeof(int);
//    cout << sizeof(int*);


//    int row = 3;
//
//    int *arr = (int*)malloc(10000 * sizeof(int));
//
//    for(int i = 0; i < 10000; i++) {
//        arr[i] = i;
//    }
//
//    for(int i = 0; i < 100; i++) {
//        cout << arr[i] << endl;
//    }
//
//    free(arr);


//    int arr[] = {1, 2, 3, 4, 5};
//    int *ptr = arr;
//    int **tmp = ptr;

//    struct pointwrapper pwrap;
//    struct jsu st = {"데이터", 4, 5, 4, 3};
//
//    pwrap.ptr = &st;
//
//    cout << pwrap.ptr << endl;
//
//    cout << pwrap.ptr -> os;

//    struct jsu st[3] = {{"데이터1", 95, 88}, {"데이터2", 84, 91},
//                        {"데이터3", 86, 75}};
//
//    struct jsu* p;
//
//    p = &st[0];
//
//    (p + 1) -> hab = (p + 1) -> os + (p + 2) -> db;
//
//    cout << p;
//    cout << *p.os;
}