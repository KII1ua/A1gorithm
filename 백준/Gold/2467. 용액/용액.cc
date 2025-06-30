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

struct FISH {
    int x;
    int y;
    int Dir;
    bool live;
};

//int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
//int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int dx[] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0,0, -1, -1, -1, 0, 1, 1, 1};
//int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
//int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
int N;
int arr[100001];

void solve() {
    int left = 0;
    int right = N-1;
    int ans = abs(arr[left] + arr[right]);
    pii result;
    result.first = arr[left];
    result.second = arr[right];

    while(left < right) {
        int stand = arr[left] + arr[right];

        if(abs(stand) < ans) {
            result.first = arr[left];
            result.second = arr[right];
            ans = abs(stand);
        }

        if(stand == 0) break;

        if(stand < 0) left++;
        else right--;
    }

    cout << result.first << " " << result.second;
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