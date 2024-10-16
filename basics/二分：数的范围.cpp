#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int n, m;

int q[N];

int main()
{   
    // 数组长度和询问个数
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    // m个query
    while (m--)
    {
        int k;
        scanf("%d", &k);
        
        // 开始二分查找(找最左边的)
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= k) r = mid;
            else l = mid + 1;
        }
        
        if (q[l] != k) cout << "-1 -1" << endl;
        else 
        {
            cout << l << ' ';
            
            // 二分查找(找最右边的)
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= k) l = mid;
                else r = mid - 1;
            }
            
            cout << l << endl;
        }
        
    }
    
    return 0;
}