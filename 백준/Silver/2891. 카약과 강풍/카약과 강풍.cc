// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, S, R;
int arr[12];
int cnt;
vector<int> v1;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> S >> R;     // 손상되면 1 여분이 있을경우 2

    for(int i = 1; i <= N; i++) {
        arr[i] = 1;
    }

    for(int i = 0; i < S; i++) {
        int a;
        cin >> a;
        arr[a]--;
    }

    for(int i = 0; i < R; i++) {
        int a;
        cin >> a;
        arr[a]++;
    }

    for(int i = 1; i <= N; i++) {
        if(arr[i] == 2) {
            if(!arr[i-1]) {
                arr[i] = arr[i-1] = 1;
                continue;
            }

            if(!arr[i+1]) {
                arr[i] = arr[i+1] = 1;
                continue;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if(arr[i] == 0) cnt++;
    }

    cout << cnt;
}

