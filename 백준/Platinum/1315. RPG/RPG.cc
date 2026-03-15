#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N;
vector<tuple<int, int, int>> v;
int dp[1001][1001];
bool visited[101];

int func(int STR, int INT) {
    int &ret = dp[STR][INT];

    if(ret != -1) return ret;

    ret = 0;
    int pnt = 0;
    vector<int> tmp;

    // 현재 완료할 수 있는 퀘스트 개수 세기
    for(int i = 0; i < N; i++) {
        int str = get<0>(v[i]);
        int intr = get<1>(v[i]);
        int pt = get<2>(v[i]);

        if(STR >= str || INT >= intr) {
            ret++;
            if(!visited[i]) {
                visited[i] = true;
                pnt += pt;
                tmp.push_back(i);
            }
        }
    }

    for(int i = 0; i <= pnt; i++) {
        int nextstr = min(STR + pnt - i, 1000);
        int nextint = min(INT + i, 1000);

        ret = max(ret, func(nextstr,nextint));
    }

    for(auto &iter : tmp) {
        visited[iter] = false;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);


    cin >> N;

    for(int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v.push_back({a, b, c});
    }

    memset(dp, -1, sizeof(dp));

    cout << func(1, 1);
}