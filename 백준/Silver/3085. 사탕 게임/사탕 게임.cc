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

int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, answer;
char graph[51][51];
char C_graph[51][51];

bool check(int nx, int ny) {
    if(nx < 0 || nx >= N || ny < 0 || ny >= N) return false;
    else return true;
}

int Count() {
    int result = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char candy = C_graph[i][j];
            for(int k = 0; k < 2; k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];
                int cnt = 1;

                while(check(nx, ny)) {
                    if(candy != C_graph[nx][ny]) {        // 다른경우 탈출
                        break;
                    }

                    cnt++;
                    result = max(result, cnt);
                    nx += dx[k];
                    ny += dy[k];
                }
            }
        }
    }
    return result;
}

void Copy() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            C_graph[i][j] = graph[i][j];
        }
    }
}

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            char stand = graph[i][j];
            for(int k = 0; k < 2; k++) {
                Copy();

                int nx = i + dx[k];
                int ny = j + dy[k];
                
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if(stand != graph[nx][ny]) {        // 같지 않을 경우
                    swap(C_graph[i][j], C_graph[nx][ny]);
                }
                answer = max(answer, Count());
            }
        }
    }

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
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