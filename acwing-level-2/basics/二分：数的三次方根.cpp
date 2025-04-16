#include <iostream>

using namespace std;

int main()
{
    double x;
    cin >> x;
    
    double l = -10000, r = 10000;
    while (r - l > 1e-8) // 保留六位小数，多取两位，truncate时更精准
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }
    
    printf("%lf", l); // lf默认保留六位小数
    return 0;
}