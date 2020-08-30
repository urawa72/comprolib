#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX = 1000000;
const int MOD = 1000000007;

// テーブルを作る前処理
long long fac[MAX], finv[MAX], inv[MAX];
void com_init() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

 // 二項係数計算
long long com(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


// 繰り返し二乗法
ll mod_pow(ll x, ll a){
    if(a == 1) return x;
    // 指数aが奇数の時はx*x^(a-1)
    if(a % 2) return (x * mod_pow(x, a - 1)) % MOD;
    // 指数aが偶数の時はx^(a/2)
    ll t = mod_pow(x, a / 2);
    return (t * t) % MOD;
}

// フェルマーの小定理からxのMOD-2乗を計算
ll mod_inv(ll x){
    return mod_pow(x, MOD - 2);
}

// kまでの階乗計算
ll mod_perm(ll n, ll k){
    ll ret = 1;
    for(int i = 0; i < k; i++){
        ret = (ret * (n - i)) % MOD;
    }
    return ret;
}

// 二項係数(n = 1e9, k = 1e7まで対応可能))
ll mod_comb(ll n, ll k){
    ll a, b;
    // n - k + 1からnまでの積
    a = mod_perm(n, k);
    // k!
    b = mod_perm(k, k);
    return (a * mod_inv(b)) % MOD;
}


// https://atcoder.jp/contests/abc156/tasks/abc156_d
int main() {
    ll n, a, b; cin >> n >> a >> b;

    ll ans = (mod_pow(2, n) - 1 - mod_comb(n, a) - mod_comb(n, b)) % MOD;
    ans = (ans + MOD) % MOD;
    cout << ans << endl;
}
