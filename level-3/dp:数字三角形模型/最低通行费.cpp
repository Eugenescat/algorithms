#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110, INF = 1e9;

int n;
int w[N][N];
int f[N][N];

int main() {

    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> w[i][j];
        }
    }

    f[1][1] = w[1][1];
    for (int i = 2; i <= n; i++) f[i][0] = f[0][i] = INF;


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            f[i][j] = min(f[i-1][j], f[i][j-1]) + w[i][j];
        }
    }

    cout << f[n][n] << endl;
}