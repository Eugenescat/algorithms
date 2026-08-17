class Solution {
    public:
        int minSwaps(vector<int>& nums) {
            int n = nums.size();
            
            vector<int> sum(n);
            for (int i = 0; i < n; i++) {
                int k = nums[i];
                int s = 0;
                while (k) {
                    s += k % 10;
                    k = k / 10;
                }
                sum[i] = s;
            }
            
            // 排序前的位置排列
            vector<int> idx(n);
            for (int i = 0; i < n; i++) idx[i] = i;
            // 排序后的位置排列
            sort(idx.begin(), idx.end(), [&](int a, int b) {
                if (sum[a] != sum[b]) return sum[a] < sum[b];
                return nums[a] < nums[b];
            });
            
            // 建立从老排列->新排列的映射（e.g. '3'去了'0'）
            vector<int> to(n);
            for (int i = 0; i < n; i++) {
                to[ idx[i] ] = i;
            }
            
            // 把i位置上的value交换去与它相等的位置，直到i位置上的value等于i
            int swaps = 0;
            for (int i = 0; i < n; i++) {
                while (to[i] != i) {
                    swap(to[i], to[to[i]]);
                    swaps ++;
                }
            }
            return swaps;
        }
    };