#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
};

int dx[] = {0, 0, -1, 1, 1, -1, -1, 1};
int dy[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int N, M;
int unf[1000001];

int Find(int a) {
    if(a == unf[a]) return a;
    return unf[a] = Find(unf[a]);
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) {
        unf[a] = b;
    }
    else unf[b] = a;
}

bool isUnion(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Init() {
    for(int i = 0; i <= N; i++) {
        unf[i] = i;
    }
}

void input() {
    cin >> N >> M;

    Init();

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0) {
            Union(b, c);
        }
        else {
            if(isUnion(b, c)) {
                cout << "YES" << endl;
            }
            else cout << "NO" << endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}