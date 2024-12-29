// baekjoon 1012
#include <bits/stdc++.h>
#define endl "\n";
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int N, a, b;
vector<int> v[100001];
int arr[100001];
bool visited[100001];

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

void dfs(int x) {
    visited[x] = true;

    for(int i = 0; i < v[x].size(); i++) {
        int tmp = v[x][i];
        if(!visited[tmp]) {
            arr[tmp] = x;
            dfs(tmp);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for(int i = 1 ; i < N; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);

    for(int i = 2 ; i <= N; i++) {
        cout << arr[i] << endl;
    }
}