// baekjoon 28706
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
vector<int> v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, tmp, idx, res, count;

    cin >> N;
    count = N-1;

    for(int i = 0; i < N; i++) {
        cin >> tmp;
        v.push_back(tmp);
        if(v[i] == N) {
            idx = i;
            res = N;
        }
    }

    for(int j = idx-1; j >= 0; j--) {
        if(v[j] == res-1) {
            res--;
            count--;
        }
    }
    cout << count;
}