#include <bits/stdc++.h>

using namespace std;

int arr[31];

int solution(int n, vector<int> lost, vector<int> reserve) {
    int result = 0;
    
    for(auto it : lost) {
        arr[it]--;
    }
    
    for(auto it : reserve) {
        arr[it]++;
    }
    
    for(int i = 1; i <= n; i++) {
        if(arr[i] == -1) {
            if(arr[i-1] == 1) {
                arr[i-1] = 0;
                arr[i]++;
                continue;
            }
            else if(arr[i+1] == 1) {
                arr[i+1] = 0;
                arr[i]++;
                continue;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        if(arr[i] != -1) result++;
    }
    
    return result;
}