#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, M = 510;

int ball_num, hp, n;
int ball, harm;
int f[N][M]; // 精灵球使用量小于j，掉血小于k，最多能抓多少只精灵

int main() {
    cin >> ball_num >> hp >> n;
    // 使得皮卡丘体力小于等于0的野生小精灵也不会被小智收服，所以实际能更新到的体力极限是hp - 1
    hp--;
    
    for (int i = 0; i < n; i++) {
        cin >> ball >> harm;
        
        for (int j = ball_num; j >= ball; j--) {
            for (int k = hp; k >= harm; k--) {
                f[j][k] = max(f[j][k], f[j - ball][k - harm] + 1);
            }
        }
    }
    
    // 如果可以收服的小精灵数量一样，小智希望皮卡丘受到的伤害越小（剩余体力越大）
    int k = hp;
    while (k > 0 && f[ball_num][k-1] == f[ball_num][hp]) k--;
    cout << f[ball_num][hp] << ' ' << hp + 1 - k << endl; // 计算剩余体力时记得还原hp+1
    
    return 0;
}