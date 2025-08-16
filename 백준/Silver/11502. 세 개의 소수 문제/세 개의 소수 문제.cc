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
int T, N;
int arr[1001];
vector<int> v;

void solve() {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v.size(); j++) {
            for(int k = 0; k < v.size(); k++) {
                if(v[i] + v[j] + v[k] == N) {
                    cout << v[i] << " " << v[j] << " " << v[k] << endl;
                    return;
                }
            }
        }
    }

    cout << 0 << endl;
}

void Init() {
    arr[0] = true;
    arr[1] = true;

    for(int i = 2; i <= 1000; i++) {
        if(!arr[i]) {
            for(int j = i + i; j <= 1000; j += i) {
                arr[j] = true;
            }
        }
    }

    for(int i = 2; i <= 1000; i++) {
        if(!arr[i]) {
            v.push_back(i);
        }
    }
}

void input() {
    cin >> T;

    Init();

    while(T--) {
        cin >> N;

        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
