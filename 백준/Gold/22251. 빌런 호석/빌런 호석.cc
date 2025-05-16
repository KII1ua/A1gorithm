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
int N, K, P, X, result;
bool check[10][7] = {{true, true, true, false, true, true, true},
                     {false, false, true, false, false, true, false},
                     {true, false, true, true, true, false, true},
                     {true, false, true, true, false, true, true},
                     {false, true, true, true, false, true, false},
                     {true, true, false, true, false, true, true},
                     {true, true, false, true, true, true, true},
                     {true, false, true, false, false, true, false},
                     {true, true, true, true, true, true, true},
                     {true, true, true, true, false, true, true}};
vector<int> res;

int segment_df(int a, int b) {      // a와 b를 비교해서 차이값 리턴
    int cnt = 0;

    for(int i = 0; i < 7; i++) {
        if(check[a][i] != check[b][i]) {
            cnt++;
        }
    }

    return cnt;
}

void bt(int idx, int cnt, vector<int> &v) {
    if(cnt > P) return;

    if(idx == K) {
        int num = 0;
        for(auto it : v) {
            num = num * 10 + it;
        }

        if(num >= 1 && num <= N && num != X) {
            result++;
        }
        return;
    }

    int stand = res[idx];

    for(int i = 0; i < 10; i++) {
        int dff = segment_df(stand, i);
        v[idx] = i;
        bt(idx+1, cnt + dff, v);
    }
}

void solve() {
    int tmp = X;

    res.resize(K);

    for(int i = K-1; i >= 0; i--) {
        res[i] = tmp % 10;
        tmp /= 10;
    }

    vector<int> tmpv = res;

    bt(0, 0, tmpv);

    cout << result;
}

void input() {
    cin >> N >> K >> P >> X;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}