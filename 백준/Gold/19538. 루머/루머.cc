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
int N, M;
vector<vector<int>> v(200001);
int rumor[200001];
queue<int> q;
queue<int> tmpq;
int currenttime;

int rumorCount(int Node) {
    int cnt = 0;

    for(auto it : v[Node]) {
        if(rumor[it] != -1) cnt++;
    }

    return cnt;
}

void bfs() {
    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < v[x].size(); i++) {
            int nextNode = v[x][i];
            if(rumor[nextNode] != -1) continue;

            int rumorcnt = rumorCount(nextNode);

            if((v[nextNode].size() + 1) / 2 > rumorcnt) continue;
            tmpq.push(nextNode);
        }
        if(q.empty()) {
            currenttime++;
            while(!tmpq.empty()) {
                int tmp = tmpq.front();
                tmpq.pop();
                rumor[tmp] = currenttime;
                q.push(tmp);
            }
        }
    }
}

void solve() {
    bfs();

    for(int i = 1; i <= N; i++) {
        cout << rumor[i] << " ";
    }
}

void input() {
    cin >> N;

    fill(rumor, rumor + N + 1, -1);

    for(int i = 1; i <= N; i++) {
        for(int j = 0; ; j++) {
            int a;
            cin >> a;

            if(a == 0) break;

            v[i].push_back(a);
        }
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        rumor[a] = 0;
        q.push(a);
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