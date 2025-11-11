#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

bool compare(const vector<int> &a, const vector<int> &b) {
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {
    int answer = 0;
    
    sort(targets.begin(), targets.end(), compare);
    
    
    int hi = 0;
    for(int i = 0; i < targets.size(); i++) {
        if(targets[i][0] >= hi) {
            hi = targets[i][1];
            answer++;
        }
    }
    
    return answer;
}