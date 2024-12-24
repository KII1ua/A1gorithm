#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N;
    vector<pair<int, int>> v;

    int a, b;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());

    for(int i = 0; i < N; i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }

}