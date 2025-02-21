// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;
int arr[250001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    while(true) {
        cin >> N;
        if(!N) return 0;

        int result = -10001;

        for(int i = 1; i <= N; i++) {
            cin >> arr[i];
        }

        for(int i = 2; i <= N; i++) {
            arr[i] = max(arr[i] + arr[i-1], arr[i]);
        }

        for(int i = 1; i <= N; i++) {
            result = max(result, arr[i]);
        }

        cout << result << endl;

        memset(arr, 0, sizeof(arr));
    }
}
