// baekjoon 24228
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, S;
int cnt = int(1e9);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    vector<int> v;

    cin >> N >> S;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    int left, right;
    int res = v[right];

    while(left <= right && right <= N) {

        if(res >= S) {
            cnt = min(cnt, right - left + 1);
        }

        if(res > S) {       // 부분 합이 S보다 클때 left를 땡겨와야한다.
            res -= v[left];
            left++;
        }
        else {
            right++;
            res += v[right];
        }
    }

    if(cnt == int(1e9)) cout << 0;
    else cout << cnt;

}
