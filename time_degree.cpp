// 時計算 度とラジアン
template <typename T>
struct TimeDegree {
    const double PI=3.14159265358979323846;
    T hour;
    T minute;
    TimeDegree(T h, T m) {
        hour = h;
        minute = m;
    }
    // 時計算(長針と短針のなす角)
    double getDegree() const {
        double x = hour * 30 + minute * 0.5; // 短針は0.5度/分
        double y = minute * 6.0; // 長針は6度/分
        return abs(x - y);
    }
    // 度をラジアンへ
    double getRadian() const {
        return getDegree() * PI / 180.0;
    }
};
