// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N, M;
vector<int> v;
int arr[10];
int result;

void bt(int cnt, int end) {
    if(cnt == end) {
        string a = "";
        int res;
        for(int i = 0; i < end; i++) {
            a += to_string(arr[i]);
        }
        res = stoi(a);
        if(N >= res)
            result = max(result, res);

        return;
    }

    for(int i = 0; i < M; i++) {
        arr[cnt] = v[i];
        bt(cnt+1, end);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    string tmp = to_string(N);

    for(int i = 1; i <= tmp.length(); i++) {
        bt(0, i);
    }

    cout << result;
}
