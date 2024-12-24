#include <bits/stdc++.h>
using namespace std;

bool compare(string a, string b) {
    if(a.length() == b.length())
        return a < b;
    else
        return a.length() < b.length();
}

int main() {
    int N;

    cin >> N;

    string arr[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, compare);
    
    for(int i = 0; i < N; i++) {
        if(arr[i] == arr[i-1])
            continue;
        else
            cout << arr[i] << "\n";
    }
}