#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M, K;
vector<vector<pii>> v(301);
int dist[301][301];

void dijkstra(int x) {
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>> pq;
    pq.push({1, 0, x});     // 횟수, 비용, 좌표
    dist[x][1] = 0;    // 노드, 횟수

    while(!pq.empty()) {
        int cnt = get<0>(pq.top());
        int cost = get<1>(pq.top());
        int Node = get<2>(pq.top());
        pq.pop();

        if(dist[Node][cnt] > cost) continue;

        for(auto it : v[Node]) {
            int NextNode = it.first;
            int NextCost = cost + it.second;

            if(Node >= NextNode) continue;
            if(cnt + 1 > M) continue;

            if(dist[NextNode][cnt+1] < NextCost) {
                dist[NextNode][cnt+1] = NextCost;
                pq.push({cnt+1, NextCost, NextNode});
            }
        }
    }
}

void solve() {
    memset(dist, -1, sizeof(dist));
    dijkstra(1);

    int res = 0;
    for(int i = 1; i <= M; i++) {
        res = max(res, dist[N][i]);
    }

    cout << res;
}

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a > b) continue;
        v[a].push_back({b, c});
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