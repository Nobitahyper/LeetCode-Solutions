class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        n = len(nums)
        hash_set = set()
        for i in range(1, n): # given n + 1 and [1, n]
            hash_set.add(i)
            
        for num in nums:
            if num in hash_set:
                hash_set.remove(num)
                
            else:
                repeat = num
                
        return repeat