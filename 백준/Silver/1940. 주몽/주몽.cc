#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x, y;
};

int dx[] = {-1 ,1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<int> v;

void solve() {
    sort(v.begin(), v.end());

    int left = 0;
    int right = N-1;
    int result = 0;

    while(left < right) {
        if(v[left] + v[right] == M) {
            result++;
            left++;
        }
        else if(v[left] + v[right] > M) {
            right--;
        }
        else left++;
    }

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}