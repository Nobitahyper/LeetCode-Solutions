class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        dp = [float('-inf')] * 5  # dp[0 to 4]
        dp[0] = 0  # Base case: no elements selected, score is 0
        for b_i in b:
            # Update dp[k] for k from 4 down to 1
            for k in range(4, 0, -1):
                dp[k] = max(dp[k], dp[k - 1] + a[k - 1] * b_i)
        return dp[4]