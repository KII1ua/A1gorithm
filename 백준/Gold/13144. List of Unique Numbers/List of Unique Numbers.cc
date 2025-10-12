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

struct horse {
    int x;
    int y;
    int dir;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 0, 1, -1};
int dy[] = {0, 1, -1, 0, 0};
int N;
int arr[100001];
bool check[100001];

void solve() {
    ll left = 0;
    ll right = 0;
    ll answer = 0;

    while(right < N) {
        if(!check[arr[right]]) {
            check[arr[right]] = true;
            right++;
        }
        else {
            answer += right - left;
            check[arr[left]] = false;
            left++;
        }
    }

    answer += (right - left) * (right - left + 1) / 2;

    cout << answer;
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
