#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

// 階乗
ll factorial(ll n) {
    ll ans = 1;
    for(ll i = 1; i <= n; i++){
        ans *= i;
        ans %= MOD;
    }
    return ans % MOD;
}
