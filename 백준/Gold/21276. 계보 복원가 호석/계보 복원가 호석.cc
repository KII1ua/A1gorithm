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
int N, M;
string arr[1001];
map<string, int> lst;
vector<vector<int>> v(1001);
int isDegree[1001];

void solve() {
    vector<int> tmp;

    for(int i = 1; i <= N; i++) {
        if(!isDegree[i]) {
            tmp.push_back(i);
        }
    }

    cout << tmp.size() << endl;

    for(auto it : tmp) {
        cout << arr[it] << " ";
    }
    cout << endl;

    vector<vector<int>> child(1001);

    for(int i = 1; i <= N; i++) {
        for(auto it : v[i]) {
            if(isDegree[it] == isDegree[i] + 1) {
                child[i].push_back(it);
            }
        }
        sort(child[i].begin(), child[i].end());
    }

    for(int i = 1; i <= N; i++) {
        cout << arr[i] << " " << child[i].size() << " ";
        for(auto it : child[i]) {
            cout << arr[it] << " ";
        }
        cout << endl;
    }
}

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    sort(arr+1, arr+1+N);

    for(int i = 1; i <= N; i++) {
        lst[arr[i]] = i;
    }

    cin >> M;

    for(int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        isDegree[lst[a]]++;
        v[lst[b]].push_back(lst[a]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}
