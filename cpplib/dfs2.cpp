#include <bits/stdc++.h>
#include <vector>
using namespace std;

#define all(v) v.begin(), v.end()
typedef long long ll;

const int M = 2;
void dfs(vector<int> &A){
    if(A.size() == 10){
        for(int i = 0; i < 10; i++) cout << A[i];
        cout << endl;
        return;
    }

    for(int i = 0; i < M; i++){
        A.push_back(i);
        dfs(A);
        A.pop_back();
    }
}

int main() {
    vector<int> A;
    dfs(A);
}
