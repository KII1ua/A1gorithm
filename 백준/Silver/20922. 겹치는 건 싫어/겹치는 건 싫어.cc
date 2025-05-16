#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

struct coordinate {
    int x;
    int y;
};

int dx[] = {-1 ,1, 0, 0, -1, -1, 1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int M, N, result;
int arr[200001];
int cnt[100001];

void solve() {
    int left = 1;
    int right = 1;

    while(right <= N) {
        if(cnt[arr[right]] != M) {
            cnt[arr[right]]++;
            right++;
        }
        else {
            cnt[arr[left]]--;
            left++;
        }

        result = max(result, right - left);
    }

    cout << result;
}

void input() {
    cin >> N >> M;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}