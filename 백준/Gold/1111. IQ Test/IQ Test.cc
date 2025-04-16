#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N;
int arr[51];

void check() {
    int a = 0;
    int b = 0;

    if(arr[1] - arr[0] != 0) {
        a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
    }
    b = arr[1] - arr[0] * a;

    for(int i = 1; i < N; i++) {
        if(arr[i] != arr[i-1] * a + b) {
            cout << "B";
            return;
        }
    }

    cout << arr[N-1] * a + b;
}

void solve() {
    if(N == 1) {
        cout << "A";
        return;
    }
    else if(N == 2) {
        if(arr[0] == arr[1]) {
            cout << arr[1];
        }
        else cout << "A";
        return;
    }

    check();
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}