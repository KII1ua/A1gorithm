#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, M, K;
vector<pii> v;

struct cmp {
    bool operator()(pii a, pii b) {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
};

bool compare(pii a, pii b) {
    if(a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

void solve() {
    sort(v.begin(), v.end(), compare);
    priority_queue<pii, vector<pii>, cmp> pq;

    int cnt = 0;
    int maxlevel = 0;
    for(auto it : v) {
        int prefer = it.first;
        int level = it.second;
        pq.push({prefer, level});
        cnt += prefer;

        if(pq.size() == N) {
            if(cnt < M) {       // 선호도가 충족이 되지 않은 경우
                int stand = pq.top().first;
                pq.pop();
                cnt -= stand;
            }
            else {
                while(!pq.empty()) {
                    int level = pq.top().second;
                    pq.pop();
                    maxlevel = max(level, maxlevel);
                }
                cout << maxlevel;
                return;
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> N >> M >> K;

    for(int i = 0; i < K; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
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