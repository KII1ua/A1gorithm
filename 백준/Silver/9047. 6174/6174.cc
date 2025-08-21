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
int T, N;
priority_queue<int, vector<int>> pq1;       // 최대
priority_queue<int, vector<int>, greater<int>> pq2;     // 최소

void divided(int a) {
    while(!pq1.empty()) pq1.pop();
    while(!pq2.empty()) pq2.pop();

    int div = 10, divs = 1;

    for(int i = 0; i < 4; i++) {
        int tmp = a % div;
        pq1.push(tmp / divs);
        pq2.push(tmp / divs);

        a -= tmp;
        div *= 10;
        divs *= 10;
    }
}

int calculate() {
    int max1 = 0, min1 = 0;

    int w1 = 1000, w2 = 1000;

    for(int i = 0; i < 4; i++) {
        int tmp1 = pq1.top() * w1;
        int tmp2 = pq2.top() * w2;
        pq1.pop();
        pq2.pop();

        max1 += tmp1;
        min1 += tmp2;

        w1 /= 10;
        w2 /= 10;
    }

    return max1 - min1;
}

void solve() {
    int tmp = N;

    if(tmp == 6174) {
        cout << 0 << endl;
        return;
    }

    int cnt = 1;

    while(true) {
        divided(tmp);

        tmp = calculate();

        if(tmp == 6174) {
            cout << cnt << endl;
            return;
        }
        cnt++;
    }
}

void input() {
    cin >> T;

    while(T--) {
        cin >> N;

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
