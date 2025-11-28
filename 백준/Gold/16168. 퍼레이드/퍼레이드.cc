#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e9

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, M;
int unf[3001];
int inDegree[3001];
int graph[3001];        // 부모의 정점이 i면서 홀수 정점의 개수

int Find(int a) {
    if(unf[a] == a) return a;
    return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a < b) {
        unf[b] = a;
    }
    else unf[a] = b;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Print() {
    for(int i = 1; i <= N; i++) {
        cout << inDegree[i] << " ";
    }
}

void solve() {
    int root = 0;

    for(int i = 1; i <= N; i++) {
        if(inDegree[i] > 0) {
            int curroot = Find(i);

            if(root == 0) {
                root = curroot;
            }
            else if(root != curroot) {
                cout << "NO";
                return;
            }
        }
    }

    int count = 0;
    for(int i = 1; i <= N; i++) {
        if(inDegree[i] % 2 == 1) {
            count++;
        }
    }

    if(count > 2) {
        cout << "NO";
    }
    else cout << "YES";
}

void Init() {
    for(int i = 1; i <= N; i++) {
        unf[i] = i;
    }
}

void input() {
    cin >> N >> M;

    Init();

    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        inDegree[a]++, inDegree[b]++;

        if(!isUnion(a, b)) {
            Union(a, b);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
    solve();
}