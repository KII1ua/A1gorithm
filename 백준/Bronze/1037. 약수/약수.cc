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

void solve(vector<int> &arr) {
    int a = *min_element(arr.begin(), arr.end());
    int b = *max_element(arr.begin(), arr.end());

    cout << a * b;
}

void input() {
    cin >> N;

    vector<int> v(N);

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
