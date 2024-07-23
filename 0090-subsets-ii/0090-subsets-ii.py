class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        res = []
        curSet = []
        nums.sort()
        
        def backtrack(i):
            if i >= len(nums):
                res.append(curSet.copy())
                return
            
            # decision to include
            curSet.append(nums[i])
            backtrack(i + 1)
            curSet.pop()
            
            # decision not to include
            while i + 1 < len(nums) and nums[i] == nums[i + 1]:
                i += 1
            
            backtrack(i + 1)
            
        backtrack(0)
        return res