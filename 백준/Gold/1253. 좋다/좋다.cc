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

int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int N;

bool check(int val, vector<int> &v, int idx) {
    int left = 0;
    int right = N-1;

    while(left < right) {
        if(left == idx) {left++; continue;}
        if(right == idx) {right--; continue;}

        int stand = v[left] + v[right];

        if(stand == val) {
            return true;
        }

        if(stand < val) {
            left++;
        }
        else right--;
    }

    return false;
}

void solve(vector<int> &arr) {
    int cnt = 0;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < N; i++) {
        if(check(arr[i], arr, i)) cnt++;
    }

    cout << cnt;
}

void input() {
    cin >> N;

    vector<int> v(N, 0);

    for(auto &it : v) {
        cin >> it;
    }

    solve(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
