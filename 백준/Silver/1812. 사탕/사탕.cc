#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
    int r;
};

int dx[] = {0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {-1, 0, 1, 0, -1, 1, -1, 1};
int N, first;
int arr[1000];

void solve() {
    first /= 2;

    cout << first << endl;

    for(int i = 1; i < N; i++) {
        int tmp = arr[i] - first;
        first = tmp;
        cout << first << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];

        if(i % 2 == 0) {
            first -= arr[i];
        }
        else {
            first += arr[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
