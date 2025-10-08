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
int N, T;
vector<tuple<int, int, int>> v;

void solve() {
    int answer = MAX;


    for(int i = 0; i < N; i++) {
        int le = 1;
        int ri = get<2>(v[i]);
        int start = get<0>(v[i]);
        int gap = get<1>(v[i]);

        while(le <= ri) {
            int mid = (le + ri) / 2;
            int tmp = start + (mid - 1) * gap;

            if(tmp >= T) {      // 왼쪽
                answer = min(answer, abs(T - tmp));
                ri = mid - 1;
            }
            else {
                le = mid + 1;
            }
        }
    }

    cout << ((answer == MAX)? -1 : answer);
}

void input() {
    cin >> N >> T;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
