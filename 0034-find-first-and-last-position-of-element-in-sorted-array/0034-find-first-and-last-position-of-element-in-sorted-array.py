class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        def bsearch(nums, target, findFirst):
            index = -1
            low, high = 0, len(nums) - 1
            
            while (low <= high):
                mid = (low + high) // 2
                if nums[mid] == target:
                    index = mid
                    if findFirst:
                        high = mid - 1
                    else:
                        low = mid + 1
                        
                elif nums[mid] < target:
                    low = mid + 1
                else:
                    high = mid - 1
                    
            return index
                    
        first = bsearch(nums, target, True)
        second = bsearch(nums, target, False)
        
        return [first, second]
        

   