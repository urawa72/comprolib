#include <bits/stdc++.h>
#include "../time_degree.cpp"
using namespace std;
typedef long long ll;

int main() {
    double a = 3, b = 4;
    int h = 10, m = 40;
    TimeDegree<int> tg(h, m);
    double ans = pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(tg.getRadian());
    cout << setprecision(20) << sqrt(ans) << endl;
}
