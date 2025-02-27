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
int arr[10];
int result[10];
bool primes[10001];
bool visited[10];
set<int> st;

void isprime() {
    primes[1] = true;

    for(int i = 2; i <= sqrt(10000); i++) {
        if(!primes[i]) {
            for(int j = i * 2; j <= 10000; j += i) {
                primes[j] = true;       // 소수가 아님
            }
        }
    }
}

void bt(int x) {
    if(x == M) {
        int tmp = 0;
        for(int i = 0; i < M; i++) {
            tmp += result[i];
        }
        if(!primes[tmp]) {
            st.insert(tmp);
        }
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visited[i]) {
            visited[i] = true;
            result[x] = arr[i];
            bt(x+1);
            visited[i] = false;
        }
    }
}

void input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
}

void solution() {
    input();
    isprime();
    bt(0);
    
    if(st.size() == 0) {
        cout << -1;
        return;
    }

    for(auto it : st) {
        cout << it << " ";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    solution();
}
