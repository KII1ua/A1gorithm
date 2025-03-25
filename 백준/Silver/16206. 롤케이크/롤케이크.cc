#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N, M;
int cnt;
vector<int> v1;
vector<int> v2;

void solve() {
    for(int i = 0; i < v1.size(); i++) {
        if(M == 0) break;
        int stand = v1[i];
        int tmp = stand / 10;

        if(stand % 10 != 0) {
            if(M - tmp >= 0) {
                M -= tmp;
                cnt += tmp;
            }
            else {
                cnt += M;
                M = 0;
            }
        }
        else {
            if(M - (tmp - 1) >= 0) {
                M -= (tmp-1);
                cnt += tmp;
            }
            else {
                cnt += M;
                M = 0;
            }
        }
    }

    cout << cnt;
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a == 10) cnt++;
        else if(a % 10 == 0 && a > 10) {
            v1.push_back(a);
        }
        else v2.push_back(a);
    }

    if(v1.size()) {
        sort(v1.begin(), v1.end());
    }
    if(v2.size()) {
        sort(v2.begin(), v2.end());
    }

    v1.insert(v1.end(), v2.begin(), v2.end());
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
