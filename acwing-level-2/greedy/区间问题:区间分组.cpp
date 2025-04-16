#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

int n;

struct Range
{
    int l, r;
    bool operator< (const Range& w)const
    {
        return l < w.l;
    }
}range[N];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> range[i].l >> range[i].r;

    sort(range, range + n);

    priority_queue<int, vector<int>, greater<int>> heap;
    for (int i = 0; i < n; i++)
    {
        auto cnt = range[i];
        if (heap.empty() || heap.top() >= cnt.l) heap.push(cnt.r);
        else
        {
            heap.pop();
            heap.push(cnt.r);
        }
    }

    cout << heap.size() << endl;

    return 0;
}