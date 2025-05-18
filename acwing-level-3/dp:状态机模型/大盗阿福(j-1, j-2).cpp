#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 10e5 + 10;

int f[N];

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        cin >> f[0];
        int temp;
        cin >> temp;
        f[1] = max(temp, f[0]);
        
        for (int i = 2; i < n; i++) {
            int w;
            cin >> w;
            f[i] = max(f[i-1], f[i-2] + w);
        }
        cout << f[n-1] << endl;
    }
    return 0;
}