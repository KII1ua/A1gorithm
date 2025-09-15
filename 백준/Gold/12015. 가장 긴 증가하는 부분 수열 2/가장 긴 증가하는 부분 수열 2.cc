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
vector<int> v;
int arr[1000001];

void solve() {
    for(int i = 0; i < N; i++) {
        if(v.size() == 0 || v[v.size()-1] < arr[i]) v.push_back(arr[i]);
        else {
            int left = 0;
            int right = v.size()-1;
            while(left < right) {
                int mid = (left + right) / 2;

                if(v[mid] >= arr[i]) right = mid;
                else left = mid + 1;
            }
            v[left] = arr[i];
        }
    }

    cout << v.size();
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
