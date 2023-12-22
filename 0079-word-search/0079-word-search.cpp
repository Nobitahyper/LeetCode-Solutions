class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (dfs(board, word, 0, i, j)) {
                    return true; // Word found starting from (i, j)
                }
            }
        }
        return false; // Word not found in the grid
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int index, int x, int y) {
        if (index == word.size()) return true; // Word is completely found
        if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size()) return false; // Out of bounds
        if (board[x][y] != word[index]) return false; // Character mismatch

        char temp = board[x][y];
        board[x][y] = '#'; // Mark as visited

        // Explore all four directions
        if (dfs(board, word, index + 1, x + 1, y) || dfs(board, word, index + 1, x - 1, y) ||
            dfs(board, word, index + 1, x, y + 1) || dfs(board, word, index + 1, x, y - 1)) {
            return true;
        }

        board[x][y] = temp; // Backtrack and unmark as visited
        return false;
    }
};

