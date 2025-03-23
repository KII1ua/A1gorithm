#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int arr[100002];
int result[1000002];
int N, M, cnt;

void input() {
    cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i++) {
        if(arr[i] < arr[i-1]) {
            result[i] = result[i-1] + 1;
        }
        else {
            result[i] = result[i-1];
        }
    }
    
    cin >> M;
    
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        
        cout << result[b] - result[a] << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
