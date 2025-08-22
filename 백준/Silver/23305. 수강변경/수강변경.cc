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
int N;
int arr[1000001];
map<int, int> m;

void solve() {
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        if(m.find(arr[i]) != m.end()) {
            m[arr[i]]--;
            cnt++;
            if(m[arr[i]] == 0) m.erase(arr[i]);
        }
    }

    cout << N - cnt;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        m[a]++;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
