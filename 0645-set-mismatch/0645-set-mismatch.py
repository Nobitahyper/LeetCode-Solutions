class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n = len(nums)
        sum_nums = sum(nums)
        sum_nums_sq = sum(x*x for x in nums)
        
        expected_sum = n * (n + 1) // 2
        expected_sum_sq = n * (n + 1) * (2 * n + 1) // 6
        
        # deriving equation
        diff_sum = sum_nums - expected_sum # x - y
        diff_sum_sq = sum_nums_sq - expected_sum_sq # x^2 - y^2 = (x + y) (x - y)
        
        # solving for x & y
        sum_xy = diff_sum_sq // diff_sum # x + y
        x = (diff_sum + sum_xy) // 2  # x + y + x - y
        y = sum_xy - x  # y = (x + y) - x
        
        return [x, y]
        
        
