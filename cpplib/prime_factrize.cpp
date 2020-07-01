#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// 素因数分解
vector<pair<ll, ll> > prime_factorize(ll N){
    vector<pair<ll, ll> > res;
    for(ll i = 2; i * i <= N; i++){
        if(N % i != 0) continue;
        ll ex = 0;
        while(N % i == 0){
            ex++;
            N /= i;
        }
        // 素数と指数をpush
        res.push_back({i, ex});
    }
    if(N != 1) res.push_back({N, 1});
    return res;
}
