#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e8

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 1, -1, 0, 1, -1, -1, 1};
int dy[] = {1, 0, 0, -1, -1, 1, -1, 1};
int N, S;
int arr[51];

void solve() {
    for(int i = 0; i < N; i++) {
        int value = arr[i];
        int maxidx = i;

        for(int j = i+1; j < min(N, i+S+1); j++) {
            if(value < arr[j]) {
                value = arr[j];
                maxidx = j;
            }
        }

        for(int j = maxidx; j > i; j--) {
            swap(arr[j], arr[j-1]);
            S--;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
}

void input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cin >> S;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}