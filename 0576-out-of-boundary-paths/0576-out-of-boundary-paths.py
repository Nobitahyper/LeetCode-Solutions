MOD = 10**9 + 7

class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        dp = [[[0 for _ in range(n)] for _ in range(m)] for _ in range(maxMove + 1)]
        
        for move in range(1, maxMove + 1):
            for r in range(m):
                for c in range(n):
                    top = dp[move - 1][r - 1][c] if r > 0 else 1
                    bottom = dp[move - 1][r + 1][c] if r < m - 1 else 1
                    left = dp[move - 1][r][c - 1] if c > 0 else 1
                    right = dp[move - 1][r][c + 1] if c < n - 1 else 1
                    
                    dp[move][r][c] = (top + bottom + left + right) % MOD
        
        return dp[maxMove][startRow][startColumn]
        

