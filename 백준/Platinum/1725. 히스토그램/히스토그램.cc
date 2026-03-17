#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define endl "\n"

struct Tree {
    int Node, left, right;
};

const int INF = 1e9;
const int MAX = 20001;
const int D = 2000000;
const int MOD = 10007;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N;
    int answer = 0;
    stack<int> st;

    cin >> N;

    vector<int> v(N, 0);

    for(auto &iter : v) {
        cin >> iter;
    }

    v.push_back(0);


    for(int i = 0; i < v.size(); i++) {

        while(!st.empty() && v[st.top()] > v[i]) {
            int height = v[st.top()];
            st.pop();

            int width = st.empty()? i : i - st.top() - 1;

            answer = max(answer, height * width);
        }
        st.push(i);
    }

    cout << answer;
}