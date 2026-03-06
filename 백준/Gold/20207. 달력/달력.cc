#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const ll INF = 1e18;
const int MAX = 200000;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int day[367];

void solve() {
    int answer = 0;
    int height = 0;
    int width = 0;

    for(int i = 1; i <= 365; i++) {
        if(day[i] != 0) {
            width++;
            height = max(height, day[i]);
        }
        else {
            answer += width * height;
            width = 0;
            height = 0;
        }
    }

    answer += width * height;

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        day[a]++;
        day[b+1]--;
    }

    for(int i = 1; i <= 365; i++) {
        day[i] += day[i-1];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}