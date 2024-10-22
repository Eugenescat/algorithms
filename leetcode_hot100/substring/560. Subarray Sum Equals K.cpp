class Solution {
public:
    // 子串和：用前缀和 Si - Sj = k
    // 用哈希表存<Si's index, int>
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        vector<int> s(n+1);
        for (int i = 1; i <= n; i ++) s[i] = s[i-1] + nums[i-1];

        // // O(n^2)的暴力做法
        // for (int i = 1; i <= n; i++)
        //     for (int j = 0; j < i; j++)
        //         if (s[i] - s[j] == k) res++;

        // 哈希表做法O(n)
        // 用哈希表存储所有的前缀和出现次数，对于某个特定下标i，如果哈希表中已经存过n个Sj且Si-Sj=k，意味着有n组（Si-Sj=k），res += n
        unordered_map<int, int> hash;
        hash[0] = 1; // 前缀和为0的情况包括S[0]
        for (int i = 1; i <= n; i ++)
        {
            res += hash[s[i] - k];
            hash[s[i]] ++;
        }

        return res;
    }
};