#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, K, M;        // 학생 수, 퇴장 번호, 동호 인덱스

void solve() {
    int result = 0;
    int tmp_m = M;

    while(result < N) {
        result += 1;
        if(K % (N - result + 1) == tmp_m % (N - result + 1)) {
            break;
        }
        else {
            tmp_m -= K;
            while(tmp_m <= 0) {
                tmp_m += (N - result + 1);
            }
        }
    }

    cout << result;
}

void input() {
    cin >> N >> K >> M;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}