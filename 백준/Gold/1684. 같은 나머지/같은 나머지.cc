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

void solve(vector<int> &v) {
    vector<int> tmp;

    sort(v.begin(), v.end());

    for(int i = 1; i < N; i++) {
        tmp.push_back(v[i] - v[0]);
    }
    
    int answer = gcd(tmp[0], tmp[1]);

    for(int i = 1; i < N; i++) {
        answer = gcd(answer, tmp[i]);
    }

    cout << answer;
}

void input() {
    cin >> N;

    vector<int> v(N, 0);

    for(auto &it : v) {
        cin >> it;
    }

    solve(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
