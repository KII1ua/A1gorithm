// baekjoon 1504
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
ll arr[5][5];      // 입력 행렬
ll result[5][5];       // 단위 행렬
ll temp[5][5];       // 임시 배열
ll N, B;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int a;

    cin >> N >> B;      // B제곱

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> a;
            arr[i][j] = a;
        }
        result[i][i] = 1;
    }

    while(B) {
        if(B % 2 == 1) {
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    temp[i][j] = 0;
                    for(int k = 0; k < N; k++) {
                        temp[i][j] += (arr[i][k] * result[k][j]);
                    }
                }
            }

            for(int i = 0; i < N; i++) {
                for(int j = 0; j < N; j++) {
                    result[i][j] = temp[i][j] % 1000;
                }
            }
        }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                temp[i][j] = 0;
                for(int k = 0; k < N; k++) {
                    temp[i][j] += (arr[i][k] * arr[k][j]);
                }
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                arr[i][j] = temp[i][j] % 1000;
            }
        }
        B /= 2;

    }
    for(int i = 0; i < N ; i++) {
        for(int j = 0; j < N; j++) {
            cout << result[i][j] % 1000 << " ";
        }
        cout << endl;
    }
}
