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

int dx[] = {0 ,0, -1, 0, 1, 1, -1, -1, 1};
int dy[] = {0, -1, 0, 1, 0, -1, 1, -1, 1};
int N, cnt;
string arr[101];

void solve() {
    for(int i = 0; i < N; i++) {
        for(int j = i+1; j < N; j++) {
            string a = arr[i];
            string b = arr[j];

            char visited1[26] = {0};
            char visited2[26] = {0};
            bool flag = false;

            for(int k = 0; k < a.size(); k++) {
                int idx1 = a[k] - 'a';
                int idx2 = b[k] - 'a';

                if(visited1[idx1] == 0 && visited2[idx2] == 0) {
                    visited1[idx1] = b[k];
                    visited2[idx2] = a[k];
                }
                else if(visited1[idx1] != b[k] || visited2[idx2] != a[k]) {
                    flag = true;
                    break;
                }
            }

            if(!flag) cnt++;
        }
    }

    cout << cnt;
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
