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
int N;
int first[] = {2, 3, 5, 7};
int arr[10];

bool isPrime(int num) {
    if(num < 2) return false;

    for(int i = 2; i < num; i++) {
        if(num % i == 0) return false;
    }

    return true;
}

void bt(int x, int cnt) {
    if(cnt == 0) {
        if(isPrime(x)) {
            cout << x << endl;
        }
        return;
    }

    for(int i = 1; i < 10; i++) {
        int tmp = x * 10 + i;
        if(isPrime(tmp)) {
            bt(tmp, cnt-1);
        }
    }
}

void solve() {
    for(int i = 0; i < 4; i++) {
        bt(first[i], N-1);
    }
}

void input() {
    cin >> N;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}