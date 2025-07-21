#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int a, b, c, d;
map<pii, int> m;

bool check(int x, int y) {
    if(m.find({x, y}) != m.end()) {         // 이미 있는 경우
        return false;
    }

    if(x > a || y > b || x < 0 || y < 0) return false;
    return true;
}

void bfs() {
    queue<tuple<int, int, int>> q;
    m[{0, 0}] = 1;
    q.push({0, 0, 0});          // a 물통 양, b 물통 양, 횟수

    while(!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int cnt = get<2>(q.front());
        q.pop();

        if(c == x && d == y) {
            cout << cnt;
            exit(0);
        }

        for(int i = 0; i < 3; i++) {
            if(i == 0) {        // 물 채우기
                for(int j = 0; j < 2; j++) {
                    if(j == 0) {
                        int nx = a;
                        int ny = y;

                        if(check(nx, ny)) {
                            q.push({nx, ny, cnt+1});
                            m[{nx, ny}] = 1;
                        }
                    }
                    else {
                        int nx = x;
                        int ny = b;

                        if(check(nx, ny)) {
                            q.push({nx, ny, cnt+1});
                            m[{nx, ny}] = 1;
                        }
                    }
                }
            }
            else if(i == 1) {       // 물 버리기
                for(int j = 0; j < 2; j++) {
                    if(j == 0) {
                        int nx = 0;
                        int ny = y;

                        if(check(nx, ny)) {
                            q.push({nx, ny, cnt+1});
                            m[{nx, ny}] = 1;
                        }
                    }
                    else {
                        int nx = x;
                        int ny = 0;

                        if(check(nx, ny)) {
                            q.push({nx, ny, cnt+1});
                            m[{nx, ny}] = 1;
                        }
                    }
                }
            }
            else {              // 물 옮기기
                int pour1 = min(x, b - y);
                int nx1 = x - pour1;
                int ny1 = y + pour1;

                if(check(nx1, ny1)) {
                    q.push({nx1, ny1, cnt+1});
                    m[{nx1, ny1}] = 1;
                }

                int pour2 = min(y, a - x);
                int nx2 = x + pour2;
                int ny2 = y - pour2;

                if(check(nx2, ny2)) {
                    q.push({nx2, ny2, cnt+1});
                    m[{nx2, ny2}] = 1;
                }
            }
        }
    }
}

void solve() {
    bfs();

    cout << -1;
}

void input() {
    cin >> a >> b >> c >> d;
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