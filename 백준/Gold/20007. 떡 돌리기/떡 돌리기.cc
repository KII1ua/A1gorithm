#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M, X, Y;
vector<vector<pii>> v(1001);
int dist[1001];

void dijkstra(int a) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[a] = 0;
    pq.push({0, a});        // 비용, 노드

    while(!pq.empty()) {
        int Node = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(dist[Node] < cost) continue;

        for(auto it : v[Node]) {
            int nextNode = it.first;
            int nextcost = cost + it.second;

            if(dist[nextNode] > nextcost) {
                pq.push({nextcost, nextNode});
                dist[nextNode] = nextcost;
            }
        }
    }
}

void Init() {
    for(int i = 0; i < N; i++) {
        dist[i] = MAX;
    }
}

void solve() {
    dijkstra(Y);

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < N; i++) {
        dist[i] *= 2;
    }

    for(int i = 0; i < N; i++) {
        if(i != Y) {
            pq.push(dist[i]);
        }
    }

    int tmp = 0;
    int cnt = 0;

    while(!pq.empty()) {
        int x = pq.top();
        pq.pop();

        if(x > X) {
            cout << -1;
            return;
        }

        if(tmp + x> X) {
            tmp = 0;
            cnt++;
        }

        tmp += x;
    }

    if(tmp > 0) cnt++;

    cout << cnt;
}

void input() {
    cin >> N >> M >> X >> Y;

    Init();

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
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