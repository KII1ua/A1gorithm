#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 123457;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
int arr[MAX];
vector<vector<int>> v(MAX);

ll func(int Node) {
    ll answer = arr[Node];

    for(auto &it : v[Node]) {
        answer += func(it);
    }

    if(answer < 0) {
        return 0;
    }
    else return answer;
}

void solve() {
    cout << func(1);
}

void input() {
    cin >> N;

    for(int i = 2; i <= N; i++) {
        char a;
        int b, c;

        cin >> a >> b >> c;
        if(a == 'S') {
            arr[i] = b;
        }
        else arr[i] = -b;

        v[c].push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}