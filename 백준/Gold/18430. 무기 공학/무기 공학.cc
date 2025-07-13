#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

//int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
//int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int dx[][2] = {{1, 0}, {1, 0}, {-1, 0}, {-1, 0}};
int dy[][2] = {{0, -1}, {0, 1}, {0, 1}, {0, -1}};
int N, M;
int graph[6][6];
bool visited[6][6];
int result;

void bt(int x, int y, int num) {
    if(x == N) {
        result = max(result, num);
        return;
    }

    int nx = x;
    int ny = y+1;
    if(ny == M) {
        nx++;
        ny = 0;
    }

    if(!visited[x][y]) {
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i][0];
            int yy = y + dy[i][0];
            int ax = x + dx[i][1];
            int ay = y + dy[i][1];

            if(xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
            if(ax < 0 || ax >= N || ay < 0 || ay >= M) continue;

            if(!visited[xx][yy] && !visited[ax][ay]) {
                visited[x][y] = true;
                visited[xx][yy] = true;
                visited[ax][ay] = true;
                int tmp = graph[x][y] * 2 + graph[xx][yy] + graph[ax][ay];
                bt(nx, ny, num + tmp);
                visited[x][y] = false;
                visited[xx][yy] = false;
                visited[ax][ay] = false;
            }
        }
    }
    bt(nx, ny, num);
}

void solve() {
    bt(0, 0, 0);

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
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