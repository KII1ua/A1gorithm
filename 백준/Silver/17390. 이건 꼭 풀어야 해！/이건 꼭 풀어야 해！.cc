// baekjoon 15649
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, M;
vector<int> v;
vector<int> sumv;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int result;
    int tmp = 0;

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        tmp += v[i];
        sumv.push_back(tmp);
    }

    for(int i = 0; i < M; i++) {
        int start, end;
        cin >> start >> end;
        result = sumv[end-1] - sumv[start-1] + v[start-1];
        cout << result << endl;
    }
}
