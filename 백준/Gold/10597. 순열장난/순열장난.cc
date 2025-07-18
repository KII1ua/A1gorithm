#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 1, -1, 0,1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
string s;
bool used[51];
vector<int> result;
bool finished = false;

void dfs(int idx) {
    if (finished) return;

    if (idx == s.size()) {
        int maxVal = 0;
        for (int x : result) maxVal = max(maxVal, x);
        int count = 0;
        for (int i = 1; i <= maxVal; ++i)
            if (used[i]) count++;

        if (count == maxVal) {
            for (int x : result) cout << x << " ";
            cout << "\n";
            finished = true;
        }
        return;
    }

    if (idx < s.size()) {
        int num = s[idx] - '0';
        if (num >= 1 && num <= 50 && !used[num]) {
            used[num] = true;
            result.push_back(num);
            dfs(idx + 1);
            result.pop_back();
            used[num] = false;
        }
    }

    if (idx + 1 < s.size()) {
        int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
        if (num >= 1 && num <= 50 && !used[num]) {
            used[num] = true;
            result.push_back(num);
            dfs(idx + 2);
            result.pop_back();
            used[num] = false;
        }
    }
}

void solve() {
    dfs(0);
}

void input() {
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