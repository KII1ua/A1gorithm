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
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int T, N;

bool check(vector<int> *v) {
    for(int i = 0; i < v->size(); i++) {
        for(int j = i+1; j < v->size(); j++) {
            for(int k = j+1; k < v->size(); k++) {
                if(((*v)[i] ^ (*v)[j] ^ (*v)[k]) == 0) return false;
            }
        }
    }

    return true;
}

void solve() {
    int max_size = 0;
    vector<int> ans;
    for(int i = 1; i < (1 << N); i++) {
        vector<int> v;
        for(int j = 0; j < N; j++) {
            if(i & (1 << j)) v.push_back(j+1);
        }

        if(check(&v)) {
            if(max_size < v.size()) {
                ans = v;
                max_size = v.size();
            }
        }
    }

    cout << ans.size() << endl;
    for(auto it : ans) {
        cout << it << " ";
    }
    cout << endl;
}

void input() {
    cin >> T;

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
