class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        unique_list = set(nums)
        if len(unique_list) == len(nums):
            return False
        else:
            return True