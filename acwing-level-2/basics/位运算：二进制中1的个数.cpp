#include <iostream>

using namespace std;

int n;

int lowbit(int x)
{
    return x & -x;
}

int main()
{
    scanf("%d", &n);
    
    while (n--)
    {
        int x;
        scanf("%d", &x);
        
        int res = 0;
        while (x)
        {
            x -= lowbit(x);
            res++;
        }
        cout << res << ' ';
    }
    
    return 0;
}
