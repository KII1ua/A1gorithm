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

int dx[] = {-1, 0, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 1, 0, -1, 1, -1, 1};
//int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
//int dy[] = {0,0, -1, -1, -1, 0, 1, 1, 1};
//int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
//int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int N;
ll dist;
vector<pii> v;
bool visited[3001];

void solve() {
    sort(v.begin(), v.end());

    int time = 0;
    for(int i = 0; i < N; i++) {
        int locate = v[i].first;
        int boxtime = v[i].second;

        if(locate >= boxtime) {
            visited[i] = true;
        }
    }

    time += v[N-1].first;
    int curloc = time;
    bool flag = true;

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            flag = false;
            break;
        }
    }

    if(!flag) {
        for (int i = N - 1; i >= 0; i--) {
            int locate = v[i].first;
            int boxtime = v[i].second;

            if (visited[i]) {
                continue;
            }


            if (curloc != locate) {      // 현재 위치랑 다를 경우
                int addloc = curloc - locate;
                time += addloc;
                curloc = locate;

                if (time >= boxtime) {       // 현재 시간이 반품 시간보다 큰경우 바로 가져감
                    continue;
                } else {                      // 기다렸다 가져감
                    int tmp = boxtime - time;
                    time += tmp;
                }
            } else {
                int addtime = boxtime - time;
                time += addtime;
            }
        }
        cout << time + v[0].first;
    }
    else {
        cout << v[N-1].first * 2;
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back({a, 0});
    }

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v[i].second = a;
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