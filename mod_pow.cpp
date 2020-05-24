// べき乗 mod 1e9 + 7で割った余りを求める
template<typename T>
T modPow(T x, T n, const T &mod){
    T res = 1;
    while(n > 0){
        if(n & 1) (res *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1; // nを1bit左にずらす
    }
    return res;
}
