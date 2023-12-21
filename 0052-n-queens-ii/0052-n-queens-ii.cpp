class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false), diag(2 * n, false), antiDiag(2 * n, false);
        backtrack(0, n, cols, diag, antiDiag, count);
        return count;
    }

private:
    void backtrack(int row, int n, vector<bool>& cols, vector<bool>& diag, vector<bool>& antiDiag, int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int col = 0; col < n; col++) {
            if (!cols[col] && !diag[row + col] && !antiDiag[row - col + n]) {
                cols[col] = diag[row + col] = antiDiag[row - col + n] = true;
                backtrack(row + 1, n, cols, diag, antiDiag, count);
                cols[col] = diag[row + col] = antiDiag[row - col + n] = false;
            }
        }
    }
};

