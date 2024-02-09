class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        res = r
        
        while l <= r:
            k = (l + r) // 2
            hours = sum((p - 1) // k + 1 for p in piles)  
            
            if hours <= h:
                res = k  
                r = k - 1
            else:
                l = k + 1
                
        return res
