class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int len = 1;
        string res;

        vector<vector<bool>> f(n, vector<bool>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i == j || (s[i] == s[j] && (i - j <= 2 || f[j+1][i-1] == true))) {
                    f[j][i] = true;
                    if ((i-j+1) >= len) {
                        len = i-j+1;
                        res = s.substr(j, len);
                    }
                }
            }
        }
        return res;
    }
};