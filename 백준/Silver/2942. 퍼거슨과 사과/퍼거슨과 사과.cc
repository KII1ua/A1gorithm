// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};
int R, G;

int divisor(int a, int b) {
    int cnt = 1;
    bool visited = false;

    while(true) {
        visited = false;
        for(int i = 2; i <= min(a, b); i++) {
            if(a % i == 0 && b % i == 0) {
                cnt *= i;
                a /= i;
                b /= i;
                visited = true;
                break;
            }
        }
        if(!visited) {
            return cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int tmp;

    cin >> R >> G;

    tmp = divisor(R, G);
    for(int i = 1; i <= tmp; i++) {
        if(tmp % i == 0) {
            cout << i << " " << R / i << " " << G / i << endl;
        }
    }
}