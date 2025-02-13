// baekjoon 17835
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"
#define INF int(1e9)

int dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
int dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
int N;

struct tree {
    char root = '\0';
    char left = '\0';
    char right = '\0';
};

tree arr[27];

void preorder(tree a) {
    if(a.root == '\0' || a.root == '.') {
        return;
    }
    cout << a.root;
    if(a.left != '\0' && a.left != '.') {
        preorder(arr[a.left-'A']);
    }
    if(a.right != '\0' && a.right != '.') {
        preorder(arr[a.right-'A']);
    }
}

void order(tree a) {
    if(a.left != '\0' && a.left != '.') {
        order(arr[a.left - 'A']);
    }
    if(a.root == '\0' || a.root == '.') {
        return;
    }
    if(a.root != '\0' && a.root != '.') {
        cout << a.root;
    }
    if(a.right != '\0' && a.right != '.') {
        order(arr[a.right - 'A']);
    }
}

void lastorder(tree a) {
    if(a.left != '\0' && a.left != '.') {
        lastorder(arr[a.left - 'A']);
    }
    if(a.right != '\0' && a.right != '.') {
        lastorder(arr[a.right - 'A']);
    }
    if(a.root != '\0' && a.root != '.') {
        cout << a.root;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        char ch1, ch2, ch3;
        cin >> ch1 >> ch2 >> ch3;
        arr[ch1-'A'].root = ch1;
        arr[ch1-'A'].left = ch2;
        arr[ch1-'A'].right = ch3;
    }

    preorder(arr['A'-'A']);
    cout << endl;
    order(arr['A'-'A']);
    cout << endl;
    lastorder(arr['A'-'A']);
}
