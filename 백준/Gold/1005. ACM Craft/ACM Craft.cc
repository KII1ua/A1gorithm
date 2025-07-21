#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int T, N, K, W;
int inDegree[1001];
int arr[1001];
int dp[1001];
vector<vector<int>> v(1001);

void topologySort() {
    queue<pii> q;

    for(int i = 1; i <= N; i++) {
        dp[i] = arr[i];
        if(inDegree[i] == 0) {
            q.push({i, arr[i]});
        }
    }

    while(!q.empty()) {
        int x = q.front().first;
        int t = q.front().second;
        q.pop();

        for(auto it : v[x]) {
            dp[it] = max(dp[it], t + arr[it]);
            if(--inDegree[it] == 0) {
                q.push({it, dp[it]});
            }
        }
    }
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N >> K;

        v.resize(N+1);

        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for(int i = 0; i < K; i++) {
            int a, b;
            cin >> a >> b;
            inDegree[b]++;
            v[a].push_back(b);
        }

        cin >> W;

        topologySort();

        cout << dp[W] << endl;

        memset(inDegree, 0, sizeof(inDegree));
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        v.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();

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