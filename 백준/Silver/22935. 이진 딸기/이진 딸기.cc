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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int T, N;
int arr[29];

void Print() {
    for(int i = 0; i <= 28; i++) {
        cout << arr[i] << " ";
    }
}

void solve() {
    deque<string> dq;
    int tmp = (N-1) % 28;
    
    if(tmp >= 15) {
        tmp = arr[tmp];
    }
    
    tmp = arr[tmp];

    for(int i = 0; i < 4; i++) {
        if(1 & (tmp >> i)) {        // 1인 경우
            dq.push_front("딸기");
        }
        else dq.push_front("V");
    }

    while(!dq.empty()) {
        string s = dq.front();
        dq.pop_front();

        cout << s;
    }
    cout << endl;
}

void input() {
    cin >> T;

    for(int i = 0; i <= 14; i++) {
        arr[i] = i+1;
    }

    int tmp = 13;
    for(int i = 15; i <= 28; i++) {
        arr[i] = tmp--;
    }

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
