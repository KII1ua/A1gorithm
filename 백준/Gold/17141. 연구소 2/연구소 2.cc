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

int dx[] = {-1, 0, 1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, -1, 1};
int N, M;
int graph[51][51];      // 0 : 빈칸, 1 : 벽, 2 : 바이러를 놓을 수 있는 칸
int C_Map[51][51];
vector<coordinate> virus;
bool visited[10];
bool check[51][51];
int result = MAX;
int tmpcnt;

void Copy() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            C_Map[i][j] = graph[i][j];
            check[i][j] = false;
        }
    }
}

void Spread() {
    vector<coordinate> tmp;

    for(int i = 0; i < virus.size(); i++) {
        if(visited[i]) {
            tmp.push_back({virus[i]});
        }
    }

    int cnt = 0;

    for(auto it : tmp) {
        int x = it.x;
        int y = it.y;

        check[x][y] = true;
    }
    while(!tmp.empty()) {
        vector<coordinate> tmparr;
        for(auto it: tmp) {
            int x = it.x;
            int y = it.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if(C_Map[nx][ny] != 1 && !check[nx][ny]) {
                    tmparr.push_back({nx, ny});
                    check[nx][ny] = true;
                }
            }
        }
        tmp = tmparr;
        cnt++;
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(C_Map[i][j] != 1 && !check[i][j]) {
                return;
            }
        }
    }

    result = min(result, cnt);
}

void bt(int x, int cnt) {
    if(cnt == M) {
        Copy();
        Spread();
        return;
    }

    for(int i = x; i < virus.size(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            bt(i+1, cnt+1);
            visited[i] = false;
        }
    }
}

void solve() {
    if(M == 0) {
        if(tmpcnt == 0) {
            cout << 0;
            return;
        }
    }

    bt(0, 0);

    if(result == MAX) {
        cout << -1;
    }
    else cout << result-1;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> graph[i][j];

            if(graph[i][j] == 2) virus.push_back({i, j});

            if(graph[i][j] != 1) {
                tmpcnt++;
            }
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