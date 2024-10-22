class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 先将所有数都放到有序哈希表里
        unordered_set<int> s;
        for (auto x : nums) s.insert(x);
        
        int res = 0;
        // 按顺序遍历
        for (auto x : nums)
        {
            // 如果x-1不存在，说明x是一个连续序列的起点
            if (s.count(x) && !s.count(x - 1))
            {   
                // 从x开始向后找，直到找不到为止
                int y = x;
                s.erase(x); // 从哈希表中删除
                if (s.count(y+1))
                {
                    y++;
                    s.erase(y);
                }
                // 更新结果
                res = max(res, y - x + 1);
            }
        }
        return res;
    }
};