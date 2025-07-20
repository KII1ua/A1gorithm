#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M, K, lens, cnt;
char graph[101][101];
int dp[101][101][81];
string s;

int dfs(int x, int y, int idx) {
    if(dp[x][y][idx] != -1) return dp[x][y][idx];

    if(idx == lens-1) return 1;

    dp[x][y][idx] = 0;

    int& ret = dp[x][y][idx];

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < K; j++) {
            int nx = x + dx[i] * (j + 1);
            int ny = y + dy[i] * (j + 1);

            if(nx >= N || nx < 0 || ny >= M || ny < 0) continue;

            if(graph[nx][ny] == s[idx+1]) {
                ret += dfs(nx, ny, idx+1);
            }
        }
    }

    return ret;
}

void solve() {
    memset(dp, -1, sizeof(dp));

    lens = s.length();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(graph[i][j] == s[0]) {
                cnt += dfs(i, j, 0);
            }
        }
    }

    cout << cnt;
}

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    cin >> s;
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