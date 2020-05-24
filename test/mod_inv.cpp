#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9 + 7;

// 繰り返し二乗法
ll modPow(ll x, ll a){
    if(a == 1) return x;
    // 指数aが奇数の時はx*x^(a-1)
    if(a % 2) return (x * modPow(x, a - 1)) % MOD;
    // 指数aが偶数の時はx^(a/2)
    ll t = modPow(x, a / 2);
    return (t * t) % MOD;
}

// フェルマーの小定理からxのMOD-2乗を計算
ll modInv(ll x){
    return modPow(x, MOD - 2);
}

// kまでの階乗計算
ll modPerm(ll n, ll k){
    ll ret = 1;
    for(int i = 0; i < k; i++){
        ret = (ret * (n - 1)) % MOD;
    }
    return ret;
}

// 二項係数(n = 1e9, k = 1e7まで対応可能))
ll modComb(ll n, ll k){
    ll a, b;
    // n - k + 1からnまでの積
    a = modPerm(n, k);
    // k!
    b = modPerm(k, k);
    return (a * modInv(b)) % MOD;
}

int main() {
    ll x = 8;
    // xのmod MODの世界における逆元を求める
    cout << modInv(x) << endl;

    ll n = 1e9, k = 1e7;
    cout << modComb(n, k) << endl;
}
