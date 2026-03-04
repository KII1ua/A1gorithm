#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 1001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
bool arr[10];

bool valid(int value) {
    if(value == 0 && arr[value]) {
        return false;
    }

    while(value != 0) {
        int val = value % 10;
        if(arr[val]) {
            return false;
        }

        value /= 10;
    }
    return true;
}

int count(int value) {
    if(value == 0) return 1;

    int cnt = 0;

    while(value != 0) {
        value /= 10;
        cnt++;
    }

    return cnt;
}

void solve() {
    int answer = abs(100 - N);

    for(int i = 0; i <= 1000000; i++) {
        if(valid(i)) {
            int cnt = count(i);
            answer = min(answer, abs(N - i) + cnt);
        }
    }
    cout << answer;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        arr[a] = true;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}