#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5e4 + 10;
typedef pair<long long, long long> PII;

int n;
PII cow[N];

int main()
{   
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w, s;
        cin >> w >> s;
        cow[i] = {w+s, w};
    }

    sort(cow, cow + n); // 从小到大（从上到下）

    int risk = -2e9, sum = 0; // sum表示在当前牛上方已经堆叠的所有牛的总重量
    for (int i = 0; i < n; i ++ )
    {
        int s = cow[i].first - cow[i].second;
        int w = cow[i].second;
        risk = max(risk, sum - s); // 当前牛上方已经堆叠的所有牛的总重量 - 当前牛的强壮程度
        sum += w;
    }

    cout << risk << endl;

    return 0;
}