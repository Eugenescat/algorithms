class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i  = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size();j ++) {
                if (dfs(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }

    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

    // int u: 正在遍历第u个字符
    // int x, y: 起点
    bool dfs(vector<vector<char>>& board, string& word, int u, int x, int y) {
        if (board[x][y] != word[u]) return false;
        if (u == word.size() - 1) return true; 

        char t = board[x][y];
        board[x][y] = '.'; // 不能重复，因此标记为已经走过
        for (int i = 0; i < 4; i ++) {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= board.size() || b < 0 || b >= board[0].size() || board[a][b] == '.') continue;
            if (dfs(board, word, u + 1, a, b)) return true;
        }
        board[x][y] = t; // 回溯恢复
        return false;
    }
};