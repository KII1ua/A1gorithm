// baekjoon 4889
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define MAX 1025
int arr[50];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1 ,1};

bool isPrime(int num) {
    if(num <= 1) {
        return false;
    }

    if(num % 2 == 0) {
        if(num == 2)
            return true;
        return false;
    }

    for(int i = 3; i <= sqrt(num); i += 2) {
        if(num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int M, N;

    cin >> M >> N;

    for(int i = M; i <= N; i++) {
        if(isPrime(i)) {
            cout << i << endl;
        }
    }
}