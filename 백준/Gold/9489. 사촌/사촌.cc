#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1e11

struct coordinate {
    int x;
    int y;
    int r;
};

struct halloween {
    int cnt;
    int score;
};

// int dx[] = {-1, 1, 0, 0, 1, -1, -1, 1};
// int dy[] = {0, 0, -1, 1, -1, 1, -1, 1};
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int N, K;

void solve(int parent[], int arr[]) {
    int answer = 0;

    if(K == arr[0]) {
        answer = 0;
    }
    else {
        for(int i = 0; i < N; i++) {
            if(parent[parent[arr[i]]] == parent[parent[K]] && parent[arr[i]] != parent[K]) {
                answer++;
            }
        }
    }

    cout << answer << "\n";
}

void input() {
    while(true) {
        cin >> N >> K;

        if(N == 0 && K == 0) return;

        int parent[1000001];
        int arr[1000001];

        int Node = -1;
        int idx = -1;
        for(int i = 0; i < N; i++) {
            cin >> arr[i];

            int a = arr[i];

            if(i == 0) {
                Node = a;
                parent[a] = -1;
            }
            else {
                if(Node + 1 == a) {     // 같은 집합
                    parent[a] = arr[idx];
                    Node = a;
                }
                else {
                    Node = a;
                    idx++;
                    parent[a] = arr[idx];
                }
            }
        }

        solve(parent, arr);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
