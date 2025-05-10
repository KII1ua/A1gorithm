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

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int A, B;
int nx[] = {4, 7};
int arr[9];
int cnt;

bool check(string tmp) {
    int res = stoi(tmp);

    if(A <= res && res <= B) {
        return true;
    }
    return false;
}

void bt(int x, int end) {
    if(x == end) {
        string tmp = "";
        for(int i = 0; i < end; i++) {
            tmp += to_string(arr[i]);
        }
        if(check(tmp)) cnt++;
        return;
    }

    for(int i = 0; i < 2; i++) {
        arr[x] = nx[i];
        bt(x+1, end);
    }
}

void solve() {
    for(int i = 1; i <= 9; i++) {
        bt(0, i);
    }

    cout << cnt;
}

void input() {
    cin >> A >> B;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}