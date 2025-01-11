// baekjoon 3968            unorder_map은 해시테이블 기반으로 insert, erase, find가 O(1)으로 수행된다.
#include <bits/stdc++.h>  // but map은 레드블랙트리를 기반으로 하여 실행 시간이 O(log N)이 된다.
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, res, k;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int maxdp[2][3];
    int mindp[2][3];
    int left, middle, right;

    cin >> N;

    cin >> maxdp[0][0] >> maxdp[0][1] >> maxdp[0][2];
    mindp[0][0] = maxdp[0][0];
    mindp[0][1] = maxdp[0][1];
    mindp[0][2] = maxdp[0][2];

    for(int i = 1; i < N; i++) {
        int tmp = i % 2;
        cin >> left >> middle >> right;

        maxdp[tmp][0] = max(maxdp[k][0], maxdp[k][1]) + left;
        maxdp[tmp][1] = max({maxdp[k][0], maxdp[k][1], maxdp[k][2]}) + middle;
        maxdp[tmp][2] = max(maxdp[k][1], maxdp[k][2]) + right;

        mindp[tmp][0] = min(mindp[k][0], mindp[k][1]) + left;
        mindp[tmp][1] = min({mindp[k][0], mindp[k][1], mindp[k][2]}) + middle;
        mindp[tmp][2] = min(mindp[k][1], mindp[k][2]) + right;

        k = 1 - k;
    }

    cout << max({maxdp[k][0], maxdp[k][1], maxdp[k][2]}) << " " << min({mindp[k][0], mindp[k][1], mindp[k][2]});
}
