#include <bits/stdc++.h>
using namespace std;

// ランレングス
vector<pair<char, int>> runlength(string s) {
    int n = s.size();
    vector<pair<char, int> > res;
    char pre = s[0];
    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(pre != s[i]){
            res.push_back({ pre, cnt });
            pre = s[i];
            cnt = 1;
        }
        else cnt++;
    }
    res.push_back({pre, cnt});
    return res;
}
