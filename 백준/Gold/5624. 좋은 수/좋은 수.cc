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
int arr[5001];
bool visited[400001];

void solve() {
    int answer = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(visited[arr[i] - arr[j]+ 200000]) {
                answer++;
                break;
            }
        }

        for(int j = 0; j <= i; j++) {
            visited[arr[i] + arr[j] + 200000] = true;
        }
    }

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
