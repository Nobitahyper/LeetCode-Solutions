class Solution:
    def getSneakyNumbers(self, nums: List[int]) -> List[int]:
        n = len(nums) - 2
        counts = [0] * n  # Initialize counts for numbers from 0 to n-1
        for num in nums:
            counts[num] += 1  # Increment count for each number
        duplicates = []
        for i in range(n):
            if counts[i] == 2:
                duplicates.append(i)  # Collect numbers that appear twice
        return duplicates