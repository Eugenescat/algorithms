class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 记录每个字符最后出现的位置
        unordered_map<int, int> last;
        for (int i = 0; i < s.size(); i ++) last[s[i]] = i;

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i ++) {
            // 展期当前区间
            end = max(end, last[s[i]]);
            if (i == end) {
                res.push_back(end - start + 1);
                end = start = end + 1;
            }
        }
        return res;
    }
};