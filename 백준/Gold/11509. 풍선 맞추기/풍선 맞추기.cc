#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 200000;
const int D = 2000000;
const int MOD = 10007;
// int dx[] = {0, 0, 1, -1};
// int dy[] = {1, -1, 0, 0};
int dx[] = {1, 0, 0};
int dy[] = {0, -1, 1};
int N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    vector<int> v(N+1, 0);
    int arr[1000001] = {0};

    for(auto &iter : v) {
        cin >> iter;
    }

    int result = 0;

    for(int i = 0; i < N; i++) {
        int a = v[i];

        if(arr[a] > 0) {      // 화살이 있는 경우
            arr[a]--;
            if(a-1 > 0) {
                arr[a-1]++;
            }
        }
        else {
            arr[a-1]++;
            result++;
        }
    }

    cout << result;
}