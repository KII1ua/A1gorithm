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

void solve() {

}

void input() {
    cin >> N;

    int answer = 0;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;

        if(a) {
            ++cnt;
            answer += cnt;
        }
        else cnt = 0;
    }

    cout << answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
