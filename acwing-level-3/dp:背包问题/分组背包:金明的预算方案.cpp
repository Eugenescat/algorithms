#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int M = 32010, N = 70;

typedef pair<int, int> PII;

int m, n;
PII master[N];
vector<PII> slave[N]; // 一个长度为N的数组，里面存放的是vector<PII>类型的元素
int f[M];

int main() {

    // m金钱，n个物品
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        int v, p, q;
        cin >> v >> p >> q;
        if (q == 0) { // 是主键
            master[i] = {v, v * p};
        } else {
            slave[q].push_back({v, v * p}); // q的范围是[1,n]，所以后面遍历n记得是从1开始
        }
    }

    // 遍历每组物品（一个master带领一组物品）
    for (int i = 1; i <= n; i++) {
        if (!master[i].first) continue; // 不是master
        int v = master[i].first, w = master[i].second; // master物品的v和w
        
        // 遍历体积
        for (int j = m; j >= 0; j--) {
            // 二进制优化:该组物品有k个，选项子集有2^k种，用 0~(2^k - 1) 的整数表示，每个整数都有k位
            for (int u = 0; u < 1 << slave[i].size(); u++) {
                // 统计每个整数的二进制位代表：是否选某个附件
                for (int k = 0; k < slave[i].size(); k++) {
                    if (j << k & 1) {
                        v += slave[i][k].first;
                        w += slave[i][k].second;
                    }
                }

                if (j >= v) f[j] = max(f[j], f[j - v] + w);
            } 
        }
    }
    
    cout << f[m] << endl;
    
    return 0;
}