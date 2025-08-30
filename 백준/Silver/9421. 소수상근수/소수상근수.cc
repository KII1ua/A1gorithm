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
int N;
bool arr[1000001];       // 소수이면 false

void Init() {
    arr[0] = true;
    arr[1] = true;

    for(int i = 2; i <= 1000000; i++) {
        if(!arr[i]) {
            for(int j = i + i; j <= 1000000; j += i) {
                arr[j] = true;
            }
        }
    }
}

void check(int a) {
    set<int> st;

    int answer = a;

    while(true) {
        if(st.find(a) != st.end()) {
            return;
        }
        else st.insert(a);
        string s = to_string(a);

        int total = 0;
        for(int i = 0; i < s.size(); i++) {
            int tmp = s[i] - '0';
            total += tmp * tmp;
        }

        a = total;

        if(total == 1) {
            cout << answer << endl;
            return;
        }
    }
}

void solve() {
    Init();

    for(int i = 2; i <= N; i++) {
        if(!arr[i]) {
            check(i);
        }
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
