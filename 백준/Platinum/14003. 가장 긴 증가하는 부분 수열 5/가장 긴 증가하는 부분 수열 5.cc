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
int Index[1000001];

void solve(vector<int> &arr) {
    vector<int> v;

    for(int i = 0; i < N; i++) {
        if(v.size() == 0 || v[v.size()-1] < arr[i]) {
            v.push_back(arr[i]);
            Index[i] = v.size()-1;
        }
        else {
            int idx = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();

            v[idx] = arr[i];
            Index[i] = idx;
        }
    }

    cout << v.size() << endl;
    int idx = v.size() - 1;
    vector<int> answer;

    for(int i = N-1; i >= 0; i--) {
        if(Index[i] == idx) {
            answer.push_back(arr[i]);
            idx--;
        }
    }

    for(int i = v.size() - 1; i >= 0; i--) {
        cout << answer[i] << " ";
    }
}

void input() {
    cin >> N;

    vector<int> arr(N, 0);

    for(auto &it : arr) {
        cin >> it;
    }

    solve(arr);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
