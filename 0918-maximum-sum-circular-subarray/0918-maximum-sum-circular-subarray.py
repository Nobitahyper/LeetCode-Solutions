from typing import List

class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        def kadane(arr: List[int]) -> int:
            max_end_here = max_so_far = arr[0]
            for num in arr[1:]:
                max_end_here = max(num, max_end_here + num)
                max_so_far = max(max_so_far, max_end_here)
            return max_so_far

        max_kadane = kadane(nums)
        total_sum = sum(nums)

        inverted_nums = [-num for num in nums]
        max_inverted_kadane = kadane(inverted_nums)

        if total_sum + max_inverted_kadane == 0:
            return max_kadane
        
        return max(max_kadane, total_sum + max_inverted_kadane)

