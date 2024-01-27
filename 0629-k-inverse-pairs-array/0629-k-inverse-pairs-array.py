
MOD = 10**9 + 7

class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        dp = [[0] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for i in range(1, n + 1):
            cumulative = 0
            for j in range(0, k + 1):
                cumulative += dp[i - 1][j]
                if j >= i:
                    cumulative -= dp[i - 1][j - i]
                dp[i][j] = cumulative % MOD

        return dp[n][k]
