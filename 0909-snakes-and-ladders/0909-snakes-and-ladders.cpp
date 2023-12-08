class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n * n + 1, -1); // 1-indexed array for board

        // Fill 1D array with board values, adjusting for Boustrophedon style
        bool leftToRight = true;
        int idx = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (leftToRight) {
                for (int j = 0; j < n; ++j) {
                    arr[idx++] = board[i][j];
                }
            } else {
                for (int j = n - 1; j >= 0; --j) {
                    arr[idx++] = board[i][j];
                }
            }
            leftToRight = !leftToRight;
        }

        // BFS to find shortest path
        queue<int> q;
        q.push(1); // start from cell 1
        vector<bool> visited(n * n + 1, false);
        visited[1] = true;

        int moves = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                int curr = q.front();
                q.pop();

                if (curr == n * n) return moves; // reached end

                for (int next = curr + 1; next <= min(curr + 6, n * n); ++next) {
                    int dest = arr[next] == -1 ? next : arr[next];
                    if (!visited[dest]) {
                        visited[dest] = true;
                        q.push(dest);
                    }
                }
            }
            ++moves;
        }

        return -1;

    }
};

