#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int N, M;
vector<ll> segmentTree;
int arr[1000001];

ll make_segmentTree(int node, int start, int end) {
    if(start == end) return segmentTree[node] = arr[start];
    int mid = (start + end) / 2;
    ll left = make_segmentTree(node * 2, start, mid);
    ll right = make_segmentTree(node * 2 + 1, mid + 1, end);
    segmentTree[node] = left + right;

    return segmentTree[node];
}

ll Sum(int node, int start, int end, int left, int right) {
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segmentTree[node];

    int mid = (start + end) / 2;
    ll left_result = Sum(node * 2, start, mid, left, right);
    ll right_result = Sum(node * 2 + 1, mid + 1, end, left, right);
    return left_result + right_result;
}

void update_segmentTree(int node, int start, int end, int index, int value) {
    if(index < start || index > end) return;
    if(start == end) {
        arr[index] = segmentTree[node] = value;
        return;
    }

    int mid = (start + end) / 2;
    update_segmentTree(node * 2, start, mid, index, value);
    update_segmentTree(node * 2 + 1, mid + 1, end, index, value);
    segmentTree[node] = segmentTree[node * 2] + segmentTree[node * 2 + 1];
}

void input() {
    cin >> N >> M;
    segmentTree.resize(N * 4);
    make_segmentTree(1, 0, N-1);

    for(int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            if(b > c) swap(b, c);
            cout << Sum(1, 0, N-1, b-1, c-1) << endl;
        }
        else {
            update_segmentTree(1, 0, N-1, b-1, c);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    input();
}
