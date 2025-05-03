#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int arr[10];        // 정답
int tmp[10];
int result;

/*
 *      백트래킹
 */

void bt(int x) {
    if(x == 10) {
        int cnt = 0;
        bool flag = false;

        for(int i = 0; i < 8; i++) {
            if(tmp[i] == tmp[i+1] && tmp[i+1] == tmp[i+2]) {
                flag = true;
                break;
            }
        }

        if(!flag) {
            for (int i = 0; i < 10; i++) {
                if (arr[i] == tmp[i]) {
                    cnt++;
                }
            }
            if (cnt >= 5) {
                result++;
            }
        }
        return;
    }

    for(int i = 1; i <= 5; i++) {
        tmp[x] = i;
        bt(x+1);
    }
}

void solve() {
    bt(0);

    cout << result;
}

void input() {
    for(int i = 0; i < 10; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}