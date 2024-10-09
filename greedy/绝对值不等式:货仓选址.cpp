#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, q[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> q[i];
    sort(q, q+n);

    int res = 0;
    for (int i = 0; i < n; i++) res += abs(q[i] - q[n/2]); // 加上q[i]和中位数之间的距离

    cout << res << endl;

    return 0;
}