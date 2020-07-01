// 繰り返し二乗法 bit配列版
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

// 繰り返し二乗法
template<typename T>
T mod_pow(T n, T k, T &m){
    if(k == 0){
        return 1;
    }else if(k % 2 == 1){
        return mod_pow(n, k - 1, m) * n % m;
    }else{
        T t = mod_pow(n, k / 2, m);
        return t * t % m;
    }
}
